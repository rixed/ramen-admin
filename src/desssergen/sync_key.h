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
enum Constr_t0193f94945d5c55637b2beab1e77dc5c {
  StateFile,
  InputRingFile,
  Pid,
  LastKilled,
  LastExit,
  LastExitStatus,
  SuccessiveFailures,
  QuarantineUntil,
};

inline std::ostream &operator<<(std::ostream &os, t0193f94945d5c55637b2beab1e77dc5c const &v) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0193f94945d5c55637b2beab1e77dc5c> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t21e5dc291e02ff6b92981a2d2fa864dc const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t21e5dc291e02ff6b92981a2d2fa864dc> const t) { os << *t; return os; }

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
  per_worker(std::tuple<dessser::gen::fq_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_worker_data> > p)
    : std::tuple<dessser::gen::fq_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_worker_data> >(std::get<0>(p), std::get<1>(p)) {}
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
enum Constr_t64f559dd09cb0d16d29224992777183c {
  Host,
  Port,
};

inline std::ostream &operator<<(std::ostream &os, t64f559dd09cb0d16d29224992777183c const &v) {
  switch (v.index()) {
    case 0: os << "Host" << std::get<0>(v); break;
    case 1: os << "Port" << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t64f559dd09cb0d16d29224992777183c> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t9a3e45e6c9736129ff8eafaa89ab1b6a const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t9a3e45e6c9736129ff8eafaa89ab1b6a> const t) { os << *t; return os; }

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
enum Constr_tea8c2377036e530fd3f67fa8653a3834 {
  Executable,
};

inline std::ostream &operator<<(std::ostream &os, tea8c2377036e530fd3f67fa8653a3834 const &v) {
  switch (v.index()) {
    case 0: os << "Executable" << std::get<0>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tea8c2377036e530fd3f67fa8653a3834> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, td7912e294d6f3a12e8335070433dc663 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<td7912e294d6f3a12e8335070433dc663> const t) { os << *t; return os; }

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
  per_site(std::tuple<dessser::gen::site_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_site_data> > p)
    : std::tuple<dessser::gen::site_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_site_data> >(std::get<0>(p), std::get<1>(p)) {}
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
inline std::ostream &operator<<(std::ostream &os, t5dbfadfb7b29c686ebe36a9b92f12903 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t5dbfadfb7b29c686ebe36a9b92f12903> const t) { os << *t; return os; }

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
enum Constr_t803a3c9022c32e1702f6b5e3eaa82fb3 {
  TotalSize,
  RecallCost,
  RetentionsOverride,
};

inline std::ostream &operator<<(std::ostream &os, t803a3c9022c32e1702f6b5e3eaa82fb3 const &v) {
  switch (v.index()) {
    case 0: os << "TotalSize" << std::get<0>(v); break;
    case 1: os << "RecallCost" << std::get<1>(v); break;
    case 2: os << "RetentionsOverride " << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t803a3c9022c32e1702f6b5e3eaa82fb3> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t5ea3af2f8623cdaebfc7634cbf90ee9c const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t5ea3af2f8623cdaebfc7634cbf90ee9c> const t) { os << *t; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t5f85ea99fc65adca3880884cd8e9f15d const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t5f85ea99fc65adca3880884cd8e9f15d> const t) { os << *t; return os; }

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
enum Constr_t30dc3dcca77170cf1e1cb9d48379ab77 {
  Contacts,
  Inhibition,
};

inline std::ostream &operator<<(std::ostream &os, t30dc3dcca77170cf1e1cb9d48379ab77 const &v) {
  switch (v.index()) {
    case 0: os << "Contacts " << std::get<0>(v); break;
    case 1: os << "Inhibition " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t30dc3dcca77170cf1e1cb9d48379ab77> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, tdb06243db69543aa6c581d0479aed01a const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tdb06243db69543aa6c581d0479aed01a> const t) { os << *t; return os; }

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
enum Constr_t79ebb6356ea2c5020930921b51ef4e3a {
  NumDeliveryAttempts,
  FirstDeliveryAttempt,
  LastDeliveryAttempt,
  NextScheduled,
  NextSend,
  DeliveryStatus,
  Ack,
};

inline std::ostream &operator<<(std::ostream &os, t79ebb6356ea2c5020930921b51ef4e3a const &v) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t79ebb6356ea2c5020930921b51ef4e3a> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t8790f8724a8266402c08dc86b40c110a const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t8790f8724a8266402c08dc86b40c110a> const t) { os << *t; return os; }

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
inline std::ostream &operator<<(std::ostream &os, taf1e37f579ece7fa9db5670cfd23039b const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<taf1e37f579ece7fa9db5670cfd23039b> const t) { os << *t; return os; }

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
enum Constr_t28c98086737a6a32e1b0783ceb1c4a02 {
  FirstStartNotif,
  LastStartNotif,
  LastStopNotif,
  LastStateChangeNotif,
  Team,
  Dialogs,
  Journal,
};

inline std::ostream &operator<<(std::ostream &os, t28c98086737a6a32e1b0783ceb1c4a02 const &v) {
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t28c98086737a6a32e1b0783ceb1c4a02> const v) { os << *v; return os; }

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
inline std::ostream &operator<<(std::ostream &os, t51f195064564f7c62f51e21289134f76 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t51f195064564f7c62f51e21289134f76> const t) { os << *t; return os; }

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
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> per_dash_key_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> per_client_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> per_tail_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,Pointer)> per_worker_data_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker> ,Pointer)> per_worker_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,Pointer)> per_site_data_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site> ,Pointer)> per_site_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> per_dash_key_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> per_client_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> per_tail_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> )> per_worker_data_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker> )> per_worker_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site_data> )> per_site_data_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site> )> per_site_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> sersize_of_row_binary;
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
