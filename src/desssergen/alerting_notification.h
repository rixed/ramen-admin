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
typedef std::tuple<
  std::string,
  std::string
> t8961925d22ebc35140986110e41bc2a4;

struct t {
  double certainty;
  double debounce;
  std::optional<double> event_time;
  bool firing;
  std::string name;
  Lst<::dessser::gen::alerting_notification::t8961925d22ebc35140986110e41bc2a4> parameters;
  double sent_time;
  dessser::gen::site_name::t_ext site;
  bool test;
  double timeout;
  dessser::gen::fq_name::t_ext worker;
  t(double certainty_, double debounce_, std::optional<double> event_time_, bool firing_, std::string name_, Lst<::dessser::gen::alerting_notification::t8961925d22ebc35140986110e41bc2a4> parameters_, double sent_time_, dessser::gen::site_name::t_ext site_, bool test_, double timeout_, dessser::gen::fq_name::t_ext worker_) : certainty(certainty_), debounce(debounce_), event_time(event_time_), firing(firing_), name(name_), parameters(parameters_), sent_time(sent_time_), site(site_), test(test_), timeout(timeout_), worker(worker_) {}
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
typedef std::tuple<
  ::dessser::gen::alerting_notification::t*,
  Pointer
> t281c4a1c5bbc4c0959c7fb563f217845;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_notification::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_notification::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_notification::t281c4a1c5bbc4c0959c7fb563f217845(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
