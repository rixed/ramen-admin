#ifndef DESSSER_GEN_replayer
#define DESSSER_GEN_replayer
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/time_range.h"

namespace dessser::gen::replayer {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  Arr<uint16_t> channels;
  double creation;
  std::optional<std::string> exit_status;
  double last_killed;
  std::optional<uint32_t> pid;
  dessser::gen::time_range::t_ext time_range;
  bool operator==(t const &other) const {
    return channels == other.channels && creation == other.creation && exit_status == other.exit_status && last_killed == other.last_killed && pid == other.pid && time_range == other.time_range;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "channels:" << r.channels << ',';
  os << "creation:" << r.creation << ',';
  os << "exit_status:" << r.exit_status << ',';
  os << "last_killed:" << r.last_killed << ',';
  os << "pid:" << r.pid << ',';
  os << "time_range:" << r.time_range;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::replayer::t*,
  Pointer
> t93389eb2d4b902a099441781e878b2f7;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::replayer::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::replayer::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::replayer::t93389eb2d4b902a099441781e878b2f7(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
