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
typedef std::tuple<
  dessser::gen::fq_function_name::t_ext,
  dessser::gen::fq_function_name::t_ext
> tf40d0e33ee7e61244eb0d101d73f35d2;

struct tdb74c4acee71fb13194723c985502b12 : public std::variant<
  dessser::gen::file_path::t_ext,
  std::string
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, tdb74c4acee71fb13194723c985502b12 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct t {
  uint16_t channel;
  Arr<::dessser::gen::replay::tf40d0e33ee7e61244eb0d101d73f35d2> links;
  ::dessser::gen::replay::tdb74c4acee71fb13194723c985502b12 recipient;
  double since;
  Arr<dessser::gen::fq_function_name::t_ext> sources;
  dessser::gen::fq_function_name::t_ext target;
  std::string target_fieldmask;
  double timeout_date;
  double until;
  bool operator==(t const &other) const {
    return channel == other.channel && links == other.links && recipient == other.recipient && since == other.since && sources == other.sources && target == other.target && target_fieldmask == other.target_fieldmask && timeout_date == other.timeout_date && until == other.until;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "channel:" << r.channel << ',';
  os << "links:" << r.links << ',';
  os << "recipient:" << r.recipient << ',';
  os << "since:" << r.since << ',';
  os << "sources:" << r.sources << ',';
  os << "target:" << r.target << ',';
  os << "target_fieldmask:" << r.target_fieldmask << ',';
  os << "timeout_date:" << r.timeout_date << ',';
  os << "until:" << r.until;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::replay::t*,
  Pointer
> t50c6e021a2b332a68db298a909a2b414;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::replay::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::replay::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::replay::t50c6e021a2b332a68db298a909a2b414(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
