#ifndef DESSSER_GEN_replay_request
#define DESSSER_GEN_replay_request
#include <functional>
#include <memory>
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
  dessser::gen::fq_function_name::t_ext target;
  double since;
  double until;
  bool explain;
  dessser::gen::sync_key::t_ext resp_key;
  t(dessser::gen::fq_function_name::t_ext target_, double since_, double until_, bool explain_, dessser::gen::sync_key::t_ext resp_key_) : target(target_), since(since_), until(until_), explain(explain_), resp_key(resp_key_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::fq_function_name::Deref(a.target) == ::dessser::gen::fq_function_name::Deref(b.target) && a.since == b.since && a.until == b.until && a.explain == b.explain && ::dessser::gen::sync_key::Deref(a.resp_key) == ::dessser::gen::sync_key::Deref(b.resp_key);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
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
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct tcfdae0eebc6d2c4c070de31c29d5d722 : public std::tuple<
  ::dessser::gen::replay_request::t,
  Pointer
> {
  using tuple::tuple;
  tcfdae0eebc6d2c4c070de31c29d5d722(std::tuple<::dessser::gen::replay_request::t, Pointer> p)
    : std::tuple<::dessser::gen::replay_request::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcfdae0eebc6d2c4c070de31c29d5d722 const &a, tcfdae0eebc6d2c4c070de31c29d5d722 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcfdae0eebc6d2c4c070de31c29d5d722 const &a, tcfdae0eebc6d2c4c070de31c29d5d722 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tcfdae0eebc6d2c4c070de31c29d5d722 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tcfdae0eebc6d2c4c070de31c29d5d722> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::replay_request::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::replay_request::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::replay_request::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
