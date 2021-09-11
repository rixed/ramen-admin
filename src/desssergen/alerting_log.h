#ifndef DESSSER_GEN_alerting_log
#define DESSSER_GEN_alerting_log
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::alerting_log {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t89816cbdea496c3fdf253c2ff7eb9816 : public std::variant<
  Void, // Duplicate
  Void, // Inhibited
  Void, // STFU
  Void // StartEscalation
> { using variant::variant; };

enum Constr_t89816cbdea496c3fdf253c2ff7eb9816 {
  Duplicate,
  Inhibited,
  STFU,
  StartEscalation,
};

inline std::ostream &operator<<(std::ostream &os, t89816cbdea496c3fdf253c2ff7eb9816 const &v) {
  switch (v.index()) {
    case 0: os << "Duplicate " << std::get<0>(v); break;
    case 1: os << "Inhibited " << std::get<1>(v); break;
    case 2: os << "STFU " << std::get<2>(v); break;
    case 3: os << "StartEscalation " << std::get<3>(v); break;
  }
  return os;
}

inline bool operator==(t89816cbdea496c3fdf253c2ff7eb9816 const &a, t89816cbdea496c3fdf253c2ff7eb9816 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Duplicate
    case 1: return std::get<1>(a) == std::get<1>(b); // Inhibited
    case 2: return std::get<2>(a) == std::get<2>(b); // STFU
    case 3: return std::get<3>(a) == std::get<3>(b); // StartEscalation
  };
  return false;
}
inline bool operator!=(t89816cbdea496c3fdf253c2ff7eb9816 const &a, t89816cbdea496c3fdf253c2ff7eb9816 const &b) {
  return !operator==(a, b);
}
struct t634cf874353f100ca9a3d84e2b6c3c4b : public std::tuple<
  std::string,
  uint32_t
> {
  using tuple::tuple;
  t634cf874353f100ca9a3d84e2b6c3c4b(std::tuple<std::string, uint32_t> p)
    : std::tuple<std::string, uint32_t>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t634cf874353f100ca9a3d84e2b6c3c4b const &a, t634cf874353f100ca9a3d84e2b6c3c4b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t634cf874353f100ca9a3d84e2b6c3c4b const &a, t634cf874353f100ca9a3d84e2b6c3c4b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t634cf874353f100ca9a3d84e2b6c3c4b const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct tc13ab978611f6f6c6f0eb7ff36eb72f4 : public std::variant<
  Void, // Notification
  std::string, // Manual
  std::string // Timeout
> { using variant::variant; };

enum Constr_tc13ab978611f6f6c6f0eb7ff36eb72f4 {
  Notification,
  Manual,
  Timeout,
};

inline std::ostream &operator<<(std::ostream &os, tc13ab978611f6f6c6f0eb7ff36eb72f4 const &v) {
  switch (v.index()) {
    case 0: os << "Notification " << std::get<0>(v); break;
    case 1: os << "Manual " << std::get<1>(v); break;
    case 2: os << "Timeout " << std::get<2>(v); break;
  }
  return os;
}

inline bool operator==(tc13ab978611f6f6c6f0eb7ff36eb72f4 const &a, tc13ab978611f6f6c6f0eb7ff36eb72f4 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Notification
    case 1: return std::get<1>(a) == std::get<1>(b); // Manual
    case 2: return std::get<2>(a) == std::get<2>(b); // Timeout
  };
  return false;
}
inline bool operator!=(tc13ab978611f6f6c6f0eb7ff36eb72f4 const &a, tc13ab978611f6f6c6f0eb7ff36eb72f4 const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816, // NewNotification
  ::dessser::gen::alerting_log::t634cf874353f100ca9a3d84e2b6c3c4b, // Outcry
  std::string, // Ack
  ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4, // Stop
  std::string // Cancel
> { using variant::variant; };

enum Constr_t {
  NewNotification,
  Outcry,
  Ack,
  Stop,
  Cancel,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "NewNotification " << std::get<0>(v); break;
    case 1: os << "Outcry " << std::get<1>(v); break;
    case 2: os << "Ack " << std::get<2>(v); break;
    case 3: os << "Stop " << std::get<3>(v); break;
    case 4: os << "Cancel " << std::get<4>(v); break;
  }
  return os;
}

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // NewNotification
    case 1: return std::get<1>(a) == std::get<1>(b); // Outcry
    case 2: return std::get<2>(a) == std::get<2>(b); // Ack
    case 3: return std::get<3>(a) == std::get<3>(b); // Stop
    case 4: return std::get<4>(a) == std::get<4>(b); // Cancel
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tfb6b082684a87ff594b0de919b33994b : public std::tuple<
  ::dessser::gen::alerting_log::t*,
  Pointer
> {
  using tuple::tuple;
  tfb6b082684a87ff594b0de919b33994b(std::tuple<::dessser::gen::alerting_log::t*, Pointer> p)
    : std::tuple<::dessser::gen::alerting_log::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tfb6b082684a87ff594b0de919b33994b const &a, tfb6b082684a87ff594b0de919b33994b const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tfb6b082684a87ff594b0de919b33994b const &a, tfb6b082684a87ff594b0de919b33994b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tfb6b082684a87ff594b0de919b33994b const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_log::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_log::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_log::tfb6b082684a87ff594b0de919b33994b(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
