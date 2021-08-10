#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::alerting_contact {
// don't ask me why:
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct f6f331efc660707e57f0e15ccf4fd321 {
  std::string file;
  std::string insert;
  std::string create;
  bool operator==(f6f331efc660707e57f0e15ccf4fd321 const &other) const {
    return file == other.file && insert == other.insert && create == other.create;
  }
};
std::ostream &operator<<(std::ostream &os, f6f331efc660707e57f0e15ccf4fd321 const &r) {
  os << '{';
  os << "file:" << r.file << ',';
  os << "insert:" << r.insert << ',';
  os << "create:" << r.create;
  os << '}';
  return os;
}

typedef std::tuple<
  std::string,
  std::string
> d135bed341a046f128507720bca94ebf;

struct e952f334fe511c004f72c55ab7164557 {
  Lst<d135bed341a046f128507720bca94ebf> options;
  std::string topic;
  uint16_t partition;
  std::string text;
  bool operator==(e952f334fe511c004f72c55ab7164557 const &other) const {
    return options == other.options && topic == other.topic && partition == other.partition && text == other.text;
  }
};
std::ostream &operator<<(std::ostream &os, e952f334fe511c004f72c55ab7164557 const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "topic:" << r.topic << ',';
  os << "partition:" << r.partition << ',';
  os << "text:" << r.text;
  os << '}';
  return os;
}

struct d575d47fd9161b749ff8b023ef1235a9 : public std::variant<
  Void,
  std::string,
  std::string,
  f6f331efc660707e57f0e15ccf4fd321,
  e952f334fe511c004f72c55ab7164557
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, d575d47fd9161b749ff8b023ef1235a9 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
  }
  return os;
}

struct t {
  d575d47fd9161b749ff8b023ef1235a9 via;
  double timeout;
  bool operator==(t const &other) const {
    return via == other.via && timeout == other.timeout;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "via:" << r.via << ',';
  os << "timeout:" << r.timeout;
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
