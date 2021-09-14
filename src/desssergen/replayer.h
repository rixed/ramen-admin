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
  t(Arr<uint16_t> channels_, double creation_, std::optional<std::string> exit_status_, double last_killed_, std::optional<uint32_t> pid_, dessser::gen::time_range::t_ext time_range_) : channels(channels_), creation(creation_), exit_status(exit_status_), last_killed(last_killed_), pid(pid_), time_range(time_range_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "channels:" << r.channels << ',';
  os << "creation:" << r.creation << ',';
  if (r.exit_status) os << "exit_status:" << r.exit_status.value() << ',';
  os << "last_killed:" << r.last_killed << ',';
  if (r.pid) os << "pid:" << r.pid.value() << ',';
  os << "time_range:" << ::dessser::gen::time_range::Deref(r.time_range);
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.channels == b.channels && a.creation == b.creation && ((a.exit_status && b.exit_status && a.exit_status.value() == b.exit_status.value()) || (!a.exit_status && !b.exit_status)) && a.last_killed == b.last_killed && ((a.pid && b.pid && a.pid.value() == b.pid.value()) || (!a.pid && !b.pid)) && ::dessser::gen::time_range::Deref(a.time_range) == ::dessser::gen::time_range::Deref(b.time_range);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t6917ef55820d0fab931ee64de5c03063 : public std::tuple<
  ::dessser::gen::replayer::t*,
  Pointer
> {
  using tuple::tuple;
  t6917ef55820d0fab931ee64de5c03063(std::tuple<::dessser::gen::replayer::t*, Pointer> p)
    : std::tuple<::dessser::gen::replayer::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6917ef55820d0fab931ee64de5c03063 const &a, t6917ef55820d0fab931ee64de5c03063 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6917ef55820d0fab931ee64de5c03063 const &a, t6917ef55820d0fab931ee64de5c03063 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t6917ef55820d0fab931ee64de5c03063 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::replayer::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::replayer::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::replayer::t6917ef55820d0fab931ee64de5c03063(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif