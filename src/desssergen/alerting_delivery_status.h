#ifndef DESSSER_GEN_alerting_delivery_status
#define DESSSER_GEN_alerting_delivery_status
#include <arpa/inet.h>
#include <functional>
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
    case 0: os << "StartToBeSent " << std::get<0>(v); break;
    case 1: os << "StartToBeSentThenStopped " << std::get<1>(v); break;
    case 2: os << "StartSent " << std::get<2>(v); break;
    case 3: os << "StartAcked " << std::get<3>(v); break;
    case 4: os << "StopToBeSent " << std::get<4>(v); break;
    case 5: os << "StopSent " << std::get<5>(v); break;
  }
  return os;
}

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
struct tec8dd05d08a833eba987e623943a6c52 : public std::tuple<
  ::dessser::gen::alerting_delivery_status::t*,
  Pointer
> {
  using tuple::tuple;
  tec8dd05d08a833eba987e623943a6c52(std::tuple<::dessser::gen::alerting_delivery_status::t*, Pointer> p)
    : std::tuple<::dessser::gen::alerting_delivery_status::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tec8dd05d08a833eba987e623943a6c52 const &a, tec8dd05d08a833eba987e623943a6c52 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tec8dd05d08a833eba987e623943a6c52 const &a, tec8dd05d08a833eba987e623943a6c52 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tec8dd05d08a833eba987e623943a6c52 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_delivery_status::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_delivery_status::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_delivery_status::tec8dd05d08a833eba987e623943a6c52(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
