#ifndef DESSSER_GEN_alerting_inhibition
#define DESSSER_GEN_alerting_inhibition
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::alerting_inhibition {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  std::string what;
  double start_date;
  double stop_date;
  std::string who;
  std::string why;
  bool operator==(t const &other) const {
    return what == other.what && start_date == other.start_date && stop_date == other.stop_date && who == other.who && why == other.why;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "what:" << r.what << ',';
  os << "start_date:" << r.start_date << ',';
  os << "stop_date:" << r.stop_date << ',';
  os << "who:" << r.who << ',';
  os << "why:" << r.why;
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
