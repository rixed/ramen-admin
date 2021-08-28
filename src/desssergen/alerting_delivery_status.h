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

typedef std::tuple<
  ::dessser::gen::alerting_delivery_status::t*,
  Pointer
> t70d102344d070f394857c83a5a1198d3;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_delivery_status::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_delivery_status::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_delivery_status::t70d102344d070f394857c83a5a1198d3(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
