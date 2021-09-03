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
  t(bool explain_, std::string resp_key_, double since_, dessser::gen::fq_function_name::t_ext target_, double until_) : explain(explain_), resp_key(resp_key_), since(since_), target(target_), until(until_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "explain:" << r.explain << ',';
  os << "resp_key:" << r.resp_key << ',';
  os << "since:" << r.since << ',';
  os << "target:" << ::dessser::gen::fq_function_name::Deref(r.target) << ',';
  os << "until:" << r.until;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.explain == b.explain && a.resp_key == b.resp_key && a.since == b.since && ::dessser::gen::fq_function_name::Deref(a.target) == ::dessser::gen::fq_function_name::Deref(b.target) && a.until == b.until;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
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
inline t Deref(t_ext x) { return *x; }

}
#endif
