#ifndef DESSSER_GEN_replayer
#define DESSSER_GEN_replayer
#include <arpa/inet.h>
#include <functional>
#include <memory>
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
  t(Arr<uint16_t> channels_, double creation_, std::optional<std::string> exit_status_, double last_killed_, std::optional<uint32_t> pid_, dessser::gen::time_range::t_ext time_range_) : channels(channels_), creation(creation_), exit_status(exit_status_), last_killed(last_killed_), pid(pid_), time_range(time_range_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.channels == b.channels && a.creation == b.creation && ((a.exit_status && b.exit_status && a.exit_status.value() == b.exit_status.value()) || (!a.exit_status && !b.exit_status)) && a.last_killed == b.last_killed && ((a.pid && b.pid && a.pid.value() == b.pid.value()) || (!a.pid && !b.pid)) && ::dessser::gen::time_range::Deref(a.time_range) == ::dessser::gen::time_range::Deref(b.time_range);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "channels:" << r.channels << ',';
  os << "creation:" << r.creation << ',';
  if (r.exit_status) os << "exit_status:" << r.exit_status.value() << ',';
  os << "last_killed:" << r.last_killed << ',';
  if (r.pid) os << "pid:" << r.pid.value() << ',';
  os << "time_range:" << r.time_range;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t0bd45f437ea17ff5374b334c82df701e : public std::tuple<
  std::shared_ptr<::dessser::gen::replayer::t> ,
  Pointer
> {
  using tuple::tuple;
  t0bd45f437ea17ff5374b334c82df701e(std::tuple<std::shared_ptr<::dessser::gen::replayer::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::replayer::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0bd45f437ea17ff5374b334c82df701e const &a, t0bd45f437ea17ff5374b334c82df701e const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0bd45f437ea17ff5374b334c82df701e const &a, t0bd45f437ea17ff5374b334c82df701e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t0bd45f437ea17ff5374b334c82df701e const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0bd45f437ea17ff5374b334c82df701e> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::replayer::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::replayer::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::replayer::t0bd45f437ea17ff5374b334c82df701e(Pointer)> of_row_binary;
extern std::function<::dessser::gen::replayer::t0bd45f437ea17ff5374b334c82df701e(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::replayer::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
