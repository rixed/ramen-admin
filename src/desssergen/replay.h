#ifndef DESSSER_GEN_replay
#define DESSSER_GEN_replay
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/file_path.h"
#include "desssergen/fq_function_name.h"

namespace dessser::gen::replay {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct tc170c819a643f08a9bdcc6f98064cf69 : public std::variant<
  dessser::gen::file_path::t_ext,
  std::string
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tc170c819a643f08a9bdcc6f98064cf69 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::fq_function_name::t_ext,
  dessser::gen::fq_function_name::t_ext
> tf40d0e33ee7e61244eb0d101d73f35d2;

struct t {
  uint16_t channel;
  dessser::gen::fq_function_name::t_ext target;
  std::string target_fieldmask;
  double since;
  double until;
  tc170c819a643f08a9bdcc6f98064cf69 recipient;
  Arr<dessser::gen::fq_function_name::t_ext> sources;
  Arr<tf40d0e33ee7e61244eb0d101d73f35d2> links;
  double timeout_date;
  bool operator==(t const &other) const {
    return channel == other.channel && target == other.target && target_fieldmask == other.target_fieldmask && since == other.since && until == other.until && recipient == other.recipient && sources == other.sources && links == other.links && timeout_date == other.timeout_date;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
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
