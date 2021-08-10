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
struct v_1d53ca1dfc33d45608c16f60daf686b4 {
  double since;
  double until;
  bool growing;
  bool operator==(v_1d53ca1dfc33d45608c16f60daf686b4 const &other) const {
    return since == other.since && until == other.until && growing == other.growing;
  }
};
std::ostream &operator<<(std::ostream &os, v_1d53ca1dfc33d45608c16f60daf686b4 const &r) {
  os << '{';
  os << "since:" << r.since << ',';
  os << "until:" << r.until << ',';
  os << "growing:" << r.growing;
  os << '}';
  return os;
}

typedef std::tuple<
  Arr<v_1d53ca1dfc33d45608c16f60daf686b4>,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(Arr<v_1d53ca1dfc33d45608c16f60daf686b4>&,Pointer)> to_row_binary;
std::function<Size(Arr<v_1d53ca1dfc33d45608c16f60daf686b4>&)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
