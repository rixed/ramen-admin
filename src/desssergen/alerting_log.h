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

typedef std::tuple<
  std::string,
  uint32_t
> t8fac3da053db9cb461751be833f41f86;

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

struct t : public std::variant<
  ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816, // NewNotification
  ::dessser::gen::alerting_log::t8fac3da053db9cb461751be833f41f86, // Outcry
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

typedef std::tuple<
  ::dessser::gen::alerting_log::t*,
  Pointer
> t7ed4ba740a9d377e5cafe90b9af62314;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_log::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_log::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_log::t7ed4ba740a9d377e5cafe90b9af62314(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
