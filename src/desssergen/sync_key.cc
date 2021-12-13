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
struct t0193f94945d5c55637b2beab1e77dc5c : public std::variant<
  Void, // StateFile
  Void, // InputRingFile
  Void, // Pid
  Void, // LastKilled
  Void, // LastExit
  Void, // LastExitStatus
  Void, // SuccessiveFailures
  Void // QuarantineUntil
> { using variant::variant; };

inline bool operator==(t0193f94945d5c55637b2beab1e77dc5c const &a, t0193f94945d5c55637b2beab1e77dc5c const &b) {
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
inline bool operator!=(t0193f94945d5c55637b2beab1e77dc5c const &a, t0193f94945d5c55637b2beab1e77dc5c const &b) {
  return !operator==(a, b);
}
struct t21e5dc291e02ff6b92981a2d2fa864dc : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c
> {
  using tuple::tuple;
  t21e5dc291e02ff6b92981a2d2fa864dc(std::tuple<std::string, ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t21e5dc291e02ff6b92981a2d2fa864dc const &a, t21e5dc291e02ff6b92981a2d2fa864dc const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t21e5dc291e02ff6b92981a2d2fa864dc const &a, t21e5dc291e02ff6b92981a2d2fa864dc const &b) {
  return !operator==(a, b);
}
struct per_worker_data : public std::variant<
  Void, // RuntimeStats
  Void, // ArchivedTimes
  Void, // NumArcFiles
  Void, // NumArcBytes
  Void, // AllocedArcBytes
  Void, // Worker
  ::dessser::gen::sync_key::t21e5dc291e02ff6b92981a2d2fa864dc, // PerInstance
  uint32_t, // PerReplayer
  Void // OutputSpecs
> { using variant::variant; };

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
struct t64f559dd09cb0d16d29224992777183c : public std::variant<
  Void, // Host
  Void // Port
> { using variant::variant; };

inline bool operator==(t64f559dd09cb0d16d29224992777183c const &a, t64f559dd09cb0d16d29224992777183c const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Host
    case 1: return std::get<1>(a) == std::get<1>(b); // Port
  };
  return false;
}
inline bool operator!=(t64f559dd09cb0d16d29224992777183c const &a, t64f559dd09cb0d16d29224992777183c const &b) {
  return !operator==(a, b);
}
struct t9a3e45e6c9736129ff8eafaa89ab1b6a : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c
> {
  using tuple::tuple;
  t9a3e45e6c9736129ff8eafaa89ab1b6a(std::tuple<std::string, ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9a3e45e6c9736129ff8eafaa89ab1b6a const &a, t9a3e45e6c9736129ff8eafaa89ab1b6a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9a3e45e6c9736129ff8eafaa89ab1b6a const &a, t9a3e45e6c9736129ff8eafaa89ab1b6a const &b) {
  return !operator==(a, b);
}
struct tea8c2377036e530fd3f67fa8653a3834 : public std::variant<
  Void // Executable
> { using variant::variant; };

inline bool operator==(tea8c2377036e530fd3f67fa8653a3834 const &a, tea8c2377036e530fd3f67fa8653a3834 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Executable
  };
  return false;
}
inline bool operator!=(tea8c2377036e530fd3f67fa8653a3834 const &a, tea8c2377036e530fd3f67fa8653a3834 const &b) {
  return !operator==(a, b);
}
struct td7912e294d6f3a12e8335070433dc663 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::tea8c2377036e530fd3f67fa8653a3834
> {
  using tuple::tuple;
  td7912e294d6f3a12e8335070433dc663(std::tuple<std::string, ::dessser::gen::sync_key::tea8c2377036e530fd3f67fa8653a3834> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::tea8c2377036e530fd3f67fa8653a3834>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td7912e294d6f3a12e8335070433dc663 const &a, td7912e294d6f3a12e8335070433dc663 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td7912e294d6f3a12e8335070433dc663 const &a, td7912e294d6f3a12e8335070433dc663 const &b) {
  return !operator==(a, b);
}
struct per_site_data : public std::variant<
  Void, // IsMaster
  ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a, // PerService
  std::shared_ptr<::dessser::gen::sync_key::per_worker> , // PerWorker
  ::dessser::gen::sync_key::td7912e294d6f3a12e8335070433dc663 // PerProgram
> { using variant::variant; };

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
struct t803a3c9022c32e1702f6b5e3eaa82fb3 : public std::variant<
  Void, // TotalSize
  Void, // RecallCost
  std::string // RetentionsOverride
> { using variant::variant; };

inline bool operator==(t803a3c9022c32e1702f6b5e3eaa82fb3 const &a, t803a3c9022c32e1702f6b5e3eaa82fb3 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // TotalSize
    case 1: return std::get<1>(a) == std::get<1>(b); // RecallCost
    case 2: return std::get<2>(a) == std::get<2>(b); // RetentionsOverride
  };
  return false;
}
inline bool operator!=(t803a3c9022c32e1702f6b5e3eaa82fb3 const &a, t803a3c9022c32e1702f6b5e3eaa82fb3 const &b) {
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
struct t30dc3dcca77170cf1e1cb9d48379ab77 : public std::variant<
  std::string, // Contacts
  std::string // Inhibition
> { using variant::variant; };

inline bool operator==(t30dc3dcca77170cf1e1cb9d48379ab77 const &a, t30dc3dcca77170cf1e1cb9d48379ab77 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Contacts
    case 1: return std::get<1>(a) == std::get<1>(b); // Inhibition
  };
  return false;
}
inline bool operator!=(t30dc3dcca77170cf1e1cb9d48379ab77 const &a, t30dc3dcca77170cf1e1cb9d48379ab77 const &b) {
  return !operator==(a, b);
}
struct tdb06243db69543aa6c581d0479aed01a : public std::tuple<
  dessser::gen::team_name::t_ext,
  ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77
> {
  using tuple::tuple;
  tdb06243db69543aa6c581d0479aed01a(std::tuple<dessser::gen::team_name::t_ext, ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77> p)
    : std::tuple<dessser::gen::team_name::t_ext, ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tdb06243db69543aa6c581d0479aed01a const &a, tdb06243db69543aa6c581d0479aed01a const &b) {
  return ::dessser::gen::team_name::Deref(std::get<0>(a)) == ::dessser::gen::team_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tdb06243db69543aa6c581d0479aed01a const &a, tdb06243db69543aa6c581d0479aed01a const &b) {
  return !operator==(a, b);
}
struct t79ebb6356ea2c5020930921b51ef4e3a : public std::variant<
  Void, // NumDeliveryAttempts
  Void, // FirstDeliveryAttempt
  Void, // LastDeliveryAttempt
  Void, // NextScheduled
  Void, // NextSend
  Void, // DeliveryStatus
  Void // Ack
> { using variant::variant; };

inline bool operator==(t79ebb6356ea2c5020930921b51ef4e3a const &a, t79ebb6356ea2c5020930921b51ef4e3a const &b) {
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
inline bool operator!=(t79ebb6356ea2c5020930921b51ef4e3a const &a, t79ebb6356ea2c5020930921b51ef4e3a const &b) {
  return !operator==(a, b);
}
struct t8790f8724a8266402c08dc86b40c110a : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a
> {
  using tuple::tuple;
  t8790f8724a8266402c08dc86b40c110a(std::tuple<std::string, ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8790f8724a8266402c08dc86b40c110a const &a, t8790f8724a8266402c08dc86b40c110a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8790f8724a8266402c08dc86b40c110a const &a, t8790f8724a8266402c08dc86b40c110a const &b) {
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
struct t28c98086737a6a32e1b0783ceb1c4a02 : public std::variant<
  Void, // FirstStartNotif
  Void, // LastStartNotif
  Void, // LastStopNotif
  Void, // LastStateChangeNotif
  Void, // Team
  ::dessser::gen::sync_key::t8790f8724a8266402c08dc86b40c110a, // Dialogs
  ::dessser::gen::sync_key::taf1e37f579ece7fa9db5670cfd23039b // Journal
> { using variant::variant; };

inline bool operator==(t28c98086737a6a32e1b0783ceb1c4a02 const &a, t28c98086737a6a32e1b0783ceb1c4a02 const &b) {
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
inline bool operator!=(t28c98086737a6a32e1b0783ceb1c4a02 const &a, t28c98086737a6a32e1b0783ceb1c4a02 const &b) {
  return !operator==(a, b);
}
struct t51f195064564f7c62f51e21289134f76 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02
> {
  using tuple::tuple;
  t51f195064564f7c62f51e21289134f76(std::tuple<std::string, ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t51f195064564f7c62f51e21289134f76 const &a, t51f195064564f7c62f51e21289134f76 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t51f195064564f7c62f51e21289134f76 const &a, t51f195064564f7c62f51e21289134f76 const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  Void, // DevNull
  Void, // Time
  std::string, // Versions
  ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903, // Sources
  Void, // TargetConfig
  std::shared_ptr<::dessser::gen::sync_key::per_site> , // PerSite
  ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3, // Storage
  ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc, // Tails
  uint16_t, // Replays
  std::optional<dessser::gen::sync_socket::t_ext>, // Error
  Void, // ReplayRequests
  ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c, // PerClient
  ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d, // Dashboards
  Void, // Notifications
  ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a, // Teams
  ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 // Incidents
> { using variant::variant; };

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
struct tc8853f3e8e540f5b422cf8f39096e477 : public std::tuple<
  ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c,
  Pointer
> {
  using tuple::tuple;
  tc8853f3e8e540f5b422cf8f39096e477(std::tuple<::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc8853f3e8e540f5b422cf8f39096e477 const &a, tc8853f3e8e540f5b422cf8f39096e477 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc8853f3e8e540f5b422cf8f39096e477 const &a, tc8853f3e8e540f5b422cf8f39096e477 const &b) {
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
struct tf52fd12fa8c3e9d420341149b10f12af : public std::tuple<
  ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c,
  Pointer
> {
  using tuple::tuple;
  tf52fd12fa8c3e9d420341149b10f12af(std::tuple<::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf52fd12fa8c3e9d420341149b10f12af const &a, tf52fd12fa8c3e9d420341149b10f12af const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf52fd12fa8c3e9d420341149b10f12af const &a, tf52fd12fa8c3e9d420341149b10f12af const &b) {
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
struct t1f5dea46176c28beac68cca21417e43b : public std::tuple<
  ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3,
  Pointer
> {
  using tuple::tuple;
  t1f5dea46176c28beac68cca21417e43b(std::tuple<::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1f5dea46176c28beac68cca21417e43b const &a, t1f5dea46176c28beac68cca21417e43b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1f5dea46176c28beac68cca21417e43b const &a, t1f5dea46176c28beac68cca21417e43b const &b) {
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
struct td61542ca3754c3b2859a4da2d9287bea : public std::tuple<
  ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77,
  Pointer
> {
  using tuple::tuple;
  td61542ca3754c3b2859a4da2d9287bea(std::tuple<::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td61542ca3754c3b2859a4da2d9287bea const &a, td61542ca3754c3b2859a4da2d9287bea const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td61542ca3754c3b2859a4da2d9287bea const &a, td61542ca3754c3b2859a4da2d9287bea const &b) {
  return !operator==(a, b);
}
struct tab59127137d5c6f7f536acfcb79eef6e : public std::tuple<
  ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02,
  Pointer
> {
  using tuple::tuple;
  tab59127137d5c6f7f536acfcb79eef6e(std::tuple<::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tab59127137d5c6f7f536acfcb79eef6e const &a, tab59127137d5c6f7f536acfcb79eef6e const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tab59127137d5c6f7f536acfcb79eef6e const &a, tab59127137d5c6f7f536acfcb79eef6e const &b) {
  return !operator==(a, b);
}
struct tce8ec428a5acd1f0e7adb8d93fe37cdf : public std::tuple<
  ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a,
  Pointer
> {
  using tuple::tuple;
  tce8ec428a5acd1f0e7adb8d93fe37cdf(std::tuple<::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tce8ec428a5acd1f0e7adb8d93fe37cdf const &a, tce8ec428a5acd1f0e7adb8d93fe37cdf const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tce8ec428a5acd1f0e7adb8d93fe37cdf const &a, tce8ec428a5acd1f0e7adb8d93fe37cdf const &b) {
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
    (fun ("[Widgets U32]" "Ptr")
      (let "ssum_dst_750" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (write-u32 little-endian (identifier "ssum_dst_750") (get-alt "Widgets" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> per_dash_key_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_750 { id_2 };
      uint16_t id_4 { uint16_t((*p_0).index()) };
      uint16_t id_5 { 0 };
      bool id_6 { bool(id_4 == id_5) };
      Void id_7 { ((void)(assert(id_6)), ::dessser::VOID) };
      (void)id_7;
      uint32_t id_8 { std::get<0 /* Widgets */>((*p_0)) };
      Pointer id_9 { ssum_dst_750.writeU32Le(id_8) };
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
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> fun10 { [&fun10](std::shared_ptr<::dessser::gen::sync_key::per_client>  p_0, Pointer p_1) {
    uint16_t id_11 { uint16_t((*p_0).index()) };
    Pointer id_12 { p_1.writeU16Le(id_11) };
    Pointer let_res_13;
    {
      Pointer ssum_dst_752 { id_12 };
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
          Vec<1, uint32_t> leb128_sz_753 { id_20 };
          Vec<1, Pointer> id_22 {  ssum_dst_752  };
          Pointer let_res_23;
          {
            Vec<1, Pointer> leb128_ptr_754 { id_22 };
            bool while_flag_24 { true };
            do {
              uint8_t id_25 { 0 };
              uint8_t id_26 { 0 };
              Pointer id_27 { leb128_ptr_754[id_26] };
              uint32_t id_28 { 128U };
              uint8_t id_29 { 0 };
              uint32_t id_30 { leb128_sz_753[id_29] };
              bool id_31 { bool(id_28 > id_30) };
              uint8_t choose_res_32;
              if (id_31) {
                uint8_t id_33 { 0 };
                uint32_t id_34 { leb128_sz_753[id_33] };
                uint8_t id_35 { uint8_t(id_34) };
                choose_res_32 = id_35;
              } else {
                uint8_t id_36 { 0 };
                uint32_t id_37 { leb128_sz_753[id_36] };
                uint8_t id_38 { uint8_t(id_37) };
                uint8_t id_39 { 128 };
                uint8_t id_40 { uint8_t(id_38 | id_39) };
                choose_res_32 = id_40;
              }
              Pointer id_41 { id_27.writeU8(choose_res_32) };
              Void id_42 { ((void)(leb128_ptr_754[id_25] = id_41), ::dessser::VOID) };
              (void)id_42;
              uint8_t id_43 { 0 };
              uint8_t id_44 { 0 };
              uint32_t id_45 { leb128_sz_753[id_44] };
              uint8_t id_46 { 7 };
              uint32_t id_47 { uint32_t(id_45 >> id_46) };
              Void id_48 { ((void)(leb128_sz_753[id_43] = id_47), ::dessser::VOID) };
              (void)id_48;
              uint8_t id_49 { 0 };
              uint32_t id_50 { leb128_sz_753[id_49] };
              uint32_t id_51 { 0U };
              bool id_52 { bool(id_50 > id_51) };
              while_flag_24 = id_52;
              if (while_flag_24) {
                (void)::dessser::VOID;
              }
            } while (while_flag_24);
            (void)::dessser::VOID;
            uint8_t id_53 { 0 };
            Pointer id_54 { leb128_ptr_754[id_53] };
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
        Pointer id_63 { per_dash_key_to_row_binary(id_62, ssum_dst_752) };
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
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> fun64 { [&fun64](std::shared_ptr<::dessser::gen::sync_key::per_tail>  p_0, Pointer p_1) {
    uint16_t id_65 { uint16_t((*p_0).index()) };
    Pointer id_66 { p_1.writeU16Le(id_65) };
    Pointer let_res_67;
    {
      Pointer ssum_dst_746 { id_66 };
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
          Vec<1, uint32_t> leb128_sz_747 { id_74 };
          Vec<1, Pointer> id_76 {  ssum_dst_746  };
          Pointer let_res_77;
          {
            Vec<1, Pointer> leb128_ptr_748 { id_76 };
            bool while_flag_78 { true };
            do {
              uint8_t id_79 { 0 };
              uint8_t id_80 { 0 };
              Pointer id_81 { leb128_ptr_748[id_80] };
              uint32_t id_82 { 128U };
              uint8_t id_83 { 0 };
              uint32_t id_84 { leb128_sz_747[id_83] };
              bool id_85 { bool(id_82 > id_84) };
              uint8_t choose_res_86;
              if (id_85) {
                uint8_t id_87 { 0 };
                uint32_t id_88 { leb128_sz_747[id_87] };
                uint8_t id_89 { uint8_t(id_88) };
                choose_res_86 = id_89;
              } else {
                uint8_t id_90 { 0 };
                uint32_t id_91 { leb128_sz_747[id_90] };
                uint8_t id_92 { uint8_t(id_91) };
                uint8_t id_93 { 128 };
                uint8_t id_94 { uint8_t(id_92 | id_93) };
                choose_res_86 = id_94;
              }
              Pointer id_95 { id_81.writeU8(choose_res_86) };
              Void id_96 { ((void)(leb128_ptr_748[id_79] = id_95), ::dessser::VOID) };
              (void)id_96;
              uint8_t id_97 { 0 };
              uint8_t id_98 { 0 };
              uint32_t id_99 { leb128_sz_747[id_98] };
              uint8_t id_100 { 7 };
              uint32_t id_101 { uint32_t(id_99 >> id_100) };
              Void id_102 { ((void)(leb128_sz_747[id_97] = id_101), ::dessser::VOID) };
              (void)id_102;
              uint8_t id_103 { 0 };
              uint32_t id_104 { leb128_sz_747[id_103] };
              uint32_t id_105 { 0U };
              bool id_106 { bool(id_104 > id_105) };
              while_flag_78 = id_106;
              if (while_flag_78) {
                (void)::dessser::VOID;
              }
            } while (while_flag_78);
            (void)::dessser::VOID;
            uint8_t id_107 { 0 };
            Pointer id_108 { leb128_ptr_748[id_107] };
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
        Pointer id_117 { ssum_dst_746.writeU32Le(id_116) };
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
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,Pointer)> fun118 { [&fun118](std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  p_0, Pointer p_1) {
    uint16_t id_119 { uint16_t((*p_0).index()) };
    Pointer let_res_120;
    {
      uint16_t label1_724 { id_119 };
      Pointer id_121 { p_1.writeU16Le(label1_724) };
      Pointer let_res_122;
      {
        Pointer ssum_dst_725 { id_121 };
        uint16_t id_123 { 0 };
        bool id_124 { bool(id_123 == label1_724) };
        Pointer choose_res_125;
        if (id_124) {
          choose_res_125 = ssum_dst_725;
        } else {
          uint16_t id_126 { 1 };
          bool id_127 { bool(id_126 == label1_724) };
          Pointer choose_res_128;
          if (id_127) {
            choose_res_128 = ssum_dst_725;
          } else {
            uint16_t id_129 { 2 };
            bool id_130 { bool(id_129 == label1_724) };
            Pointer choose_res_131;
            if (id_130) {
              choose_res_131 = ssum_dst_725;
            } else {
              uint16_t id_132 { 3 };
              bool id_133 { bool(id_132 == label1_724) };
              Pointer choose_res_134;
              if (id_133) {
                choose_res_134 = ssum_dst_725;
              } else {
                uint16_t id_135 { 4 };
                bool id_136 { bool(id_135 == label1_724) };
                Pointer choose_res_137;
                if (id_136) {
                  choose_res_137 = ssum_dst_725;
                } else {
                  uint16_t id_138 { 5 };
                  bool id_139 { bool(id_138 == label1_724) };
                  Pointer choose_res_140;
                  if (id_139) {
                    choose_res_140 = ssum_dst_725;
                  } else {
                    uint16_t id_141 { 6 };
                    bool id_142 { bool(id_141 == label1_724) };
                    Pointer choose_res_143;
                    if (id_142) {
                      ::dessser::gen::sync_key::t21e5dc291e02ff6b92981a2d2fa864dc id_144 { std::get<6 /* PerInstance */>((*p_0)) };
                      std::string id_145 { std::get<0>(id_144) };
                      uint32_t id_146 { (uint32_t)id_145.size() };
                      Vec<1, uint32_t> id_147 {  id_146  };
                      Pointer let_res_148;
                      {
                        Vec<1, uint32_t> leb128_sz_726 { id_147 };
                        Vec<1, Pointer> id_149 {  ssum_dst_725  };
                        Pointer let_res_150;
                        {
                          Vec<1, Pointer> leb128_ptr_727 { id_149 };
                          bool while_flag_151 { true };
                          do {
                            uint8_t id_152 { 0 };
                            uint8_t id_153 { 0 };
                            Pointer id_154 { leb128_ptr_727[id_153] };
                            uint32_t id_155 { 128U };
                            uint8_t id_156 { 0 };
                            uint32_t id_157 { leb128_sz_726[id_156] };
                            bool id_158 { bool(id_155 > id_157) };
                            uint8_t choose_res_159;
                            if (id_158) {
                              uint8_t id_160 { 0 };
                              uint32_t id_161 { leb128_sz_726[id_160] };
                              uint8_t id_162 { uint8_t(id_161) };
                              choose_res_159 = id_162;
                            } else {
                              uint8_t id_163 { 0 };
                              uint32_t id_164 { leb128_sz_726[id_163] };
                              uint8_t id_165 { uint8_t(id_164) };
                              uint8_t id_166 { 128 };
                              uint8_t id_167 { uint8_t(id_165 | id_166) };
                              choose_res_159 = id_167;
                            }
                            Pointer id_168 { id_154.writeU8(choose_res_159) };
                            Void id_169 { ((void)(leb128_ptr_727[id_152] = id_168), ::dessser::VOID) };
                            (void)id_169;
                            uint8_t id_170 { 0 };
                            uint8_t id_171 { 0 };
                            uint32_t id_172 { leb128_sz_726[id_171] };
                            uint8_t id_173 { 7 };
                            uint32_t id_174 { uint32_t(id_172 >> id_173) };
                            Void id_175 { ((void)(leb128_sz_726[id_170] = id_174), ::dessser::VOID) };
                            (void)id_175;
                            uint8_t id_176 { 0 };
                            uint32_t id_177 { leb128_sz_726[id_176] };
                            uint32_t id_178 { 0U };
                            bool id_179 { bool(id_177 > id_178) };
                            while_flag_151 = id_179;
                            if (while_flag_151) {
                              (void)::dessser::VOID;
                            }
                          } while (while_flag_151);
                          (void)::dessser::VOID;
                          uint8_t id_180 { 0 };
                          Pointer id_181 { leb128_ptr_727[id_180] };
                          let_res_150 = id_181;
                        }
                        let_res_148 = let_res_150;
                      }
                      ::dessser::gen::sync_key::t21e5dc291e02ff6b92981a2d2fa864dc id_182 { std::get<6 /* PerInstance */>((*p_0)) };
                      std::string id_183 { std::get<0>(id_182) };
                      Bytes id_184 { id_183 };
                      Pointer id_185 { let_res_148.writeBytes(id_184) };
                      Pointer let_res_186;
                      {
                        Pointer stup_dst_728 { id_185 };
                        ::dessser::gen::sync_key::t21e5dc291e02ff6b92981a2d2fa864dc id_187 { std::get<6 /* PerInstance */>((*p_0)) };
                        ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c id_188 { std::get<1>(id_187) };
                        uint16_t id_189 { uint16_t(id_188.index()) };
                        Pointer let_res_190;
                        {
                          uint16_t label1_729 { id_189 };
                          Pointer id_191 { stup_dst_728.writeU16Le(label1_729) };
                          Pointer let_res_192;
                          {
                            Pointer ssum_dst_730 { id_191 };
                            uint16_t id_193 { 0 };
                            bool id_194 { bool(id_193 == label1_729) };
                            Pointer choose_res_195;
                            if (id_194) {
                              choose_res_195 = ssum_dst_730;
                            } else {
                              uint16_t id_196 { 1 };
                              bool id_197 { bool(id_196 == label1_729) };
                              Pointer choose_res_198;
                              if (id_197) {
                                choose_res_198 = ssum_dst_730;
                              } else {
                                uint16_t id_199 { 2 };
                                bool id_200 { bool(id_199 == label1_729) };
                                Pointer choose_res_201;
                                if (id_200) {
                                  choose_res_201 = ssum_dst_730;
                                } else {
                                  uint16_t id_202 { 3 };
                                  bool id_203 { bool(id_202 == label1_729) };
                                  Pointer choose_res_204;
                                  if (id_203) {
                                    choose_res_204 = ssum_dst_730;
                                  } else {
                                    uint16_t id_205 { 4 };
                                    bool id_206 { bool(id_205 == label1_729) };
                                    Pointer choose_res_207;
                                    if (id_206) {
                                      choose_res_207 = ssum_dst_730;
                                    } else {
                                      uint16_t id_208 { 5 };
                                      bool id_209 { bool(id_208 == label1_729) };
                                      Pointer choose_res_210;
                                      if (id_209) {
                                        choose_res_210 = ssum_dst_730;
                                      } else {
                                        uint16_t id_211 { 6 };
                                        bool id_212 { bool(id_211 == label1_729) };
                                        Pointer choose_res_213;
                                        if (id_212) {
                                          choose_res_213 = ssum_dst_730;
                                        } else {
                                          uint16_t id_214 { 7 };
                                          bool id_215 { bool(label1_729 == id_214) };
                                          Void id_216 { ((void)(assert(id_215)), ::dessser::VOID) };
                                          (void)id_216;
                                          choose_res_213 = ssum_dst_730;
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
                      bool id_218 { bool(id_217 == label1_724) };
                      Pointer choose_res_219;
                      if (id_218) {
                        uint32_t id_220 { std::get<7 /* PerReplayer */>((*p_0)) };
                        Pointer id_221 { ssum_dst_725.writeU32Le(id_220) };
                        choose_res_219 = id_221;
                      } else {
                        uint16_t id_222 { 8 };
                        bool id_223 { bool(label1_724 == id_222) };
                        Void id_224 { ((void)(assert(id_223)), ::dessser::VOID) };
                        (void)id_224;
                        choose_res_219 = ssum_dst_725;
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
      (let "stup_dst_731" (apply (ext-identifier fq_name to-row-binary) (get-item 0 (param 0)) (param 1)) (apply (identifier "per_worker_data-to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_731"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker> ,Pointer)> per_worker_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker> ,Pointer)> fun225 { [&fun225](std::shared_ptr<::dessser::gen::sync_key::per_worker>  p_0, Pointer p_1) {
    auto fun226 { dessser::gen::fq_name::to_row_binary };
    dessser::gen::fq_name::t_ext id_227 { std::get<0>((*p_0)) };
    Pointer id_228 { fun226(id_227, p_1) };
    Pointer let_res_229;
    {
      Pointer stup_dst_731 { id_228 };
      std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_230 { std::get<1>((*p_0)) };
      Pointer id_231 { per_worker_data_to_row_binary(id_230, stup_dst_731) };
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
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,Pointer)> fun232 { [&fun232](std::shared_ptr<::dessser::gen::sync_key::per_site_data>  p_0, Pointer p_1) {
    uint16_t id_233 { uint16_t((*p_0).index()) };
    Pointer id_234 { p_1.writeU16Le(id_233) };
    Pointer let_res_235;
    {
      Pointer ssum_dst_733 { id_234 };
      uint16_t id_236 { 0 };
      uint16_t id_237 { uint16_t((*p_0).index()) };
      bool id_238 { bool(id_236 == id_237) };
      Pointer choose_res_239;
      if (id_238) {
        choose_res_239 = ssum_dst_733;
      } else {
        uint16_t id_240 { 1 };
        uint16_t id_241 { uint16_t((*p_0).index()) };
        bool id_242 { bool(id_240 == id_241) };
        Pointer choose_res_243;
        if (id_242) {
          ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a id_244 { std::get<1 /* PerService */>((*p_0)) };
          std::string id_245 { std::get<0>(id_244) };
          uint32_t id_246 { (uint32_t)id_245.size() };
          Vec<1, uint32_t> id_247 {  id_246  };
          Pointer let_res_248;
          {
            Vec<1, uint32_t> leb128_sz_739 { id_247 };
            Vec<1, Pointer> id_249 {  ssum_dst_733  };
            Pointer let_res_250;
            {
              Vec<1, Pointer> leb128_ptr_740 { id_249 };
              bool while_flag_251 { true };
              do {
                uint8_t id_252 { 0 };
                uint8_t id_253 { 0 };
                Pointer id_254 { leb128_ptr_740[id_253] };
                uint32_t id_255 { 128U };
                uint8_t id_256 { 0 };
                uint32_t id_257 { leb128_sz_739[id_256] };
                bool id_258 { bool(id_255 > id_257) };
                uint8_t choose_res_259;
                if (id_258) {
                  uint8_t id_260 { 0 };
                  uint32_t id_261 { leb128_sz_739[id_260] };
                  uint8_t id_262 { uint8_t(id_261) };
                  choose_res_259 = id_262;
                } else {
                  uint8_t id_263 { 0 };
                  uint32_t id_264 { leb128_sz_739[id_263] };
                  uint8_t id_265 { uint8_t(id_264) };
                  uint8_t id_266 { 128 };
                  uint8_t id_267 { uint8_t(id_265 | id_266) };
                  choose_res_259 = id_267;
                }
                Pointer id_268 { id_254.writeU8(choose_res_259) };
                Void id_269 { ((void)(leb128_ptr_740[id_252] = id_268), ::dessser::VOID) };
                (void)id_269;
                uint8_t id_270 { 0 };
                uint8_t id_271 { 0 };
                uint32_t id_272 { leb128_sz_739[id_271] };
                uint8_t id_273 { 7 };
                uint32_t id_274 { uint32_t(id_272 >> id_273) };
                Void id_275 { ((void)(leb128_sz_739[id_270] = id_274), ::dessser::VOID) };
                (void)id_275;
                uint8_t id_276 { 0 };
                uint32_t id_277 { leb128_sz_739[id_276] };
                uint32_t id_278 { 0U };
                bool id_279 { bool(id_277 > id_278) };
                while_flag_251 = id_279;
                if (while_flag_251) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_251);
              (void)::dessser::VOID;
              uint8_t id_280 { 0 };
              Pointer id_281 { leb128_ptr_740[id_280] };
              let_res_250 = id_281;
            }
            let_res_248 = let_res_250;
          }
          ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a id_282 { std::get<1 /* PerService */>((*p_0)) };
          std::string id_283 { std::get<0>(id_282) };
          Bytes id_284 { id_283 };
          Pointer id_285 { let_res_248.writeBytes(id_284) };
          Pointer let_res_286;
          {
            Pointer stup_dst_741 { id_285 };
            ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a id_287 { std::get<1 /* PerService */>((*p_0)) };
            ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c id_288 { std::get<1>(id_287) };
            uint16_t id_289 { uint16_t(id_288.index()) };
            Pointer id_290 { stup_dst_741.writeU16Le(id_289) };
            Pointer let_res_291;
            {
              Pointer ssum_dst_743 { id_290 };
              uint16_t id_292 { 0 };
              ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a id_293 { std::get<1 /* PerService */>((*p_0)) };
              ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c id_294 { std::get<1>(id_293) };
              uint16_t id_295 { uint16_t(id_294.index()) };
              bool id_296 { bool(id_292 == id_295) };
              Pointer choose_res_297;
              if (id_296) {
                choose_res_297 = ssum_dst_743;
              } else {
                ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a id_298 { std::get<1 /* PerService */>((*p_0)) };
                ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c id_299 { std::get<1>(id_298) };
                uint16_t id_300 { uint16_t(id_299.index()) };
                uint16_t id_301 { 1 };
                bool id_302 { bool(id_300 == id_301) };
                Void id_303 { ((void)(assert(id_302)), ::dessser::VOID) };
                (void)id_303;
                choose_res_297 = ssum_dst_743;
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
            Pointer id_309 { per_worker_to_row_binary(id_308, ssum_dst_733) };
            choose_res_307 = id_309;
          } else {
            uint16_t id_310 { uint16_t((*p_0).index()) };
            uint16_t id_311 { 3 };
            bool id_312 { bool(id_310 == id_311) };
            Void id_313 { ((void)(assert(id_312)), ::dessser::VOID) };
            (void)id_313;
            ::dessser::gen::sync_key::td7912e294d6f3a12e8335070433dc663 id_314 { std::get<3 /* PerProgram */>((*p_0)) };
            std::string id_315 { std::get<0>(id_314) };
            uint32_t id_316 { (uint32_t)id_315.size() };
            Vec<1, uint32_t> id_317 {  id_316  };
            Pointer let_res_318;
            {
              Vec<1, uint32_t> leb128_sz_734 { id_317 };
              Vec<1, Pointer> id_319 {  ssum_dst_733  };
              Pointer let_res_320;
              {
                Vec<1, Pointer> leb128_ptr_735 { id_319 };
                bool while_flag_321 { true };
                do {
                  uint8_t id_322 { 0 };
                  uint8_t id_323 { 0 };
                  Pointer id_324 { leb128_ptr_735[id_323] };
                  uint32_t id_325 { 128U };
                  uint8_t id_326 { 0 };
                  uint32_t id_327 { leb128_sz_734[id_326] };
                  bool id_328 { bool(id_325 > id_327) };
                  uint8_t choose_res_329;
                  if (id_328) {
                    uint8_t id_330 { 0 };
                    uint32_t id_331 { leb128_sz_734[id_330] };
                    uint8_t id_332 { uint8_t(id_331) };
                    choose_res_329 = id_332;
                  } else {
                    uint8_t id_333 { 0 };
                    uint32_t id_334 { leb128_sz_734[id_333] };
                    uint8_t id_335 { uint8_t(id_334) };
                    uint8_t id_336 { 128 };
                    uint8_t id_337 { uint8_t(id_335 | id_336) };
                    choose_res_329 = id_337;
                  }
                  Pointer id_338 { id_324.writeU8(choose_res_329) };
                  Void id_339 { ((void)(leb128_ptr_735[id_322] = id_338), ::dessser::VOID) };
                  (void)id_339;
                  uint8_t id_340 { 0 };
                  uint8_t id_341 { 0 };
                  uint32_t id_342 { leb128_sz_734[id_341] };
                  uint8_t id_343 { 7 };
                  uint32_t id_344 { uint32_t(id_342 >> id_343) };
                  Void id_345 { ((void)(leb128_sz_734[id_340] = id_344), ::dessser::VOID) };
                  (void)id_345;
                  uint8_t id_346 { 0 };
                  uint32_t id_347 { leb128_sz_734[id_346] };
                  uint32_t id_348 { 0U };
                  bool id_349 { bool(id_347 > id_348) };
                  while_flag_321 = id_349;
                  if (while_flag_321) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_321);
                (void)::dessser::VOID;
                uint8_t id_350 { 0 };
                Pointer id_351 { leb128_ptr_735[id_350] };
                let_res_320 = id_351;
              }
              let_res_318 = let_res_320;
            }
            ::dessser::gen::sync_key::td7912e294d6f3a12e8335070433dc663 id_352 { std::get<3 /* PerProgram */>((*p_0)) };
            std::string id_353 { std::get<0>(id_352) };
            Bytes id_354 { id_353 };
            Pointer id_355 { let_res_318.writeBytes(id_354) };
            Pointer let_res_356;
            {
              Pointer stup_dst_736 { id_355 };
              ::dessser::gen::sync_key::td7912e294d6f3a12e8335070433dc663 id_357 { std::get<3 /* PerProgram */>((*p_0)) };
              ::dessser::gen::sync_key::tea8c2377036e530fd3f67fa8653a3834 id_358 { std::get<1>(id_357) };
              uint16_t id_359 { uint16_t(id_358.index()) };
              Pointer id_360 { stup_dst_736.writeU16Le(id_359) };
              Pointer let_res_361;
              {
                Pointer ssum_dst_738 { id_360 };
                ::dessser::gen::sync_key::td7912e294d6f3a12e8335070433dc663 id_362 { std::get<3 /* PerProgram */>((*p_0)) };
                ::dessser::gen::sync_key::tea8c2377036e530fd3f67fa8653a3834 id_363 { std::get<1>(id_362) };
                uint16_t id_364 { uint16_t(id_363.index()) };
                uint16_t id_365 { 0 };
                bool id_366 { bool(id_364 == id_365) };
                Void id_367 { ((void)(assert(id_366)), ::dessser::VOID) };
                (void)id_367;
                let_res_361 = ssum_dst_738;
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
      (let "stup_dst_744" (apply (ext-identifier site_name to-row-binary) (get-item 0 (param 0)) (param 1)) (apply (identifier "per_site_data-to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_744"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site> ,Pointer)> per_site_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site> ,Pointer)> fun368 { [&fun368](std::shared_ptr<::dessser::gen::sync_key::per_site>  p_0, Pointer p_1) {
    auto fun369 { dessser::gen::site_name::to_row_binary };
    dessser::gen::site_name::t_ext id_370 { std::get<0>((*p_0)) };
    Pointer id_371 { fun369(id_370, p_1) };
    Pointer let_res_372;
    {
      Pointer stup_dst_744 { id_371 };
      std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_373 { std::get<1>((*p_0)) };
      Pointer id_374 { per_site_data_to_row_binary(id_373, stup_dst_744) };
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
      (let "label1_755" (label-of (param 0))
        (let "ssum_dst_756" (write-u16 little-endian (param 1) (identifier "label1_755"))
          (if (eq (u16 0) (identifier "label1_755")) (identifier "ssum_dst_756")
            (if (eq (u16 1) (identifier "label1_755")) (identifier "ssum_dst_756")
              (if (eq (u16 2) (identifier "label1_755"))
                (write-bytes
                  (let "leb128_sz_791" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "leb128_ptr_792" (make-vec (identifier "ssum_dst_756"))
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
                (if (eq (u16 3) (identifier "label1_755"))
                  (let "stup_dst_788" (apply (ext-identifier src_path to-row-binary) (get-item 0 (get-alt "Sources" (param 0))) (identifier "ssum_dst_756"))
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
                  (if (eq (u16 4) (identifier "label1_755")) (identifier "ssum_dst_756")
                    (if (eq (u16 5) (identifier "label1_755")) (apply (identifier "per_site-to-row-binary") (get-alt "PerSite" (param 0)) (identifier "ssum_dst_756"))
                      (if (eq (u16 6) (identifier "label1_755"))
                        (let "ssum_dst_785" (write-u16 little-endian (identifier "ssum_dst_756") (label-of (get-alt "Storage" (param 0))))
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
                        (if (eq (u16 7) (identifier "label1_755"))
                          (let "stup_dst_783"
                            (let "stup_dst_780"
                              (let "stup_dst_779" (apply (ext-identifier site_name to-row-binary) (get-item 0 (get-alt "Tails" (param 0))) (identifier "ssum_dst_756"))
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
                          (if (eq (u16 8) (identifier "label1_755")) 
                            (write-u16 little-endian (identifier "ssum_dst_756") (get-alt "Replays" (param 0)))
                            (if (eq (u16 9) (identifier "label1_755"))
                              (if (is-null (get-alt "Error" (param 0))) 
                                (write-u8 (identifier "ssum_dst_756") (u8 1)) 
                                (apply (ext-identifier sync_socket to-row-binary) (force (get-alt "Error" (param 0))) (write-u8 (identifier "ssum_dst_756") (u8 0))))
                              (if (eq (u16 10) (identifier "label1_755")) 
                                (identifier "ssum_dst_756")
                                (if (eq (u16 11) (identifier "label1_755"))
                                  (let "stup_dst_778" (apply (ext-identifier sync_socket to-row-binary) (get-item 0 (get-alt "PerClient" (param 0))) (identifier "ssum_dst_756"))
                                    (apply (identifier "per_client-to-row-binary") (get-item 1 (get-alt "PerClient" (param 0))) (identifier "stup_dst_778")))
                                  (if (eq (u16 12) (identifier "label1_755"))
                                    (let "stup_dst_777"
                                      (write-bytes
                                        (let "leb128_sz_775" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "leb128_ptr_776" (make-vec (identifier "ssum_dst_756"))
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
                                    (if (eq (u16 13) (identifier "label1_755")) 
                                      (identifier "ssum_dst_756")
                                      (if (eq (u16 14) (identifier "label1_755"))
                                        (let "stup_dst_768" (apply (ext-identifier team_name to-row-binary) (get-item 0 (get-alt "Teams" (param 0))) (identifier "ssum_dst_756"))
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
                                        (seq (assert (eq (identifier "label1_755") (u16 15)))
                                          (let "stup_dst_759"
                                            (write-bytes
                                              (let "leb128_sz_757" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "leb128_ptr_758" 
                                                  (make-vec (identifier "ssum_dst_756"))
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
                                              (bytes-of-string (get-item 0 (get-alt "Incidents" (param 0)))))
                                            (let "label1_760" (label-of (get-item 1 (get-alt "Incidents" (param 0))))
                                              (let "ssum_dst_761" (write-u16 little-endian (identifier "stup_dst_759") (identifier "label1_760"))
                                                (if (eq (u16 0) (identifier "label1_760")) 
                                                  (identifier "ssum_dst_761")
                                                  (if (eq (u16 1) (identifier "label1_760")) 
                                                    (identifier "ssum_dst_761")
                                                    (if (eq (u16 2) (identifier "label1_760")) 
                                                      (identifier "ssum_dst_761")
                                                      (if (eq (u16 3) (identifier "label1_760")) 
                                                        (identifier "ssum_dst_761")
                                                        (if (eq (u16 4) (identifier "label1_760")) 
                                                          (identifier "ssum_dst_761")
                                                          (if (eq (u16 5) (identifier "label1_760"))
                                                            (let "stup_dst_765"
                                                              (write-bytes
                                                                (let "leb128_sz_763" 
                                                                  (make-vec (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                  (let "leb128_ptr_764" 
                                                                    (make-vec (identifier "ssum_dst_761"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_764")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_764"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_763"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_763"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_763"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_763") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_763")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_763")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_764"))))) 
                                                                (bytes-of-string (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                              (let "label1_766" 
                                                                (label-of (get-item 1 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0))))))
                                                                (let "ssum_dst_767" 
                                                                  (write-u16 little-endian (identifier "stup_dst_765") (identifier "label1_766"))
                                                                  (if 
                                                                    (eq (u16 0) (identifier "label1_766")) 
                                                                    (identifier "ssum_dst_767")
                                                                    (if 
                                                                    (eq (u16 1) (identifier "label1_766")) 
                                                                    (identifier "ssum_dst_767")
                                                                    (if 
                                                                    (eq (u16 2) (identifier "label1_766")) 
                                                                    (identifier "ssum_dst_767")
                                                                    (if 
                                                                    (eq (u16 3) (identifier "label1_766")) 
                                                                    (identifier "ssum_dst_767")
                                                                    (if 
                                                                    (eq (u16 4) (identifier "label1_766")) 
                                                                    (identifier "ssum_dst_767")
                                                                    (if (eq (u16 5) (identifier "label1_766")) (identifier "ssum_dst_767") (seq (assert (eq (identifier "label1_766") (u16 6))) (identifier "ssum_dst_767")))))))))))
                                                            (seq (assert (eq (identifier "label1_760") (u16 6)))
                                                              (let "stup_dst_762" 
                                                                (write-u64 little-endian (identifier "ssum_dst_761") (u64-of-float (get-item 0 (get-alt "Journal" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                (write-u32 little-endian (identifier "stup_dst_762") (get-item 1 (get-alt "Journal" (get-item 1 (get-alt "Incidents" (param 0))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> fun375 { [&fun375](std::shared_ptr<::dessser::gen::sync_key::t>  p_0, Pointer p_1) {
    uint16_t id_376 { uint16_t((*p_0).index()) };
    Pointer let_res_377;
    {
      uint16_t label1_755 { id_376 };
      Pointer id_378 { p_1.writeU16Le(label1_755) };
      Pointer let_res_379;
      {
        Pointer ssum_dst_756 { id_378 };
        uint16_t id_380 { 0 };
        bool id_381 { bool(id_380 == label1_755) };
        Pointer choose_res_382;
        if (id_381) {
          choose_res_382 = ssum_dst_756;
        } else {
          uint16_t id_383 { 1 };
          bool id_384 { bool(id_383 == label1_755) };
          Pointer choose_res_385;
          if (id_384) {
            choose_res_385 = ssum_dst_756;
          } else {
            uint16_t id_386 { 2 };
            bool id_387 { bool(id_386 == label1_755) };
            Pointer choose_res_388;
            if (id_387) {
              std::string id_389 { std::get<2 /* Versions */>((*p_0)) };
              uint32_t id_390 { (uint32_t)id_389.size() };
              Vec<1, uint32_t> id_391 {  id_390  };
              Pointer let_res_392;
              {
                Vec<1, uint32_t> leb128_sz_791 { id_391 };
                Vec<1, Pointer> id_393 {  ssum_dst_756  };
                Pointer let_res_394;
                {
                  Vec<1, Pointer> leb128_ptr_792 { id_393 };
                  bool while_flag_395 { true };
                  do {
                    uint8_t id_396 { 0 };
                    uint8_t id_397 { 0 };
                    Pointer id_398 { leb128_ptr_792[id_397] };
                    uint32_t id_399 { 128U };
                    uint8_t id_400 { 0 };
                    uint32_t id_401 { leb128_sz_791[id_400] };
                    bool id_402 { bool(id_399 > id_401) };
                    uint8_t choose_res_403;
                    if (id_402) {
                      uint8_t id_404 { 0 };
                      uint32_t id_405 { leb128_sz_791[id_404] };
                      uint8_t id_406 { uint8_t(id_405) };
                      choose_res_403 = id_406;
                    } else {
                      uint8_t id_407 { 0 };
                      uint32_t id_408 { leb128_sz_791[id_407] };
                      uint8_t id_409 { uint8_t(id_408) };
                      uint8_t id_410 { 128 };
                      uint8_t id_411 { uint8_t(id_409 | id_410) };
                      choose_res_403 = id_411;
                    }
                    Pointer id_412 { id_398.writeU8(choose_res_403) };
                    Void id_413 { ((void)(leb128_ptr_792[id_396] = id_412), ::dessser::VOID) };
                    (void)id_413;
                    uint8_t id_414 { 0 };
                    uint8_t id_415 { 0 };
                    uint32_t id_416 { leb128_sz_791[id_415] };
                    uint8_t id_417 { 7 };
                    uint32_t id_418 { uint32_t(id_416 >> id_417) };
                    Void id_419 { ((void)(leb128_sz_791[id_414] = id_418), ::dessser::VOID) };
                    (void)id_419;
                    uint8_t id_420 { 0 };
                    uint32_t id_421 { leb128_sz_791[id_420] };
                    uint32_t id_422 { 0U };
                    bool id_423 { bool(id_421 > id_422) };
                    while_flag_395 = id_423;
                    if (while_flag_395) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_395);
                  (void)::dessser::VOID;
                  uint8_t id_424 { 0 };
                  Pointer id_425 { leb128_ptr_792[id_424] };
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
              bool id_430 { bool(id_429 == label1_755) };
              Pointer choose_res_431;
              if (id_430) {
                auto fun432 { dessser::gen::src_path::to_row_binary };
                ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_433 { std::get<3 /* Sources */>((*p_0)) };
                dessser::gen::src_path::t_ext id_434 { std::get<0>(id_433) };
                Pointer id_435 { fun432(id_434, ssum_dst_756) };
                Pointer let_res_436;
                {
                  Pointer stup_dst_788 { id_435 };
                  ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_437 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_438 { std::get<1>(id_437) };
                  uint32_t id_439 { (uint32_t)id_438.size() };
                  Vec<1, uint32_t> id_440 {  id_439  };
                  Pointer let_res_441;
                  {
                    Vec<1, uint32_t> leb128_sz_789 { id_440 };
                    Vec<1, Pointer> id_442 {  stup_dst_788  };
                    Pointer let_res_443;
                    {
                      Vec<1, Pointer> leb128_ptr_790 { id_442 };
                      bool while_flag_444 { true };
                      do {
                        uint8_t id_445 { 0 };
                        uint8_t id_446 { 0 };
                        Pointer id_447 { leb128_ptr_790[id_446] };
                        uint32_t id_448 { 128U };
                        uint8_t id_449 { 0 };
                        uint32_t id_450 { leb128_sz_789[id_449] };
                        bool id_451 { bool(id_448 > id_450) };
                        uint8_t choose_res_452;
                        if (id_451) {
                          uint8_t id_453 { 0 };
                          uint32_t id_454 { leb128_sz_789[id_453] };
                          uint8_t id_455 { uint8_t(id_454) };
                          choose_res_452 = id_455;
                        } else {
                          uint8_t id_456 { 0 };
                          uint32_t id_457 { leb128_sz_789[id_456] };
                          uint8_t id_458 { uint8_t(id_457) };
                          uint8_t id_459 { 128 };
                          uint8_t id_460 { uint8_t(id_458 | id_459) };
                          choose_res_452 = id_460;
                        }
                        Pointer id_461 { id_447.writeU8(choose_res_452) };
                        Void id_462 { ((void)(leb128_ptr_790[id_445] = id_461), ::dessser::VOID) };
                        (void)id_462;
                        uint8_t id_463 { 0 };
                        uint8_t id_464 { 0 };
                        uint32_t id_465 { leb128_sz_789[id_464] };
                        uint8_t id_466 { 7 };
                        uint32_t id_467 { uint32_t(id_465 >> id_466) };
                        Void id_468 { ((void)(leb128_sz_789[id_463] = id_467), ::dessser::VOID) };
                        (void)id_468;
                        uint8_t id_469 { 0 };
                        uint32_t id_470 { leb128_sz_789[id_469] };
                        uint32_t id_471 { 0U };
                        bool id_472 { bool(id_470 > id_471) };
                        while_flag_444 = id_472;
                        if (while_flag_444) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_444);
                      (void)::dessser::VOID;
                      uint8_t id_473 { 0 };
                      Pointer id_474 { leb128_ptr_790[id_473] };
                      let_res_443 = id_474;
                    }
                    let_res_441 = let_res_443;
                  }
                  ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_475 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_476 { std::get<1>(id_475) };
                  Bytes id_477 { id_476 };
                  Pointer id_478 { let_res_441.writeBytes(id_477) };
                  let_res_436 = id_478;
                }
                choose_res_431 = let_res_436;
              } else {
                uint16_t id_479 { 4 };
                bool id_480 { bool(id_479 == label1_755) };
                Pointer choose_res_481;
                if (id_480) {
                  choose_res_481 = ssum_dst_756;
                } else {
                  uint16_t id_482 { 5 };
                  bool id_483 { bool(id_482 == label1_755) };
                  Pointer choose_res_484;
                  if (id_483) {
                    std::shared_ptr<::dessser::gen::sync_key::per_site>  id_485 { std::get<5 /* PerSite */>((*p_0)) };
                    Pointer id_486 { per_site_to_row_binary(id_485, ssum_dst_756) };
                    choose_res_484 = id_486;
                  } else {
                    uint16_t id_487 { 6 };
                    bool id_488 { bool(id_487 == label1_755) };
                    Pointer choose_res_489;
                    if (id_488) {
                      ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_490 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_491 { uint16_t(id_490.index()) };
                      Pointer id_492 { ssum_dst_756.writeU16Le(id_491) };
                      Pointer let_res_493;
                      {
                        Pointer ssum_dst_785 { id_492 };
                        uint16_t id_494 { 0 };
                        ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_495 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_496 { uint16_t(id_495.index()) };
                        bool id_497 { bool(id_494 == id_496) };
                        Pointer choose_res_498;
                        if (id_497) {
                          choose_res_498 = ssum_dst_785;
                        } else {
                          uint16_t id_499 { 1 };
                          ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_500 { std::get<6 /* Storage */>((*p_0)) };
                          uint16_t id_501 { uint16_t(id_500.index()) };
                          bool id_502 { bool(id_499 == id_501) };
                          Pointer choose_res_503;
                          if (id_502) {
                            choose_res_503 = ssum_dst_785;
                          } else {
                            ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_504 { std::get<6 /* Storage */>((*p_0)) };
                            uint16_t id_505 { uint16_t(id_504.index()) };
                            uint16_t id_506 { 2 };
                            bool id_507 { bool(id_505 == id_506) };
                            Void id_508 { ((void)(assert(id_507)), ::dessser::VOID) };
                            (void)id_508;
                            ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_509 { std::get<6 /* Storage */>((*p_0)) };
                            std::string id_510 { std::get<2 /* RetentionsOverride */>(id_509) };
                            uint32_t id_511 { (uint32_t)id_510.size() };
                            Vec<1, uint32_t> id_512 {  id_511  };
                            Pointer let_res_513;
                            {
                              Vec<1, uint32_t> leb128_sz_786 { id_512 };
                              Vec<1, Pointer> id_514 {  ssum_dst_785  };
                              Pointer let_res_515;
                              {
                                Vec<1, Pointer> leb128_ptr_787 { id_514 };
                                bool while_flag_516 { true };
                                do {
                                  uint8_t id_517 { 0 };
                                  uint8_t id_518 { 0 };
                                  Pointer id_519 { leb128_ptr_787[id_518] };
                                  uint32_t id_520 { 128U };
                                  uint8_t id_521 { 0 };
                                  uint32_t id_522 { leb128_sz_786[id_521] };
                                  bool id_523 { bool(id_520 > id_522) };
                                  uint8_t choose_res_524;
                                  if (id_523) {
                                    uint8_t id_525 { 0 };
                                    uint32_t id_526 { leb128_sz_786[id_525] };
                                    uint8_t id_527 { uint8_t(id_526) };
                                    choose_res_524 = id_527;
                                  } else {
                                    uint8_t id_528 { 0 };
                                    uint32_t id_529 { leb128_sz_786[id_528] };
                                    uint8_t id_530 { uint8_t(id_529) };
                                    uint8_t id_531 { 128 };
                                    uint8_t id_532 { uint8_t(id_530 | id_531) };
                                    choose_res_524 = id_532;
                                  }
                                  Pointer id_533 { id_519.writeU8(choose_res_524) };
                                  Void id_534 { ((void)(leb128_ptr_787[id_517] = id_533), ::dessser::VOID) };
                                  (void)id_534;
                                  uint8_t id_535 { 0 };
                                  uint8_t id_536 { 0 };
                                  uint32_t id_537 { leb128_sz_786[id_536] };
                                  uint8_t id_538 { 7 };
                                  uint32_t id_539 { uint32_t(id_537 >> id_538) };
                                  Void id_540 { ((void)(leb128_sz_786[id_535] = id_539), ::dessser::VOID) };
                                  (void)id_540;
                                  uint8_t id_541 { 0 };
                                  uint32_t id_542 { leb128_sz_786[id_541] };
                                  uint32_t id_543 { 0U };
                                  bool id_544 { bool(id_542 > id_543) };
                                  while_flag_516 = id_544;
                                  if (while_flag_516) {
                                    (void)::dessser::VOID;
                                  }
                                } while (while_flag_516);
                                (void)::dessser::VOID;
                                uint8_t id_545 { 0 };
                                Pointer id_546 { leb128_ptr_787[id_545] };
                                let_res_515 = id_546;
                              }
                              let_res_513 = let_res_515;
                            }
                            ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_547 { std::get<6 /* Storage */>((*p_0)) };
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
                      bool id_552 { bool(id_551 == label1_755) };
                      Pointer choose_res_553;
                      if (id_552) {
                        auto fun554 { dessser::gen::site_name::to_row_binary };
                        ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_555 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::site_name::t_ext id_556 { std::get<0>(id_555) };
                        Pointer id_557 { fun554(id_556, ssum_dst_756) };
                        Pointer let_res_558;
                        {
                          Pointer stup_dst_779 { id_557 };
                          auto fun559 { dessser::gen::fq_name::to_row_binary };
                          ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_560 { std::get<7 /* Tails */>((*p_0)) };
                          dessser::gen::fq_name::t_ext id_561 { std::get<1>(id_560) };
                          Pointer id_562 { fun559(id_561, stup_dst_779) };
                          let_res_558 = id_562;
                        }
                        Pointer let_res_563;
                        {
                          Pointer stup_dst_780 { let_res_558 };
                          ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_564 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_565 { std::get<2>(id_564) };
                          uint32_t id_566 { (uint32_t)id_565.size() };
                          Vec<1, uint32_t> id_567 {  id_566  };
                          Pointer let_res_568;
                          {
                            Vec<1, uint32_t> leb128_sz_781 { id_567 };
                            Vec<1, Pointer> id_569 {  stup_dst_780  };
                            Pointer let_res_570;
                            {
                              Vec<1, Pointer> leb128_ptr_782 { id_569 };
                              bool while_flag_571 { true };
                              do {
                                uint8_t id_572 { 0 };
                                uint8_t id_573 { 0 };
                                Pointer id_574 { leb128_ptr_782[id_573] };
                                uint32_t id_575 { 128U };
                                uint8_t id_576 { 0 };
                                uint32_t id_577 { leb128_sz_781[id_576] };
                                bool id_578 { bool(id_575 > id_577) };
                                uint8_t choose_res_579;
                                if (id_578) {
                                  uint8_t id_580 { 0 };
                                  uint32_t id_581 { leb128_sz_781[id_580] };
                                  uint8_t id_582 { uint8_t(id_581) };
                                  choose_res_579 = id_582;
                                } else {
                                  uint8_t id_583 { 0 };
                                  uint32_t id_584 { leb128_sz_781[id_583] };
                                  uint8_t id_585 { uint8_t(id_584) };
                                  uint8_t id_586 { 128 };
                                  uint8_t id_587 { uint8_t(id_585 | id_586) };
                                  choose_res_579 = id_587;
                                }
                                Pointer id_588 { id_574.writeU8(choose_res_579) };
                                Void id_589 { ((void)(leb128_ptr_782[id_572] = id_588), ::dessser::VOID) };
                                (void)id_589;
                                uint8_t id_590 { 0 };
                                uint8_t id_591 { 0 };
                                uint32_t id_592 { leb128_sz_781[id_591] };
                                uint8_t id_593 { 7 };
                                uint32_t id_594 { uint32_t(id_592 >> id_593) };
                                Void id_595 { ((void)(leb128_sz_781[id_590] = id_594), ::dessser::VOID) };
                                (void)id_595;
                                uint8_t id_596 { 0 };
                                uint32_t id_597 { leb128_sz_781[id_596] };
                                uint32_t id_598 { 0U };
                                bool id_599 { bool(id_597 > id_598) };
                                while_flag_571 = id_599;
                                if (while_flag_571) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_571);
                              (void)::dessser::VOID;
                              uint8_t id_600 { 0 };
                              Pointer id_601 { leb128_ptr_782[id_600] };
                              let_res_570 = id_601;
                            }
                            let_res_568 = let_res_570;
                          }
                          ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_602 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_603 { std::get<2>(id_602) };
                          Bytes id_604 { id_603 };
                          Pointer id_605 { let_res_568.writeBytes(id_604) };
                          let_res_563 = id_605;
                        }
                        Pointer let_res_606;
                        {
                          Pointer stup_dst_783 { let_res_563 };
                          ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_607 { std::get<7 /* Tails */>((*p_0)) };
                          std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_608 { std::get<3>(id_607) };
                          Pointer id_609 { per_tail_to_row_binary(id_608, stup_dst_783) };
                          let_res_606 = id_609;
                        }
                        choose_res_553 = let_res_606;
                      } else {
                        uint16_t id_610 { 8 };
                        bool id_611 { bool(id_610 == label1_755) };
                        Pointer choose_res_612;
                        if (id_611) {
                          uint16_t id_613 { std::get<8 /* Replays */>((*p_0)) };
                          Pointer id_614 { ssum_dst_756.writeU16Le(id_613) };
                          choose_res_612 = id_614;
                        } else {
                          uint16_t id_615 { 9 };
                          bool id_616 { bool(id_615 == label1_755) };
                          Pointer choose_res_617;
                          if (id_616) {
                            std::optional<dessser::gen::sync_socket::t_ext> id_618 { std::get<9 /* Error */>((*p_0)) };
                            bool id_619 { !(id_618.has_value ()) };
                            Pointer choose_res_620;
                            if (id_619) {
                              uint8_t id_621 { 1 };
                              Pointer id_622 { ssum_dst_756.writeU8(id_621) };
                              choose_res_620 = id_622;
                            } else {
                              auto fun623 { dessser::gen::sync_socket::to_row_binary };
                              std::optional<dessser::gen::sync_socket::t_ext> id_624 { std::get<9 /* Error */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_625 { id_624.value() };
                              uint8_t id_626 { 0 };
                              Pointer id_627 { ssum_dst_756.writeU8(id_626) };
                              Pointer id_628 { fun623(id_625, id_627) };
                              choose_res_620 = id_628;
                            }
                            choose_res_617 = choose_res_620;
                          } else {
                            uint16_t id_629 { 10 };
                            bool id_630 { bool(id_629 == label1_755) };
                            Pointer choose_res_631;
                            if (id_630) {
                              choose_res_631 = ssum_dst_756;
                            } else {
                              uint16_t id_632 { 11 };
                              bool id_633 { bool(id_632 == label1_755) };
                              Pointer choose_res_634;
                              if (id_633) {
                                auto fun635 { dessser::gen::sync_socket::to_row_binary };
                                ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c id_636 { std::get<11 /* PerClient */>((*p_0)) };
                                dessser::gen::sync_socket::t_ext id_637 { std::get<0>(id_636) };
                                Pointer id_638 { fun635(id_637, ssum_dst_756) };
                                Pointer let_res_639;
                                {
                                  Pointer stup_dst_778 { id_638 };
                                  ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c id_640 { std::get<11 /* PerClient */>((*p_0)) };
                                  std::shared_ptr<::dessser::gen::sync_key::per_client>  id_641 { std::get<1>(id_640) };
                                  Pointer id_642 { per_client_to_row_binary(id_641, stup_dst_778) };
                                  let_res_639 = id_642;
                                }
                                choose_res_634 = let_res_639;
                              } else {
                                uint16_t id_643 { 12 };
                                bool id_644 { bool(id_643 == label1_755) };
                                Pointer choose_res_645;
                                if (id_644) {
                                  ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_646 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_647 { std::get<0>(id_646) };
                                  uint32_t id_648 { (uint32_t)id_647.size() };
                                  Vec<1, uint32_t> id_649 {  id_648  };
                                  Pointer let_res_650;
                                  {
                                    Vec<1, uint32_t> leb128_sz_775 { id_649 };
                                    Vec<1, Pointer> id_651 {  ssum_dst_756  };
                                    Pointer let_res_652;
                                    {
                                      Vec<1, Pointer> leb128_ptr_776 { id_651 };
                                      bool while_flag_653 { true };
                                      do {
                                        uint8_t id_654 { 0 };
                                        uint8_t id_655 { 0 };
                                        Pointer id_656 { leb128_ptr_776[id_655] };
                                        uint32_t id_657 { 128U };
                                        uint8_t id_658 { 0 };
                                        uint32_t id_659 { leb128_sz_775[id_658] };
                                        bool id_660 { bool(id_657 > id_659) };
                                        uint8_t choose_res_661;
                                        if (id_660) {
                                          uint8_t id_662 { 0 };
                                          uint32_t id_663 { leb128_sz_775[id_662] };
                                          uint8_t id_664 { uint8_t(id_663) };
                                          choose_res_661 = id_664;
                                        } else {
                                          uint8_t id_665 { 0 };
                                          uint32_t id_666 { leb128_sz_775[id_665] };
                                          uint8_t id_667 { uint8_t(id_666) };
                                          uint8_t id_668 { 128 };
                                          uint8_t id_669 { uint8_t(id_667 | id_668) };
                                          choose_res_661 = id_669;
                                        }
                                        Pointer id_670 { id_656.writeU8(choose_res_661) };
                                        Void id_671 { ((void)(leb128_ptr_776[id_654] = id_670), ::dessser::VOID) };
                                        (void)id_671;
                                        uint8_t id_672 { 0 };
                                        uint8_t id_673 { 0 };
                                        uint32_t id_674 { leb128_sz_775[id_673] };
                                        uint8_t id_675 { 7 };
                                        uint32_t id_676 { uint32_t(id_674 >> id_675) };
                                        Void id_677 { ((void)(leb128_sz_775[id_672] = id_676), ::dessser::VOID) };
                                        (void)id_677;
                                        uint8_t id_678 { 0 };
                                        uint32_t id_679 { leb128_sz_775[id_678] };
                                        uint32_t id_680 { 0U };
                                        bool id_681 { bool(id_679 > id_680) };
                                        while_flag_653 = id_681;
                                        if (while_flag_653) {
                                          (void)::dessser::VOID;
                                        }
                                      } while (while_flag_653);
                                      (void)::dessser::VOID;
                                      uint8_t id_682 { 0 };
                                      Pointer id_683 { leb128_ptr_776[id_682] };
                                      let_res_652 = id_683;
                                    }
                                    let_res_650 = let_res_652;
                                  }
                                  ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_684 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_685 { std::get<0>(id_684) };
                                  Bytes id_686 { id_685 };
                                  Pointer id_687 { let_res_650.writeBytes(id_686) };
                                  Pointer let_res_688;
                                  {
                                    Pointer stup_dst_777 { id_687 };
                                    ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_689 { std::get<12 /* Dashboards */>((*p_0)) };
                                    std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_690 { std::get<1>(id_689) };
                                    Pointer id_691 { per_dash_key_to_row_binary(id_690, stup_dst_777) };
                                    let_res_688 = id_691;
                                  }
                                  choose_res_645 = let_res_688;
                                } else {
                                  uint16_t id_692 { 13 };
                                  bool id_693 { bool(id_692 == label1_755) };
                                  Pointer choose_res_694;
                                  if (id_693) {
                                    choose_res_694 = ssum_dst_756;
                                  } else {
                                    uint16_t id_695 { 14 };
                                    bool id_696 { bool(id_695 == label1_755) };
                                    Pointer choose_res_697;
                                    if (id_696) {
                                      auto fun698 { dessser::gen::team_name::to_row_binary };
                                      ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_699 { std::get<14 /* Teams */>((*p_0)) };
                                      dessser::gen::team_name::t_ext id_700 { std::get<0>(id_699) };
                                      Pointer id_701 { fun698(id_700, ssum_dst_756) };
                                      Pointer let_res_702;
                                      {
                                        Pointer stup_dst_768 { id_701 };
                                        ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_703 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_704 { std::get<1>(id_703) };
                                        uint16_t id_705 { uint16_t(id_704.index()) };
                                        Pointer id_706 { stup_dst_768.writeU16Le(id_705) };
                                        Pointer let_res_707;
                                        {
                                          Pointer ssum_dst_770 { id_706 };
                                          uint16_t id_708 { 0 };
                                          ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_709 { std::get<14 /* Teams */>((*p_0)) };
                                          ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_710 { std::get<1>(id_709) };
                                          uint16_t id_711 { uint16_t(id_710.index()) };
                                          bool id_712 { bool(id_708 == id_711) };
                                          Pointer choose_res_713;
                                          if (id_712) {
                                            ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_714 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_715 { std::get<1>(id_714) };
                                            std::string id_716 { std::get<0 /* Contacts */>(id_715) };
                                            uint32_t id_717 { (uint32_t)id_716.size() };
                                            Vec<1, uint32_t> id_718 {  id_717  };
                                            Pointer let_res_719;
                                            {
                                              Vec<1, uint32_t> leb128_sz_773 { id_718 };
                                              Vec<1, Pointer> id_720 {  ssum_dst_770  };
                                              Pointer let_res_721;
                                              {
                                                Vec<1, Pointer> leb128_ptr_774 { id_720 };
                                                bool while_flag_722 { true };
                                                do {
                                                  uint8_t id_723 { 0 };
                                                  uint8_t id_724 { 0 };
                                                  Pointer id_725 { leb128_ptr_774[id_724] };
                                                  uint32_t id_726 { 128U };
                                                  uint8_t id_727 { 0 };
                                                  uint32_t id_728 { leb128_sz_773[id_727] };
                                                  bool id_729 { bool(id_726 > id_728) };
                                                  uint8_t choose_res_730;
                                                  if (id_729) {
                                                    uint8_t id_731 { 0 };
                                                    uint32_t id_732 { leb128_sz_773[id_731] };
                                                    uint8_t id_733 { uint8_t(id_732) };
                                                    choose_res_730 = id_733;
                                                  } else {
                                                    uint8_t id_734 { 0 };
                                                    uint32_t id_735 { leb128_sz_773[id_734] };
                                                    uint8_t id_736 { uint8_t(id_735) };
                                                    uint8_t id_737 { 128 };
                                                    uint8_t id_738 { uint8_t(id_736 | id_737) };
                                                    choose_res_730 = id_738;
                                                  }
                                                  Pointer id_739 { id_725.writeU8(choose_res_730) };
                                                  Void id_740 { ((void)(leb128_ptr_774[id_723] = id_739), ::dessser::VOID) };
                                                  (void)id_740;
                                                  uint8_t id_741 { 0 };
                                                  uint8_t id_742 { 0 };
                                                  uint32_t id_743 { leb128_sz_773[id_742] };
                                                  uint8_t id_744 { 7 };
                                                  uint32_t id_745 { uint32_t(id_743 >> id_744) };
                                                  Void id_746 { ((void)(leb128_sz_773[id_741] = id_745), ::dessser::VOID) };
                                                  (void)id_746;
                                                  uint8_t id_747 { 0 };
                                                  uint32_t id_748 { leb128_sz_773[id_747] };
                                                  uint32_t id_749 { 0U };
                                                  bool id_750 { bool(id_748 > id_749) };
                                                  while_flag_722 = id_750;
                                                  if (while_flag_722) {
                                                    (void)::dessser::VOID;
                                                  }
                                                } while (while_flag_722);
                                                (void)::dessser::VOID;
                                                uint8_t id_751 { 0 };
                                                Pointer id_752 { leb128_ptr_774[id_751] };
                                                let_res_721 = id_752;
                                              }
                                              let_res_719 = let_res_721;
                                            }
                                            ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_753 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_754 { std::get<1>(id_753) };
                                            std::string id_755 { std::get<0 /* Contacts */>(id_754) };
                                            Bytes id_756 { id_755 };
                                            Pointer id_757 { let_res_719.writeBytes(id_756) };
                                            choose_res_713 = id_757;
                                          } else {
                                            ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_758 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_759 { std::get<1>(id_758) };
                                            uint16_t id_760 { uint16_t(id_759.index()) };
                                            uint16_t id_761 { 1 };
                                            bool id_762 { bool(id_760 == id_761) };
                                            Void id_763 { ((void)(assert(id_762)), ::dessser::VOID) };
                                            (void)id_763;
                                            ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_764 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_765 { std::get<1>(id_764) };
                                            std::string id_766 { std::get<1 /* Inhibition */>(id_765) };
                                            uint32_t id_767 { (uint32_t)id_766.size() };
                                            Vec<1, uint32_t> id_768 {  id_767  };
                                            Pointer let_res_769;
                                            {
                                              Vec<1, uint32_t> leb128_sz_771 { id_768 };
                                              Vec<1, Pointer> id_770 {  ssum_dst_770  };
                                              Pointer let_res_771;
                                              {
                                                Vec<1, Pointer> leb128_ptr_772 { id_770 };
                                                bool while_flag_772 { true };
                                                do {
                                                  uint8_t id_773 { 0 };
                                                  uint8_t id_774 { 0 };
                                                  Pointer id_775 { leb128_ptr_772[id_774] };
                                                  uint32_t id_776 { 128U };
                                                  uint8_t id_777 { 0 };
                                                  uint32_t id_778 { leb128_sz_771[id_777] };
                                                  bool id_779 { bool(id_776 > id_778) };
                                                  uint8_t choose_res_780;
                                                  if (id_779) {
                                                    uint8_t id_781 { 0 };
                                                    uint32_t id_782 { leb128_sz_771[id_781] };
                                                    uint8_t id_783 { uint8_t(id_782) };
                                                    choose_res_780 = id_783;
                                                  } else {
                                                    uint8_t id_784 { 0 };
                                                    uint32_t id_785 { leb128_sz_771[id_784] };
                                                    uint8_t id_786 { uint8_t(id_785) };
                                                    uint8_t id_787 { 128 };
                                                    uint8_t id_788 { uint8_t(id_786 | id_787) };
                                                    choose_res_780 = id_788;
                                                  }
                                                  Pointer id_789 { id_775.writeU8(choose_res_780) };
                                                  Void id_790 { ((void)(leb128_ptr_772[id_773] = id_789), ::dessser::VOID) };
                                                  (void)id_790;
                                                  uint8_t id_791 { 0 };
                                                  uint8_t id_792 { 0 };
                                                  uint32_t id_793 { leb128_sz_771[id_792] };
                                                  uint8_t id_794 { 7 };
                                                  uint32_t id_795 { uint32_t(id_793 >> id_794) };
                                                  Void id_796 { ((void)(leb128_sz_771[id_791] = id_795), ::dessser::VOID) };
                                                  (void)id_796;
                                                  uint8_t id_797 { 0 };
                                                  uint32_t id_798 { leb128_sz_771[id_797] };
                                                  uint32_t id_799 { 0U };
                                                  bool id_800 { bool(id_798 > id_799) };
                                                  while_flag_772 = id_800;
                                                  if (while_flag_772) {
                                                    (void)::dessser::VOID;
                                                  }
                                                } while (while_flag_772);
                                                (void)::dessser::VOID;
                                                uint8_t id_801 { 0 };
                                                Pointer id_802 { leb128_ptr_772[id_801] };
                                                let_res_771 = id_802;
                                              }
                                              let_res_769 = let_res_771;
                                            }
                                            ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_803 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_804 { std::get<1>(id_803) };
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
                                      bool id_809 { bool(label1_755 == id_808) };
                                      Void id_810 { ((void)(assert(id_809)), ::dessser::VOID) };
                                      (void)id_810;
                                      ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_811 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_812 { std::get<0>(id_811) };
                                      uint32_t id_813 { (uint32_t)id_812.size() };
                                      Vec<1, uint32_t> id_814 {  id_813  };
                                      Pointer let_res_815;
                                      {
                                        Vec<1, uint32_t> leb128_sz_757 { id_814 };
                                        Vec<1, Pointer> id_816 {  ssum_dst_756  };
                                        Pointer let_res_817;
                                        {
                                          Vec<1, Pointer> leb128_ptr_758 { id_816 };
                                          bool while_flag_818 { true };
                                          do {
                                            uint8_t id_819 { 0 };
                                            uint8_t id_820 { 0 };
                                            Pointer id_821 { leb128_ptr_758[id_820] };
                                            uint32_t id_822 { 128U };
                                            uint8_t id_823 { 0 };
                                            uint32_t id_824 { leb128_sz_757[id_823] };
                                            bool id_825 { bool(id_822 > id_824) };
                                            uint8_t choose_res_826;
                                            if (id_825) {
                                              uint8_t id_827 { 0 };
                                              uint32_t id_828 { leb128_sz_757[id_827] };
                                              uint8_t id_829 { uint8_t(id_828) };
                                              choose_res_826 = id_829;
                                            } else {
                                              uint8_t id_830 { 0 };
                                              uint32_t id_831 { leb128_sz_757[id_830] };
                                              uint8_t id_832 { uint8_t(id_831) };
                                              uint8_t id_833 { 128 };
                                              uint8_t id_834 { uint8_t(id_832 | id_833) };
                                              choose_res_826 = id_834;
                                            }
                                            Pointer id_835 { id_821.writeU8(choose_res_826) };
                                            Void id_836 { ((void)(leb128_ptr_758[id_819] = id_835), ::dessser::VOID) };
                                            (void)id_836;
                                            uint8_t id_837 { 0 };
                                            uint8_t id_838 { 0 };
                                            uint32_t id_839 { leb128_sz_757[id_838] };
                                            uint8_t id_840 { 7 };
                                            uint32_t id_841 { uint32_t(id_839 >> id_840) };
                                            Void id_842 { ((void)(leb128_sz_757[id_837] = id_841), ::dessser::VOID) };
                                            (void)id_842;
                                            uint8_t id_843 { 0 };
                                            uint32_t id_844 { leb128_sz_757[id_843] };
                                            uint32_t id_845 { 0U };
                                            bool id_846 { bool(id_844 > id_845) };
                                            while_flag_818 = id_846;
                                            if (while_flag_818) {
                                              (void)::dessser::VOID;
                                            }
                                          } while (while_flag_818);
                                          (void)::dessser::VOID;
                                          uint8_t id_847 { 0 };
                                          Pointer id_848 { leb128_ptr_758[id_847] };
                                          let_res_817 = id_848;
                                        }
                                        let_res_815 = let_res_817;
                                      }
                                      ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_849 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_850 { std::get<0>(id_849) };
                                      Bytes id_851 { id_850 };
                                      Pointer id_852 { let_res_815.writeBytes(id_851) };
                                      Pointer let_res_853;
                                      {
                                        Pointer stup_dst_759 { id_852 };
                                        ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_854 { std::get<15 /* Incidents */>((*p_0)) };
                                        ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_855 { std::get<1>(id_854) };
                                        uint16_t id_856 { uint16_t(id_855.index()) };
                                        Pointer let_res_857;
                                        {
                                          uint16_t label1_760 { id_856 };
                                          Pointer id_858 { stup_dst_759.writeU16Le(label1_760) };
                                          Pointer let_res_859;
                                          {
                                            Pointer ssum_dst_761 { id_858 };
                                            uint16_t id_860 { 0 };
                                            bool id_861 { bool(id_860 == label1_760) };
                                            Pointer choose_res_862;
                                            if (id_861) {
                                              choose_res_862 = ssum_dst_761;
                                            } else {
                                              uint16_t id_863 { 1 };
                                              bool id_864 { bool(id_863 == label1_760) };
                                              Pointer choose_res_865;
                                              if (id_864) {
                                                choose_res_865 = ssum_dst_761;
                                              } else {
                                                uint16_t id_866 { 2 };
                                                bool id_867 { bool(id_866 == label1_760) };
                                                Pointer choose_res_868;
                                                if (id_867) {
                                                  choose_res_868 = ssum_dst_761;
                                                } else {
                                                  uint16_t id_869 { 3 };
                                                  bool id_870 { bool(id_869 == label1_760) };
                                                  Pointer choose_res_871;
                                                  if (id_870) {
                                                    choose_res_871 = ssum_dst_761;
                                                  } else {
                                                    uint16_t id_872 { 4 };
                                                    bool id_873 { bool(id_872 == label1_760) };
                                                    Pointer choose_res_874;
                                                    if (id_873) {
                                                      choose_res_874 = ssum_dst_761;
                                                    } else {
                                                      uint16_t id_875 { 5 };
                                                      bool id_876 { bool(id_875 == label1_760) };
                                                      Pointer choose_res_877;
                                                      if (id_876) {
                                                        ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_878 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_879 { std::get<1>(id_878) };
                                                        ::dessser::gen::sync_key::t8790f8724a8266402c08dc86b40c110a id_880 { std::get<5 /* Dialogs */>(id_879) };
                                                        std::string id_881 { std::get<0>(id_880) };
                                                        uint32_t id_882 { (uint32_t)id_881.size() };
                                                        Vec<1, uint32_t> id_883 {  id_882  };
                                                        Pointer let_res_884;
                                                        {
                                                          Vec<1, uint32_t> leb128_sz_763 { id_883 };
                                                          Vec<1, Pointer> id_885 {  ssum_dst_761  };
                                                          Pointer let_res_886;
                                                          {
                                                            Vec<1, Pointer> leb128_ptr_764 { id_885 };
                                                            bool while_flag_887 { true };
                                                            do {
                                                              uint8_t id_888 { 0 };
                                                              uint8_t id_889 { 0 };
                                                              Pointer id_890 { leb128_ptr_764[id_889] };
                                                              uint32_t id_891 { 128U };
                                                              uint8_t id_892 { 0 };
                                                              uint32_t id_893 { leb128_sz_763[id_892] };
                                                              bool id_894 { bool(id_891 > id_893) };
                                                              uint8_t choose_res_895;
                                                              if (id_894) {
                                                                uint8_t id_896 { 0 };
                                                                uint32_t id_897 { leb128_sz_763[id_896] };
                                                                uint8_t id_898 { uint8_t(id_897) };
                                                                choose_res_895 = id_898;
                                                              } else {
                                                                uint8_t id_899 { 0 };
                                                                uint32_t id_900 { leb128_sz_763[id_899] };
                                                                uint8_t id_901 { uint8_t(id_900) };
                                                                uint8_t id_902 { 128 };
                                                                uint8_t id_903 { uint8_t(id_901 | id_902) };
                                                                choose_res_895 = id_903;
                                                              }
                                                              Pointer id_904 { id_890.writeU8(choose_res_895) };
                                                              Void id_905 { ((void)(leb128_ptr_764[id_888] = id_904), ::dessser::VOID) };
                                                              (void)id_905;
                                                              uint8_t id_906 { 0 };
                                                              uint8_t id_907 { 0 };
                                                              uint32_t id_908 { leb128_sz_763[id_907] };
                                                              uint8_t id_909 { 7 };
                                                              uint32_t id_910 { uint32_t(id_908 >> id_909) };
                                                              Void id_911 { ((void)(leb128_sz_763[id_906] = id_910), ::dessser::VOID) };
                                                              (void)id_911;
                                                              uint8_t id_912 { 0 };
                                                              uint32_t id_913 { leb128_sz_763[id_912] };
                                                              uint32_t id_914 { 0U };
                                                              bool id_915 { bool(id_913 > id_914) };
                                                              while_flag_887 = id_915;
                                                              if (while_flag_887) {
                                                                (void)::dessser::VOID;
                                                              }
                                                            } while (while_flag_887);
                                                            (void)::dessser::VOID;
                                                            uint8_t id_916 { 0 };
                                                            Pointer id_917 { leb128_ptr_764[id_916] };
                                                            let_res_886 = id_917;
                                                          }
                                                          let_res_884 = let_res_886;
                                                        }
                                                        ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_918 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_919 { std::get<1>(id_918) };
                                                        ::dessser::gen::sync_key::t8790f8724a8266402c08dc86b40c110a id_920 { std::get<5 /* Dialogs */>(id_919) };
                                                        std::string id_921 { std::get<0>(id_920) };
                                                        Bytes id_922 { id_921 };
                                                        Pointer id_923 { let_res_884.writeBytes(id_922) };
                                                        Pointer let_res_924;
                                                        {
                                                          Pointer stup_dst_765 { id_923 };
                                                          ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_925 { std::get<15 /* Incidents */>((*p_0)) };
                                                          ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_926 { std::get<1>(id_925) };
                                                          ::dessser::gen::sync_key::t8790f8724a8266402c08dc86b40c110a id_927 { std::get<5 /* Dialogs */>(id_926) };
                                                          ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a id_928 { std::get<1>(id_927) };
                                                          uint16_t id_929 { uint16_t(id_928.index()) };
                                                          Pointer let_res_930;
                                                          {
                                                            uint16_t label1_766 { id_929 };
                                                            Pointer id_931 { stup_dst_765.writeU16Le(label1_766) };
                                                            Pointer let_res_932;
                                                            {
                                                              Pointer ssum_dst_767 { id_931 };
                                                              uint16_t id_933 { 0 };
                                                              bool id_934 { bool(id_933 == label1_766) };
                                                              Pointer choose_res_935;
                                                              if (id_934) {
                                                                choose_res_935 = ssum_dst_767;
                                                              } else {
                                                                uint16_t id_936 { 1 };
                                                                bool id_937 { bool(id_936 == label1_766) };
                                                                Pointer choose_res_938;
                                                                if (id_937) {
                                                                  choose_res_938 = ssum_dst_767;
                                                                } else {
                                                                  uint16_t id_939 { 2 };
                                                                  bool id_940 { bool(id_939 == label1_766) };
                                                                  Pointer choose_res_941;
                                                                  if (id_940) {
                                                                    choose_res_941 = ssum_dst_767;
                                                                  } else {
                                                                    uint16_t id_942 { 3 };
                                                                    bool id_943 { bool(id_942 == label1_766) };
                                                                    Pointer choose_res_944;
                                                                    if (id_943) {
                                                                      choose_res_944 = ssum_dst_767;
                                                                    } else {
                                                                      uint16_t id_945 { 4 };
                                                                      bool id_946 { bool(id_945 == label1_766) };
                                                                      Pointer choose_res_947;
                                                                      if (id_946) {
                                                                        choose_res_947 = ssum_dst_767;
                                                                      } else {
                                                                        uint16_t id_948 { 5 };
                                                                        bool id_949 { bool(id_948 == label1_766) };
                                                                        Pointer choose_res_950;
                                                                        if (id_949) {
                                                                          choose_res_950 = ssum_dst_767;
                                                                        } else {
                                                                          uint16_t id_951 { 6 };
                                                                          bool id_952 { bool(label1_766 == id_951) };
                                                                          Void id_953 { ((void)(assert(id_952)), ::dessser::VOID) };
                                                                          (void)id_953;
                                                                          choose_res_950 = ssum_dst_767;
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
                                                        bool id_955 { bool(label1_760 == id_954) };
                                                        Void id_956 { ((void)(assert(id_955)), ::dessser::VOID) };
                                                        (void)id_956;
                                                        ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_957 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_958 { std::get<1>(id_957) };
                                                        ::dessser::gen::sync_key::taf1e37f579ece7fa9db5670cfd23039b id_959 { std::get<6 /* Journal */>(id_958) };
                                                        double id_960 { std::get<0>(id_959) };
                                                        uint64_t id_961 { qword_of_float(id_960) };
                                                        Pointer id_962 { ssum_dst_761.writeU64Le(id_961) };
                                                        Pointer let_res_963;
                                                        {
                                                          Pointer stup_dst_762 { id_962 };
                                                          ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_964 { std::get<15 /* Incidents */>((*p_0)) };
                                                          ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_965 { std::get<1>(id_964) };
                                                          ::dessser::gen::sync_key::taf1e37f579ece7fa9db5670cfd23039b id_966 { std::get<6 /* Journal */>(id_965) };
                                                          uint32_t id_967 { std::get<1>(id_966) };
                                                          Pointer id_968 { stup_dst_762.writeU32Le(id_967) };
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
        Vec<1, uint32_t> n_ref_672 { id_983 };
        uint32_t id_985 { 1U };
        Vec<1, uint32_t> id_986 {  id_985  };
        Size let_res_987;
        {
          Vec<1, uint32_t> lebsz_ref_673 { id_986 };
          bool while_flag_988 { true };
          do {
            uint8_t id_989 { 0 };
            uint32_t id_990 { n_ref_672[id_989] };
            uint8_t id_991 { 0 };
            uint32_t id_992 { lebsz_ref_673[id_991] };
            uint8_t id_993 { 7 };
            uint32_t id_994 { uint32_t(id_992 << id_993) };
            bool id_995 { bool(id_990 >= id_994) };
            while_flag_988 = id_995;
            if (while_flag_988) {
              uint8_t id_996 { 0 };
              uint8_t id_997 { 0 };
              uint32_t id_998 { lebsz_ref_673[id_997] };
              uint32_t id_999 { 1U };
              uint32_t id_1000 { uint32_t(id_998 + id_999) };
              Void id_1001 { ((void)(lebsz_ref_673[id_996] = id_1000), ::dessser::VOID) };
              (void)id_1001;
            }
          } while (while_flag_988);
          (void)::dessser::VOID;
          uint8_t id_1002 { 0 };
          uint32_t id_1003 { lebsz_ref_673[id_1002] };
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
        Vec<1, uint32_t> n_ref_667 { id_1026 };
        uint32_t id_1028 { 1U };
        Vec<1, uint32_t> id_1029 {  id_1028  };
        Size let_res_1030;
        {
          Vec<1, uint32_t> lebsz_ref_668 { id_1029 };
          bool while_flag_1031 { true };
          do {
            uint8_t id_1032 { 0 };
            uint32_t id_1033 { n_ref_667[id_1032] };
            uint8_t id_1034 { 0 };
            uint32_t id_1035 { lebsz_ref_668[id_1034] };
            uint8_t id_1036 { 7 };
            uint32_t id_1037 { uint32_t(id_1035 << id_1036) };
            bool id_1038 { bool(id_1033 >= id_1037) };
            while_flag_1031 = id_1038;
            if (while_flag_1031) {
              uint8_t id_1039 { 0 };
              uint8_t id_1040 { 0 };
              uint32_t id_1041 { lebsz_ref_668[id_1040] };
              uint32_t id_1042 { 1U };
              uint32_t id_1043 { uint32_t(id_1041 + id_1042) };
              Void id_1044 { ((void)(lebsz_ref_668[id_1039] = id_1043), ::dessser::VOID) };
              (void)id_1044;
            }
          } while (while_flag_1031);
          (void)::dessser::VOID;
          uint8_t id_1045 { 0 };
          uint32_t id_1046 { lebsz_ref_668[id_1045] };
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
                  ::dessser::gen::sync_key::t21e5dc291e02ff6b92981a2d2fa864dc id_1094 { std::get<6 /* PerInstance */>((*p_0)) };
                  std::string id_1095 { std::get<0>(id_1094) };
                  uint32_t id_1096 { (uint32_t)id_1095.size() };
                  Vec<1, uint32_t> id_1097 {  id_1096  };
                  Size let_res_1098;
                  {
                    Vec<1, uint32_t> n_ref_644 { id_1097 };
                    uint32_t id_1099 { 1U };
                    Vec<1, uint32_t> id_1100 {  id_1099  };
                    Size let_res_1101;
                    {
                      Vec<1, uint32_t> lebsz_ref_645 { id_1100 };
                      bool while_flag_1102 { true };
                      do {
                        uint8_t id_1103 { 0 };
                        uint32_t id_1104 { n_ref_644[id_1103] };
                        uint8_t id_1105 { 0 };
                        uint32_t id_1106 { lebsz_ref_645[id_1105] };
                        uint8_t id_1107 { 7 };
                        uint32_t id_1108 { uint32_t(id_1106 << id_1107) };
                        bool id_1109 { bool(id_1104 >= id_1108) };
                        while_flag_1102 = id_1109;
                        if (while_flag_1102) {
                          uint8_t id_1110 { 0 };
                          uint8_t id_1111 { 0 };
                          uint32_t id_1112 { lebsz_ref_645[id_1111] };
                          uint32_t id_1113 { 1U };
                          uint32_t id_1114 { uint32_t(id_1112 + id_1113) };
                          Void id_1115 { ((void)(lebsz_ref_645[id_1110] = id_1114), ::dessser::VOID) };
                          (void)id_1115;
                        }
                      } while (while_flag_1102);
                      (void)::dessser::VOID;
                      uint8_t id_1116 { 0 };
                      uint32_t id_1117 { lebsz_ref_645[id_1116] };
                      Size id_1118 { Size(id_1117) };
                      let_res_1101 = id_1118;
                    }
                    let_res_1098 = let_res_1101;
                  }
                  ::dessser::gen::sync_key::t21e5dc291e02ff6b92981a2d2fa864dc id_1119 { std::get<6 /* PerInstance */>((*p_0)) };
                  std::string id_1120 { std::get<0>(id_1119) };
                  uint32_t id_1121 { (uint32_t)id_1120.size() };
                  Size id_1122 { Size(id_1121) };
                  Size id_1123 { Size(let_res_1098 + id_1122) };
                  Size id_1124 { Size(id_1093 + id_1123) };
                  Size let_res_1125;
                  {
                    Size sz_646 { id_1124 };
                    ::dessser::gen::sync_key::t21e5dc291e02ff6b92981a2d2fa864dc id_1126 { std::get<6 /* PerInstance */>((*p_0)) };
                    ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c id_1127 { std::get<1>(id_1126) };
                    uint16_t id_1128 { uint16_t(id_1127.index()) };
                    Size let_res_1129;
                    {
                      uint16_t label2_647 { id_1128 };
                      uint16_t id_1130 { 0 };
                      bool id_1131 { bool(id_1130 == label2_647) };
                      Size choose_res_1132;
                      if (id_1131) {
                        Size id_1133 { 2UL };
                        Size id_1134 { Size(sz_646 + id_1133) };
                        choose_res_1132 = id_1134;
                      } else {
                        uint16_t id_1135 { 1 };
                        bool id_1136 { bool(id_1135 == label2_647) };
                        Size choose_res_1137;
                        if (id_1136) {
                          Size id_1138 { 2UL };
                          Size id_1139 { Size(sz_646 + id_1138) };
                          choose_res_1137 = id_1139;
                        } else {
                          uint16_t id_1140 { 2 };
                          bool id_1141 { bool(id_1140 == label2_647) };
                          Size choose_res_1142;
                          if (id_1141) {
                            Size id_1143 { 2UL };
                            Size id_1144 { Size(sz_646 + id_1143) };
                            choose_res_1142 = id_1144;
                          } else {
                            uint16_t id_1145 { 3 };
                            bool id_1146 { bool(id_1145 == label2_647) };
                            Size choose_res_1147;
                            if (id_1146) {
                              Size id_1148 { 2UL };
                              Size id_1149 { Size(sz_646 + id_1148) };
                              choose_res_1147 = id_1149;
                            } else {
                              uint16_t id_1150 { 4 };
                              bool id_1151 { bool(id_1150 == label2_647) };
                              Size choose_res_1152;
                              if (id_1151) {
                                Size id_1153 { 2UL };
                                Size id_1154 { Size(sz_646 + id_1153) };
                                choose_res_1152 = id_1154;
                              } else {
                                uint16_t id_1155 { 5 };
                                bool id_1156 { bool(id_1155 == label2_647) };
                                Size choose_res_1157;
                                if (id_1156) {
                                  Size id_1158 { 2UL };
                                  Size id_1159 { Size(sz_646 + id_1158) };
                                  choose_res_1157 = id_1159;
                                } else {
                                  uint16_t id_1160 { 6 };
                                  bool id_1161 { bool(id_1160 == label2_647) };
                                  Size choose_res_1162;
                                  if (id_1161) {
                                    Size id_1163 { 2UL };
                                    Size id_1164 { Size(sz_646 + id_1163) };
                                    choose_res_1162 = id_1164;
                                  } else {
                                    uint16_t id_1165 { 7 };
                                    bool id_1166 { bool(label2_647 == id_1165) };
                                    Void id_1167 { ((void)(assert(id_1166)), ::dessser::VOID) };
                                    (void)id_1167;
                                    Size id_1168 { 2UL };
                                    Size id_1169 { Size(sz_646 + id_1168) };
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
      (let "sz_649" (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 0 (param 0))) (add (identifier "sz_649") (apply (identifier "per_worker_data-sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker> )> per_worker_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker> )> fun1180 { [&fun1180](std::shared_ptr<::dessser::gen::sync_key::per_worker>  p_0) {
    auto fun1181 { dessser::gen::fq_name::sersize_of_row_binary };
    dessser::gen::fq_name::t_ext id_1182 { std::get<0>((*p_0)) };
    Size id_1183 { fun1181(id_1182) };
    Size let_res_1184;
    {
      Size sz_649 { id_1183 };
      std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_1185 { std::get<1>((*p_0)) };
      Size id_1186 { per_worker_data_sersize_of_row_binary(id_1185) };
      Size id_1187 { Size(sz_649 + id_1186) };
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
        ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a id_1199 { std::get<1 /* PerService */>((*p_0)) };
        std::string id_1200 { std::get<0>(id_1199) };
        uint32_t id_1201 { (uint32_t)id_1200.size() };
        Vec<1, uint32_t> id_1202 {  id_1201  };
        Size let_res_1203;
        {
          Vec<1, uint32_t> n_ref_659 { id_1202 };
          uint32_t id_1204 { 1U };
          Vec<1, uint32_t> id_1205 {  id_1204  };
          Size let_res_1206;
          {
            Vec<1, uint32_t> lebsz_ref_660 { id_1205 };
            bool while_flag_1207 { true };
            do {
              uint8_t id_1208 { 0 };
              uint32_t id_1209 { n_ref_659[id_1208] };
              uint8_t id_1210 { 0 };
              uint32_t id_1211 { lebsz_ref_660[id_1210] };
              uint8_t id_1212 { 7 };
              uint32_t id_1213 { uint32_t(id_1211 << id_1212) };
              bool id_1214 { bool(id_1209 >= id_1213) };
              while_flag_1207 = id_1214;
              if (while_flag_1207) {
                uint8_t id_1215 { 0 };
                uint8_t id_1216 { 0 };
                uint32_t id_1217 { lebsz_ref_660[id_1216] };
                uint32_t id_1218 { 1U };
                uint32_t id_1219 { uint32_t(id_1217 + id_1218) };
                Void id_1220 { ((void)(lebsz_ref_660[id_1215] = id_1219), ::dessser::VOID) };
                (void)id_1220;
              }
            } while (while_flag_1207);
            (void)::dessser::VOID;
            uint8_t id_1221 { 0 };
            uint32_t id_1222 { lebsz_ref_660[id_1221] };
            Size id_1223 { Size(id_1222) };
            let_res_1206 = id_1223;
          }
          let_res_1203 = let_res_1206;
        }
        ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a id_1224 { std::get<1 /* PerService */>((*p_0)) };
        std::string id_1225 { std::get<0>(id_1224) };
        uint32_t id_1226 { (uint32_t)id_1225.size() };
        Size id_1227 { Size(id_1226) };
        Size id_1228 { Size(let_res_1203 + id_1227) };
        Size id_1229 { Size(id_1198 + id_1228) };
        Size let_res_1230;
        {
          Size sz_661 { id_1229 };
          uint16_t id_1231 { 0 };
          ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a id_1232 { std::get<1 /* PerService */>((*p_0)) };
          ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c id_1233 { std::get<1>(id_1232) };
          uint16_t id_1234 { uint16_t(id_1233.index()) };
          bool id_1235 { bool(id_1231 == id_1234) };
          Size choose_res_1236;
          if (id_1235) {
            Size id_1237 { 2UL };
            Size id_1238 { Size(sz_661 + id_1237) };
            choose_res_1236 = id_1238;
          } else {
            ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a id_1239 { std::get<1 /* PerService */>((*p_0)) };
            ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c id_1240 { std::get<1>(id_1239) };
            uint16_t id_1241 { uint16_t(id_1240.index()) };
            uint16_t id_1242 { 1 };
            bool id_1243 { bool(id_1241 == id_1242) };
            Void id_1244 { ((void)(assert(id_1243)), ::dessser::VOID) };
            (void)id_1244;
            Size id_1245 { 2UL };
            Size id_1246 { Size(sz_661 + id_1245) };
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
          ::dessser::gen::sync_key::td7912e294d6f3a12e8335070433dc663 id_1260 { std::get<3 /* PerProgram */>((*p_0)) };
          std::string id_1261 { std::get<0>(id_1260) };
          uint32_t id_1262 { (uint32_t)id_1261.size() };
          Vec<1, uint32_t> id_1263 {  id_1262  };
          Size let_res_1264;
          {
            Vec<1, uint32_t> n_ref_653 { id_1263 };
            uint32_t id_1265 { 1U };
            Vec<1, uint32_t> id_1266 {  id_1265  };
            Size let_res_1267;
            {
              Vec<1, uint32_t> lebsz_ref_654 { id_1266 };
              bool while_flag_1268 { true };
              do {
                uint8_t id_1269 { 0 };
                uint32_t id_1270 { n_ref_653[id_1269] };
                uint8_t id_1271 { 0 };
                uint32_t id_1272 { lebsz_ref_654[id_1271] };
                uint8_t id_1273 { 7 };
                uint32_t id_1274 { uint32_t(id_1272 << id_1273) };
                bool id_1275 { bool(id_1270 >= id_1274) };
                while_flag_1268 = id_1275;
                if (while_flag_1268) {
                  uint8_t id_1276 { 0 };
                  uint8_t id_1277 { 0 };
                  uint32_t id_1278 { lebsz_ref_654[id_1277] };
                  uint32_t id_1279 { 1U };
                  uint32_t id_1280 { uint32_t(id_1278 + id_1279) };
                  Void id_1281 { ((void)(lebsz_ref_654[id_1276] = id_1280), ::dessser::VOID) };
                  (void)id_1281;
                }
              } while (while_flag_1268);
              (void)::dessser::VOID;
              uint8_t id_1282 { 0 };
              uint32_t id_1283 { lebsz_ref_654[id_1282] };
              Size id_1284 { Size(id_1283) };
              let_res_1267 = id_1284;
            }
            let_res_1264 = let_res_1267;
          }
          ::dessser::gen::sync_key::td7912e294d6f3a12e8335070433dc663 id_1285 { std::get<3 /* PerProgram */>((*p_0)) };
          std::string id_1286 { std::get<0>(id_1285) };
          uint32_t id_1287 { (uint32_t)id_1286.size() };
          Size id_1288 { Size(id_1287) };
          Size id_1289 { Size(let_res_1264 + id_1288) };
          Size id_1290 { Size(id_1259 + id_1289) };
          Size let_res_1291;
          {
            Size sz_655 { id_1290 };
            ::dessser::gen::sync_key::td7912e294d6f3a12e8335070433dc663 id_1292 { std::get<3 /* PerProgram */>((*p_0)) };
            ::dessser::gen::sync_key::tea8c2377036e530fd3f67fa8653a3834 id_1293 { std::get<1>(id_1292) };
            uint16_t id_1294 { uint16_t(id_1293.index()) };
            uint16_t id_1295 { 0 };
            bool id_1296 { bool(id_1294 == id_1295) };
            Void id_1297 { ((void)(assert(id_1296)), ::dessser::VOID) };
            (void)id_1297;
            Size id_1298 { 2UL };
            Size id_1299 { Size(sz_655 + id_1298) };
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
      (let "sz_664" (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (param 0))) (add (identifier "sz_664") (apply (identifier "per_site_data-sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site> )> per_site_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site> )> fun1300 { [&fun1300](std::shared_ptr<::dessser::gen::sync_key::per_site>  p_0) {
    auto fun1301 { dessser::gen::site_name::sersize_of_row_binary };
    dessser::gen::site_name::t_ext id_1302 { std::get<0>((*p_0)) };
    Size id_1303 { fun1301(id_1302) };
    Size let_res_1304;
    {
      Size sz_664 { id_1303 };
      std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_1305 { std::get<1>((*p_0)) };
      Size id_1306 { per_site_data_sersize_of_row_binary(id_1305) };
      Size id_1307 { Size(sz_664 + id_1306) };
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
      (let "label2_674" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_674")) (size 2)
          (if (eq (u16 1) (identifier "label2_674")) (size 2)
            (if (eq (u16 2) (identifier "label2_674"))
              (add (size 2)
                (add
                  (let "n_ref_722" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "lebsz_ref_723" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_722")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_723")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_723") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_723")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_723")))))) 
                  (size-of-u32 (string-length (get-alt "Versions" (param 0))))))
              (if (eq (u16 3) (identifier "label2_674"))
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
                (if (eq (u16 4) (identifier "label2_674")) (size 2)
                  (if (eq (u16 5) (identifier "label2_674")) (add (size 2) (apply (identifier "per_site-sersize-of-row-binary") (get-alt "PerSite" (param 0))))
                    (if (eq (u16 6) (identifier "label2_674"))
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
                      (if (eq (u16 7) (identifier "label2_674"))
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
                        (if (eq (u16 8) (identifier "label2_674")) (size 4)
                          (if (eq (u16 9) (identifier "label2_674"))
                            (if (is-null (get-alt "Error" (param 0))) (size 3) (add (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (force (get-alt "Error" (param 0))))) (size 1)))
                            (if (eq (u16 10) (identifier "label2_674")) 
                              (size 2)
                              (if (eq (u16 11) (identifier "label2_674"))
                                (let "sz_704" (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (get-item 0 (get-alt "PerClient" (param 0)))))
                                  (add (identifier "sz_704") (apply (identifier "per_client-sersize-of-row-binary") (get-item 1 (get-alt "PerClient" (param 0))))))
                                (if (eq (u16 12) (identifier "label2_674"))
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
                                  (if (eq (u16 13) (identifier "label2_674")) 
                                    (size 2)
                                    (if (eq (u16 14) (identifier "label2_674"))
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
                                      (seq (assert (eq (identifier "label2_674") (u16 15)))
                                        (let "sz_679"
                                          (add (size 2)
                                            (add
                                              (let "n_ref_677" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "lebsz_ref_678" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_677")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_678")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_678") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_678")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_678")))))) 
                                              (size-of-u32 (string-length (get-item 0 (get-alt "Incidents" (param 0)))))))
                                          (let "label2_680" (label-of (get-item 1 (get-alt "Incidents" (param 0))))
                                            (if (eq (u16 0) (identifier "label2_680")) 
                                              (add (identifier "sz_679") (size 2))
                                              (if (eq (u16 1) (identifier "label2_680")) 
                                                (add (identifier "sz_679") (size 2))
                                                (if (eq (u16 2) (identifier "label2_680")) 
                                                  (add (identifier "sz_679") (size 2))
                                                  (if (eq (u16 3) (identifier "label2_680")) 
                                                    (add (identifier "sz_679") (size 2))
                                                    (if (eq (u16 4) (identifier "label2_680")) 
                                                      (add (identifier "sz_679") (size 2))
                                                      (if (eq (u16 5) (identifier "label2_680"))
                                                        (let "sz_687"
                                                          (add (add (identifier "sz_679") (size 2))
                                                            (add
                                                              (let "n_ref_685" 
                                                                (make-vec (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                (let "lebsz_ref_686" 
                                                                  (make-vec (u32 1))
                                                                  (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_685")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_686")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_686") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_686")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_686"))))))
                                                              (size-of-u32 (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))))
                                                          (let "label2_688" 
                                                            (label-of (get-item 1 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0))))))
                                                            (if (eq (u16 0) (identifier "label2_688")) 
                                                              (add (identifier "sz_687") (size 2))
                                                              (if (eq (u16 1) (identifier "label2_688")) 
                                                                (add (identifier "sz_687") (size 2))
                                                                (if (eq (u16 2) (identifier "label2_688")) 
                                                                  (add (identifier "sz_687") (size 2))
                                                                  (if 
                                                                    (eq (u16 3) (identifier "label2_688")) 
                                                                    (add (identifier "sz_687") (size 2))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "label2_688")) 
                                                                    (add (identifier "sz_687") (size 2))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "label2_688")) 
                                                                    (add (identifier "sz_687") (size 2)) 
                                                                    (seq (assert (eq (identifier "label2_688") (u16 6))) (add (identifier "sz_687") (size 2)))))))))))
                                                        (seq (assert (eq (identifier "label2_680") (u16 6))) (add (add (add (identifier "sz_679") (size 2)) (size 8)) (size 4)))))))))))))))))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> fun1308 { [&fun1308](std::shared_ptr<::dessser::gen::sync_key::t>  p_0) {
    uint16_t id_1309 { uint16_t((*p_0).index()) };
    Size let_res_1310;
    {
      uint16_t label2_674 { id_1309 };
      uint16_t id_1311 { 0 };
      bool id_1312 { bool(id_1311 == label2_674) };
      Size choose_res_1313;
      if (id_1312) {
        Size id_1314 { 2UL };
        choose_res_1313 = id_1314;
      } else {
        uint16_t id_1315 { 1 };
        bool id_1316 { bool(id_1315 == label2_674) };
        Size choose_res_1317;
        if (id_1316) {
          Size id_1318 { 2UL };
          choose_res_1317 = id_1318;
        } else {
          uint16_t id_1319 { 2 };
          bool id_1320 { bool(id_1319 == label2_674) };
          Size choose_res_1321;
          if (id_1320) {
            Size id_1322 { 2UL };
            std::string id_1323 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1324 { (uint32_t)id_1323.size() };
            Vec<1, uint32_t> id_1325 {  id_1324  };
            Size let_res_1326;
            {
              Vec<1, uint32_t> n_ref_722 { id_1325 };
              uint32_t id_1327 { 1U };
              Vec<1, uint32_t> id_1328 {  id_1327  };
              Size let_res_1329;
              {
                Vec<1, uint32_t> lebsz_ref_723 { id_1328 };
                bool while_flag_1330 { true };
                do {
                  uint8_t id_1331 { 0 };
                  uint32_t id_1332 { n_ref_722[id_1331] };
                  uint8_t id_1333 { 0 };
                  uint32_t id_1334 { lebsz_ref_723[id_1333] };
                  uint8_t id_1335 { 7 };
                  uint32_t id_1336 { uint32_t(id_1334 << id_1335) };
                  bool id_1337 { bool(id_1332 >= id_1336) };
                  while_flag_1330 = id_1337;
                  if (while_flag_1330) {
                    uint8_t id_1338 { 0 };
                    uint8_t id_1339 { 0 };
                    uint32_t id_1340 { lebsz_ref_723[id_1339] };
                    uint32_t id_1341 { 1U };
                    uint32_t id_1342 { uint32_t(id_1340 + id_1341) };
                    Void id_1343 { ((void)(lebsz_ref_723[id_1338] = id_1342), ::dessser::VOID) };
                    (void)id_1343;
                  }
                } while (while_flag_1330);
                (void)::dessser::VOID;
                uint8_t id_1344 { 0 };
                uint32_t id_1345 { lebsz_ref_723[id_1344] };
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
            bool id_1353 { bool(id_1352 == label2_674) };
            Size choose_res_1354;
            if (id_1353) {
              Size id_1355 { 2UL };
              auto fun1356 { dessser::gen::src_path::sersize_of_row_binary };
              ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_1357 { std::get<3 /* Sources */>((*p_0)) };
              dessser::gen::src_path::t_ext id_1358 { std::get<0>(id_1357) };
              Size id_1359 { fun1356(id_1358) };
              Size id_1360 { Size(id_1355 + id_1359) };
              Size let_res_1361;
              {
                Size sz_717 { id_1360 };
                ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_1362 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1363 { std::get<1>(id_1362) };
                uint32_t id_1364 { (uint32_t)id_1363.size() };
                Vec<1, uint32_t> id_1365 {  id_1364  };
                Size let_res_1366;
                {
                  Vec<1, uint32_t> n_ref_719 { id_1365 };
                  uint32_t id_1367 { 1U };
                  Vec<1, uint32_t> id_1368 {  id_1367  };
                  Size let_res_1369;
                  {
                    Vec<1, uint32_t> lebsz_ref_720 { id_1368 };
                    bool while_flag_1370 { true };
                    do {
                      uint8_t id_1371 { 0 };
                      uint32_t id_1372 { n_ref_719[id_1371] };
                      uint8_t id_1373 { 0 };
                      uint32_t id_1374 { lebsz_ref_720[id_1373] };
                      uint8_t id_1375 { 7 };
                      uint32_t id_1376 { uint32_t(id_1374 << id_1375) };
                      bool id_1377 { bool(id_1372 >= id_1376) };
                      while_flag_1370 = id_1377;
                      if (while_flag_1370) {
                        uint8_t id_1378 { 0 };
                        uint8_t id_1379 { 0 };
                        uint32_t id_1380 { lebsz_ref_720[id_1379] };
                        uint32_t id_1381 { 1U };
                        uint32_t id_1382 { uint32_t(id_1380 + id_1381) };
                        Void id_1383 { ((void)(lebsz_ref_720[id_1378] = id_1382), ::dessser::VOID) };
                        (void)id_1383;
                      }
                    } while (while_flag_1370);
                    (void)::dessser::VOID;
                    uint8_t id_1384 { 0 };
                    uint32_t id_1385 { lebsz_ref_720[id_1384] };
                    Size id_1386 { Size(id_1385) };
                    let_res_1369 = id_1386;
                  }
                  let_res_1366 = let_res_1369;
                }
                ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_1387 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1388 { std::get<1>(id_1387) };
                uint32_t id_1389 { (uint32_t)id_1388.size() };
                Size id_1390 { Size(id_1389) };
                Size id_1391 { Size(let_res_1366 + id_1390) };
                Size id_1392 { Size(sz_717 + id_1391) };
                let_res_1361 = id_1392;
              }
              choose_res_1354 = let_res_1361;
            } else {
              uint16_t id_1393 { 4 };
              bool id_1394 { bool(id_1393 == label2_674) };
              Size choose_res_1395;
              if (id_1394) {
                Size id_1396 { 2UL };
                choose_res_1395 = id_1396;
              } else {
                uint16_t id_1397 { 5 };
                bool id_1398 { bool(id_1397 == label2_674) };
                Size choose_res_1399;
                if (id_1398) {
                  Size id_1400 { 2UL };
                  std::shared_ptr<::dessser::gen::sync_key::per_site>  id_1401 { std::get<5 /* PerSite */>((*p_0)) };
                  Size id_1402 { per_site_sersize_of_row_binary(id_1401) };
                  Size id_1403 { Size(id_1400 + id_1402) };
                  choose_res_1399 = id_1403;
                } else {
                  uint16_t id_1404 { 6 };
                  bool id_1405 { bool(id_1404 == label2_674) };
                  Size choose_res_1406;
                  if (id_1405) {
                    uint16_t id_1407 { 0 };
                    ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_1408 { std::get<6 /* Storage */>((*p_0)) };
                    uint16_t id_1409 { uint16_t(id_1408.index()) };
                    bool id_1410 { bool(id_1407 == id_1409) };
                    Size choose_res_1411;
                    if (id_1410) {
                      Size id_1412 { 4UL };
                      choose_res_1411 = id_1412;
                    } else {
                      uint16_t id_1413 { 1 };
                      ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_1414 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_1415 { uint16_t(id_1414.index()) };
                      bool id_1416 { bool(id_1413 == id_1415) };
                      Size choose_res_1417;
                      if (id_1416) {
                        Size id_1418 { 4UL };
                        choose_res_1417 = id_1418;
                      } else {
                        ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_1419 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_1420 { uint16_t(id_1419.index()) };
                        uint16_t id_1421 { 2 };
                        bool id_1422 { bool(id_1420 == id_1421) };
                        Void id_1423 { ((void)(assert(id_1422)), ::dessser::VOID) };
                        (void)id_1423;
                        Size id_1424 { 4UL };
                        ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_1425 { std::get<6 /* Storage */>((*p_0)) };
                        std::string id_1426 { std::get<2 /* RetentionsOverride */>(id_1425) };
                        uint32_t id_1427 { (uint32_t)id_1426.size() };
                        Vec<1, uint32_t> id_1428 {  id_1427  };
                        Size let_res_1429;
                        {
                          Vec<1, uint32_t> n_ref_714 { id_1428 };
                          uint32_t id_1430 { 1U };
                          Vec<1, uint32_t> id_1431 {  id_1430  };
                          Size let_res_1432;
                          {
                            Vec<1, uint32_t> lebsz_ref_715 { id_1431 };
                            bool while_flag_1433 { true };
                            do {
                              uint8_t id_1434 { 0 };
                              uint32_t id_1435 { n_ref_714[id_1434] };
                              uint8_t id_1436 { 0 };
                              uint32_t id_1437 { lebsz_ref_715[id_1436] };
                              uint8_t id_1438 { 7 };
                              uint32_t id_1439 { uint32_t(id_1437 << id_1438) };
                              bool id_1440 { bool(id_1435 >= id_1439) };
                              while_flag_1433 = id_1440;
                              if (while_flag_1433) {
                                uint8_t id_1441 { 0 };
                                uint8_t id_1442 { 0 };
                                uint32_t id_1443 { lebsz_ref_715[id_1442] };
                                uint32_t id_1444 { 1U };
                                uint32_t id_1445 { uint32_t(id_1443 + id_1444) };
                                Void id_1446 { ((void)(lebsz_ref_715[id_1441] = id_1445), ::dessser::VOID) };
                                (void)id_1446;
                              }
                            } while (while_flag_1433);
                            (void)::dessser::VOID;
                            uint8_t id_1447 { 0 };
                            uint32_t id_1448 { lebsz_ref_715[id_1447] };
                            Size id_1449 { Size(id_1448) };
                            let_res_1432 = id_1449;
                          }
                          let_res_1429 = let_res_1432;
                        }
                        ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_1450 { std::get<6 /* Storage */>((*p_0)) };
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
                    bool id_1457 { bool(id_1456 == label2_674) };
                    Size choose_res_1458;
                    if (id_1457) {
                      Size id_1459 { 2UL };
                      auto fun1460 { dessser::gen::site_name::sersize_of_row_binary };
                      ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_1461 { std::get<7 /* Tails */>((*p_0)) };
                      dessser::gen::site_name::t_ext id_1462 { std::get<0>(id_1461) };
                      Size id_1463 { fun1460(id_1462) };
                      Size id_1464 { Size(id_1459 + id_1463) };
                      Size let_res_1465;
                      {
                        Size sz_706 { id_1464 };
                        auto fun1466 { dessser::gen::fq_name::sersize_of_row_binary };
                        ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_1467 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::fq_name::t_ext id_1468 { std::get<1>(id_1467) };
                        Size id_1469 { fun1466(id_1468) };
                        Size id_1470 { Size(sz_706 + id_1469) };
                        let_res_1465 = id_1470;
                      }
                      Size let_res_1471;
                      {
                        Size sz_707 { let_res_1465 };
                        ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_1472 { std::get<7 /* Tails */>((*p_0)) };
                        std::string id_1473 { std::get<2>(id_1472) };
                        uint32_t id_1474 { (uint32_t)id_1473.size() };
                        Vec<1, uint32_t> id_1475 {  id_1474  };
                        Size let_res_1476;
                        {
                          Vec<1, uint32_t> n_ref_709 { id_1475 };
                          uint32_t id_1477 { 1U };
                          Vec<1, uint32_t> id_1478 {  id_1477  };
                          Size let_res_1479;
                          {
                            Vec<1, uint32_t> lebsz_ref_710 { id_1478 };
                            bool while_flag_1480 { true };
                            do {
                              uint8_t id_1481 { 0 };
                              uint32_t id_1482 { n_ref_709[id_1481] };
                              uint8_t id_1483 { 0 };
                              uint32_t id_1484 { lebsz_ref_710[id_1483] };
                              uint8_t id_1485 { 7 };
                              uint32_t id_1486 { uint32_t(id_1484 << id_1485) };
                              bool id_1487 { bool(id_1482 >= id_1486) };
                              while_flag_1480 = id_1487;
                              if (while_flag_1480) {
                                uint8_t id_1488 { 0 };
                                uint8_t id_1489 { 0 };
                                uint32_t id_1490 { lebsz_ref_710[id_1489] };
                                uint32_t id_1491 { 1U };
                                uint32_t id_1492 { uint32_t(id_1490 + id_1491) };
                                Void id_1493 { ((void)(lebsz_ref_710[id_1488] = id_1492), ::dessser::VOID) };
                                (void)id_1493;
                              }
                            } while (while_flag_1480);
                            (void)::dessser::VOID;
                            uint8_t id_1494 { 0 };
                            uint32_t id_1495 { lebsz_ref_710[id_1494] };
                            Size id_1496 { Size(id_1495) };
                            let_res_1479 = id_1496;
                          }
                          let_res_1476 = let_res_1479;
                        }
                        ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_1497 { std::get<7 /* Tails */>((*p_0)) };
                        std::string id_1498 { std::get<2>(id_1497) };
                        uint32_t id_1499 { (uint32_t)id_1498.size() };
                        Size id_1500 { Size(id_1499) };
                        Size id_1501 { Size(let_res_1476 + id_1500) };
                        Size id_1502 { Size(sz_707 + id_1501) };
                        let_res_1471 = id_1502;
                      }
                      Size let_res_1503;
                      {
                        Size sz_711 { let_res_1471 };
                        ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_1504 { std::get<7 /* Tails */>((*p_0)) };
                        std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_1505 { std::get<3>(id_1504) };
                        Size id_1506 { per_tail_sersize_of_row_binary(id_1505) };
                        Size id_1507 { Size(sz_711 + id_1506) };
                        let_res_1503 = id_1507;
                      }
                      choose_res_1458 = let_res_1503;
                    } else {
                      uint16_t id_1508 { 8 };
                      bool id_1509 { bool(id_1508 == label2_674) };
                      Size choose_res_1510;
                      if (id_1509) {
                        Size id_1511 { 4UL };
                        choose_res_1510 = id_1511;
                      } else {
                        uint16_t id_1512 { 9 };
                        bool id_1513 { bool(id_1512 == label2_674) };
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
                          bool id_1528 { bool(id_1527 == label2_674) };
                          Size choose_res_1529;
                          if (id_1528) {
                            Size id_1530 { 2UL };
                            choose_res_1529 = id_1530;
                          } else {
                            uint16_t id_1531 { 11 };
                            bool id_1532 { bool(id_1531 == label2_674) };
                            Size choose_res_1533;
                            if (id_1532) {
                              Size id_1534 { 2UL };
                              auto fun1535 { dessser::gen::sync_socket::sersize_of_row_binary };
                              ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c id_1536 { std::get<11 /* PerClient */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_1537 { std::get<0>(id_1536) };
                              Size id_1538 { fun1535(id_1537) };
                              Size id_1539 { Size(id_1534 + id_1538) };
                              Size let_res_1540;
                              {
                                Size sz_704 { id_1539 };
                                ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c id_1541 { std::get<11 /* PerClient */>((*p_0)) };
                                std::shared_ptr<::dessser::gen::sync_key::per_client>  id_1542 { std::get<1>(id_1541) };
                                Size id_1543 { per_client_sersize_of_row_binary(id_1542) };
                                Size id_1544 { Size(sz_704 + id_1543) };
                                let_res_1540 = id_1544;
                              }
                              choose_res_1533 = let_res_1540;
                            } else {
                              uint16_t id_1545 { 12 };
                              bool id_1546 { bool(id_1545 == label2_674) };
                              Size choose_res_1547;
                              if (id_1546) {
                                Size id_1548 { 2UL };
                                ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_1549 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1550 { std::get<0>(id_1549) };
                                uint32_t id_1551 { (uint32_t)id_1550.size() };
                                Vec<1, uint32_t> id_1552 {  id_1551  };
                                Size let_res_1553;
                                {
                                  Vec<1, uint32_t> n_ref_700 { id_1552 };
                                  uint32_t id_1554 { 1U };
                                  Vec<1, uint32_t> id_1555 {  id_1554  };
                                  Size let_res_1556;
                                  {
                                    Vec<1, uint32_t> lebsz_ref_701 { id_1555 };
                                    bool while_flag_1557 { true };
                                    do {
                                      uint8_t id_1558 { 0 };
                                      uint32_t id_1559 { n_ref_700[id_1558] };
                                      uint8_t id_1560 { 0 };
                                      uint32_t id_1561 { lebsz_ref_701[id_1560] };
                                      uint8_t id_1562 { 7 };
                                      uint32_t id_1563 { uint32_t(id_1561 << id_1562) };
                                      bool id_1564 { bool(id_1559 >= id_1563) };
                                      while_flag_1557 = id_1564;
                                      if (while_flag_1557) {
                                        uint8_t id_1565 { 0 };
                                        uint8_t id_1566 { 0 };
                                        uint32_t id_1567 { lebsz_ref_701[id_1566] };
                                        uint32_t id_1568 { 1U };
                                        uint32_t id_1569 { uint32_t(id_1567 + id_1568) };
                                        Void id_1570 { ((void)(lebsz_ref_701[id_1565] = id_1569), ::dessser::VOID) };
                                        (void)id_1570;
                                      }
                                    } while (while_flag_1557);
                                    (void)::dessser::VOID;
                                    uint8_t id_1571 { 0 };
                                    uint32_t id_1572 { lebsz_ref_701[id_1571] };
                                    Size id_1573 { Size(id_1572) };
                                    let_res_1556 = id_1573;
                                  }
                                  let_res_1553 = let_res_1556;
                                }
                                ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_1574 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1575 { std::get<0>(id_1574) };
                                uint32_t id_1576 { (uint32_t)id_1575.size() };
                                Size id_1577 { Size(id_1576) };
                                Size id_1578 { Size(let_res_1553 + id_1577) };
                                Size id_1579 { Size(id_1548 + id_1578) };
                                Size let_res_1580;
                                {
                                  Size sz_702 { id_1579 };
                                  ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_1581 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1582 { std::get<1>(id_1581) };
                                  Size id_1583 { per_dash_key_sersize_of_row_binary(id_1582) };
                                  Size id_1584 { Size(sz_702 + id_1583) };
                                  let_res_1580 = id_1584;
                                }
                                choose_res_1547 = let_res_1580;
                              } else {
                                uint16_t id_1585 { 13 };
                                bool id_1586 { bool(id_1585 == label2_674) };
                                Size choose_res_1587;
                                if (id_1586) {
                                  Size id_1588 { 2UL };
                                  choose_res_1587 = id_1588;
                                } else {
                                  uint16_t id_1589 { 14 };
                                  bool id_1590 { bool(id_1589 == label2_674) };
                                  Size choose_res_1591;
                                  if (id_1590) {
                                    Size id_1592 { 2UL };
                                    auto fun1593 { dessser::gen::team_name::sersize_of_row_binary };
                                    ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_1594 { std::get<14 /* Teams */>((*p_0)) };
                                    dessser::gen::team_name::t_ext id_1595 { std::get<0>(id_1594) };
                                    Size id_1596 { fun1593(id_1595) };
                                    Size id_1597 { Size(id_1592 + id_1596) };
                                    Size let_res_1598;
                                    {
                                      Size sz_690 { id_1597 };
                                      uint16_t id_1599 { 0 };
                                      ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_1600 { std::get<14 /* Teams */>((*p_0)) };
                                      ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_1601 { std::get<1>(id_1600) };
                                      uint16_t id_1602 { uint16_t(id_1601.index()) };
                                      bool id_1603 { bool(id_1599 == id_1602) };
                                      Size choose_res_1604;
                                      if (id_1603) {
                                        Size id_1605 { 2UL };
                                        Size id_1606 { Size(sz_690 + id_1605) };
                                        ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_1607 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_1608 { std::get<1>(id_1607) };
                                        std::string id_1609 { std::get<0 /* Contacts */>(id_1608) };
                                        uint32_t id_1610 { (uint32_t)id_1609.size() };
                                        Vec<1, uint32_t> id_1611 {  id_1610  };
                                        Size let_res_1612;
                                        {
                                          Vec<1, uint32_t> n_ref_696 { id_1611 };
                                          uint32_t id_1613 { 1U };
                                          Vec<1, uint32_t> id_1614 {  id_1613  };
                                          Size let_res_1615;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_697 { id_1614 };
                                            bool while_flag_1616 { true };
                                            do {
                                              uint8_t id_1617 { 0 };
                                              uint32_t id_1618 { n_ref_696[id_1617] };
                                              uint8_t id_1619 { 0 };
                                              uint32_t id_1620 { lebsz_ref_697[id_1619] };
                                              uint8_t id_1621 { 7 };
                                              uint32_t id_1622 { uint32_t(id_1620 << id_1621) };
                                              bool id_1623 { bool(id_1618 >= id_1622) };
                                              while_flag_1616 = id_1623;
                                              if (while_flag_1616) {
                                                uint8_t id_1624 { 0 };
                                                uint8_t id_1625 { 0 };
                                                uint32_t id_1626 { lebsz_ref_697[id_1625] };
                                                uint32_t id_1627 { 1U };
                                                uint32_t id_1628 { uint32_t(id_1626 + id_1627) };
                                                Void id_1629 { ((void)(lebsz_ref_697[id_1624] = id_1628), ::dessser::VOID) };
                                                (void)id_1629;
                                              }
                                            } while (while_flag_1616);
                                            (void)::dessser::VOID;
                                            uint8_t id_1630 { 0 };
                                            uint32_t id_1631 { lebsz_ref_697[id_1630] };
                                            Size id_1632 { Size(id_1631) };
                                            let_res_1615 = id_1632;
                                          }
                                          let_res_1612 = let_res_1615;
                                        }
                                        ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_1633 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_1634 { std::get<1>(id_1633) };
                                        std::string id_1635 { std::get<0 /* Contacts */>(id_1634) };
                                        uint32_t id_1636 { (uint32_t)id_1635.size() };
                                        Size id_1637 { Size(id_1636) };
                                        Size id_1638 { Size(let_res_1612 + id_1637) };
                                        Size id_1639 { Size(id_1606 + id_1638) };
                                        choose_res_1604 = id_1639;
                                      } else {
                                        ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_1640 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_1641 { std::get<1>(id_1640) };
                                        uint16_t id_1642 { uint16_t(id_1641.index()) };
                                        uint16_t id_1643 { 1 };
                                        bool id_1644 { bool(id_1642 == id_1643) };
                                        Void id_1645 { ((void)(assert(id_1644)), ::dessser::VOID) };
                                        (void)id_1645;
                                        Size id_1646 { 2UL };
                                        Size id_1647 { Size(sz_690 + id_1646) };
                                        ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_1648 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_1649 { std::get<1>(id_1648) };
                                        std::string id_1650 { std::get<1 /* Inhibition */>(id_1649) };
                                        uint32_t id_1651 { (uint32_t)id_1650.size() };
                                        Vec<1, uint32_t> id_1652 {  id_1651  };
                                        Size let_res_1653;
                                        {
                                          Vec<1, uint32_t> n_ref_693 { id_1652 };
                                          uint32_t id_1654 { 1U };
                                          Vec<1, uint32_t> id_1655 {  id_1654  };
                                          Size let_res_1656;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_694 { id_1655 };
                                            bool while_flag_1657 { true };
                                            do {
                                              uint8_t id_1658 { 0 };
                                              uint32_t id_1659 { n_ref_693[id_1658] };
                                              uint8_t id_1660 { 0 };
                                              uint32_t id_1661 { lebsz_ref_694[id_1660] };
                                              uint8_t id_1662 { 7 };
                                              uint32_t id_1663 { uint32_t(id_1661 << id_1662) };
                                              bool id_1664 { bool(id_1659 >= id_1663) };
                                              while_flag_1657 = id_1664;
                                              if (while_flag_1657) {
                                                uint8_t id_1665 { 0 };
                                                uint8_t id_1666 { 0 };
                                                uint32_t id_1667 { lebsz_ref_694[id_1666] };
                                                uint32_t id_1668 { 1U };
                                                uint32_t id_1669 { uint32_t(id_1667 + id_1668) };
                                                Void id_1670 { ((void)(lebsz_ref_694[id_1665] = id_1669), ::dessser::VOID) };
                                                (void)id_1670;
                                              }
                                            } while (while_flag_1657);
                                            (void)::dessser::VOID;
                                            uint8_t id_1671 { 0 };
                                            uint32_t id_1672 { lebsz_ref_694[id_1671] };
                                            Size id_1673 { Size(id_1672) };
                                            let_res_1656 = id_1673;
                                          }
                                          let_res_1653 = let_res_1656;
                                        }
                                        ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_1674 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_1675 { std::get<1>(id_1674) };
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
                                    bool id_1682 { bool(label2_674 == id_1681) };
                                    Void id_1683 { ((void)(assert(id_1682)), ::dessser::VOID) };
                                    (void)id_1683;
                                    Size id_1684 { 2UL };
                                    ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_1685 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1686 { std::get<0>(id_1685) };
                                    uint32_t id_1687 { (uint32_t)id_1686.size() };
                                    Vec<1, uint32_t> id_1688 {  id_1687  };
                                    Size let_res_1689;
                                    {
                                      Vec<1, uint32_t> n_ref_677 { id_1688 };
                                      uint32_t id_1690 { 1U };
                                      Vec<1, uint32_t> id_1691 {  id_1690  };
                                      Size let_res_1692;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_678 { id_1691 };
                                        bool while_flag_1693 { true };
                                        do {
                                          uint8_t id_1694 { 0 };
                                          uint32_t id_1695 { n_ref_677[id_1694] };
                                          uint8_t id_1696 { 0 };
                                          uint32_t id_1697 { lebsz_ref_678[id_1696] };
                                          uint8_t id_1698 { 7 };
                                          uint32_t id_1699 { uint32_t(id_1697 << id_1698) };
                                          bool id_1700 { bool(id_1695 >= id_1699) };
                                          while_flag_1693 = id_1700;
                                          if (while_flag_1693) {
                                            uint8_t id_1701 { 0 };
                                            uint8_t id_1702 { 0 };
                                            uint32_t id_1703 { lebsz_ref_678[id_1702] };
                                            uint32_t id_1704 { 1U };
                                            uint32_t id_1705 { uint32_t(id_1703 + id_1704) };
                                            Void id_1706 { ((void)(lebsz_ref_678[id_1701] = id_1705), ::dessser::VOID) };
                                            (void)id_1706;
                                          }
                                        } while (while_flag_1693);
                                        (void)::dessser::VOID;
                                        uint8_t id_1707 { 0 };
                                        uint32_t id_1708 { lebsz_ref_678[id_1707] };
                                        Size id_1709 { Size(id_1708) };
                                        let_res_1692 = id_1709;
                                      }
                                      let_res_1689 = let_res_1692;
                                    }
                                    ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_1710 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1711 { std::get<0>(id_1710) };
                                    uint32_t id_1712 { (uint32_t)id_1711.size() };
                                    Size id_1713 { Size(id_1712) };
                                    Size id_1714 { Size(let_res_1689 + id_1713) };
                                    Size id_1715 { Size(id_1684 + id_1714) };
                                    Size let_res_1716;
                                    {
                                      Size sz_679 { id_1715 };
                                      ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_1717 { std::get<15 /* Incidents */>((*p_0)) };
                                      ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_1718 { std::get<1>(id_1717) };
                                      uint16_t id_1719 { uint16_t(id_1718.index()) };
                                      Size let_res_1720;
                                      {
                                        uint16_t label2_680 { id_1719 };
                                        uint16_t id_1721 { 0 };
                                        bool id_1722 { bool(id_1721 == label2_680) };
                                        Size choose_res_1723;
                                        if (id_1722) {
                                          Size id_1724 { 2UL };
                                          Size id_1725 { Size(sz_679 + id_1724) };
                                          choose_res_1723 = id_1725;
                                        } else {
                                          uint16_t id_1726 { 1 };
                                          bool id_1727 { bool(id_1726 == label2_680) };
                                          Size choose_res_1728;
                                          if (id_1727) {
                                            Size id_1729 { 2UL };
                                            Size id_1730 { Size(sz_679 + id_1729) };
                                            choose_res_1728 = id_1730;
                                          } else {
                                            uint16_t id_1731 { 2 };
                                            bool id_1732 { bool(id_1731 == label2_680) };
                                            Size choose_res_1733;
                                            if (id_1732) {
                                              Size id_1734 { 2UL };
                                              Size id_1735 { Size(sz_679 + id_1734) };
                                              choose_res_1733 = id_1735;
                                            } else {
                                              uint16_t id_1736 { 3 };
                                              bool id_1737 { bool(id_1736 == label2_680) };
                                              Size choose_res_1738;
                                              if (id_1737) {
                                                Size id_1739 { 2UL };
                                                Size id_1740 { Size(sz_679 + id_1739) };
                                                choose_res_1738 = id_1740;
                                              } else {
                                                uint16_t id_1741 { 4 };
                                                bool id_1742 { bool(id_1741 == label2_680) };
                                                Size choose_res_1743;
                                                if (id_1742) {
                                                  Size id_1744 { 2UL };
                                                  Size id_1745 { Size(sz_679 + id_1744) };
                                                  choose_res_1743 = id_1745;
                                                } else {
                                                  uint16_t id_1746 { 5 };
                                                  bool id_1747 { bool(id_1746 == label2_680) };
                                                  Size choose_res_1748;
                                                  if (id_1747) {
                                                    Size id_1749 { 2UL };
                                                    Size id_1750 { Size(sz_679 + id_1749) };
                                                    ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_1751 { std::get<15 /* Incidents */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_1752 { std::get<1>(id_1751) };
                                                    ::dessser::gen::sync_key::t8790f8724a8266402c08dc86b40c110a id_1753 { std::get<5 /* Dialogs */>(id_1752) };
                                                    std::string id_1754 { std::get<0>(id_1753) };
                                                    uint32_t id_1755 { (uint32_t)id_1754.size() };
                                                    Vec<1, uint32_t> id_1756 {  id_1755  };
                                                    Size let_res_1757;
                                                    {
                                                      Vec<1, uint32_t> n_ref_685 { id_1756 };
                                                      uint32_t id_1758 { 1U };
                                                      Vec<1, uint32_t> id_1759 {  id_1758  };
                                                      Size let_res_1760;
                                                      {
                                                        Vec<1, uint32_t> lebsz_ref_686 { id_1759 };
                                                        bool while_flag_1761 { true };
                                                        do {
                                                          uint8_t id_1762 { 0 };
                                                          uint32_t id_1763 { n_ref_685[id_1762] };
                                                          uint8_t id_1764 { 0 };
                                                          uint32_t id_1765 { lebsz_ref_686[id_1764] };
                                                          uint8_t id_1766 { 7 };
                                                          uint32_t id_1767 { uint32_t(id_1765 << id_1766) };
                                                          bool id_1768 { bool(id_1763 >= id_1767) };
                                                          while_flag_1761 = id_1768;
                                                          if (while_flag_1761) {
                                                            uint8_t id_1769 { 0 };
                                                            uint8_t id_1770 { 0 };
                                                            uint32_t id_1771 { lebsz_ref_686[id_1770] };
                                                            uint32_t id_1772 { 1U };
                                                            uint32_t id_1773 { uint32_t(id_1771 + id_1772) };
                                                            Void id_1774 { ((void)(lebsz_ref_686[id_1769] = id_1773), ::dessser::VOID) };
                                                            (void)id_1774;
                                                          }
                                                        } while (while_flag_1761);
                                                        (void)::dessser::VOID;
                                                        uint8_t id_1775 { 0 };
                                                        uint32_t id_1776 { lebsz_ref_686[id_1775] };
                                                        Size id_1777 { Size(id_1776) };
                                                        let_res_1760 = id_1777;
                                                      }
                                                      let_res_1757 = let_res_1760;
                                                    }
                                                    ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_1778 { std::get<15 /* Incidents */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_1779 { std::get<1>(id_1778) };
                                                    ::dessser::gen::sync_key::t8790f8724a8266402c08dc86b40c110a id_1780 { std::get<5 /* Dialogs */>(id_1779) };
                                                    std::string id_1781 { std::get<0>(id_1780) };
                                                    uint32_t id_1782 { (uint32_t)id_1781.size() };
                                                    Size id_1783 { Size(id_1782) };
                                                    Size id_1784 { Size(let_res_1757 + id_1783) };
                                                    Size id_1785 { Size(id_1750 + id_1784) };
                                                    Size let_res_1786;
                                                    {
                                                      Size sz_687 { id_1785 };
                                                      ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_1787 { std::get<15 /* Incidents */>((*p_0)) };
                                                      ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_1788 { std::get<1>(id_1787) };
                                                      ::dessser::gen::sync_key::t8790f8724a8266402c08dc86b40c110a id_1789 { std::get<5 /* Dialogs */>(id_1788) };
                                                      ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a id_1790 { std::get<1>(id_1789) };
                                                      uint16_t id_1791 { uint16_t(id_1790.index()) };
                                                      Size let_res_1792;
                                                      {
                                                        uint16_t label2_688 { id_1791 };
                                                        uint16_t id_1793 { 0 };
                                                        bool id_1794 { bool(id_1793 == label2_688) };
                                                        Size choose_res_1795;
                                                        if (id_1794) {
                                                          Size id_1796 { 2UL };
                                                          Size id_1797 { Size(sz_687 + id_1796) };
                                                          choose_res_1795 = id_1797;
                                                        } else {
                                                          uint16_t id_1798 { 1 };
                                                          bool id_1799 { bool(id_1798 == label2_688) };
                                                          Size choose_res_1800;
                                                          if (id_1799) {
                                                            Size id_1801 { 2UL };
                                                            Size id_1802 { Size(sz_687 + id_1801) };
                                                            choose_res_1800 = id_1802;
                                                          } else {
                                                            uint16_t id_1803 { 2 };
                                                            bool id_1804 { bool(id_1803 == label2_688) };
                                                            Size choose_res_1805;
                                                            if (id_1804) {
                                                              Size id_1806 { 2UL };
                                                              Size id_1807 { Size(sz_687 + id_1806) };
                                                              choose_res_1805 = id_1807;
                                                            } else {
                                                              uint16_t id_1808 { 3 };
                                                              bool id_1809 { bool(id_1808 == label2_688) };
                                                              Size choose_res_1810;
                                                              if (id_1809) {
                                                                Size id_1811 { 2UL };
                                                                Size id_1812 { Size(sz_687 + id_1811) };
                                                                choose_res_1810 = id_1812;
                                                              } else {
                                                                uint16_t id_1813 { 4 };
                                                                bool id_1814 { bool(id_1813 == label2_688) };
                                                                Size choose_res_1815;
                                                                if (id_1814) {
                                                                  Size id_1816 { 2UL };
                                                                  Size id_1817 { Size(sz_687 + id_1816) };
                                                                  choose_res_1815 = id_1817;
                                                                } else {
                                                                  uint16_t id_1818 { 5 };
                                                                  bool id_1819 { bool(id_1818 == label2_688) };
                                                                  Size choose_res_1820;
                                                                  if (id_1819) {
                                                                    Size id_1821 { 2UL };
                                                                    Size id_1822 { Size(sz_687 + id_1821) };
                                                                    choose_res_1820 = id_1822;
                                                                  } else {
                                                                    uint16_t id_1823 { 6 };
                                                                    bool id_1824 { bool(label2_688 == id_1823) };
                                                                    Void id_1825 { ((void)(assert(id_1824)), ::dessser::VOID) };
                                                                    (void)id_1825;
                                                                    Size id_1826 { 2UL };
                                                                    Size id_1827 { Size(sz_687 + id_1826) };
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
                                                    bool id_1829 { bool(label2_680 == id_1828) };
                                                    Void id_1830 { ((void)(assert(id_1829)), ::dessser::VOID) };
                                                    (void)id_1830;
                                                    Size id_1831 { 2UL };
                                                    Size id_1832 { Size(sz_679 + id_1831) };
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
      (let "dsum1_278" (let-pair "du16_fst_273" "du16_snd_274" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_273") (identifier "du16_snd_274")))
        (let-pair "dsum1_fst_279" "dsum1_snd_280" (identifier "dsum1_278")
          (seq (assert (eq (identifier "dsum1_fst_279") (u16 0)))
            (let-pair "du32_fst_282" "du32_snd_283" (read-u32 little-endian (identifier "dsum1_snd_280")) (make-tup (construct "[Widgets U32]" 0 (identifier "du32_fst_282")) (identifier "du32_snd_283")))))))
 */
static std::function<::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713(Pointer)> per_dash_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713(Pointer)> fun1837 { [&fun1837](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1838 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1839;
    {
      auto du16_fst_273 { std::get<0>(id_1838) };
      auto du16_snd_274 { std::get<1>(id_1838) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1840 { du16_fst_273, du16_snd_274 };
      letpair_res_1839 = id_1840;
    }
    ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 let_res_1841;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_278 { letpair_res_1839 };
      ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 letpair_res_1842;
      {
        auto dsum1_fst_279 { std::get<0>(dsum1_278) };
        auto dsum1_snd_280 { std::get<1>(dsum1_278) };
        uint16_t id_1843 { 0 };
        bool id_1844 { bool(dsum1_fst_279 == id_1843) };
        Void id_1845 { ((void)(assert(id_1844)), ::dessser::VOID) };
        (void)id_1845;
        ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_1846 { dsum1_snd_280.readU32Le() };
        ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 letpair_res_1847;
        {
          auto du32_fst_282 { std::get<0>(id_1846) };
          auto du32_snd_283 { std::get<1>(id_1846) };
          std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1848 { std::make_shared<::dessser::gen::sync_key::per_dash_key>(std::in_place_index<0>, du32_fst_282) };
          ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 id_1849 { id_1848, du32_snd_283 };
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
  std::function<::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796(Pointer)> fun1850 { [&fun1850](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1851 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1852;
    {
      auto du16_fst_288 { std::get<0>(id_1851) };
      auto du16_snd_289 { std::get<1>(id_1851) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1853 { du16_fst_288, du16_snd_289 };
      letpair_res_1852 = id_1853;
    }
    ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 let_res_1854;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_293 { letpair_res_1852 };
      ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 letpair_res_1855;
      {
        auto dsum1_fst_294 { std::get<0>(dsum1_293) };
        auto dsum1_snd_295 { std::get<1>(dsum1_293) };
        uint16_t id_1856 { 0 };
        bool id_1857 { bool(id_1856 == dsum1_fst_294) };
        ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 choose_res_1858;
        if (id_1857) {
          uint32_t id_1859 { 0U };
          Vec<1, uint32_t> id_1860 {  id_1859  };
          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1861;
          {
            Vec<1, uint32_t> leb_ref_299 { id_1860 };
            uint8_t id_1862 { 0 };
            Vec<1, uint8_t> id_1863 {  id_1862  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1864;
            {
              Vec<1, uint8_t> shft_ref_300 { id_1863 };
              Vec<1, Pointer> id_1865 {  dsum1_snd_295  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1866;
              {
                Vec<1, Pointer> p_ref_301 { id_1865 };
                bool while_flag_1867 { true };
                do {
                  uint8_t id_1868 { 0 };
                  Pointer id_1869 { p_ref_301[id_1868] };
                  ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_1870 { id_1869.readU8() };
                  bool let_res_1871;
                  {
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_302 { id_1870 };
                    bool letpair_res_1872;
                    {
                      auto leb128_fst_303 { std::get<0>(leb128_302) };
                      auto leb128_snd_304 { std::get<1>(leb128_302) };
                      uint8_t id_1873 { 0 };
                      Void id_1874 { ((void)(p_ref_301[id_1873] = leb128_snd_304), ::dessser::VOID) };
                      (void)id_1874;
                      uint8_t id_1875 { 0 };
                      uint8_t id_1876 { 127 };
                      uint8_t id_1877 { uint8_t(leb128_fst_303 & id_1876) };
                      uint32_t id_1878 { uint32_t(id_1877) };
                      uint8_t id_1879 { 0 };
                      uint8_t id_1880 { shft_ref_300[id_1879] };
                      uint32_t id_1881 { uint32_t(id_1878 << id_1880) };
                      uint8_t id_1882 { 0 };
                      uint32_t id_1883 { leb_ref_299[id_1882] };
                      uint32_t id_1884 { uint32_t(id_1881 | id_1883) };
                      Void id_1885 { ((void)(leb_ref_299[id_1875] = id_1884), ::dessser::VOID) };
                      (void)id_1885;
                      uint8_t id_1886 { 0 };
                      uint8_t id_1887 { 0 };
                      uint8_t id_1888 { shft_ref_300[id_1887] };
                      uint8_t id_1889 { 7 };
                      uint8_t id_1890 { uint8_t(id_1888 + id_1889) };
                      Void id_1891 { ((void)(shft_ref_300[id_1886] = id_1890), ::dessser::VOID) };
                      (void)id_1891;
                      uint8_t id_1892 { 128 };
                      bool id_1893 { bool(leb128_fst_303 >= id_1892) };
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
                uint32_t id_1895 { leb_ref_299[id_1894] };
                Size id_1896 { Size(id_1895) };
                uint8_t id_1897 { 0 };
                Pointer id_1898 { p_ref_301[id_1897] };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_1899 { id_1896, id_1898 };
                let_res_1866 = id_1899;
              }
              let_res_1864 = let_res_1866;
            }
            let_res_1861 = let_res_1864;
          }
          ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 let_res_1900;
          {
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_305 { let_res_1861 };
            ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 letpair_res_1901;
            {
              auto dstring1_fst_306 { std::get<0>(dstring1_305) };
              auto dstring1_snd_307 { std::get<1>(dstring1_305) };
              ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_1902 { dstring1_snd_307.readBytes(dstring1_fst_306) };
              ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 letpair_res_1903;
              {
                auto dstring2_fst_309 { std::get<0>(id_1902) };
                auto dstring2_snd_310 { std::get<1>(id_1902) };
                std::string id_1904 { dstring2_fst_309.toString() };
                std::shared_ptr<::dessser::gen::sync_key::per_client>  id_1905 { std::make_shared<::dessser::gen::sync_key::per_client>(std::in_place_index<0>, id_1904) };
                ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 id_1906 { id_1905, dstring2_snd_310 };
                letpair_res_1903 = id_1906;
              }
              letpair_res_1901 = letpair_res_1903;
            }
            let_res_1900 = letpair_res_1901;
          }
          choose_res_1858 = let_res_1900;
        } else {
          uint16_t id_1907 { 1 };
          bool id_1908 { bool(dsum1_fst_294 == id_1907) };
          Void id_1909 { ((void)(assert(id_1908)), ::dessser::VOID) };
          (void)id_1909;
          ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 id_1910 { per_dash_key_of_row_binary(dsum1_snd_295) };
          ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 letpair_res_1911;
          {
            auto dsum2_fst_297 { std::get<0>(id_1910) };
            auto dsum2_snd_298 { std::get<1>(id_1910) };
            std::shared_ptr<::dessser::gen::sync_key::per_client>  id_1912 { std::make_shared<::dessser::gen::sync_key::per_client>(std::in_place_index<1>, dsum2_fst_297) };
            ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 id_1913 { id_1912, dsum2_snd_298 };
            letpair_res_1911 = id_1913;
          }
          choose_res_1858 = letpair_res_1911;
        }
        letpair_res_1855 = choose_res_1858;
      }
      let_res_1854 = letpair_res_1855;
    }
    return let_res_1854;
  }
   };
  return fun1850;
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
  std::function<::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e(Pointer)> fun1914 { [&fun1914](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1915 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1916;
    {
      auto du16_fst_243 { std::get<0>(id_1915) };
      auto du16_snd_244 { std::get<1>(id_1915) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1917 { du16_fst_243, du16_snd_244 };
      letpair_res_1916 = id_1917;
    }
    ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e let_res_1918;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_248 { letpair_res_1916 };
      ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e letpair_res_1919;
      {
        auto dsum1_fst_249 { std::get<0>(dsum1_248) };
        auto dsum1_snd_250 { std::get<1>(dsum1_248) };
        uint16_t id_1920 { 0 };
        bool id_1921 { bool(id_1920 == dsum1_fst_249) };
        ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e choose_res_1922;
        if (id_1921) {
          uint32_t id_1923 { 0U };
          Vec<1, uint32_t> id_1924 {  id_1923  };
          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1925;
          {
            Vec<1, uint32_t> leb_ref_257 { id_1924 };
            uint8_t id_1926 { 0 };
            Vec<1, uint8_t> id_1927 {  id_1926  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1928;
            {
              Vec<1, uint8_t> shft_ref_258 { id_1927 };
              Vec<1, Pointer> id_1929 {  dsum1_snd_250  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1930;
              {
                Vec<1, Pointer> p_ref_259 { id_1929 };
                bool while_flag_1931 { true };
                do {
                  uint8_t id_1932 { 0 };
                  Pointer id_1933 { p_ref_259[id_1932] };
                  ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_1934 { id_1933.readU8() };
                  bool let_res_1935;
                  {
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_260 { id_1934 };
                    bool letpair_res_1936;
                    {
                      auto leb128_fst_261 { std::get<0>(leb128_260) };
                      auto leb128_snd_262 { std::get<1>(leb128_260) };
                      uint8_t id_1937 { 0 };
                      Void id_1938 { ((void)(p_ref_259[id_1937] = leb128_snd_262), ::dessser::VOID) };
                      (void)id_1938;
                      uint8_t id_1939 { 0 };
                      uint8_t id_1940 { 127 };
                      uint8_t id_1941 { uint8_t(leb128_fst_261 & id_1940) };
                      uint32_t id_1942 { uint32_t(id_1941) };
                      uint8_t id_1943 { 0 };
                      uint8_t id_1944 { shft_ref_258[id_1943] };
                      uint32_t id_1945 { uint32_t(id_1942 << id_1944) };
                      uint8_t id_1946 { 0 };
                      uint32_t id_1947 { leb_ref_257[id_1946] };
                      uint32_t id_1948 { uint32_t(id_1945 | id_1947) };
                      Void id_1949 { ((void)(leb_ref_257[id_1939] = id_1948), ::dessser::VOID) };
                      (void)id_1949;
                      uint8_t id_1950 { 0 };
                      uint8_t id_1951 { 0 };
                      uint8_t id_1952 { shft_ref_258[id_1951] };
                      uint8_t id_1953 { 7 };
                      uint8_t id_1954 { uint8_t(id_1952 + id_1953) };
                      Void id_1955 { ((void)(shft_ref_258[id_1950] = id_1954), ::dessser::VOID) };
                      (void)id_1955;
                      uint8_t id_1956 { 128 };
                      bool id_1957 { bool(leb128_fst_261 >= id_1956) };
                      letpair_res_1936 = id_1957;
                    }
                    let_res_1935 = letpair_res_1936;
                  }
                  while_flag_1931 = let_res_1935;
                  if (while_flag_1931) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_1931);
                (void)::dessser::VOID;
                uint8_t id_1958 { 0 };
                uint32_t id_1959 { leb_ref_257[id_1958] };
                Size id_1960 { Size(id_1959) };
                uint8_t id_1961 { 0 };
                Pointer id_1962 { p_ref_259[id_1961] };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_1963 { id_1960, id_1962 };
                let_res_1930 = id_1963;
              }
              let_res_1928 = let_res_1930;
            }
            let_res_1925 = let_res_1928;
          }
          ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e let_res_1964;
          {
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_263 { let_res_1925 };
            ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e letpair_res_1965;
            {
              auto dstring1_fst_264 { std::get<0>(dstring1_263) };
              auto dstring1_snd_265 { std::get<1>(dstring1_263) };
              ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_1966 { dstring1_snd_265.readBytes(dstring1_fst_264) };
              ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e letpair_res_1967;
              {
                auto dstring2_fst_267 { std::get<0>(id_1966) };
                auto dstring2_snd_268 { std::get<1>(id_1966) };
                std::string id_1968 { dstring2_fst_267.toString() };
                std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_1969 { std::make_shared<::dessser::gen::sync_key::per_tail>(std::in_place_index<0>, id_1968) };
                ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e id_1970 { id_1969, dstring2_snd_268 };
                letpair_res_1967 = id_1970;
              }
              letpair_res_1965 = letpair_res_1967;
            }
            let_res_1964 = letpair_res_1965;
          }
          choose_res_1922 = let_res_1964;
        } else {
          uint16_t id_1971 { 1 };
          bool id_1972 { bool(dsum1_fst_249 == id_1971) };
          Void id_1973 { ((void)(assert(id_1972)), ::dessser::VOID) };
          (void)id_1973;
          ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_1974 { dsum1_snd_250.readU32Le() };
          ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e letpair_res_1975;
          {
            auto du32_fst_252 { std::get<0>(id_1974) };
            auto du32_snd_253 { std::get<1>(id_1974) };
            std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_1976 { std::make_shared<::dessser::gen::sync_key::per_tail>(std::in_place_index<1>, du32_fst_252) };
            ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e id_1977 { id_1976, du32_snd_253 };
            letpair_res_1975 = id_1977;
          }
          choose_res_1922 = letpair_res_1975;
        }
        letpair_res_1919 = choose_res_1922;
      }
      let_res_1918 = letpair_res_1919;
    }
    return let_res_1918;
  }
   };
  return fun1914;
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
  std::function<::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049(Pointer)> fun1978 { [&fun1978](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1979 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1980;
    {
      auto du16_fst_57 { std::get<0>(id_1979) };
      auto du16_snd_58 { std::get<1>(id_1979) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1981 { du16_fst_57, du16_snd_58 };
      letpair_res_1980 = id_1981;
    }
    ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 let_res_1982;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_62 { letpair_res_1980 };
      ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 letpair_res_1983;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_1984 { 0 };
        bool id_1985 { bool(id_1984 == dsum1_fst_63) };
        ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_1986;
        if (id_1985) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_1987 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_1988 { id_1987, dsum1_snd_64 };
          choose_res_1986 = id_1988;
        } else {
          uint16_t id_1989 { 1 };
          bool id_1990 { bool(id_1989 == dsum1_fst_63) };
          ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_1991;
          if (id_1990) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_1992 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_1993 { id_1992, dsum1_snd_64 };
            choose_res_1991 = id_1993;
          } else {
            uint16_t id_1994 { 2 };
            bool id_1995 { bool(id_1994 == dsum1_fst_63) };
            ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_1996;
            if (id_1995) {
              (void)::dessser::VOID;
              std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_1997 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<2>, ::dessser::VOID) };
              ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_1998 { id_1997, dsum1_snd_64 };
              choose_res_1996 = id_1998;
            } else {
              uint16_t id_1999 { 3 };
              bool id_2000 { bool(id_1999 == dsum1_fst_63) };
              ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2001;
              if (id_2000) {
                (void)::dessser::VOID;
                std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2002 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<3>, ::dessser::VOID) };
                ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2003 { id_2002, dsum1_snd_64 };
                choose_res_2001 = id_2003;
              } else {
                uint16_t id_2004 { 4 };
                bool id_2005 { bool(id_2004 == dsum1_fst_63) };
                ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2006;
                if (id_2005) {
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2007 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<4>, ::dessser::VOID) };
                  ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2008 { id_2007, dsum1_snd_64 };
                  choose_res_2006 = id_2008;
                } else {
                  uint16_t id_2009 { 5 };
                  bool id_2010 { bool(id_2009 == dsum1_fst_63) };
                  ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2011;
                  if (id_2010) {
                    (void)::dessser::VOID;
                    std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2012 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<5>, ::dessser::VOID) };
                    ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2013 { id_2012, dsum1_snd_64 };
                    choose_res_2011 = id_2013;
                  } else {
                    uint16_t id_2014 { 6 };
                    bool id_2015 { bool(id_2014 == dsum1_fst_63) };
                    ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2016;
                    if (id_2015) {
                      uint32_t id_2017 { 0U };
                      Vec<1, uint32_t> id_2018 {  id_2017  };
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2019;
                      {
                        Vec<1, uint32_t> leb_ref_74 { id_2018 };
                        uint8_t id_2020 { 0 };
                        Vec<1, uint8_t> id_2021 {  id_2020  };
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2022;
                        {
                          Vec<1, uint8_t> shft_ref_75 { id_2021 };
                          Vec<1, Pointer> id_2023 {  dsum1_snd_64  };
                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2024;
                          {
                            Vec<1, Pointer> p_ref_76 { id_2023 };
                            bool while_flag_2025 { true };
                            do {
                              uint8_t id_2026 { 0 };
                              Pointer id_2027 { p_ref_76[id_2026] };
                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2028 { id_2027.readU8() };
                              bool let_res_2029;
                              {
                                ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_77 { id_2028 };
                                bool letpair_res_2030;
                                {
                                  auto leb128_fst_78 { std::get<0>(leb128_77) };
                                  auto leb128_snd_79 { std::get<1>(leb128_77) };
                                  uint8_t id_2031 { 0 };
                                  Void id_2032 { ((void)(p_ref_76[id_2031] = leb128_snd_79), ::dessser::VOID) };
                                  (void)id_2032;
                                  uint8_t id_2033 { 0 };
                                  uint8_t id_2034 { 127 };
                                  uint8_t id_2035 { uint8_t(leb128_fst_78 & id_2034) };
                                  uint32_t id_2036 { uint32_t(id_2035) };
                                  uint8_t id_2037 { 0 };
                                  uint8_t id_2038 { shft_ref_75[id_2037] };
                                  uint32_t id_2039 { uint32_t(id_2036 << id_2038) };
                                  uint8_t id_2040 { 0 };
                                  uint32_t id_2041 { leb_ref_74[id_2040] };
                                  uint32_t id_2042 { uint32_t(id_2039 | id_2041) };
                                  Void id_2043 { ((void)(leb_ref_74[id_2033] = id_2042), ::dessser::VOID) };
                                  (void)id_2043;
                                  uint8_t id_2044 { 0 };
                                  uint8_t id_2045 { 0 };
                                  uint8_t id_2046 { shft_ref_75[id_2045] };
                                  uint8_t id_2047 { 7 };
                                  uint8_t id_2048 { uint8_t(id_2046 + id_2047) };
                                  Void id_2049 { ((void)(shft_ref_75[id_2044] = id_2048), ::dessser::VOID) };
                                  (void)id_2049;
                                  uint8_t id_2050 { 128 };
                                  bool id_2051 { bool(leb128_fst_78 >= id_2050) };
                                  letpair_res_2030 = id_2051;
                                }
                                let_res_2029 = letpair_res_2030;
                              }
                              while_flag_2025 = let_res_2029;
                              if (while_flag_2025) {
                                (void)::dessser::VOID;
                              }
                            } while (while_flag_2025);
                            (void)::dessser::VOID;
                            uint8_t id_2052 { 0 };
                            uint32_t id_2053 { leb_ref_74[id_2052] };
                            Size id_2054 { Size(id_2053) };
                            uint8_t id_2055 { 0 };
                            Pointer id_2056 { p_ref_76[id_2055] };
                            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2057 { id_2054, id_2056 };
                            let_res_2024 = id_2057;
                          }
                          let_res_2022 = let_res_2024;
                        }
                        let_res_2019 = let_res_2022;
                      }
                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2058;
                      {
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_80 { let_res_2019 };
                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2059;
                        {
                          auto dstring1_fst_81 { std::get<0>(dstring1_80) };
                          auto dstring1_snd_82 { std::get<1>(dstring1_80) };
                          ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2060 { dstring1_snd_82.readBytes(dstring1_fst_81) };
                          ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2061;
                          {
                            auto dstring2_fst_84 { std::get<0>(id_2060) };
                            auto dstring2_snd_85 { std::get<1>(id_2060) };
                            std::string id_2062 { dstring2_fst_84.toString() };
                            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2063 { id_2062, dstring2_snd_85 };
                            letpair_res_2061 = id_2063;
                          }
                          letpair_res_2059 = letpair_res_2061;
                        }
                        let_res_2058 = letpair_res_2059;
                      }
                      ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 let_res_2064;
                      {
                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_86 { let_res_2058 };
                        ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 letpair_res_2065;
                        {
                          auto dtup_fst_87 { std::get<0>(dtup_86) };
                          auto dtup_snd_88 { std::get<1>(dtup_86) };
                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2066 { dtup_snd_88.readU16Le() };
                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2067;
                          {
                            auto du16_fst_90 { std::get<0>(id_2066) };
                            auto du16_snd_91 { std::get<1>(id_2066) };
                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2068 { du16_fst_90, du16_snd_91 };
                            letpair_res_2067 = id_2068;
                          }
                          ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 let_res_2069;
                          {
                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_95 { letpair_res_2067 };
                            ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 letpair_res_2070;
                            {
                              auto dsum1_fst_96 { std::get<0>(dsum1_95) };
                              auto dsum1_snd_97 { std::get<1>(dsum1_95) };
                              uint16_t id_2071 { 0 };
                              bool id_2072 { bool(id_2071 == dsum1_fst_96) };
                              ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 choose_res_2073;
                              if (id_2072) {
                                (void)::dessser::VOID;
                                ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c id_2074 { std::in_place_index<0>, ::dessser::VOID };
                                ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 id_2075 { id_2074, dsum1_snd_97 };
                                choose_res_2073 = id_2075;
                              } else {
                                uint16_t id_2076 { 1 };
                                bool id_2077 { bool(id_2076 == dsum1_fst_96) };
                                ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 choose_res_2078;
                                if (id_2077) {
                                  (void)::dessser::VOID;
                                  ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c id_2079 { std::in_place_index<1>, ::dessser::VOID };
                                  ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 id_2080 { id_2079, dsum1_snd_97 };
                                  choose_res_2078 = id_2080;
                                } else {
                                  uint16_t id_2081 { 2 };
                                  bool id_2082 { bool(id_2081 == dsum1_fst_96) };
                                  ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 choose_res_2083;
                                  if (id_2082) {
                                    (void)::dessser::VOID;
                                    ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c id_2084 { std::in_place_index<2>, ::dessser::VOID };
                                    ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 id_2085 { id_2084, dsum1_snd_97 };
                                    choose_res_2083 = id_2085;
                                  } else {
                                    uint16_t id_2086 { 3 };
                                    bool id_2087 { bool(id_2086 == dsum1_fst_96) };
                                    ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 choose_res_2088;
                                    if (id_2087) {
                                      (void)::dessser::VOID;
                                      ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c id_2089 { std::in_place_index<3>, ::dessser::VOID };
                                      ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 id_2090 { id_2089, dsum1_snd_97 };
                                      choose_res_2088 = id_2090;
                                    } else {
                                      uint16_t id_2091 { 4 };
                                      bool id_2092 { bool(id_2091 == dsum1_fst_96) };
                                      ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 choose_res_2093;
                                      if (id_2092) {
                                        (void)::dessser::VOID;
                                        ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c id_2094 { std::in_place_index<4>, ::dessser::VOID };
                                        ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 id_2095 { id_2094, dsum1_snd_97 };
                                        choose_res_2093 = id_2095;
                                      } else {
                                        uint16_t id_2096 { 5 };
                                        bool id_2097 { bool(id_2096 == dsum1_fst_96) };
                                        ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 choose_res_2098;
                                        if (id_2097) {
                                          (void)::dessser::VOID;
                                          ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c id_2099 { std::in_place_index<5>, ::dessser::VOID };
                                          ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 id_2100 { id_2099, dsum1_snd_97 };
                                          choose_res_2098 = id_2100;
                                        } else {
                                          uint16_t id_2101 { 6 };
                                          bool id_2102 { bool(id_2101 == dsum1_fst_96) };
                                          ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 choose_res_2103;
                                          if (id_2102) {
                                            (void)::dessser::VOID;
                                            ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c id_2104 { std::in_place_index<6>, ::dessser::VOID };
                                            ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 id_2105 { id_2104, dsum1_snd_97 };
                                            choose_res_2103 = id_2105;
                                          } else {
                                            uint16_t id_2106 { 7 };
                                            bool id_2107 { bool(dsum1_fst_96 == id_2106) };
                                            Void id_2108 { ((void)(assert(id_2107)), ::dessser::VOID) };
                                            (void)id_2108;
                                            (void)::dessser::VOID;
                                            ::dessser::gen::sync_key::t0193f94945d5c55637b2beab1e77dc5c id_2109 { std::in_place_index<7>, ::dessser::VOID };
                                            ::dessser::gen::sync_key::tc8853f3e8e540f5b422cf8f39096e477 id_2110 { id_2109, dsum1_snd_97 };
                                            choose_res_2103 = id_2110;
                                          }
                                          choose_res_2098 = choose_res_2103;
                                        }
                                        choose_res_2093 = choose_res_2098;
                                      }
                                      choose_res_2088 = choose_res_2093;
                                    }
                                    choose_res_2083 = choose_res_2088;
                                  }
                                  choose_res_2078 = choose_res_2083;
                                }
                                choose_res_2073 = choose_res_2078;
                              }
                              letpair_res_2070 = choose_res_2073;
                            }
                            let_res_2069 = letpair_res_2070;
                          }
                          ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 letpair_res_2111;
                          {
                            auto dtup_fst_123 { std::get<0>(let_res_2069) };
                            auto dtup_snd_124 { std::get<1>(let_res_2069) };
                            ::dessser::gen::sync_key::t21e5dc291e02ff6b92981a2d2fa864dc id_2112 { dtup_fst_87, dtup_fst_123 };
                            std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2113 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<6>, id_2112) };
                            ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2114 { id_2113, dtup_snd_124 };
                            letpair_res_2111 = id_2114;
                          }
                          letpair_res_2065 = letpair_res_2111;
                        }
                        let_res_2064 = letpair_res_2065;
                      }
                      choose_res_2016 = let_res_2064;
                    } else {
                      uint16_t id_2115 { 7 };
                      bool id_2116 { bool(id_2115 == dsum1_fst_63) };
                      ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2117;
                      if (id_2116) {
                        ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_2118 { dsum1_snd_64.readU32Le() };
                        ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 letpair_res_2119;
                        {
                          auto du32_fst_69 { std::get<0>(id_2118) };
                          auto du32_snd_70 { std::get<1>(id_2118) };
                          std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2120 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<7>, du32_fst_69) };
                          ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2121 { id_2120, du32_snd_70 };
                          letpair_res_2119 = id_2121;
                        }
                        choose_res_2117 = letpair_res_2119;
                      } else {
                        uint16_t id_2122 { 8 };
                        bool id_2123 { bool(dsum1_fst_63 == id_2122) };
                        Void id_2124 { ((void)(assert(id_2123)), ::dessser::VOID) };
                        (void)id_2124;
                        (void)::dessser::VOID;
                        std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2125 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<8>, ::dessser::VOID) };
                        ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2126 { id_2125, dsum1_snd_64 };
                        choose_res_2117 = id_2126;
                      }
                      choose_res_2016 = choose_res_2117;
                    }
                    choose_res_2011 = choose_res_2016;
                  }
                  choose_res_2006 = choose_res_2011;
                }
                choose_res_2001 = choose_res_2006;
              }
              choose_res_1996 = choose_res_2001;
            }
            choose_res_1991 = choose_res_1996;
          }
          choose_res_1986 = choose_res_1991;
        }
        letpair_res_1983 = choose_res_1986;
      }
      let_res_1982 = letpair_res_1983;
    }
    return let_res_1982;
  }
   };
  return fun1978;
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
  std::function<::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5(Pointer)> fun2127 { [&fun2127](Pointer p_0) {
    auto fun2128 { dessser::gen::fq_name::of_row_binary };
    ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 id_2129 { fun2128(p_0) };
    ::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5 let_res_2130;
    {
      ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 dtup_146 { id_2129 };
      ::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5 letpair_res_2131;
      {
        auto dtup_fst_147 { std::get<0>(dtup_146) };
        auto dtup_snd_148 { std::get<1>(dtup_146) };
        ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2132 { per_worker_data_of_row_binary(dtup_snd_148) };
        ::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5 letpair_res_2133;
        {
          auto dtup_fst_150 { std::get<0>(id_2132) };
          auto dtup_snd_151 { std::get<1>(id_2132) };
          std::shared_ptr<::dessser::gen::sync_key::per_worker>  id_2134 { std::make_shared<::dessser::gen::sync_key::per_worker>(dtup_fst_147, dtup_fst_150) };
          ::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5 id_2135 { id_2134, dtup_snd_151 };
          letpair_res_2133 = id_2135;
        }
        letpair_res_2131 = letpair_res_2133;
      }
      let_res_2130 = letpair_res_2131;
    }
    return let_res_2130;
  }
   };
  return fun2127;
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
  std::function<::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab(Pointer)> fun2136 { [&fun2136](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2137 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2138;
    {
      auto du16_fst_153 { std::get<0>(id_2137) };
      auto du16_snd_154 { std::get<1>(id_2137) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2139 { du16_fst_153, du16_snd_154 };
      letpair_res_2138 = id_2139;
    }
    ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab let_res_2140;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_158 { letpair_res_2138 };
      ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2141;
      {
        auto dsum1_fst_159 { std::get<0>(dsum1_158) };
        auto dsum1_snd_160 { std::get<1>(dsum1_158) };
        uint16_t id_2142 { 0 };
        bool id_2143 { bool(id_2142 == dsum1_fst_159) };
        ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab choose_res_2144;
        if (id_2143) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2145 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab id_2146 { id_2145, dsum1_snd_160 };
          choose_res_2144 = id_2146;
        } else {
          uint16_t id_2147 { 1 };
          bool id_2148 { bool(id_2147 == dsum1_fst_159) };
          ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab choose_res_2149;
          if (id_2148) {
            uint32_t id_2150 { 0U };
            Vec<1, uint32_t> id_2151 {  id_2150  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2152;
            {
              Vec<1, uint32_t> leb_ref_197 { id_2151 };
              uint8_t id_2153 { 0 };
              Vec<1, uint8_t> id_2154 {  id_2153  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2155;
              {
                Vec<1, uint8_t> shft_ref_198 { id_2154 };
                Vec<1, Pointer> id_2156 {  dsum1_snd_160  };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2157;
                {
                  Vec<1, Pointer> p_ref_199 { id_2156 };
                  bool while_flag_2158 { true };
                  do {
                    uint8_t id_2159 { 0 };
                    Pointer id_2160 { p_ref_199[id_2159] };
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2161 { id_2160.readU8() };
                    bool let_res_2162;
                    {
                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_200 { id_2161 };
                      bool letpair_res_2163;
                      {
                        auto leb128_fst_201 { std::get<0>(leb128_200) };
                        auto leb128_snd_202 { std::get<1>(leb128_200) };
                        uint8_t id_2164 { 0 };
                        Void id_2165 { ((void)(p_ref_199[id_2164] = leb128_snd_202), ::dessser::VOID) };
                        (void)id_2165;
                        uint8_t id_2166 { 0 };
                        uint8_t id_2167 { 127 };
                        uint8_t id_2168 { uint8_t(leb128_fst_201 & id_2167) };
                        uint32_t id_2169 { uint32_t(id_2168) };
                        uint8_t id_2170 { 0 };
                        uint8_t id_2171 { shft_ref_198[id_2170] };
                        uint32_t id_2172 { uint32_t(id_2169 << id_2171) };
                        uint8_t id_2173 { 0 };
                        uint32_t id_2174 { leb_ref_197[id_2173] };
                        uint32_t id_2175 { uint32_t(id_2172 | id_2174) };
                        Void id_2176 { ((void)(leb_ref_197[id_2166] = id_2175), ::dessser::VOID) };
                        (void)id_2176;
                        uint8_t id_2177 { 0 };
                        uint8_t id_2178 { 0 };
                        uint8_t id_2179 { shft_ref_198[id_2178] };
                        uint8_t id_2180 { 7 };
                        uint8_t id_2181 { uint8_t(id_2179 + id_2180) };
                        Void id_2182 { ((void)(shft_ref_198[id_2177] = id_2181), ::dessser::VOID) };
                        (void)id_2182;
                        uint8_t id_2183 { 128 };
                        bool id_2184 { bool(leb128_fst_201 >= id_2183) };
                        letpair_res_2163 = id_2184;
                      }
                      let_res_2162 = letpair_res_2163;
                    }
                    while_flag_2158 = let_res_2162;
                    if (while_flag_2158) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_2158);
                  (void)::dessser::VOID;
                  uint8_t id_2185 { 0 };
                  uint32_t id_2186 { leb_ref_197[id_2185] };
                  Size id_2187 { Size(id_2186) };
                  uint8_t id_2188 { 0 };
                  Pointer id_2189 { p_ref_199[id_2188] };
                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2190 { id_2187, id_2189 };
                  let_res_2157 = id_2190;
                }
                let_res_2155 = let_res_2157;
              }
              let_res_2152 = let_res_2155;
            }
            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2191;
            {
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_203 { let_res_2152 };
              ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2192;
              {
                auto dstring1_fst_204 { std::get<0>(dstring1_203) };
                auto dstring1_snd_205 { std::get<1>(dstring1_203) };
                ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2193 { dstring1_snd_205.readBytes(dstring1_fst_204) };
                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2194;
                {
                  auto dstring2_fst_207 { std::get<0>(id_2193) };
                  auto dstring2_snd_208 { std::get<1>(id_2193) };
                  std::string id_2195 { dstring2_fst_207.toString() };
                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2196 { id_2195, dstring2_snd_208 };
                  letpair_res_2194 = id_2196;
                }
                letpair_res_2192 = letpair_res_2194;
              }
              let_res_2191 = letpair_res_2192;
            }
            ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab let_res_2197;
            {
              ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_209 { let_res_2191 };
              ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2198;
              {
                auto dtup_fst_210 { std::get<0>(dtup_209) };
                auto dtup_snd_211 { std::get<1>(dtup_209) };
                ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2199 { dtup_snd_211.readU16Le() };
                ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2200;
                {
                  auto du16_fst_213 { std::get<0>(id_2199) };
                  auto du16_snd_214 { std::get<1>(id_2199) };
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2201 { du16_fst_213, du16_snd_214 };
                  letpair_res_2200 = id_2201;
                }
                ::dessser::gen::sync_key::tf52fd12fa8c3e9d420341149b10f12af let_res_2202;
                {
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_218 { letpair_res_2200 };
                  ::dessser::gen::sync_key::tf52fd12fa8c3e9d420341149b10f12af letpair_res_2203;
                  {
                    auto dsum1_fst_219 { std::get<0>(dsum1_218) };
                    auto dsum1_snd_220 { std::get<1>(dsum1_218) };
                    uint16_t id_2204 { 0 };
                    bool id_2205 { bool(id_2204 == dsum1_fst_219) };
                    ::dessser::gen::sync_key::tf52fd12fa8c3e9d420341149b10f12af choose_res_2206;
                    if (id_2205) {
                      (void)::dessser::VOID;
                      ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c id_2207 { std::in_place_index<0>, ::dessser::VOID };
                      ::dessser::gen::sync_key::tf52fd12fa8c3e9d420341149b10f12af id_2208 { id_2207, dsum1_snd_220 };
                      choose_res_2206 = id_2208;
                    } else {
                      uint16_t id_2209 { 1 };
                      bool id_2210 { bool(dsum1_fst_219 == id_2209) };
                      Void id_2211 { ((void)(assert(id_2210)), ::dessser::VOID) };
                      (void)id_2211;
                      (void)::dessser::VOID;
                      ::dessser::gen::sync_key::t64f559dd09cb0d16d29224992777183c id_2212 { std::in_place_index<1>, ::dessser::VOID };
                      ::dessser::gen::sync_key::tf52fd12fa8c3e9d420341149b10f12af id_2213 { id_2212, dsum1_snd_220 };
                      choose_res_2206 = id_2213;
                    }
                    letpair_res_2203 = choose_res_2206;
                  }
                  let_res_2202 = letpair_res_2203;
                }
                ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2214;
                {
                  auto dtup_fst_228 { std::get<0>(let_res_2202) };
                  auto dtup_snd_229 { std::get<1>(let_res_2202) };
                  ::dessser::gen::sync_key::t9a3e45e6c9736129ff8eafaa89ab1b6a id_2215 { dtup_fst_210, dtup_fst_228 };
                  std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2216 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<1>, id_2215) };
                  ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab id_2217 { id_2216, dtup_snd_229 };
                  letpair_res_2214 = id_2217;
                }
                letpair_res_2198 = letpair_res_2214;
              }
              let_res_2197 = letpair_res_2198;
            }
            choose_res_2149 = let_res_2197;
          } else {
            uint16_t id_2218 { 2 };
            bool id_2219 { bool(id_2218 == dsum1_fst_159) };
            ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab choose_res_2220;
            if (id_2219) {
              ::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5 id_2221 { per_worker_of_row_binary(dsum1_snd_160) };
              ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2222;
              {
                auto dsum2_fst_195 { std::get<0>(id_2221) };
                auto dsum2_snd_196 { std::get<1>(id_2221) };
                std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2223 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<2>, dsum2_fst_195) };
                ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab id_2224 { id_2223, dsum2_snd_196 };
                letpair_res_2222 = id_2224;
              }
              choose_res_2220 = letpair_res_2222;
            } else {
              uint16_t id_2225 { 3 };
              bool id_2226 { bool(dsum1_fst_159 == id_2225) };
              Void id_2227 { ((void)(assert(id_2226)), ::dessser::VOID) };
              (void)id_2227;
              uint32_t id_2228 { 0U };
              Vec<1, uint32_t> id_2229 {  id_2228  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2230;
              {
                Vec<1, uint32_t> leb_ref_161 { id_2229 };
                uint8_t id_2231 { 0 };
                Vec<1, uint8_t> id_2232 {  id_2231  };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2233;
                {
                  Vec<1, uint8_t> shft_ref_162 { id_2232 };
                  Vec<1, Pointer> id_2234 {  dsum1_snd_160  };
                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2235;
                  {
                    Vec<1, Pointer> p_ref_163 { id_2234 };
                    bool while_flag_2236 { true };
                    do {
                      uint8_t id_2237 { 0 };
                      Pointer id_2238 { p_ref_163[id_2237] };
                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2239 { id_2238.readU8() };
                      bool let_res_2240;
                      {
                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_164 { id_2239 };
                        bool letpair_res_2241;
                        {
                          auto leb128_fst_165 { std::get<0>(leb128_164) };
                          auto leb128_snd_166 { std::get<1>(leb128_164) };
                          uint8_t id_2242 { 0 };
                          Void id_2243 { ((void)(p_ref_163[id_2242] = leb128_snd_166), ::dessser::VOID) };
                          (void)id_2243;
                          uint8_t id_2244 { 0 };
                          uint8_t id_2245 { 127 };
                          uint8_t id_2246 { uint8_t(leb128_fst_165 & id_2245) };
                          uint32_t id_2247 { uint32_t(id_2246) };
                          uint8_t id_2248 { 0 };
                          uint8_t id_2249 { shft_ref_162[id_2248] };
                          uint32_t id_2250 { uint32_t(id_2247 << id_2249) };
                          uint8_t id_2251 { 0 };
                          uint32_t id_2252 { leb_ref_161[id_2251] };
                          uint32_t id_2253 { uint32_t(id_2250 | id_2252) };
                          Void id_2254 { ((void)(leb_ref_161[id_2244] = id_2253), ::dessser::VOID) };
                          (void)id_2254;
                          uint8_t id_2255 { 0 };
                          uint8_t id_2256 { 0 };
                          uint8_t id_2257 { shft_ref_162[id_2256] };
                          uint8_t id_2258 { 7 };
                          uint8_t id_2259 { uint8_t(id_2257 + id_2258) };
                          Void id_2260 { ((void)(shft_ref_162[id_2255] = id_2259), ::dessser::VOID) };
                          (void)id_2260;
                          uint8_t id_2261 { 128 };
                          bool id_2262 { bool(leb128_fst_165 >= id_2261) };
                          letpair_res_2241 = id_2262;
                        }
                        let_res_2240 = letpair_res_2241;
                      }
                      while_flag_2236 = let_res_2240;
                      if (while_flag_2236) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_2236);
                    (void)::dessser::VOID;
                    uint8_t id_2263 { 0 };
                    uint32_t id_2264 { leb_ref_161[id_2263] };
                    Size id_2265 { Size(id_2264) };
                    uint8_t id_2266 { 0 };
                    Pointer id_2267 { p_ref_163[id_2266] };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2268 { id_2265, id_2267 };
                    let_res_2235 = id_2268;
                  }
                  let_res_2233 = let_res_2235;
                }
                let_res_2230 = let_res_2233;
              }
              ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2269;
              {
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_167 { let_res_2230 };
                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2270;
                {
                  auto dstring1_fst_168 { std::get<0>(dstring1_167) };
                  auto dstring1_snd_169 { std::get<1>(dstring1_167) };
                  ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2271 { dstring1_snd_169.readBytes(dstring1_fst_168) };
                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2272;
                  {
                    auto dstring2_fst_171 { std::get<0>(id_2271) };
                    auto dstring2_snd_172 { std::get<1>(id_2271) };
                    std::string id_2273 { dstring2_fst_171.toString() };
                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2274 { id_2273, dstring2_snd_172 };
                    letpair_res_2272 = id_2274;
                  }
                  letpair_res_2270 = letpair_res_2272;
                }
                let_res_2269 = letpair_res_2270;
              }
              ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab let_res_2275;
              {
                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_173 { let_res_2269 };
                ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2276;
                {
                  auto dtup_fst_174 { std::get<0>(dtup_173) };
                  auto dtup_snd_175 { std::get<1>(dtup_173) };
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2277 { dtup_snd_175.readU16Le() };
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2278;
                  {
                    auto du16_fst_177 { std::get<0>(id_2277) };
                    auto du16_snd_178 { std::get<1>(id_2277) };
                    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2279 { du16_fst_177, du16_snd_178 };
                    letpair_res_2278 = id_2279;
                  }
                  ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab let_res_2280;
                  {
                    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_182 { letpair_res_2278 };
                    ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2281;
                    {
                      auto dsum1_fst_183 { std::get<0>(dsum1_182) };
                      auto dsum1_snd_184 { std::get<1>(dsum1_182) };
                      uint16_t id_2282 { 0 };
                      bool id_2283 { bool(dsum1_fst_183 == id_2282) };
                      Void id_2284 { ((void)(assert(id_2283)), ::dessser::VOID) };
                      (void)id_2284;
                      (void)::dessser::VOID;
                      ::dessser::gen::sync_key::tea8c2377036e530fd3f67fa8653a3834 id_2285 { std::in_place_index<0>, ::dessser::VOID };
                      ::dessser::gen::sync_key::td7912e294d6f3a12e8335070433dc663 id_2286 { dtup_fst_174, id_2285 };
                      std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2287 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<3>, id_2286) };
                      ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab id_2288 { id_2287, dsum1_snd_184 };
                      letpair_res_2281 = id_2288;
                    }
                    let_res_2280 = letpair_res_2281;
                  }
                  letpair_res_2276 = let_res_2280;
                }
                let_res_2275 = letpair_res_2276;
              }
              choose_res_2220 = let_res_2275;
            }
            choose_res_2149 = choose_res_2220;
          }
          choose_res_2144 = choose_res_2149;
        }
        letpair_res_2141 = choose_res_2144;
      }
      let_res_2140 = letpair_res_2141;
    }
    return let_res_2140;
  }
   };
  return fun2136;
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
  std::function<::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581(Pointer)> fun2289 { [&fun2289](Pointer p_0) {
    auto fun2290 { dessser::gen::site_name::of_row_binary };
    ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 id_2291 { fun2290(p_0) };
    ::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581 let_res_2292;
    {
      ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 dtup_236 { id_2291 };
      ::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581 letpair_res_2293;
      {
        auto dtup_fst_237 { std::get<0>(dtup_236) };
        auto dtup_snd_238 { std::get<1>(dtup_236) };
        ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab id_2294 { per_site_data_of_row_binary(dtup_snd_238) };
        ::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581 letpair_res_2295;
        {
          auto dtup_fst_240 { std::get<0>(id_2294) };
          auto dtup_snd_241 { std::get<1>(id_2294) };
          std::shared_ptr<::dessser::gen::sync_key::per_site>  id_2296 { std::make_shared<::dessser::gen::sync_key::per_site>(dtup_fst_237, dtup_fst_240) };
          ::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581 id_2297 { id_2296, dtup_snd_241 };
          letpair_res_2295 = id_2297;
        }
        letpair_res_2293 = letpair_res_2295;
      }
      let_res_2292 = letpair_res_2293;
    }
    return let_res_2292;
  }
   };
  return fun2289;
}
std::function<::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581(Pointer)> per_site_of_row_binary(per_site_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_320" (let-pair "du16_fst_315" "du16_snd_316" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_315") (identifier "du16_snd_316")))
        (let-pair "dsum1_fst_321" "dsum1_snd_322" (identifier "dsum1_320")
          (if (eq (u16 0) (identifier "dsum1_fst_321"))
            (make-tup
              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 0
                (nop)) (identifier "dsum1_snd_322"))
            (if (eq (u16 1) (identifier "dsum1_fst_321"))
              (make-tup
                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 1
                  (nop)) (identifier "dsum1_snd_322"))
              (if (eq (u16 2) (identifier "dsum1_fst_321"))
                (let "dstring1_623"
                  (let "leb_ref_617" (make-vec (u32 0))
                    (let "shft_ref_618" (make-vec (u8 0))
                      (let "p_ref_619" (make-vec (identifier "dsum1_snd_322"))
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
                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 2
                          (string-of-bytes (identifier "dstring2_fst_627"))) 
                        (identifier "dstring2_snd_628")))))
                (if (eq (u16 3) (identifier "dsum1_fst_321"))
                  (let "dtup_596" (apply (ext-identifier src_path of-row-binary) (identifier "dsum1_snd_322"))
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
                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 3
                                (make-tup (identifier "dtup_fst_597") (string-of-bytes (identifier "dstring2_fst_609")))) 
                              (identifier "dstring2_snd_610")))))))
                  (if (eq (u16 4) (identifier "dsum1_fst_321"))
                    (make-tup
                      (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 4
                        (nop)) (identifier "dsum1_snd_322"))
                    (if (eq (u16 5) (identifier "dsum1_fst_321"))
                      (let-pair "dsum2_fst_591" "dsum2_snd_592" (apply (identifier "per_site-of-row-binary") (identifier "dsum1_snd_322"))
                        (make-tup
                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 5
                            (identifier "dsum2_fst_591")) (identifier "dsum2_snd_592")))
                      (if (eq (u16 6) (identifier "dsum1_fst_321"))
                        (let-pair "dsum2_fst_588" "dsum2_snd_589"
                          (let "dsum1_563" (let-pair "du16_fst_558" "du16_snd_559" (read-u16 little-endian (identifier "dsum1_snd_322")) (make-tup (identifier "du16_fst_558") (identifier "du16_snd_559")))
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
                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 6
                              (identifier "dsum2_fst_588")) (identifier "dsum2_snd_589")))
                        (if (eq (u16 7) (identifier "dsum1_fst_321"))
                          (let "dtup_530" (apply (ext-identifier site_name of-row-binary) (identifier "dsum1_snd_322"))
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
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 7
                                            (make-tup (identifier "dtup_fst_531") (identifier "dtup_fst_534") (identifier "dtup_fst_549") (identifier "dtup_fst_552"))) 
                                          (identifier "dtup_snd_553")))))))))
                          (if (eq (u16 8) (identifier "dsum1_fst_321"))
                            (let-pair "du16_fst_525" "du16_snd_526" (read-u16 little-endian (identifier "dsum1_snd_322"))
                              (make-tup
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 8
                                  (identifier "du16_fst_525")) (identifier "du16_snd_526")))
                            (if (eq (u16 9) (identifier "dsum1_fst_321"))
                              (let-pair "dsum2_fst_522" "dsum2_snd_523"
                                (if (eq (peek-u8 (identifier "dsum1_snd_322") (size 0)) (u8 1)) 
                                  (make-tup (null "$sync_socket") (ptr-add (identifier "dsum1_snd_322") (size 1)))
                                  (let-pair "make1_1_fst_519" "make1_1_snd_520" 
                                    (apply (ext-identifier sync_socket of-row-binary) (ptr-add (identifier "dsum1_snd_322") (size 1))) 
                                    (make-tup (not-null (identifier "make1_1_fst_519")) (identifier "make1_1_snd_520"))))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 9
                                    (identifier "dsum2_fst_522")) (identifier "dsum2_snd_523")))
                              (if (eq (u16 10) (identifier "dsum1_fst_321"))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 10
                                    (nop)) (identifier "dsum1_snd_322"))
                                (if (eq (u16 11) (identifier "dsum1_fst_321"))
                                  (let "dtup_506" (apply (ext-identifier sync_socket of-row-binary) (identifier "dsum1_snd_322"))
                                    (let-pair "dtup_fst_507" "dtup_snd_508" 
                                      (identifier "dtup_506")
                                      (let-pair "dtup_fst_510" "dtup_snd_511" 
                                        (apply (identifier "per_client-of-row-binary") (identifier "dtup_snd_508"))
                                        (make-tup
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 11
                                            (make-tup (identifier "dtup_fst_507") (identifier "dtup_fst_510"))) 
                                          (identifier "dtup_snd_511")))))
                                  (if (eq (u16 12) (identifier "dsum1_fst_321"))
                                    (let "dtup_497"
                                      (let "dstring1_491"
                                        (let "leb_ref_485" (make-vec (u32 0))
                                          (let "shft_ref_486" (make-vec (u8 0))
                                            (let "p_ref_487" (make-vec (identifier "dsum1_snd_322"))
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
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 12
                                              (make-tup (identifier "dtup_fst_498") (identifier "dtup_fst_501"))) 
                                            (identifier "dtup_snd_502")))))
                                    (if (eq (u16 13) (identifier "dsum1_fst_321"))
                                      (make-tup
                                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 13
                                          (nop)) (identifier "dsum1_snd_322"))
                                      (if (eq (u16 14) (identifier "dsum1_fst_321"))
                                        (let "dtup_434" (apply (ext-identifier team_name of-row-binary) (identifier "dsum1_snd_322"))
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
                                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 14
                                                  (make-tup (identifier "dtup_fst_435") (identifier "dtup_fst_477"))) 
                                                (identifier "dtup_snd_478")))))
                                        (seq (assert (eq (identifier "dsum1_fst_321") (u16 15)))
                                          (let "dtup_335"
                                            (let "dstring1_329"
                                              (let "leb_ref_323" (make-vec (u32 0))
                                                (let "shft_ref_324" (make-vec (u8 0))
                                                  (let "p_ref_325" (make-vec (identifier "dsum1_snd_322"))
                                                    (seq
                                                      (while
                                                        (let "leb128_326" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_325")))
                                                          (let-pair "leb128_fst_327" "leb128_snd_328" 
                                                            (identifier "leb128_326")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_325") (identifier "leb128_snd_328"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_323")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_327") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_324")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_323")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_324") (add (unsafe-nth (u8 0) (identifier "shft_ref_324")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_327") (u8 128))))) 
                                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_323"))) (unsafe-nth (u8 0) (identifier "p_ref_325")))))))
                                              (let-pair "dstring1_fst_330" "dstring1_snd_331" 
                                                (identifier "dstring1_329")
                                                (let-pair "dstring2_fst_333" "dstring2_snd_334" 
                                                  (read-bytes (identifier "dstring1_snd_331") (identifier "dstring1_fst_330")) 
                                                  (make-tup (string-of-bytes (identifier "dstring2_fst_333")) (identifier "dstring2_snd_334")))))
                                            (let-pair "dtup_fst_336" "dtup_snd_337" 
                                              (identifier "dtup_335")
                                              (let-pair "dtup_fst_429" "dtup_snd_430"
                                                (let "dsum1_344" (let-pair "du16_fst_339" "du16_snd_340" (read-u16 little-endian (identifier "dtup_snd_337")) (make-tup (identifier "du16_fst_339") (identifier "du16_snd_340")))
                                                  (let-pair "dsum1_fst_345" "dsum1_snd_346" 
                                                    (identifier "dsum1_344")
                                                    (if (eq (u16 0) (identifier "dsum1_fst_345"))
                                                      (make-tup
                                                        (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 0
                                                          (nop)) (identifier "dsum1_snd_346"))
                                                      (if (eq (u16 1) (identifier "dsum1_fst_345"))
                                                        (make-tup
                                                          (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 1
                                                            (nop)) (identifier "dsum1_snd_346"))
                                                        (if (eq (u16 2) (identifier "dsum1_fst_345"))
                                                          (make-tup
                                                            (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 2
                                                              (nop)) 
                                                            (identifier "dsum1_snd_346"))
                                                          (if (eq (u16 3) (identifier "dsum1_fst_345"))
                                                            (make-tup
                                                              (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 3
                                                                (nop)) 
                                                              (identifier "dsum1_snd_346"))
                                                            (if (eq (u16 4) (identifier "dsum1_fst_345"))
                                                              (make-tup
                                                                (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 4
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_346"))
                                                              (if (eq (u16 5) (identifier "dsum1_fst_345"))
                                                                (let "dtup_374"
                                                                  (let "dstring1_368"
                                                                    (let "leb_ref_362" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_363" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_364" 
                                                                    (make-vec (identifier "dsum1_snd_346"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_365" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_364")))
                                                                    (let-pair "leb128_fst_366" "leb128_snd_367" 
                                                                    (identifier "leb128_365")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_364") (identifier "leb128_snd_367"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_362")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_366") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_363")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_362")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_363") (add (unsafe-nth (u8 0) (identifier "shft_ref_363")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_366") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_362"))) (unsafe-nth (u8 0) (identifier "p_ref_364")))))))
                                                                    (let-pair "dstring1_fst_369" "dstring1_snd_370" 
                                                                    (identifier "dstring1_368")
                                                                    (let-pair "dstring2_fst_372" "dstring2_snd_373" 
                                                                    (read-bytes (identifier "dstring1_snd_370") (identifier "dstring1_fst_369"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_372")) (identifier "dstring2_snd_373")))))
                                                                  (let-pair "dtup_fst_375" "dtup_snd_376" 
                                                                    (identifier "dtup_374")
                                                                    (let-pair "dtup_fst_408" "dtup_snd_409"
                                                                    (let "dsum1_383"
                                                                    (let-pair "du16_fst_378" "du16_snd_379" (read-u16 little-endian (identifier "dtup_snd_376")) (make-tup (identifier "du16_fst_378") (identifier "du16_snd_379")))
                                                                    (let-pair "dsum1_fst_384" "dsum1_snd_385" 
                                                                    (identifier "dsum1_383")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_384"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 0
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_385"))
                                                                    (if 
                                                                    (eq (u16 1) (identifier "dsum1_fst_384"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 1
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_385"))
                                                                    (if 
                                                                    (eq (u16 2) (identifier "dsum1_fst_384"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 2
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_385"))
                                                                    (if 
                                                                    (eq (u16 3) (identifier "dsum1_fst_384"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 3
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_385"))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "dsum1_fst_384"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 4
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_385"))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "dsum1_fst_384"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 5
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_385"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_384") (u16 6)))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 6
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_385")))))))))))
                                                                    (make-tup
                                                                    (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 5
                                                                    (make-tup (identifier "dtup_fst_375") (identifier "dtup_fst_408"))) 
                                                                    (identifier "dtup_snd_409")))))
                                                                (seq 
                                                                  (assert (eq (identifier "dsum1_fst_345") (u16 6)))
                                                                  (let "dtup_350"
                                                                    (let-pair "dfloat_fst_348" "dfloat_snd_349" 
                                                                    (read-u64 little-endian (identifier "dsum1_snd_346")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_348")) (identifier "dfloat_snd_349")))
                                                                    (let-pair "dtup_fst_351" "dtup_snd_352" 
                                                                    (identifier "dtup_350")
                                                                    (let-pair "du32_fst_354" "du32_snd_355" 
                                                                    (read-u32 little-endian (identifier "dtup_snd_352"))
                                                                    (make-tup
                                                                    (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 6
                                                                    (make-tup (identifier "dtup_fst_351") (identifier "du32_fst_354"))) 
                                                                    (identifier "du32_snd_355"))))))))))))))
                                                (make-tup
                                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 15
                                                    (make-tup (identifier "dtup_fst_336") (identifier "dtup_fst_429"))) 
                                                  (identifier "dtup_snd_430"))))))))))))))))))))))))
 */
static std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> fun2298 { [&fun2298](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2299 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2300;
    {
      auto du16_fst_315 { std::get<0>(id_2299) };
      auto du16_snd_316 { std::get<1>(id_2299) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2301 { du16_fst_315, du16_snd_316 };
      letpair_res_2300 = id_2301;
    }
    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2302;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_320 { letpair_res_2300 };
      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2303;
      {
        auto dsum1_fst_321 { std::get<0>(dsum1_320) };
        auto dsum1_snd_322 { std::get<1>(dsum1_320) };
        uint16_t id_2304 { 0 };
        bool id_2305 { bool(id_2304 == dsum1_fst_321) };
        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2306;
        if (id_2305) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::t>  id_2307 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2308 { id_2307, dsum1_snd_322 };
          choose_res_2306 = id_2308;
        } else {
          uint16_t id_2309 { 1 };
          bool id_2310 { bool(id_2309 == dsum1_fst_321) };
          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2311;
          if (id_2310) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::sync_key::t>  id_2312 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2313 { id_2312, dsum1_snd_322 };
            choose_res_2311 = id_2313;
          } else {
            uint16_t id_2314 { 2 };
            bool id_2315 { bool(id_2314 == dsum1_fst_321) };
            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2316;
            if (id_2315) {
              uint32_t id_2317 { 0U };
              Vec<1, uint32_t> id_2318 {  id_2317  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2319;
              {
                Vec<1, uint32_t> leb_ref_617 { id_2318 };
                uint8_t id_2320 { 0 };
                Vec<1, uint8_t> id_2321 {  id_2320  };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2322;
                {
                  Vec<1, uint8_t> shft_ref_618 { id_2321 };
                  Vec<1, Pointer> id_2323 {  dsum1_snd_322  };
                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2324;
                  {
                    Vec<1, Pointer> p_ref_619 { id_2323 };
                    bool while_flag_2325 { true };
                    do {
                      uint8_t id_2326 { 0 };
                      Pointer id_2327 { p_ref_619[id_2326] };
                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2328 { id_2327.readU8() };
                      bool let_res_2329;
                      {
                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_620 { id_2328 };
                        bool letpair_res_2330;
                        {
                          auto leb128_fst_621 { std::get<0>(leb128_620) };
                          auto leb128_snd_622 { std::get<1>(leb128_620) };
                          uint8_t id_2331 { 0 };
                          Void id_2332 { ((void)(p_ref_619[id_2331] = leb128_snd_622), ::dessser::VOID) };
                          (void)id_2332;
                          uint8_t id_2333 { 0 };
                          uint8_t id_2334 { 127 };
                          uint8_t id_2335 { uint8_t(leb128_fst_621 & id_2334) };
                          uint32_t id_2336 { uint32_t(id_2335) };
                          uint8_t id_2337 { 0 };
                          uint8_t id_2338 { shft_ref_618[id_2337] };
                          uint32_t id_2339 { uint32_t(id_2336 << id_2338) };
                          uint8_t id_2340 { 0 };
                          uint32_t id_2341 { leb_ref_617[id_2340] };
                          uint32_t id_2342 { uint32_t(id_2339 | id_2341) };
                          Void id_2343 { ((void)(leb_ref_617[id_2333] = id_2342), ::dessser::VOID) };
                          (void)id_2343;
                          uint8_t id_2344 { 0 };
                          uint8_t id_2345 { 0 };
                          uint8_t id_2346 { shft_ref_618[id_2345] };
                          uint8_t id_2347 { 7 };
                          uint8_t id_2348 { uint8_t(id_2346 + id_2347) };
                          Void id_2349 { ((void)(shft_ref_618[id_2344] = id_2348), ::dessser::VOID) };
                          (void)id_2349;
                          uint8_t id_2350 { 128 };
                          bool id_2351 { bool(leb128_fst_621 >= id_2350) };
                          letpair_res_2330 = id_2351;
                        }
                        let_res_2329 = letpair_res_2330;
                      }
                      while_flag_2325 = let_res_2329;
                      if (while_flag_2325) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_2325);
                    (void)::dessser::VOID;
                    uint8_t id_2352 { 0 };
                    uint32_t id_2353 { leb_ref_617[id_2352] };
                    Size id_2354 { Size(id_2353) };
                    uint8_t id_2355 { 0 };
                    Pointer id_2356 { p_ref_619[id_2355] };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2357 { id_2354, id_2356 };
                    let_res_2324 = id_2357;
                  }
                  let_res_2322 = let_res_2324;
                }
                let_res_2319 = let_res_2322;
              }
              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2358;
              {
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_623 { let_res_2319 };
                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2359;
                {
                  auto dstring1_fst_624 { std::get<0>(dstring1_623) };
                  auto dstring1_snd_625 { std::get<1>(dstring1_623) };
                  ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2360 { dstring1_snd_625.readBytes(dstring1_fst_624) };
                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2361;
                  {
                    auto dstring2_fst_627 { std::get<0>(id_2360) };
                    auto dstring2_snd_628 { std::get<1>(id_2360) };
                    std::string id_2362 { dstring2_fst_627.toString() };
                    std::shared_ptr<::dessser::gen::sync_key::t>  id_2363 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<2>, id_2362) };
                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2364 { id_2363, dstring2_snd_628 };
                    letpair_res_2361 = id_2364;
                  }
                  letpair_res_2359 = letpair_res_2361;
                }
                let_res_2358 = letpair_res_2359;
              }
              choose_res_2316 = let_res_2358;
            } else {
              uint16_t id_2365 { 3 };
              bool id_2366 { bool(id_2365 == dsum1_fst_321) };
              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2367;
              if (id_2366) {
                auto fun2368 { dessser::gen::src_path::of_row_binary };
                ::dessser::gen::sync_key::t6915129216bc7fcac0c82f38ea6cfec8 id_2369 { fun2368(dsum1_snd_322) };
                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2370;
                {
                  ::dessser::gen::sync_key::t6915129216bc7fcac0c82f38ea6cfec8 dtup_596 { id_2369 };
                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2371;
                  {
                    auto dtup_fst_597 { std::get<0>(dtup_596) };
                    auto dtup_snd_598 { std::get<1>(dtup_596) };
                    uint32_t id_2372 { 0U };
                    Vec<1, uint32_t> id_2373 {  id_2372  };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2374;
                    {
                      Vec<1, uint32_t> leb_ref_599 { id_2373 };
                      uint8_t id_2375 { 0 };
                      Vec<1, uint8_t> id_2376 {  id_2375  };
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2377;
                      {
                        Vec<1, uint8_t> shft_ref_600 { id_2376 };
                        Vec<1, Pointer> id_2378 {  dtup_snd_598  };
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2379;
                        {
                          Vec<1, Pointer> p_ref_601 { id_2378 };
                          bool while_flag_2380 { true };
                          do {
                            uint8_t id_2381 { 0 };
                            Pointer id_2382 { p_ref_601[id_2381] };
                            ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2383 { id_2382.readU8() };
                            bool let_res_2384;
                            {
                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_602 { id_2383 };
                              bool letpair_res_2385;
                              {
                                auto leb128_fst_603 { std::get<0>(leb128_602) };
                                auto leb128_snd_604 { std::get<1>(leb128_602) };
                                uint8_t id_2386 { 0 };
                                Void id_2387 { ((void)(p_ref_601[id_2386] = leb128_snd_604), ::dessser::VOID) };
                                (void)id_2387;
                                uint8_t id_2388 { 0 };
                                uint8_t id_2389 { 127 };
                                uint8_t id_2390 { uint8_t(leb128_fst_603 & id_2389) };
                                uint32_t id_2391 { uint32_t(id_2390) };
                                uint8_t id_2392 { 0 };
                                uint8_t id_2393 { shft_ref_600[id_2392] };
                                uint32_t id_2394 { uint32_t(id_2391 << id_2393) };
                                uint8_t id_2395 { 0 };
                                uint32_t id_2396 { leb_ref_599[id_2395] };
                                uint32_t id_2397 { uint32_t(id_2394 | id_2396) };
                                Void id_2398 { ((void)(leb_ref_599[id_2388] = id_2397), ::dessser::VOID) };
                                (void)id_2398;
                                uint8_t id_2399 { 0 };
                                uint8_t id_2400 { 0 };
                                uint8_t id_2401 { shft_ref_600[id_2400] };
                                uint8_t id_2402 { 7 };
                                uint8_t id_2403 { uint8_t(id_2401 + id_2402) };
                                Void id_2404 { ((void)(shft_ref_600[id_2399] = id_2403), ::dessser::VOID) };
                                (void)id_2404;
                                uint8_t id_2405 { 128 };
                                bool id_2406 { bool(leb128_fst_603 >= id_2405) };
                                letpair_res_2385 = id_2406;
                              }
                              let_res_2384 = letpair_res_2385;
                            }
                            while_flag_2380 = let_res_2384;
                            if (while_flag_2380) {
                              (void)::dessser::VOID;
                            }
                          } while (while_flag_2380);
                          (void)::dessser::VOID;
                          uint8_t id_2407 { 0 };
                          uint32_t id_2408 { leb_ref_599[id_2407] };
                          Size id_2409 { Size(id_2408) };
                          uint8_t id_2410 { 0 };
                          Pointer id_2411 { p_ref_601[id_2410] };
                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2412 { id_2409, id_2411 };
                          let_res_2379 = id_2412;
                        }
                        let_res_2377 = let_res_2379;
                      }
                      let_res_2374 = let_res_2377;
                    }
                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2413;
                    {
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_605 { let_res_2374 };
                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2414;
                      {
                        auto dstring1_fst_606 { std::get<0>(dstring1_605) };
                        auto dstring1_snd_607 { std::get<1>(dstring1_605) };
                        ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2415 { dstring1_snd_607.readBytes(dstring1_fst_606) };
                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2416;
                        {
                          auto dstring2_fst_609 { std::get<0>(id_2415) };
                          auto dstring2_snd_610 { std::get<1>(id_2415) };
                          std::string id_2417 { dstring2_fst_609.toString() };
                          ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_2418 { dtup_fst_597, id_2417 };
                          std::shared_ptr<::dessser::gen::sync_key::t>  id_2419 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<3>, id_2418) };
                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2420 { id_2419, dstring2_snd_610 };
                          letpair_res_2416 = id_2420;
                        }
                        letpair_res_2414 = letpair_res_2416;
                      }
                      let_res_2413 = letpair_res_2414;
                    }
                    letpair_res_2371 = let_res_2413;
                  }
                  let_res_2370 = letpair_res_2371;
                }
                choose_res_2367 = let_res_2370;
              } else {
                uint16_t id_2421 { 4 };
                bool id_2422 { bool(id_2421 == dsum1_fst_321) };
                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2423;
                if (id_2422) {
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::sync_key::t>  id_2424 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<4>, ::dessser::VOID) };
                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2425 { id_2424, dsum1_snd_322 };
                  choose_res_2423 = id_2425;
                } else {
                  uint16_t id_2426 { 5 };
                  bool id_2427 { bool(id_2426 == dsum1_fst_321) };
                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2428;
                  if (id_2427) {
                    ::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581 id_2429 { per_site_of_row_binary(dsum1_snd_322) };
                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2430;
                    {
                      auto dsum2_fst_591 { std::get<0>(id_2429) };
                      auto dsum2_snd_592 { std::get<1>(id_2429) };
                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2431 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<5>, dsum2_fst_591) };
                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2432 { id_2431, dsum2_snd_592 };
                      letpair_res_2430 = id_2432;
                    }
                    choose_res_2428 = letpair_res_2430;
                  } else {
                    uint16_t id_2433 { 6 };
                    bool id_2434 { bool(id_2433 == dsum1_fst_321) };
                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2435;
                    if (id_2434) {
                      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2436 { dsum1_snd_322.readU16Le() };
                      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2437;
                      {
                        auto du16_fst_558 { std::get<0>(id_2436) };
                        auto du16_snd_559 { std::get<1>(id_2436) };
                        ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2438 { du16_fst_558, du16_snd_559 };
                        letpair_res_2437 = id_2438;
                      }
                      ::dessser::gen::sync_key::t1f5dea46176c28beac68cca21417e43b let_res_2439;
                      {
                        ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_563 { letpair_res_2437 };
                        ::dessser::gen::sync_key::t1f5dea46176c28beac68cca21417e43b letpair_res_2440;
                        {
                          auto dsum1_fst_564 { std::get<0>(dsum1_563) };
                          auto dsum1_snd_565 { std::get<1>(dsum1_563) };
                          uint16_t id_2441 { 0 };
                          bool id_2442 { bool(id_2441 == dsum1_fst_564) };
                          ::dessser::gen::sync_key::t1f5dea46176c28beac68cca21417e43b choose_res_2443;
                          if (id_2442) {
                            (void)::dessser::VOID;
                            ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_2444 { std::in_place_index<0>, ::dessser::VOID };
                            ::dessser::gen::sync_key::t1f5dea46176c28beac68cca21417e43b id_2445 { id_2444, dsum1_snd_565 };
                            choose_res_2443 = id_2445;
                          } else {
                            uint16_t id_2446 { 1 };
                            bool id_2447 { bool(id_2446 == dsum1_fst_564) };
                            ::dessser::gen::sync_key::t1f5dea46176c28beac68cca21417e43b choose_res_2448;
                            if (id_2447) {
                              (void)::dessser::VOID;
                              ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_2449 { std::in_place_index<1>, ::dessser::VOID };
                              ::dessser::gen::sync_key::t1f5dea46176c28beac68cca21417e43b id_2450 { id_2449, dsum1_snd_565 };
                              choose_res_2448 = id_2450;
                            } else {
                              uint16_t id_2451 { 2 };
                              bool id_2452 { bool(dsum1_fst_564 == id_2451) };
                              Void id_2453 { ((void)(assert(id_2452)), ::dessser::VOID) };
                              (void)id_2453;
                              uint32_t id_2454 { 0U };
                              Vec<1, uint32_t> id_2455 {  id_2454  };
                              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2456;
                              {
                                Vec<1, uint32_t> leb_ref_566 { id_2455 };
                                uint8_t id_2457 { 0 };
                                Vec<1, uint8_t> id_2458 {  id_2457  };
                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2459;
                                {
                                  Vec<1, uint8_t> shft_ref_567 { id_2458 };
                                  Vec<1, Pointer> id_2460 {  dsum1_snd_565  };
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2461;
                                  {
                                    Vec<1, Pointer> p_ref_568 { id_2460 };
                                    bool while_flag_2462 { true };
                                    do {
                                      uint8_t id_2463 { 0 };
                                      Pointer id_2464 { p_ref_568[id_2463] };
                                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2465 { id_2464.readU8() };
                                      bool let_res_2466;
                                      {
                                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_569 { id_2465 };
                                        bool letpair_res_2467;
                                        {
                                          auto leb128_fst_570 { std::get<0>(leb128_569) };
                                          auto leb128_snd_571 { std::get<1>(leb128_569) };
                                          uint8_t id_2468 { 0 };
                                          Void id_2469 { ((void)(p_ref_568[id_2468] = leb128_snd_571), ::dessser::VOID) };
                                          (void)id_2469;
                                          uint8_t id_2470 { 0 };
                                          uint8_t id_2471 { 127 };
                                          uint8_t id_2472 { uint8_t(leb128_fst_570 & id_2471) };
                                          uint32_t id_2473 { uint32_t(id_2472) };
                                          uint8_t id_2474 { 0 };
                                          uint8_t id_2475 { shft_ref_567[id_2474] };
                                          uint32_t id_2476 { uint32_t(id_2473 << id_2475) };
                                          uint8_t id_2477 { 0 };
                                          uint32_t id_2478 { leb_ref_566[id_2477] };
                                          uint32_t id_2479 { uint32_t(id_2476 | id_2478) };
                                          Void id_2480 { ((void)(leb_ref_566[id_2470] = id_2479), ::dessser::VOID) };
                                          (void)id_2480;
                                          uint8_t id_2481 { 0 };
                                          uint8_t id_2482 { 0 };
                                          uint8_t id_2483 { shft_ref_567[id_2482] };
                                          uint8_t id_2484 { 7 };
                                          uint8_t id_2485 { uint8_t(id_2483 + id_2484) };
                                          Void id_2486 { ((void)(shft_ref_567[id_2481] = id_2485), ::dessser::VOID) };
                                          (void)id_2486;
                                          uint8_t id_2487 { 128 };
                                          bool id_2488 { bool(leb128_fst_570 >= id_2487) };
                                          letpair_res_2467 = id_2488;
                                        }
                                        let_res_2466 = letpair_res_2467;
                                      }
                                      while_flag_2462 = let_res_2466;
                                      if (while_flag_2462) {
                                        (void)::dessser::VOID;
                                      }
                                    } while (while_flag_2462);
                                    (void)::dessser::VOID;
                                    uint8_t id_2489 { 0 };
                                    uint32_t id_2490 { leb_ref_566[id_2489] };
                                    Size id_2491 { Size(id_2490) };
                                    uint8_t id_2492 { 0 };
                                    Pointer id_2493 { p_ref_568[id_2492] };
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2494 { id_2491, id_2493 };
                                    let_res_2461 = id_2494;
                                  }
                                  let_res_2459 = let_res_2461;
                                }
                                let_res_2456 = let_res_2459;
                              }
                              ::dessser::gen::sync_key::t1f5dea46176c28beac68cca21417e43b let_res_2495;
                              {
                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_572 { let_res_2456 };
                                ::dessser::gen::sync_key::t1f5dea46176c28beac68cca21417e43b letpair_res_2496;
                                {
                                  auto dstring1_fst_573 { std::get<0>(dstring1_572) };
                                  auto dstring1_snd_574 { std::get<1>(dstring1_572) };
                                  ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2497 { dstring1_snd_574.readBytes(dstring1_fst_573) };
                                  ::dessser::gen::sync_key::t1f5dea46176c28beac68cca21417e43b letpair_res_2498;
                                  {
                                    auto dstring2_fst_576 { std::get<0>(id_2497) };
                                    auto dstring2_snd_577 { std::get<1>(id_2497) };
                                    std::string id_2499 { dstring2_fst_576.toString() };
                                    ::dessser::gen::sync_key::t803a3c9022c32e1702f6b5e3eaa82fb3 id_2500 { std::in_place_index<2>, id_2499 };
                                    ::dessser::gen::sync_key::t1f5dea46176c28beac68cca21417e43b id_2501 { id_2500, dstring2_snd_577 };
                                    letpair_res_2498 = id_2501;
                                  }
                                  letpair_res_2496 = letpair_res_2498;
                                }
                                let_res_2495 = letpair_res_2496;
                              }
                              choose_res_2448 = let_res_2495;
                            }
                            choose_res_2443 = choose_res_2448;
                          }
                          letpair_res_2440 = choose_res_2443;
                        }
                        let_res_2439 = letpair_res_2440;
                      }
                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2502;
                      {
                        auto dsum2_fst_588 { std::get<0>(let_res_2439) };
                        auto dsum2_snd_589 { std::get<1>(let_res_2439) };
                        std::shared_ptr<::dessser::gen::sync_key::t>  id_2503 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<6>, dsum2_fst_588) };
                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2504 { id_2503, dsum2_snd_589 };
                        letpair_res_2502 = id_2504;
                      }
                      choose_res_2435 = letpair_res_2502;
                    } else {
                      uint16_t id_2505 { 7 };
                      bool id_2506 { bool(id_2505 == dsum1_fst_321) };
                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2507;
                      if (id_2506) {
                        auto fun2508 { dessser::gen::site_name::of_row_binary };
                        ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 id_2509 { fun2508(dsum1_snd_322) };
                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2510;
                        {
                          ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 dtup_530 { id_2509 };
                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2511;
                          {
                            auto dtup_fst_531 { std::get<0>(dtup_530) };
                            auto dtup_snd_532 { std::get<1>(dtup_530) };
                            auto fun2512 { dessser::gen::fq_name::of_row_binary };
                            ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 id_2513 { fun2512(dtup_snd_532) };
                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2514;
                            {
                              ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 dtup_533 { id_2513 };
                              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2515;
                              {
                                auto dtup_fst_534 { std::get<0>(dtup_533) };
                                auto dtup_snd_535 { std::get<1>(dtup_533) };
                                uint32_t id_2516 { 0U };
                                Vec<1, uint32_t> id_2517 {  id_2516  };
                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2518;
                                {
                                  Vec<1, uint32_t> leb_ref_536 { id_2517 };
                                  uint8_t id_2519 { 0 };
                                  Vec<1, uint8_t> id_2520 {  id_2519  };
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2521;
                                  {
                                    Vec<1, uint8_t> shft_ref_537 { id_2520 };
                                    Vec<1, Pointer> id_2522 {  dtup_snd_535  };
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2523;
                                    {
                                      Vec<1, Pointer> p_ref_538 { id_2522 };
                                      bool while_flag_2524 { true };
                                      do {
                                        uint8_t id_2525 { 0 };
                                        Pointer id_2526 { p_ref_538[id_2525] };
                                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2527 { id_2526.readU8() };
                                        bool let_res_2528;
                                        {
                                          ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_539 { id_2527 };
                                          bool letpair_res_2529;
                                          {
                                            auto leb128_fst_540 { std::get<0>(leb128_539) };
                                            auto leb128_snd_541 { std::get<1>(leb128_539) };
                                            uint8_t id_2530 { 0 };
                                            Void id_2531 { ((void)(p_ref_538[id_2530] = leb128_snd_541), ::dessser::VOID) };
                                            (void)id_2531;
                                            uint8_t id_2532 { 0 };
                                            uint8_t id_2533 { 127 };
                                            uint8_t id_2534 { uint8_t(leb128_fst_540 & id_2533) };
                                            uint32_t id_2535 { uint32_t(id_2534) };
                                            uint8_t id_2536 { 0 };
                                            uint8_t id_2537 { shft_ref_537[id_2536] };
                                            uint32_t id_2538 { uint32_t(id_2535 << id_2537) };
                                            uint8_t id_2539 { 0 };
                                            uint32_t id_2540 { leb_ref_536[id_2539] };
                                            uint32_t id_2541 { uint32_t(id_2538 | id_2540) };
                                            Void id_2542 { ((void)(leb_ref_536[id_2532] = id_2541), ::dessser::VOID) };
                                            (void)id_2542;
                                            uint8_t id_2543 { 0 };
                                            uint8_t id_2544 { 0 };
                                            uint8_t id_2545 { shft_ref_537[id_2544] };
                                            uint8_t id_2546 { 7 };
                                            uint8_t id_2547 { uint8_t(id_2545 + id_2546) };
                                            Void id_2548 { ((void)(shft_ref_537[id_2543] = id_2547), ::dessser::VOID) };
                                            (void)id_2548;
                                            uint8_t id_2549 { 128 };
                                            bool id_2550 { bool(leb128_fst_540 >= id_2549) };
                                            letpair_res_2529 = id_2550;
                                          }
                                          let_res_2528 = letpair_res_2529;
                                        }
                                        while_flag_2524 = let_res_2528;
                                        if (while_flag_2524) {
                                          (void)::dessser::VOID;
                                        }
                                      } while (while_flag_2524);
                                      (void)::dessser::VOID;
                                      uint8_t id_2551 { 0 };
                                      uint32_t id_2552 { leb_ref_536[id_2551] };
                                      Size id_2553 { Size(id_2552) };
                                      uint8_t id_2554 { 0 };
                                      Pointer id_2555 { p_ref_538[id_2554] };
                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2556 { id_2553, id_2555 };
                                      let_res_2523 = id_2556;
                                    }
                                    let_res_2521 = let_res_2523;
                                  }
                                  let_res_2518 = let_res_2521;
                                }
                                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2557;
                                {
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_542 { let_res_2518 };
                                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2558;
                                  {
                                    auto dstring1_fst_543 { std::get<0>(dstring1_542) };
                                    auto dstring1_snd_544 { std::get<1>(dstring1_542) };
                                    ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2559 { dstring1_snd_544.readBytes(dstring1_fst_543) };
                                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2560;
                                    {
                                      auto dstring2_fst_546 { std::get<0>(id_2559) };
                                      auto dstring2_snd_547 { std::get<1>(id_2559) };
                                      std::string id_2561 { dstring2_fst_546.toString() };
                                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2562 { id_2561, dstring2_snd_547 };
                                      letpair_res_2560 = id_2562;
                                    }
                                    letpair_res_2558 = letpair_res_2560;
                                  }
                                  let_res_2557 = letpair_res_2558;
                                }
                                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2563;
                                {
                                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_548 { let_res_2557 };
                                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2564;
                                  {
                                    auto dtup_fst_549 { std::get<0>(dtup_548) };
                                    auto dtup_snd_550 { std::get<1>(dtup_548) };
                                    ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e id_2565 { per_tail_of_row_binary(dtup_snd_550) };
                                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2566;
                                    {
                                      auto dtup_fst_552 { std::get<0>(id_2565) };
                                      auto dtup_snd_553 { std::get<1>(id_2565) };
                                      ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_2567 { dtup_fst_531, dtup_fst_534, dtup_fst_549, dtup_fst_552 };
                                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2568 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<7>, id_2567) };
                                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2569 { id_2568, dtup_snd_553 };
                                      letpair_res_2566 = id_2569;
                                    }
                                    letpair_res_2564 = letpair_res_2566;
                                  }
                                  let_res_2563 = letpair_res_2564;
                                }
                                letpair_res_2515 = let_res_2563;
                              }
                              let_res_2514 = letpair_res_2515;
                            }
                            letpair_res_2511 = let_res_2514;
                          }
                          let_res_2510 = letpair_res_2511;
                        }
                        choose_res_2507 = let_res_2510;
                      } else {
                        uint16_t id_2570 { 8 };
                        bool id_2571 { bool(id_2570 == dsum1_fst_321) };
                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2572;
                        if (id_2571) {
                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2573 { dsum1_snd_322.readU16Le() };
                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2574;
                          {
                            auto du16_fst_525 { std::get<0>(id_2573) };
                            auto du16_snd_526 { std::get<1>(id_2573) };
                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2575 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<8>, du16_fst_525) };
                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2576 { id_2575, du16_snd_526 };
                            letpair_res_2574 = id_2576;
                          }
                          choose_res_2572 = letpair_res_2574;
                        } else {
                          uint16_t id_2577 { 9 };
                          bool id_2578 { bool(id_2577 == dsum1_fst_321) };
                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2579;
                          if (id_2578) {
                            Size id_2580 { 0UL };
                            uint8_t id_2581 { dsum1_snd_322.peekU8(id_2580) };
                            uint8_t id_2582 { 1 };
                            bool id_2583 { bool(id_2581 == id_2582) };
                            ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 choose_res_2584;
                            if (id_2583) {
                              std::optional<dessser::gen::sync_socket::t_ext> id_2585 { std::nullopt };
                              Size id_2586 { 1UL };
                              Pointer id_2587 { dsum1_snd_322.skip(id_2586) };
                              ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 id_2588 { id_2585, id_2587 };
                              choose_res_2584 = id_2588;
                            } else {
                              auto fun2589 { dessser::gen::sync_socket::of_row_binary };
                              Size id_2590 { 1UL };
                              Pointer id_2591 { dsum1_snd_322.skip(id_2590) };
                              ::dessser::gen::sync_key::tc3c0b466d06f5b0f1ffeebd3dab58a35 id_2592 { fun2589(id_2591) };
                              ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 letpair_res_2593;
                              {
                                auto make1_1_fst_519 { std::get<0>(id_2592) };
                                auto make1_1_snd_520 { std::get<1>(id_2592) };
                                std::optional<dessser::gen::sync_socket::t_ext> id_2594 { make1_1_fst_519 };
                                ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 id_2595 { id_2594, make1_1_snd_520 };
                                letpair_res_2593 = id_2595;
                              }
                              choose_res_2584 = letpair_res_2593;
                            }
                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2596;
                            {
                              auto dsum2_fst_522 { std::get<0>(choose_res_2584) };
                              auto dsum2_snd_523 { std::get<1>(choose_res_2584) };
                              std::shared_ptr<::dessser::gen::sync_key::t>  id_2597 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<9>, dsum2_fst_522) };
                              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2598 { id_2597, dsum2_snd_523 };
                              letpair_res_2596 = id_2598;
                            }
                            choose_res_2579 = letpair_res_2596;
                          } else {
                            uint16_t id_2599 { 10 };
                            bool id_2600 { bool(id_2599 == dsum1_fst_321) };
                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2601;
                            if (id_2600) {
                              (void)::dessser::VOID;
                              std::shared_ptr<::dessser::gen::sync_key::t>  id_2602 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<10>, ::dessser::VOID) };
                              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2603 { id_2602, dsum1_snd_322 };
                              choose_res_2601 = id_2603;
                            } else {
                              uint16_t id_2604 { 11 };
                              bool id_2605 { bool(id_2604 == dsum1_fst_321) };
                              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2606;
                              if (id_2605) {
                                auto fun2607 { dessser::gen::sync_socket::of_row_binary };
                                ::dessser::gen::sync_key::tc3c0b466d06f5b0f1ffeebd3dab58a35 id_2608 { fun2607(dsum1_snd_322) };
                                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2609;
                                {
                                  ::dessser::gen::sync_key::tc3c0b466d06f5b0f1ffeebd3dab58a35 dtup_506 { id_2608 };
                                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2610;
                                  {
                                    auto dtup_fst_507 { std::get<0>(dtup_506) };
                                    auto dtup_snd_508 { std::get<1>(dtup_506) };
                                    ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 id_2611 { per_client_of_row_binary(dtup_snd_508) };
                                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2612;
                                    {
                                      auto dtup_fst_510 { std::get<0>(id_2611) };
                                      auto dtup_snd_511 { std::get<1>(id_2611) };
                                      ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c id_2613 { dtup_fst_507, dtup_fst_510 };
                                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2614 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<11>, id_2613) };
                                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2615 { id_2614, dtup_snd_511 };
                                      letpair_res_2612 = id_2615;
                                    }
                                    letpair_res_2610 = letpair_res_2612;
                                  }
                                  let_res_2609 = letpair_res_2610;
                                }
                                choose_res_2606 = let_res_2609;
                              } else {
                                uint16_t id_2616 { 12 };
                                bool id_2617 { bool(id_2616 == dsum1_fst_321) };
                                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2618;
                                if (id_2617) {
                                  uint32_t id_2619 { 0U };
                                  Vec<1, uint32_t> id_2620 {  id_2619  };
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2621;
                                  {
                                    Vec<1, uint32_t> leb_ref_485 { id_2620 };
                                    uint8_t id_2622 { 0 };
                                    Vec<1, uint8_t> id_2623 {  id_2622  };
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2624;
                                    {
                                      Vec<1, uint8_t> shft_ref_486 { id_2623 };
                                      Vec<1, Pointer> id_2625 {  dsum1_snd_322  };
                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2626;
                                      {
                                        Vec<1, Pointer> p_ref_487 { id_2625 };
                                        bool while_flag_2627 { true };
                                        do {
                                          uint8_t id_2628 { 0 };
                                          Pointer id_2629 { p_ref_487[id_2628] };
                                          ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2630 { id_2629.readU8() };
                                          bool let_res_2631;
                                          {
                                            ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_488 { id_2630 };
                                            bool letpair_res_2632;
                                            {
                                              auto leb128_fst_489 { std::get<0>(leb128_488) };
                                              auto leb128_snd_490 { std::get<1>(leb128_488) };
                                              uint8_t id_2633 { 0 };
                                              Void id_2634 { ((void)(p_ref_487[id_2633] = leb128_snd_490), ::dessser::VOID) };
                                              (void)id_2634;
                                              uint8_t id_2635 { 0 };
                                              uint8_t id_2636 { 127 };
                                              uint8_t id_2637 { uint8_t(leb128_fst_489 & id_2636) };
                                              uint32_t id_2638 { uint32_t(id_2637) };
                                              uint8_t id_2639 { 0 };
                                              uint8_t id_2640 { shft_ref_486[id_2639] };
                                              uint32_t id_2641 { uint32_t(id_2638 << id_2640) };
                                              uint8_t id_2642 { 0 };
                                              uint32_t id_2643 { leb_ref_485[id_2642] };
                                              uint32_t id_2644 { uint32_t(id_2641 | id_2643) };
                                              Void id_2645 { ((void)(leb_ref_485[id_2635] = id_2644), ::dessser::VOID) };
                                              (void)id_2645;
                                              uint8_t id_2646 { 0 };
                                              uint8_t id_2647 { 0 };
                                              uint8_t id_2648 { shft_ref_486[id_2647] };
                                              uint8_t id_2649 { 7 };
                                              uint8_t id_2650 { uint8_t(id_2648 + id_2649) };
                                              Void id_2651 { ((void)(shft_ref_486[id_2646] = id_2650), ::dessser::VOID) };
                                              (void)id_2651;
                                              uint8_t id_2652 { 128 };
                                              bool id_2653 { bool(leb128_fst_489 >= id_2652) };
                                              letpair_res_2632 = id_2653;
                                            }
                                            let_res_2631 = letpair_res_2632;
                                          }
                                          while_flag_2627 = let_res_2631;
                                          if (while_flag_2627) {
                                            (void)::dessser::VOID;
                                          }
                                        } while (while_flag_2627);
                                        (void)::dessser::VOID;
                                        uint8_t id_2654 { 0 };
                                        uint32_t id_2655 { leb_ref_485[id_2654] };
                                        Size id_2656 { Size(id_2655) };
                                        uint8_t id_2657 { 0 };
                                        Pointer id_2658 { p_ref_487[id_2657] };
                                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2659 { id_2656, id_2658 };
                                        let_res_2626 = id_2659;
                                      }
                                      let_res_2624 = let_res_2626;
                                    }
                                    let_res_2621 = let_res_2624;
                                  }
                                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2660;
                                  {
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_491 { let_res_2621 };
                                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2661;
                                    {
                                      auto dstring1_fst_492 { std::get<0>(dstring1_491) };
                                      auto dstring1_snd_493 { std::get<1>(dstring1_491) };
                                      ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2662 { dstring1_snd_493.readBytes(dstring1_fst_492) };
                                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2663;
                                      {
                                        auto dstring2_fst_495 { std::get<0>(id_2662) };
                                        auto dstring2_snd_496 { std::get<1>(id_2662) };
                                        std::string id_2664 { dstring2_fst_495.toString() };
                                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2665 { id_2664, dstring2_snd_496 };
                                        letpair_res_2663 = id_2665;
                                      }
                                      letpair_res_2661 = letpair_res_2663;
                                    }
                                    let_res_2660 = letpair_res_2661;
                                  }
                                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2666;
                                  {
                                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_497 { let_res_2660 };
                                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2667;
                                    {
                                      auto dtup_fst_498 { std::get<0>(dtup_497) };
                                      auto dtup_snd_499 { std::get<1>(dtup_497) };
                                      ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 id_2668 { per_dash_key_of_row_binary(dtup_snd_499) };
                                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2669;
                                      {
                                        auto dtup_fst_501 { std::get<0>(id_2668) };
                                        auto dtup_snd_502 { std::get<1>(id_2668) };
                                        ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_2670 { dtup_fst_498, dtup_fst_501 };
                                        std::shared_ptr<::dessser::gen::sync_key::t>  id_2671 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<12>, id_2670) };
                                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2672 { id_2671, dtup_snd_502 };
                                        letpair_res_2669 = id_2672;
                                      }
                                      letpair_res_2667 = letpair_res_2669;
                                    }
                                    let_res_2666 = letpair_res_2667;
                                  }
                                  choose_res_2618 = let_res_2666;
                                } else {
                                  uint16_t id_2673 { 13 };
                                  bool id_2674 { bool(id_2673 == dsum1_fst_321) };
                                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2675;
                                  if (id_2674) {
                                    (void)::dessser::VOID;
                                    std::shared_ptr<::dessser::gen::sync_key::t>  id_2676 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<13>, ::dessser::VOID) };
                                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2677 { id_2676, dsum1_snd_322 };
                                    choose_res_2675 = id_2677;
                                  } else {
                                    uint16_t id_2678 { 14 };
                                    bool id_2679 { bool(id_2678 == dsum1_fst_321) };
                                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2680;
                                    if (id_2679) {
                                      auto fun2681 { dessser::gen::team_name::of_row_binary };
                                      ::dessser::gen::sync_key::td204a4115a9974841e2d802fceb65890 id_2682 { fun2681(dsum1_snd_322) };
                                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2683;
                                      {
                                        ::dessser::gen::sync_key::td204a4115a9974841e2d802fceb65890 dtup_434 { id_2682 };
                                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2684;
                                        {
                                          auto dtup_fst_435 { std::get<0>(dtup_434) };
                                          auto dtup_snd_436 { std::get<1>(dtup_434) };
                                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2685 { dtup_snd_436.readU16Le() };
                                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2686;
                                          {
                                            auto du16_fst_438 { std::get<0>(id_2685) };
                                            auto du16_snd_439 { std::get<1>(id_2685) };
                                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2687 { du16_fst_438, du16_snd_439 };
                                            letpair_res_2686 = id_2687;
                                          }
                                          ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea let_res_2688;
                                          {
                                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_443 { letpair_res_2686 };
                                            ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea letpair_res_2689;
                                            {
                                              auto dsum1_fst_444 { std::get<0>(dsum1_443) };
                                              auto dsum1_snd_445 { std::get<1>(dsum1_443) };
                                              uint16_t id_2690 { 0 };
                                              bool id_2691 { bool(id_2690 == dsum1_fst_444) };
                                              ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea choose_res_2692;
                                              if (id_2691) {
                                                uint32_t id_2693 { 0U };
                                                Vec<1, uint32_t> id_2694 {  id_2693  };
                                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2695;
                                                {
                                                  Vec<1, uint32_t> leb_ref_461 { id_2694 };
                                                  uint8_t id_2696 { 0 };
                                                  Vec<1, uint8_t> id_2697 {  id_2696  };
                                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2698;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_462 { id_2697 };
                                                    Vec<1, Pointer> id_2699 {  dsum1_snd_445  };
                                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2700;
                                                    {
                                                      Vec<1, Pointer> p_ref_463 { id_2699 };
                                                      bool while_flag_2701 { true };
                                                      do {
                                                        uint8_t id_2702 { 0 };
                                                        Pointer id_2703 { p_ref_463[id_2702] };
                                                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2704 { id_2703.readU8() };
                                                        bool let_res_2705;
                                                        {
                                                          ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_464 { id_2704 };
                                                          bool letpair_res_2706;
                                                          {
                                                            auto leb128_fst_465 { std::get<0>(leb128_464) };
                                                            auto leb128_snd_466 { std::get<1>(leb128_464) };
                                                            uint8_t id_2707 { 0 };
                                                            Void id_2708 { ((void)(p_ref_463[id_2707] = leb128_snd_466), ::dessser::VOID) };
                                                            (void)id_2708;
                                                            uint8_t id_2709 { 0 };
                                                            uint8_t id_2710 { 127 };
                                                            uint8_t id_2711 { uint8_t(leb128_fst_465 & id_2710) };
                                                            uint32_t id_2712 { uint32_t(id_2711) };
                                                            uint8_t id_2713 { 0 };
                                                            uint8_t id_2714 { shft_ref_462[id_2713] };
                                                            uint32_t id_2715 { uint32_t(id_2712 << id_2714) };
                                                            uint8_t id_2716 { 0 };
                                                            uint32_t id_2717 { leb_ref_461[id_2716] };
                                                            uint32_t id_2718 { uint32_t(id_2715 | id_2717) };
                                                            Void id_2719 { ((void)(leb_ref_461[id_2709] = id_2718), ::dessser::VOID) };
                                                            (void)id_2719;
                                                            uint8_t id_2720 { 0 };
                                                            uint8_t id_2721 { 0 };
                                                            uint8_t id_2722 { shft_ref_462[id_2721] };
                                                            uint8_t id_2723 { 7 };
                                                            uint8_t id_2724 { uint8_t(id_2722 + id_2723) };
                                                            Void id_2725 { ((void)(shft_ref_462[id_2720] = id_2724), ::dessser::VOID) };
                                                            (void)id_2725;
                                                            uint8_t id_2726 { 128 };
                                                            bool id_2727 { bool(leb128_fst_465 >= id_2726) };
                                                            letpair_res_2706 = id_2727;
                                                          }
                                                          let_res_2705 = letpair_res_2706;
                                                        }
                                                        while_flag_2701 = let_res_2705;
                                                        if (while_flag_2701) {
                                                          (void)::dessser::VOID;
                                                        }
                                                      } while (while_flag_2701);
                                                      (void)::dessser::VOID;
                                                      uint8_t id_2728 { 0 };
                                                      uint32_t id_2729 { leb_ref_461[id_2728] };
                                                      Size id_2730 { Size(id_2729) };
                                                      uint8_t id_2731 { 0 };
                                                      Pointer id_2732 { p_ref_463[id_2731] };
                                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2733 { id_2730, id_2732 };
                                                      let_res_2700 = id_2733;
                                                    }
                                                    let_res_2698 = let_res_2700;
                                                  }
                                                  let_res_2695 = let_res_2698;
                                                }
                                                ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea let_res_2734;
                                                {
                                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_467 { let_res_2695 };
                                                  ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea letpair_res_2735;
                                                  {
                                                    auto dstring1_fst_468 { std::get<0>(dstring1_467) };
                                                    auto dstring1_snd_469 { std::get<1>(dstring1_467) };
                                                    ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2736 { dstring1_snd_469.readBytes(dstring1_fst_468) };
                                                    ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea letpair_res_2737;
                                                    {
                                                      auto dstring2_fst_471 { std::get<0>(id_2736) };
                                                      auto dstring2_snd_472 { std::get<1>(id_2736) };
                                                      std::string id_2738 { dstring2_fst_471.toString() };
                                                      ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_2739 { std::in_place_index<0>, id_2738 };
                                                      ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea id_2740 { id_2739, dstring2_snd_472 };
                                                      letpair_res_2737 = id_2740;
                                                    }
                                                    letpair_res_2735 = letpair_res_2737;
                                                  }
                                                  let_res_2734 = letpair_res_2735;
                                                }
                                                choose_res_2692 = let_res_2734;
                                              } else {
                                                uint16_t id_2741 { 1 };
                                                bool id_2742 { bool(dsum1_fst_444 == id_2741) };
                                                Void id_2743 { ((void)(assert(id_2742)), ::dessser::VOID) };
                                                (void)id_2743;
                                                uint32_t id_2744 { 0U };
                                                Vec<1, uint32_t> id_2745 {  id_2744  };
                                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2746;
                                                {
                                                  Vec<1, uint32_t> leb_ref_446 { id_2745 };
                                                  uint8_t id_2747 { 0 };
                                                  Vec<1, uint8_t> id_2748 {  id_2747  };
                                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2749;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_447 { id_2748 };
                                                    Vec<1, Pointer> id_2750 {  dsum1_snd_445  };
                                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2751;
                                                    {
                                                      Vec<1, Pointer> p_ref_448 { id_2750 };
                                                      bool while_flag_2752 { true };
                                                      do {
                                                        uint8_t id_2753 { 0 };
                                                        Pointer id_2754 { p_ref_448[id_2753] };
                                                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2755 { id_2754.readU8() };
                                                        bool let_res_2756;
                                                        {
                                                          ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_449 { id_2755 };
                                                          bool letpair_res_2757;
                                                          {
                                                            auto leb128_fst_450 { std::get<0>(leb128_449) };
                                                            auto leb128_snd_451 { std::get<1>(leb128_449) };
                                                            uint8_t id_2758 { 0 };
                                                            Void id_2759 { ((void)(p_ref_448[id_2758] = leb128_snd_451), ::dessser::VOID) };
                                                            (void)id_2759;
                                                            uint8_t id_2760 { 0 };
                                                            uint8_t id_2761 { 127 };
                                                            uint8_t id_2762 { uint8_t(leb128_fst_450 & id_2761) };
                                                            uint32_t id_2763 { uint32_t(id_2762) };
                                                            uint8_t id_2764 { 0 };
                                                            uint8_t id_2765 { shft_ref_447[id_2764] };
                                                            uint32_t id_2766 { uint32_t(id_2763 << id_2765) };
                                                            uint8_t id_2767 { 0 };
                                                            uint32_t id_2768 { leb_ref_446[id_2767] };
                                                            uint32_t id_2769 { uint32_t(id_2766 | id_2768) };
                                                            Void id_2770 { ((void)(leb_ref_446[id_2760] = id_2769), ::dessser::VOID) };
                                                            (void)id_2770;
                                                            uint8_t id_2771 { 0 };
                                                            uint8_t id_2772 { 0 };
                                                            uint8_t id_2773 { shft_ref_447[id_2772] };
                                                            uint8_t id_2774 { 7 };
                                                            uint8_t id_2775 { uint8_t(id_2773 + id_2774) };
                                                            Void id_2776 { ((void)(shft_ref_447[id_2771] = id_2775), ::dessser::VOID) };
                                                            (void)id_2776;
                                                            uint8_t id_2777 { 128 };
                                                            bool id_2778 { bool(leb128_fst_450 >= id_2777) };
                                                            letpair_res_2757 = id_2778;
                                                          }
                                                          let_res_2756 = letpair_res_2757;
                                                        }
                                                        while_flag_2752 = let_res_2756;
                                                        if (while_flag_2752) {
                                                          (void)::dessser::VOID;
                                                        }
                                                      } while (while_flag_2752);
                                                      (void)::dessser::VOID;
                                                      uint8_t id_2779 { 0 };
                                                      uint32_t id_2780 { leb_ref_446[id_2779] };
                                                      Size id_2781 { Size(id_2780) };
                                                      uint8_t id_2782 { 0 };
                                                      Pointer id_2783 { p_ref_448[id_2782] };
                                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2784 { id_2781, id_2783 };
                                                      let_res_2751 = id_2784;
                                                    }
                                                    let_res_2749 = let_res_2751;
                                                  }
                                                  let_res_2746 = let_res_2749;
                                                }
                                                ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea let_res_2785;
                                                {
                                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_452 { let_res_2746 };
                                                  ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea letpair_res_2786;
                                                  {
                                                    auto dstring1_fst_453 { std::get<0>(dstring1_452) };
                                                    auto dstring1_snd_454 { std::get<1>(dstring1_452) };
                                                    ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2787 { dstring1_snd_454.readBytes(dstring1_fst_453) };
                                                    ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea letpair_res_2788;
                                                    {
                                                      auto dstring2_fst_456 { std::get<0>(id_2787) };
                                                      auto dstring2_snd_457 { std::get<1>(id_2787) };
                                                      std::string id_2789 { dstring2_fst_456.toString() };
                                                      ::dessser::gen::sync_key::t30dc3dcca77170cf1e1cb9d48379ab77 id_2790 { std::in_place_index<1>, id_2789 };
                                                      ::dessser::gen::sync_key::td61542ca3754c3b2859a4da2d9287bea id_2791 { id_2790, dstring2_snd_457 };
                                                      letpair_res_2788 = id_2791;
                                                    }
                                                    letpair_res_2786 = letpair_res_2788;
                                                  }
                                                  let_res_2785 = letpair_res_2786;
                                                }
                                                choose_res_2692 = let_res_2785;
                                              }
                                              letpair_res_2689 = choose_res_2692;
                                            }
                                            let_res_2688 = letpair_res_2689;
                                          }
                                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2792;
                                          {
                                            auto dtup_fst_477 { std::get<0>(let_res_2688) };
                                            auto dtup_snd_478 { std::get<1>(let_res_2688) };
                                            ::dessser::gen::sync_key::tdb06243db69543aa6c581d0479aed01a id_2793 { dtup_fst_435, dtup_fst_477 };
                                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2794 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<14>, id_2793) };
                                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2795 { id_2794, dtup_snd_478 };
                                            letpair_res_2792 = id_2795;
                                          }
                                          letpair_res_2684 = letpair_res_2792;
                                        }
                                        let_res_2683 = letpair_res_2684;
                                      }
                                      choose_res_2680 = let_res_2683;
                                    } else {
                                      uint16_t id_2796 { 15 };
                                      bool id_2797 { bool(dsum1_fst_321 == id_2796) };
                                      Void id_2798 { ((void)(assert(id_2797)), ::dessser::VOID) };
                                      (void)id_2798;
                                      uint32_t id_2799 { 0U };
                                      Vec<1, uint32_t> id_2800 {  id_2799  };
                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2801;
                                      {
                                        Vec<1, uint32_t> leb_ref_323 { id_2800 };
                                        uint8_t id_2802 { 0 };
                                        Vec<1, uint8_t> id_2803 {  id_2802  };
                                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2804;
                                        {
                                          Vec<1, uint8_t> shft_ref_324 { id_2803 };
                                          Vec<1, Pointer> id_2805 {  dsum1_snd_322  };
                                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2806;
                                          {
                                            Vec<1, Pointer> p_ref_325 { id_2805 };
                                            bool while_flag_2807 { true };
                                            do {
                                              uint8_t id_2808 { 0 };
                                              Pointer id_2809 { p_ref_325[id_2808] };
                                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2810 { id_2809.readU8() };
                                              bool let_res_2811;
                                              {
                                                ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_326 { id_2810 };
                                                bool letpair_res_2812;
                                                {
                                                  auto leb128_fst_327 { std::get<0>(leb128_326) };
                                                  auto leb128_snd_328 { std::get<1>(leb128_326) };
                                                  uint8_t id_2813 { 0 };
                                                  Void id_2814 { ((void)(p_ref_325[id_2813] = leb128_snd_328), ::dessser::VOID) };
                                                  (void)id_2814;
                                                  uint8_t id_2815 { 0 };
                                                  uint8_t id_2816 { 127 };
                                                  uint8_t id_2817 { uint8_t(leb128_fst_327 & id_2816) };
                                                  uint32_t id_2818 { uint32_t(id_2817) };
                                                  uint8_t id_2819 { 0 };
                                                  uint8_t id_2820 { shft_ref_324[id_2819] };
                                                  uint32_t id_2821 { uint32_t(id_2818 << id_2820) };
                                                  uint8_t id_2822 { 0 };
                                                  uint32_t id_2823 { leb_ref_323[id_2822] };
                                                  uint32_t id_2824 { uint32_t(id_2821 | id_2823) };
                                                  Void id_2825 { ((void)(leb_ref_323[id_2815] = id_2824), ::dessser::VOID) };
                                                  (void)id_2825;
                                                  uint8_t id_2826 { 0 };
                                                  uint8_t id_2827 { 0 };
                                                  uint8_t id_2828 { shft_ref_324[id_2827] };
                                                  uint8_t id_2829 { 7 };
                                                  uint8_t id_2830 { uint8_t(id_2828 + id_2829) };
                                                  Void id_2831 { ((void)(shft_ref_324[id_2826] = id_2830), ::dessser::VOID) };
                                                  (void)id_2831;
                                                  uint8_t id_2832 { 128 };
                                                  bool id_2833 { bool(leb128_fst_327 >= id_2832) };
                                                  letpair_res_2812 = id_2833;
                                                }
                                                let_res_2811 = letpair_res_2812;
                                              }
                                              while_flag_2807 = let_res_2811;
                                              if (while_flag_2807) {
                                                (void)::dessser::VOID;
                                              }
                                            } while (while_flag_2807);
                                            (void)::dessser::VOID;
                                            uint8_t id_2834 { 0 };
                                            uint32_t id_2835 { leb_ref_323[id_2834] };
                                            Size id_2836 { Size(id_2835) };
                                            uint8_t id_2837 { 0 };
                                            Pointer id_2838 { p_ref_325[id_2837] };
                                            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2839 { id_2836, id_2838 };
                                            let_res_2806 = id_2839;
                                          }
                                          let_res_2804 = let_res_2806;
                                        }
                                        let_res_2801 = let_res_2804;
                                      }
                                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2840;
                                      {
                                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_329 { let_res_2801 };
                                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2841;
                                        {
                                          auto dstring1_fst_330 { std::get<0>(dstring1_329) };
                                          auto dstring1_snd_331 { std::get<1>(dstring1_329) };
                                          ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2842 { dstring1_snd_331.readBytes(dstring1_fst_330) };
                                          ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2843;
                                          {
                                            auto dstring2_fst_333 { std::get<0>(id_2842) };
                                            auto dstring2_snd_334 { std::get<1>(id_2842) };
                                            std::string id_2844 { dstring2_fst_333.toString() };
                                            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2845 { id_2844, dstring2_snd_334 };
                                            letpair_res_2843 = id_2845;
                                          }
                                          letpair_res_2841 = letpair_res_2843;
                                        }
                                        let_res_2840 = letpair_res_2841;
                                      }
                                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2846;
                                      {
                                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_335 { let_res_2840 };
                                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2847;
                                        {
                                          auto dtup_fst_336 { std::get<0>(dtup_335) };
                                          auto dtup_snd_337 { std::get<1>(dtup_335) };
                                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2848 { dtup_snd_337.readU16Le() };
                                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2849;
                                          {
                                            auto du16_fst_339 { std::get<0>(id_2848) };
                                            auto du16_snd_340 { std::get<1>(id_2848) };
                                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2850 { du16_fst_339, du16_snd_340 };
                                            letpair_res_2849 = id_2850;
                                          }
                                          ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e let_res_2851;
                                          {
                                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_344 { letpair_res_2849 };
                                            ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e letpair_res_2852;
                                            {
                                              auto dsum1_fst_345 { std::get<0>(dsum1_344) };
                                              auto dsum1_snd_346 { std::get<1>(dsum1_344) };
                                              uint16_t id_2853 { 0 };
                                              bool id_2854 { bool(id_2853 == dsum1_fst_345) };
                                              ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e choose_res_2855;
                                              if (id_2854) {
                                                (void)::dessser::VOID;
                                                ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_2856 { std::in_place_index<0>, ::dessser::VOID };
                                                ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e id_2857 { id_2856, dsum1_snd_346 };
                                                choose_res_2855 = id_2857;
                                              } else {
                                                uint16_t id_2858 { 1 };
                                                bool id_2859 { bool(id_2858 == dsum1_fst_345) };
                                                ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e choose_res_2860;
                                                if (id_2859) {
                                                  (void)::dessser::VOID;
                                                  ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_2861 { std::in_place_index<1>, ::dessser::VOID };
                                                  ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e id_2862 { id_2861, dsum1_snd_346 };
                                                  choose_res_2860 = id_2862;
                                                } else {
                                                  uint16_t id_2863 { 2 };
                                                  bool id_2864 { bool(id_2863 == dsum1_fst_345) };
                                                  ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e choose_res_2865;
                                                  if (id_2864) {
                                                    (void)::dessser::VOID;
                                                    ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_2866 { std::in_place_index<2>, ::dessser::VOID };
                                                    ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e id_2867 { id_2866, dsum1_snd_346 };
                                                    choose_res_2865 = id_2867;
                                                  } else {
                                                    uint16_t id_2868 { 3 };
                                                    bool id_2869 { bool(id_2868 == dsum1_fst_345) };
                                                    ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e choose_res_2870;
                                                    if (id_2869) {
                                                      (void)::dessser::VOID;
                                                      ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_2871 { std::in_place_index<3>, ::dessser::VOID };
                                                      ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e id_2872 { id_2871, dsum1_snd_346 };
                                                      choose_res_2870 = id_2872;
                                                    } else {
                                                      uint16_t id_2873 { 4 };
                                                      bool id_2874 { bool(id_2873 == dsum1_fst_345) };
                                                      ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e choose_res_2875;
                                                      if (id_2874) {
                                                        (void)::dessser::VOID;
                                                        ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_2876 { std::in_place_index<4>, ::dessser::VOID };
                                                        ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e id_2877 { id_2876, dsum1_snd_346 };
                                                        choose_res_2875 = id_2877;
                                                      } else {
                                                        uint16_t id_2878 { 5 };
                                                        bool id_2879 { bool(id_2878 == dsum1_fst_345) };
                                                        ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e choose_res_2880;
                                                        if (id_2879) {
                                                          uint32_t id_2881 { 0U };
                                                          Vec<1, uint32_t> id_2882 {  id_2881  };
                                                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2883;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_362 { id_2882 };
                                                            uint8_t id_2884 { 0 };
                                                            Vec<1, uint8_t> id_2885 {  id_2884  };
                                                            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2886;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_363 { id_2885 };
                                                              Vec<1, Pointer> id_2887 {  dsum1_snd_346  };
                                                              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2888;
                                                              {
                                                                Vec<1, Pointer> p_ref_364 { id_2887 };
                                                                bool while_flag_2889 { true };
                                                                do {
                                                                  uint8_t id_2890 { 0 };
                                                                  Pointer id_2891 { p_ref_364[id_2890] };
                                                                  ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2892 { id_2891.readU8() };
                                                                  bool let_res_2893;
                                                                  {
                                                                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_365 { id_2892 };
                                                                    bool letpair_res_2894;
                                                                    {
                                                                      auto leb128_fst_366 { std::get<0>(leb128_365) };
                                                                      auto leb128_snd_367 { std::get<1>(leb128_365) };
                                                                      uint8_t id_2895 { 0 };
                                                                      Void id_2896 { ((void)(p_ref_364[id_2895] = leb128_snd_367), ::dessser::VOID) };
                                                                      (void)id_2896;
                                                                      uint8_t id_2897 { 0 };
                                                                      uint8_t id_2898 { 127 };
                                                                      uint8_t id_2899 { uint8_t(leb128_fst_366 & id_2898) };
                                                                      uint32_t id_2900 { uint32_t(id_2899) };
                                                                      uint8_t id_2901 { 0 };
                                                                      uint8_t id_2902 { shft_ref_363[id_2901] };
                                                                      uint32_t id_2903 { uint32_t(id_2900 << id_2902) };
                                                                      uint8_t id_2904 { 0 };
                                                                      uint32_t id_2905 { leb_ref_362[id_2904] };
                                                                      uint32_t id_2906 { uint32_t(id_2903 | id_2905) };
                                                                      Void id_2907 { ((void)(leb_ref_362[id_2897] = id_2906), ::dessser::VOID) };
                                                                      (void)id_2907;
                                                                      uint8_t id_2908 { 0 };
                                                                      uint8_t id_2909 { 0 };
                                                                      uint8_t id_2910 { shft_ref_363[id_2909] };
                                                                      uint8_t id_2911 { 7 };
                                                                      uint8_t id_2912 { uint8_t(id_2910 + id_2911) };
                                                                      Void id_2913 { ((void)(shft_ref_363[id_2908] = id_2912), ::dessser::VOID) };
                                                                      (void)id_2913;
                                                                      uint8_t id_2914 { 128 };
                                                                      bool id_2915 { bool(leb128_fst_366 >= id_2914) };
                                                                      letpair_res_2894 = id_2915;
                                                                    }
                                                                    let_res_2893 = letpair_res_2894;
                                                                  }
                                                                  while_flag_2889 = let_res_2893;
                                                                  if (while_flag_2889) {
                                                                    (void)::dessser::VOID;
                                                                  }
                                                                } while (while_flag_2889);
                                                                (void)::dessser::VOID;
                                                                uint8_t id_2916 { 0 };
                                                                uint32_t id_2917 { leb_ref_362[id_2916] };
                                                                Size id_2918 { Size(id_2917) };
                                                                uint8_t id_2919 { 0 };
                                                                Pointer id_2920 { p_ref_364[id_2919] };
                                                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2921 { id_2918, id_2920 };
                                                                let_res_2888 = id_2921;
                                                              }
                                                              let_res_2886 = let_res_2888;
                                                            }
                                                            let_res_2883 = let_res_2886;
                                                          }
                                                          ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2922;
                                                          {
                                                            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_368 { let_res_2883 };
                                                            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2923;
                                                            {
                                                              auto dstring1_fst_369 { std::get<0>(dstring1_368) };
                                                              auto dstring1_snd_370 { std::get<1>(dstring1_368) };
                                                              ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2924 { dstring1_snd_370.readBytes(dstring1_fst_369) };
                                                              ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2925;
                                                              {
                                                                auto dstring2_fst_372 { std::get<0>(id_2924) };
                                                                auto dstring2_snd_373 { std::get<1>(id_2924) };
                                                                std::string id_2926 { dstring2_fst_372.toString() };
                                                                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2927 { id_2926, dstring2_snd_373 };
                                                                letpair_res_2925 = id_2927;
                                                              }
                                                              letpair_res_2923 = letpair_res_2925;
                                                            }
                                                            let_res_2922 = letpair_res_2923;
                                                          }
                                                          ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e let_res_2928;
                                                          {
                                                            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_374 { let_res_2922 };
                                                            ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e letpair_res_2929;
                                                            {
                                                              auto dtup_fst_375 { std::get<0>(dtup_374) };
                                                              auto dtup_snd_376 { std::get<1>(dtup_374) };
                                                              ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2930 { dtup_snd_376.readU16Le() };
                                                              ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2931;
                                                              {
                                                                auto du16_fst_378 { std::get<0>(id_2930) };
                                                                auto du16_snd_379 { std::get<1>(id_2930) };
                                                                ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2932 { du16_fst_378, du16_snd_379 };
                                                                letpair_res_2931 = id_2932;
                                                              }
                                                              ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf let_res_2933;
                                                              {
                                                                ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_383 { letpair_res_2931 };
                                                                ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf letpair_res_2934;
                                                                {
                                                                  auto dsum1_fst_384 { std::get<0>(dsum1_383) };
                                                                  auto dsum1_snd_385 { std::get<1>(dsum1_383) };
                                                                  uint16_t id_2935 { 0 };
                                                                  bool id_2936 { bool(id_2935 == dsum1_fst_384) };
                                                                  ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf choose_res_2937;
                                                                  if (id_2936) {
                                                                    (void)::dessser::VOID;
                                                                    ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a id_2938 { std::in_place_index<0>, ::dessser::VOID };
                                                                    ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf id_2939 { id_2938, dsum1_snd_385 };
                                                                    choose_res_2937 = id_2939;
                                                                  } else {
                                                                    uint16_t id_2940 { 1 };
                                                                    bool id_2941 { bool(id_2940 == dsum1_fst_384) };
                                                                    ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf choose_res_2942;
                                                                    if (id_2941) {
                                                                      (void)::dessser::VOID;
                                                                      ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a id_2943 { std::in_place_index<1>, ::dessser::VOID };
                                                                      ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf id_2944 { id_2943, dsum1_snd_385 };
                                                                      choose_res_2942 = id_2944;
                                                                    } else {
                                                                      uint16_t id_2945 { 2 };
                                                                      bool id_2946 { bool(id_2945 == dsum1_fst_384) };
                                                                      ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf choose_res_2947;
                                                                      if (id_2946) {
                                                                        (void)::dessser::VOID;
                                                                        ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a id_2948 { std::in_place_index<2>, ::dessser::VOID };
                                                                        ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf id_2949 { id_2948, dsum1_snd_385 };
                                                                        choose_res_2947 = id_2949;
                                                                      } else {
                                                                        uint16_t id_2950 { 3 };
                                                                        bool id_2951 { bool(id_2950 == dsum1_fst_384) };
                                                                        ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf choose_res_2952;
                                                                        if (id_2951) {
                                                                          (void)::dessser::VOID;
                                                                          ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a id_2953 { std::in_place_index<3>, ::dessser::VOID };
                                                                          ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf id_2954 { id_2953, dsum1_snd_385 };
                                                                          choose_res_2952 = id_2954;
                                                                        } else {
                                                                          uint16_t id_2955 { 4 };
                                                                          bool id_2956 { bool(id_2955 == dsum1_fst_384) };
                                                                          ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf choose_res_2957;
                                                                          if (id_2956) {
                                                                            (void)::dessser::VOID;
                                                                            ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a id_2958 { std::in_place_index<4>, ::dessser::VOID };
                                                                            ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf id_2959 { id_2958, dsum1_snd_385 };
                                                                            choose_res_2957 = id_2959;
                                                                          } else {
                                                                            uint16_t id_2960 { 5 };
                                                                            bool id_2961 { bool(id_2960 == dsum1_fst_384) };
                                                                            ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf choose_res_2962;
                                                                            if (id_2961) {
                                                                              (void)::dessser::VOID;
                                                                              ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a id_2963 { std::in_place_index<5>, ::dessser::VOID };
                                                                              ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf id_2964 { id_2963, dsum1_snd_385 };
                                                                              choose_res_2962 = id_2964;
                                                                            } else {
                                                                              uint16_t id_2965 { 6 };
                                                                              bool id_2966 { bool(dsum1_fst_384 == id_2965) };
                                                                              Void id_2967 { ((void)(assert(id_2966)), ::dessser::VOID) };
                                                                              (void)id_2967;
                                                                              (void)::dessser::VOID;
                                                                              ::dessser::gen::sync_key::t79ebb6356ea2c5020930921b51ef4e3a id_2968 { std::in_place_index<6>, ::dessser::VOID };
                                                                              ::dessser::gen::sync_key::tce8ec428a5acd1f0e7adb8d93fe37cdf id_2969 { id_2968, dsum1_snd_385 };
                                                                              choose_res_2962 = id_2969;
                                                                            }
                                                                            choose_res_2957 = choose_res_2962;
                                                                          }
                                                                          choose_res_2952 = choose_res_2957;
                                                                        }
                                                                        choose_res_2947 = choose_res_2952;
                                                                      }
                                                                      choose_res_2942 = choose_res_2947;
                                                                    }
                                                                    choose_res_2937 = choose_res_2942;
                                                                  }
                                                                  letpair_res_2934 = choose_res_2937;
                                                                }
                                                                let_res_2933 = letpair_res_2934;
                                                              }
                                                              ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e letpair_res_2970;
                                                              {
                                                                auto dtup_fst_408 { std::get<0>(let_res_2933) };
                                                                auto dtup_snd_409 { std::get<1>(let_res_2933) };
                                                                ::dessser::gen::sync_key::t8790f8724a8266402c08dc86b40c110a id_2971 { dtup_fst_375, dtup_fst_408 };
                                                                ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_2972 { std::in_place_index<5>, id_2971 };
                                                                ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e id_2973 { id_2972, dtup_snd_409 };
                                                                letpair_res_2970 = id_2973;
                                                              }
                                                              letpair_res_2929 = letpair_res_2970;
                                                            }
                                                            let_res_2928 = letpair_res_2929;
                                                          }
                                                          choose_res_2880 = let_res_2928;
                                                        } else {
                                                          uint16_t id_2974 { 6 };
                                                          bool id_2975 { bool(dsum1_fst_345 == id_2974) };
                                                          Void id_2976 { ((void)(assert(id_2975)), ::dessser::VOID) };
                                                          (void)id_2976;
                                                          ::dessser::gen::sync_key::td2cd337bb3c8bc04d5603393d084985b id_2977 { dsum1_snd_346.readU64Le() };
                                                          ::dessser::gen::sync_key::t9a758baeff17224a77e1a522010b4168 letpair_res_2978;
                                                          {
                                                            auto dfloat_fst_348 { std::get<0>(id_2977) };
                                                            auto dfloat_snd_349 { std::get<1>(id_2977) };
                                                            double id_2979 { float_of_qword(dfloat_fst_348) };
                                                            ::dessser::gen::sync_key::t9a758baeff17224a77e1a522010b4168 id_2980 { id_2979, dfloat_snd_349 };
                                                            letpair_res_2978 = id_2980;
                                                          }
                                                          ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e let_res_2981;
                                                          {
                                                            ::dessser::gen::sync_key::t9a758baeff17224a77e1a522010b4168 dtup_350 { letpair_res_2978 };
                                                            ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e letpair_res_2982;
                                                            {
                                                              auto dtup_fst_351 { std::get<0>(dtup_350) };
                                                              auto dtup_snd_352 { std::get<1>(dtup_350) };
                                                              ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_2983 { dtup_snd_352.readU32Le() };
                                                              ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e letpair_res_2984;
                                                              {
                                                                auto du32_fst_354 { std::get<0>(id_2983) };
                                                                auto du32_snd_355 { std::get<1>(id_2983) };
                                                                ::dessser::gen::sync_key::taf1e37f579ece7fa9db5670cfd23039b id_2985 { dtup_fst_351, du32_fst_354 };
                                                                ::dessser::gen::sync_key::t28c98086737a6a32e1b0783ceb1c4a02 id_2986 { std::in_place_index<6>, id_2985 };
                                                                ::dessser::gen::sync_key::tab59127137d5c6f7f536acfcb79eef6e id_2987 { id_2986, du32_snd_355 };
                                                                letpair_res_2984 = id_2987;
                                                              }
                                                              letpair_res_2982 = letpair_res_2984;
                                                            }
                                                            let_res_2981 = letpair_res_2982;
                                                          }
                                                          choose_res_2880 = let_res_2981;
                                                        }
                                                        choose_res_2875 = choose_res_2880;
                                                      }
                                                      choose_res_2870 = choose_res_2875;
                                                    }
                                                    choose_res_2865 = choose_res_2870;
                                                  }
                                                  choose_res_2860 = choose_res_2865;
                                                }
                                                choose_res_2855 = choose_res_2860;
                                              }
                                              letpair_res_2852 = choose_res_2855;
                                            }
                                            let_res_2851 = letpair_res_2852;
                                          }
                                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2988;
                                          {
                                            auto dtup_fst_429 { std::get<0>(let_res_2851) };
                                            auto dtup_snd_430 { std::get<1>(let_res_2851) };
                                            ::dessser::gen::sync_key::t51f195064564f7c62f51e21289134f76 id_2989 { dtup_fst_336, dtup_fst_429 };
                                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2990 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<15>, id_2989) };
                                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2991 { id_2990, dtup_snd_430 };
                                            letpair_res_2988 = id_2991;
                                          }
                                          letpair_res_2847 = letpair_res_2988;
                                        }
                                        let_res_2846 = letpair_res_2847;
                                      }
                                      choose_res_2680 = let_res_2846;
                                    }
                                    choose_res_2675 = choose_res_2680;
                                  }
                                  choose_res_2618 = choose_res_2675;
                                }
                                choose_res_2606 = choose_res_2618;
                              }
                              choose_res_2601 = choose_res_2606;
                            }
                            choose_res_2579 = choose_res_2601;
                          }
                          choose_res_2572 = choose_res_2579;
                        }
                        choose_res_2507 = choose_res_2572;
                      }
                      choose_res_2435 = choose_res_2507;
                    }
                    choose_res_2428 = choose_res_2435;
                  }
                  choose_res_2423 = choose_res_2428;
                }
                choose_res_2367 = choose_res_2423;
              }
              choose_res_2316 = choose_res_2367;
            }
            choose_res_2311 = choose_res_2316;
          }
          choose_res_2306 = choose_res_2311;
        }
        letpair_res_2303 = choose_res_2306;
      }
      let_res_2302 = letpair_res_2303;
    }
    return let_res_2302;
  }
   };
  return fun2298;
}
std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_639" "make_snd_640" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_639") (identifier "make_snd_640"))))
 */
static std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> fun2992 { [&fun2992](Pointer p_0) {
    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2993 { of_row_binary(p_0) };
    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2994;
    {
      auto make_fst_639 { std::get<0>(id_2993) };
      auto make_snd_640 { std::get<1>(id_2993) };
      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2995 { make_fst_639, make_snd_640 };
      letpair_res_2994 = id_2995;
    }
    return letpair_res_2994;
  }
   };
  return fun2992;
}
std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> fun2996 { [&fun2996](std::shared_ptr<::dessser::gen::sync_key::t>  p_0, Pointer p_1) {
    Pointer id_2997 { to_row_binary(p_0, p_1) };
    return id_2997;
  }
   };
  return fun2996;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
