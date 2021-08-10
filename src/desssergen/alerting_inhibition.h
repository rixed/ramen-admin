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
std::ostream &operator<<(std::ostream &os, t const &r) {
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
