#ifndef DESSSER_GEN_alerting_delivery_status
#define DESSSER_GEN_alerting_delivery_status
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
enum t {
  StartToBeSent,
  StartToBeSentThenStopped,
  StartSent,
  StartAcked,
  StopToBeSent,
  StopSent,
};

constexpr size_t t_size { 6 };
inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v) {
    case StartToBeSent: os << "StartToBeSent"; break;
    case StartToBeSentThenStopped: os << "StartToBeSentThenStopped"; break;
    case StartSent: os << "StartSent"; break;
    case StartAcked: os << "StartAcked"; break;
    case StopToBeSent: os << "StopToBeSent"; break;
    case StopSent: os << "StopSent"; break;
    default: assert(false); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct t3a70e06bd973b675ad23916a4f0f5e29 : public std::tuple<
  ::dessser::gen::alerting_delivery_status::t,
  Pointer
> {
  using tuple::tuple;
  t3a70e06bd973b675ad23916a4f0f5e29(std::tuple<::dessser::gen::alerting_delivery_status::t, Pointer> p)
    : std::tuple<::dessser::gen::alerting_delivery_status::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3a70e06bd973b675ad23916a4f0f5e29 const &a, t3a70e06bd973b675ad23916a4f0f5e29 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3a70e06bd973b675ad23916a4f0f5e29 const &a, t3a70e06bd973b675ad23916a4f0f5e29 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t3a70e06bd973b675ad23916a4f0f5e29 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t3a70e06bd973b675ad23916a4f0f5e29> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_delivery_status::t const &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_delivery_status::t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::alerting_delivery_status::t3a70e06bd973b675ad23916a4f0f5e29(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::alerting_delivery_status::t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
