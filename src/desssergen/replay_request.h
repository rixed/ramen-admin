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
  dessser::gen::fq_function_name::t_ext target;
  double since;
  double until;
  bool explain;
  std::string resp_key;
  bool operator==(t const &other) const {
    return target == other.target && since == other.since && until == other.until && explain == other.explain && resp_key == other.resp_key;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "target:" << r.target << ',';
  os << "since:" << r.since << ',';
  os << "until:" << r.until << ',';
  os << "explain:" << r.explain << ',';
  os << "resp_key:" << r.resp_key;
  os << '}';
  return os;
}

typedef std::tuple<
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t*,Pointer)> to_row_binary;
extern std::function<Size(t*)> sersize_of_row_binary;
extern std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
