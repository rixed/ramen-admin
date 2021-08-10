#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  std::string,
  std::string
> d135bed341a046f128507720bca94ebf;

struct t {
  *site_name site;
  *fq_name worker;
  bool test;
  double sent_time;
  std::optional<double> event_time;
  std::string name;
  bool firing;
  double certainty;
  double debounce;
  double timeout;
  Lst<d135bed341a046f128507720bca94ebf> parameters;
  bool operator==(t const &other) const {
    return site == other.site && worker == other.worker && test == other.test && sent_time == other.sent_time && event_time == other.event_time && name == other.name && firing == other.firing && certainty == other.certainty && debounce == other.debounce && timeout == other.timeout && parameters == other.parameters;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
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
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
