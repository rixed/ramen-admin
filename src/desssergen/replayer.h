#ifndef DESSSER_GEN_replayer
#define DESSSER_GEN_replayer
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
struct t40120715e1a398c85256df6891079958 : public std::tuple<
  uint16_t,
  bool
> {
  using tuple::tuple;
};
inline bool operator==(t40120715e1a398c85256df6891079958 const &a, t40120715e1a398c85256df6891079958 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t40120715e1a398c85256df6891079958 const &a, t40120715e1a398c85256df6891079958 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t40120715e1a398c85256df6891079958 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t40120715e1a398c85256df6891079958> const t) { os << *t; return os; }

struct t {
  dessser::gen::time_range::t_ext time_range;
  double creation;
  std::optional<uint32_t> pid;
  double last_killed;
  std::optional<std::string> exit_status;
  Arr<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> channels;
  t(dessser::gen::time_range::t_ext time_range_, double creation_, std::optional<uint32_t> pid_, double last_killed_, std::optional<std::string> exit_status_, Arr<::dessser::gen::replayer::t40120715e1a398c85256df6891079958> channels_) : time_range(time_range_), creation(creation_), pid(pid_), last_killed(last_killed_), exit_status(exit_status_), channels(channels_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::time_range::Deref(a.time_range) == ::dessser::gen::time_range::Deref(b.time_range) && a.creation == b.creation && ((a.pid && b.pid && a.pid.value() == b.pid.value()) || (!a.pid && !b.pid)) && a.last_killed == b.last_killed && ((a.exit_status && b.exit_status && a.exit_status.value() == b.exit_status.value()) || (!a.exit_status && !b.exit_status)) && a.channels == b.channels;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "time_range:" << r.time_range << ',';
  os << "creation:" << r.creation << ',';
  if (r.pid) os << "pid:" << r.pid.value() << ',';
  os << "last_killed:" << r.last_killed << ',';
  if (r.exit_status) os << "exit_status:" << r.exit_status.value() << ',';
  os << "channels:" << r.channels;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t43148a704ce6e620b06d3626aee0c192 : public std::tuple<
  ::dessser::gen::replayer::t,
  Pointer
> {
  using tuple::tuple;
  t43148a704ce6e620b06d3626aee0c192(std::tuple<::dessser::gen::replayer::t, Pointer> p)
    : std::tuple<::dessser::gen::replayer::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t43148a704ce6e620b06d3626aee0c192 const &a, t43148a704ce6e620b06d3626aee0c192 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t43148a704ce6e620b06d3626aee0c192 const &a, t43148a704ce6e620b06d3626aee0c192 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t43148a704ce6e620b06d3626aee0c192 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t43148a704ce6e620b06d3626aee0c192> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::replayer::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::replayer::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::replayer::t43148a704ce6e620b06d3626aee0c192(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::replayer::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
