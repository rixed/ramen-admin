#ifndef DESSSER_GEN_alerting_delivery_status
#define DESSSER_GEN_alerting_delivery_status
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::alerting_delivery_status {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  Void, // StartToBeSent
  Void, // StartToBeSentThenStopped
  Void, // StartSent
  Void, // StartAcked
  Void, // StopToBeSent
  Void // StopSent
> { using variant::variant; };

enum Constr_t {
  StartToBeSent,
  StartToBeSentThenStopped,
  StartSent,
  StartAcked,
  StopToBeSent,
  StopSent,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "StartToBeSent" << std::get<0>(v); break;
    case 1: os << "StartToBeSentThenStopped" << std::get<1>(v); break;
    case 2: os << "StartSent" << std::get<2>(v); break;
    case 3: os << "StartAcked" << std::get<3>(v); break;
    case 4: os << "StopToBeSent" << std::get<4>(v); break;
    case 5: os << "StopSent" << std::get<5>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // StartToBeSent
    case 1: return std::get<1>(a) == std::get<1>(b); // StartToBeSentThenStopped
    case 2: return std::get<2>(a) == std::get<2>(b); // StartSent
    case 3: return std::get<3>(a) == std::get<3>(b); // StartAcked
    case 4: return std::get<4>(a) == std::get<4>(b); // StopToBeSent
    case 5: return std::get<5>(a) == std::get<5>(b); // StopSent
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tef7a86fb4151f002e287c72985f042cf : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_delivery_status::t> ,
  Pointer
> {
  using tuple::tuple;
  tef7a86fb4151f002e287c72985f042cf(std::tuple<std::shared_ptr<::dessser::gen::alerting_delivery_status::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_delivery_status::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tef7a86fb4151f002e287c72985f042cf const &a, tef7a86fb4151f002e287c72985f042cf const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tef7a86fb4151f002e287c72985f042cf const &a, tef7a86fb4151f002e287c72985f042cf const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tef7a86fb4151f002e287c72985f042cf const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::alerting_delivery_status::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_delivery_status::tef7a86fb4151f002e287c72985f042cf(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
