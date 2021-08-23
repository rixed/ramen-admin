#ifndef DESSSER_GEN_replay_request
#define DESSSER_GEN_replay_request
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/fq_function_name.h"

namespace dessser::gen::replay_request {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  bool explain;
  std::string resp_key;
  double since;
  dessser::gen::fq_function_name::t_ext target;
  double until;
  bool operator==(t const &other) const {
    return explain == other.explain && resp_key == other.resp_key && since == other.since && target == other.target && until == other.until;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "explain:" << r.explain << ',';
  os << "resp_key:" << r.resp_key << ',';
  os << "since:" << r.since << ',';
  os << "target:" << r.target << ',';
  os << "until:" << r.until;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::replay_request::t*,
  Pointer
> t27e849e988795ad71224ab90ab2a0c4c;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::replay_request::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::replay_request::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::replay_request::t27e849e988795ad71224ab90ab2a0c4c(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
