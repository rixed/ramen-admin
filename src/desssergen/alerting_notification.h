#ifndef DESSSER_GEN_alerting_notification
#define DESSSER_GEN_alerting_notification
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/fq_name.h"
#include "desssergen/site_name.h"

namespace dessser::gen::alerting_notification {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t284e07c4f4868d983fec7971424a1df8 : public std::tuple<
  std::string,
  std::string
> {
  using tuple::tuple;
  t284e07c4f4868d983fec7971424a1df8(std::tuple<std::string, std::string> p)
    : std::tuple<std::string, std::string>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t284e07c4f4868d983fec7971424a1df8 const &a, t284e07c4f4868d983fec7971424a1df8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t284e07c4f4868d983fec7971424a1df8 const &a, t284e07c4f4868d983fec7971424a1df8 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t284e07c4f4868d983fec7971424a1df8 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t {
  double certainty;
  double debounce;
  std::optional<double> event_time;
  bool firing;
  std::string name;
  Lst<::dessser::gen::alerting_notification::t284e07c4f4868d983fec7971424a1df8> parameters;
  double sent_time;
  dessser::gen::site_name::t_ext site;
  bool test;
  double timeout;
  dessser::gen::fq_name::t_ext worker;
  t(double certainty_, double debounce_, std::optional<double> event_time_, bool firing_, std::string name_, Lst<::dessser::gen::alerting_notification::t284e07c4f4868d983fec7971424a1df8> parameters_, double sent_time_, dessser::gen::site_name::t_ext site_, bool test_, double timeout_, dessser::gen::fq_name::t_ext worker_) : certainty(certainty_), debounce(debounce_), event_time(event_time_), firing(firing_), name(name_), parameters(parameters_), sent_time(sent_time_), site(site_), test(test_), timeout(timeout_), worker(worker_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "certainty:" << r.certainty << ',';
  os << "debounce:" << r.debounce << ',';
  if (r.event_time) os << "event_time:" << r.event_time.value() << ',';
  os << "firing:" << r.firing << ',';
  os << "name:" << r.name << ',';
  os << "parameters:" << r.parameters << ',';
  os << "sent_time:" << r.sent_time << ',';
  os << "site:" << ::dessser::gen::site_name::Deref(r.site) << ',';
  os << "test:" << r.test << ',';
  os << "timeout:" << r.timeout << ',';
  os << "worker:" << ::dessser::gen::fq_name::Deref(r.worker);
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.certainty == b.certainty && a.debounce == b.debounce && ((a.event_time && b.event_time && a.event_time.value() == b.event_time.value()) || (!a.event_time && !b.event_time)) && a.firing == b.firing && a.name == b.name && a.parameters == b.parameters && a.sent_time == b.sent_time && ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site) && a.test == b.test && a.timeout == b.timeout && ::dessser::gen::fq_name::Deref(a.worker) == ::dessser::gen::fq_name::Deref(b.worker);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct te8ad757749fae6294b10eb09007d1f7d : public std::tuple<
  ::dessser::gen::alerting_notification::t*,
  Pointer
> {
  using tuple::tuple;
  te8ad757749fae6294b10eb09007d1f7d(std::tuple<::dessser::gen::alerting_notification::t*, Pointer> p)
    : std::tuple<::dessser::gen::alerting_notification::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te8ad757749fae6294b10eb09007d1f7d const &a, te8ad757749fae6294b10eb09007d1f7d const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te8ad757749fae6294b10eb09007d1f7d const &a, te8ad757749fae6294b10eb09007d1f7d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te8ad757749fae6294b10eb09007d1f7d const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_notification::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_notification::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_notification::te8ad757749fae6294b10eb09007d1f7d(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
