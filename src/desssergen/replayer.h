#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::replayer {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::time_range::t time_range;
  double creation;
  std::optional<uint32_t> pid;
  double last_killed;
  std::optional<std::string> exit_status;
  Arr<uint16_t> channels;
  bool operator==(t const &other) const {
    return time_range == other.time_range && creation == other.creation && pid == other.pid && last_killed == other.last_killed && exit_status == other.exit_status && channels == other.channels;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "time_range:" << r.time_range << ',';
  os << "creation:" << r.creation << ',';
  os << "pid:" << r.pid << ',';
  os << "last_killed:" << r.last_killed << ',';
  os << "exit_status:" << r.exit_status << ',';
  os << "channels:" << r.channels;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
