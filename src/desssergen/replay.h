#ifndef DESSSER_GEN_replay
#define DESSSER_GEN_replay
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/file_path.h"
#include "desssergen/fq_function_name.h"

namespace dessser::gen::replay {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  dessser::gen::fq_function_name::t_ext,
  dessser::gen::fq_function_name::t_ext
> tf40d0e33ee7e61244eb0d101d73f35d2;

struct t2dcaaead53e2477949a964d6de829472 : public std::variant<
  dessser::gen::file_path::t_ext, // RingBuf
  std::string // SyncKey
> { using variant::variant; };

enum Constr_t2dcaaead53e2477949a964d6de829472 {
  RingBuf,
  SyncKey,
};

inline bool operator==(t2dcaaead53e2477949a964d6de829472 const &a, t2dcaaead53e2477949a964d6de829472 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::file_path::Deref(std::get<0>(a)) == ::dessser::gen::file_path::Deref(std::get<0>(b)); // RingBuf
    case 1: return std::get<1>(a) == std::get<1>(b); // SyncKey
  };
  return false;
}
inline bool operator!=(t2dcaaead53e2477949a964d6de829472 const &a, t2dcaaead53e2477949a964d6de829472 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t2dcaaead53e2477949a964d6de829472 const &v) {
  switch (v.index()) {
    case 0: os << "RingBuf " << ::dessser::gen::file_path::Deref(std::get<0>(v)); break;
    case 1: os << "SyncKey " << std::get<1>(v); break;
  }
  return os;
}

struct t {
  uint16_t channel;
  Arr<::dessser::gen::replay::tf40d0e33ee7e61244eb0d101d73f35d2> links;
  ::dessser::gen::replay::t2dcaaead53e2477949a964d6de829472 recipient;
  double since;
  Arr<dessser::gen::fq_function_name::t_ext> sources;
  dessser::gen::fq_function_name::t_ext target;
  std::string target_fieldmask;
  double timeout_date;
  double until;
  t(uint16_t channel_, Arr<::dessser::gen::replay::tf40d0e33ee7e61244eb0d101d73f35d2> links_, ::dessser::gen::replay::t2dcaaead53e2477949a964d6de829472 recipient_, double since_, Arr<dessser::gen::fq_function_name::t_ext> sources_, dessser::gen::fq_function_name::t_ext target_, std::string target_fieldmask_, double timeout_date_, double until_) : channel(channel_), links(links_), recipient(recipient_), since(since_), sources(sources_), target(target_), target_fieldmask(target_fieldmask_), timeout_date(timeout_date_), until(until_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "channel:" << r.channel << ',';
  os << "links:" << r.links << ',';
  os << "recipient:" << r.recipient << ',';
  os << "since:" << r.since << ',';
  os << "sources:" << r.sources << ',';
  os << "target:" << ::dessser::gen::fq_function_name::Deref(r.target) << ',';
  os << "target_fieldmask:" << r.target_fieldmask << ',';
  os << "timeout_date:" << r.timeout_date << ',';
  os << "until:" << r.until;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.channel == b.channel && a.links == b.links && a.recipient == b.recipient && a.since == b.since && a.sources == b.sources && ::dessser::gen::fq_function_name::Deref(a.target) == ::dessser::gen::fq_function_name::Deref(b.target) && a.target_fieldmask == b.target_fieldmask && a.timeout_date == b.timeout_date && a.until == b.until;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
typedef std::tuple<
  ::dessser::gen::replay::t*,
  Pointer
> t50c6e021a2b332a68db298a909a2b414;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::replay::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::replay::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::replay::t50c6e021a2b332a68db298a909a2b414(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
