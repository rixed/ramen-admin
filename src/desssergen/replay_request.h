#ifndef DESSSER_GEN_replay_request
#define DESSSER_GEN_replay_request
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/sync_key.h"
#include "desssergen/fq_function_name.h"

namespace dessser::gen::replay_request {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  bool explain;
  dessser::gen::sync_key::t_ext resp_key;
  double since;
  dessser::gen::fq_function_name::t_ext target;
  double until;
  t(bool explain_, dessser::gen::sync_key::t_ext resp_key_, double since_, dessser::gen::fq_function_name::t_ext target_, double until_) : explain(explain_), resp_key(resp_key_), since(since_), target(target_), until(until_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "explain:" << r.explain << ',';
  os << "resp_key:" << ::dessser::gen::sync_key::Deref(r.resp_key) << ',';
  os << "since:" << r.since << ',';
  os << "target:" << ::dessser::gen::fq_function_name::Deref(r.target) << ',';
  os << "until:" << r.until;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.explain == b.explain && ::dessser::gen::sync_key::Deref(a.resp_key) == ::dessser::gen::sync_key::Deref(b.resp_key) && a.since == b.since && ::dessser::gen::fq_function_name::Deref(a.target) == ::dessser::gen::fq_function_name::Deref(b.target) && a.until == b.until;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t2ec256ee588ae4df2ce9852bc3b48550 : public std::tuple<
  ::dessser::gen::replay_request::t*,
  Pointer
> {
  using tuple::tuple;
  t2ec256ee588ae4df2ce9852bc3b48550(std::tuple<::dessser::gen::replay_request::t*, Pointer> p)
    : std::tuple<::dessser::gen::replay_request::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2ec256ee588ae4df2ce9852bc3b48550 const &a, t2ec256ee588ae4df2ce9852bc3b48550 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2ec256ee588ae4df2ce9852bc3b48550 const &a, t2ec256ee588ae4df2ce9852bc3b48550 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t2ec256ee588ae4df2ce9852bc3b48550 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::replay_request::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::replay_request::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::replay_request::t2ec256ee588ae4df2ce9852bc3b48550(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif