#ifndef DESSSER_GEN_alerting_log
#define DESSSER_GEN_alerting_log
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
struct t68e400d2c31c46ef1f50eb49f6d25f2c : public std::variant<
  Void, // Duplicate
  Void, // Inhibited
  Void, // STFU
  Void // StartEscalation
> { using variant::variant; };

inline bool operator==(t68e400d2c31c46ef1f50eb49f6d25f2c const &a, t68e400d2c31c46ef1f50eb49f6d25f2c const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Duplicate
    case 1: return std::get<1>(a) == std::get<1>(b); // Inhibited
    case 2: return std::get<2>(a) == std::get<2>(b); // STFU
    case 3: return std::get<3>(a) == std::get<3>(b); // StartEscalation
  };
  return false;
}
inline bool operator!=(t68e400d2c31c46ef1f50eb49f6d25f2c const &a, t68e400d2c31c46ef1f50eb49f6d25f2c const &b) {
  return !operator==(a, b);
}
enum Constr_t68e400d2c31c46ef1f50eb49f6d25f2c {
  Duplicate,
  Inhibited,
  STFU,
  StartEscalation,
};

inline std::ostream &operator<<(std::ostream &os, t68e400d2c31c46ef1f50eb49f6d25f2c const &v) {
  switch (v.index()) {
    case 0: os << "Duplicate" << std::get<0>(v); break;
    case 1: os << "Inhibited" << std::get<1>(v); break;
    case 2: os << "STFU" << std::get<2>(v); break;
    case 3: os << "StartEscalation" << std::get<3>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t68e400d2c31c46ef1f50eb49f6d25f2c> const v) { os << *v; return os; }

struct t6bded395cd2ca5ea5b1538d97c26812f : public std::tuple<
  std::string,
  uint32_t
> {
  using tuple::tuple;
  t6bded395cd2ca5ea5b1538d97c26812f(std::tuple<std::string, uint32_t> p)
    : std::tuple<std::string, uint32_t>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6bded395cd2ca5ea5b1538d97c26812f const &a, t6bded395cd2ca5ea5b1538d97c26812f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6bded395cd2ca5ea5b1538d97c26812f const &a, t6bded395cd2ca5ea5b1538d97c26812f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t6bded395cd2ca5ea5b1538d97c26812f const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t6bded395cd2ca5ea5b1538d97c26812f> const t) { os << *t; return os; }

struct tda1a7f0ee5c512824f4f5c13bdd6fcc3 : public std::variant<
  Void, // Notification
  std::string, // Manual
  std::string // Timeout
> { using variant::variant; };

inline bool operator==(tda1a7f0ee5c512824f4f5c13bdd6fcc3 const &a, tda1a7f0ee5c512824f4f5c13bdd6fcc3 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Notification
    case 1: return std::get<1>(a) == std::get<1>(b); // Manual
    case 2: return std::get<2>(a) == std::get<2>(b); // Timeout
  };
  return false;
}
inline bool operator!=(tda1a7f0ee5c512824f4f5c13bdd6fcc3 const &a, tda1a7f0ee5c512824f4f5c13bdd6fcc3 const &b) {
  return !operator==(a, b);
}
enum Constr_tda1a7f0ee5c512824f4f5c13bdd6fcc3 {
  Notification,
  Manual,
  Timeout,
};

inline std::ostream &operator<<(std::ostream &os, tda1a7f0ee5c512824f4f5c13bdd6fcc3 const &v) {
  switch (v.index()) {
    case 0: os << "Notification" << std::get<0>(v); break;
    case 1: os << "Manual " << std::get<1>(v); break;
    case 2: os << "Timeout " << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tda1a7f0ee5c512824f4f5c13bdd6fcc3> const v) { os << *v; return os; }

struct t : public std::variant<
  ::dessser::gen::alerting_log::t68e400d2c31c46ef1f50eb49f6d25f2c, // NewNotification
  ::dessser::gen::alerting_log::t6bded395cd2ca5ea5b1538d97c26812f, // Outcry
  std::string, // Ack
  ::dessser::gen::alerting_log::tda1a7f0ee5c512824f4f5c13bdd6fcc3, // Stop
  std::string // Cancel
> { using variant::variant; };

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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct te9c1cd78a0ebfca77aef3940bddf8190 : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_log::t> ,
  Pointer
> {
  using tuple::tuple;
  te9c1cd78a0ebfca77aef3940bddf8190(std::tuple<std::shared_ptr<::dessser::gen::alerting_log::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_log::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te9c1cd78a0ebfca77aef3940bddf8190 const &a, te9c1cd78a0ebfca77aef3940bddf8190 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te9c1cd78a0ebfca77aef3940bddf8190 const &a, te9c1cd78a0ebfca77aef3940bddf8190 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te9c1cd78a0ebfca77aef3940bddf8190 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te9c1cd78a0ebfca77aef3940bddf8190> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_log::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::alerting_log::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_log::te9c1cd78a0ebfca77aef3940bddf8190(Pointer)> of_row_binary;
extern std::function<::dessser::gen::alerting_log::te9c1cd78a0ebfca77aef3940bddf8190(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_log::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
