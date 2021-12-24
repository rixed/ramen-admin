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
struct tc97f0c1bbabddd4db874c961cd5609d9 : public std::variant<
  Void, // Duplicate
  Void, // Inhibited
  Void, // STFU
  Void // StartEscalation
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 4 };
};

inline bool operator==(tc97f0c1bbabddd4db874c961cd5609d9 const &a, tc97f0c1bbabddd4db874c961cd5609d9 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Duplicate
    case 1: return std::get<1>(a) == std::get<1>(b); // Inhibited
    case 2: return std::get<2>(a) == std::get<2>(b); // STFU
    case 3: return std::get<3>(a) == std::get<3>(b); // StartEscalation
  };
  return false;
}
inline bool operator!=(tc97f0c1bbabddd4db874c961cd5609d9 const &a, tc97f0c1bbabddd4db874c961cd5609d9 const &b) {
  return !operator==(a, b);
}
enum Constr_tc97f0c1bbabddd4db874c961cd5609d9 {
  Duplicate,
  Inhibited,
  STFU,
  StartEscalation,
};

inline std::ostream &operator<<(std::ostream &os, tc97f0c1bbabddd4db874c961cd5609d9 const &v) {
  switch (v.index()) {
    case 0: os << "Duplicate" << std::get<0>(v); break;
    case 1: os << "Inhibited" << std::get<1>(v); break;
    case 2: os << "STFU" << std::get<2>(v); break;
    case 3: os << "StartEscalation" << std::get<3>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc97f0c1bbabddd4db874c961cd5609d9> const v) { os << *v; return os; }

struct t62aae75ed55c9c452157e890cb77faf5 : public std::tuple<
  std::string,
  uint32_t
> {
  using tuple::tuple;
};
inline bool operator==(t62aae75ed55c9c452157e890cb77faf5 const &a, t62aae75ed55c9c452157e890cb77faf5 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t62aae75ed55c9c452157e890cb77faf5 const &a, t62aae75ed55c9c452157e890cb77faf5 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t62aae75ed55c9c452157e890cb77faf5 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t62aae75ed55c9c452157e890cb77faf5> const t) { os << *t; return os; }

struct t2f07d8351fa62306ecaa96746ccc3d68 : public std::variant<
  Void, // Notification
  std::string, // Manual
  std::string // Timeout
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

inline bool operator==(t2f07d8351fa62306ecaa96746ccc3d68 const &a, t2f07d8351fa62306ecaa96746ccc3d68 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Notification
    case 1: return std::get<1>(a) == std::get<1>(b); // Manual
    case 2: return std::get<2>(a) == std::get<2>(b); // Timeout
  };
  return false;
}
inline bool operator!=(t2f07d8351fa62306ecaa96746ccc3d68 const &a, t2f07d8351fa62306ecaa96746ccc3d68 const &b) {
  return !operator==(a, b);
}
enum Constr_t2f07d8351fa62306ecaa96746ccc3d68 {
  Notification,
  Manual,
  Timeout,
};

inline std::ostream &operator<<(std::ostream &os, t2f07d8351fa62306ecaa96746ccc3d68 const &v) {
  switch (v.index()) {
    case 0: os << "Notification" << std::get<0>(v); break;
    case 1: os << "Manual " << std::get<1>(v); break;
    case 2: os << "Timeout " << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t2f07d8351fa62306ecaa96746ccc3d68> const v) { os << *v; return os; }

struct t : public std::variant<
  ::dessser::gen::alerting_log::tc97f0c1bbabddd4db874c961cd5609d9, // NewNotification
  ::dessser::gen::alerting_log::t62aae75ed55c9c452157e890cb77faf5, // Outcry
  std::string, // Ack
  ::dessser::gen::alerting_log::t2f07d8351fa62306ecaa96746ccc3d68, // Stop
  std::string // Cancel
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 5 };
};

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
