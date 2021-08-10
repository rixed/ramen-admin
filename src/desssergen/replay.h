#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::replay {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct ed5c0948580fc7adda63d975e64ca75f : public std::variant<
  dessser::gen::file_path::t,
  std::string
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, ed5c0948580fc7adda63d975e64ca75f const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::fq_function_name::t,
  dessser::gen::fq_function_name::t
> v_350131e9cf91ccd34558b5986f609d67;

struct t {
  uint16_t channel;
  dessser::gen::fq_function_name::t target;
  std::string target_fieldmask;
  double since;
  double until;
  ed5c0948580fc7adda63d975e64ca75f recipient;
  Arr<dessser::gen::fq_function_name::t> sources;
  Arr<v_350131e9cf91ccd34558b5986f609d67> links;
  double timeout_date;
  bool operator==(t const &other) const {
    return channel == other.channel && target == other.target && target_fieldmask == other.target_fieldmask && since == other.since && until == other.until && recipient == other.recipient && sources == other.sources && links == other.links && timeout_date == other.timeout_date;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "channel:" << r.channel << ',';
  os << "target:" << r.target << ',';
  os << "target_fieldmask:" << r.target_fieldmask << ',';
  os << "since:" << r.since << ',';
  os << "until:" << r.until << ',';
  os << "recipient:" << r.recipient << ',';
  os << "sources:" << r.sources << ',';
  os << "links:" << r.links << ',';
  os << "timeout_date:" << r.timeout_date;
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
