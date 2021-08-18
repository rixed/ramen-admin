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
  dessser::gen::site_name::t_ext site;
  dessser::gen::fq_name::t_ext worker;
  bool test;
  double sent_time;
  std::optional<double> event_time;
  std::string name;
  bool firing;
  double certainty;
  double debounce;
  double timeout;
  Lst<t8961925d22ebc35140986110e41bc2a4> parameters;
  bool operator==(t const &other) const {
    return site == other.site && worker == other.worker && test == other.test && sent_time == other.sent_time && event_time == other.event_time && name == other.name && firing == other.firing && certainty == other.certainty && debounce == other.debounce && timeout == other.timeout && parameters == other.parameters;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "site:" << r.site << ',';
  os << "worker:" << r.worker << ',';
  os << "test:" << r.test << ',';
  os << "sent_time:" << r.sent_time << ',';
  os << "event_time:" << r.event_time << ',';
  os << "name:" << r.name << ',';
  os << "firing:" << r.firing << ',';
  os << "certainty:" << r.certainty << ',';
  os << "debounce:" << r.debounce << ',';
  os << "timeout:" << r.timeout << ',';
  os << "parameters:" << r.parameters;
  os << '}';
  return os;
}

typedef std::tuple<
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(t*,Pointer)> to_row_binary;
extern std::function<Size(t*)> sersize_of_row_binary;
extern std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
