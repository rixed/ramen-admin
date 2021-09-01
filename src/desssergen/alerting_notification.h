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
  bool operator==(t const &other) const {
    return certainty == other.certainty && debounce == other.debounce && event_time == other.event_time && firing == other.firing && name == other.name && parameters == other.parameters && sent_time == other.sent_time && site == other.site && test == other.test && timeout == other.timeout && worker == other.worker;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "certainty:" << r.certainty << ',';
  os << "debounce:" << r.debounce << ',';
  os << "event_time:" << r.event_time << ',';
  os << "firing:" << r.firing << ',';
  os << "name:" << r.name << ',';
  os << "parameters:" << r.parameters << ',';
  os << "sent_time:" << r.sent_time << ',';
  os << "site:" << r.site << ',';
  os << "test:" << r.test << ',';
  os << "timeout:" << r.timeout << ',';
  os << "worker:" << r.worker;
  os << '}';
  return os;
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

}
#endif
