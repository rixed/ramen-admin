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
  *fq_function_name target;
  double since;
  double until;
  bool explain;
  std::string resp_key;
  bool operator==(t const &other) const {
    return target == other.target && since == other.since && until == other.until && explain == other.explain && resp_key == other.resp_key;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "target:" << r.target << ',';
  os << "since:" << r.since << ',';
  os << "until:" << r.until << ',';
  os << "explain:" << r.explain << ',';
  os << "resp_key:" << r.resp_key;
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
