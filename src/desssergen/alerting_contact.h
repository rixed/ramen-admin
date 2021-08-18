#ifndef DESSSER_GEN_alerting_contact
#define DESSSER_GEN_alerting_contact
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::alerting_contact {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t8168c0cbfe27e0636debcd4584da2f46 {
  std::string file;
  std::string insert;
  std::string create;
  bool operator==(t8168c0cbfe27e0636debcd4584da2f46 const &other) const {
    return file == other.file && insert == other.insert && create == other.create;
  }
};
inline std::ostream &operator<<(std::ostream &os, t8168c0cbfe27e0636debcd4584da2f46 const &r) {
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
> t8961925d22ebc35140986110e41bc2a4;

struct t33f81fdc8a31c3bb7fa1e41b40b7bf7e {
  Lst<t8961925d22ebc35140986110e41bc2a4> options;
  std::string topic;
  uint16_t partition;
  std::string text;
  bool operator==(t33f81fdc8a31c3bb7fa1e41b40b7bf7e const &other) const {
    return options == other.options && topic == other.topic && partition == other.partition && text == other.text;
  }
};
inline std::ostream &operator<<(std::ostream &os, t33f81fdc8a31c3bb7fa1e41b40b7bf7e const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "topic:" << r.topic << ',';
  os << "partition:" << r.partition << ',';
  os << "text:" << r.text;
  os << '}';
  return os;
}

struct td1d0857ca32957475d057baccdf24fb1 : public std::variant<
  Void,
  std::string,
  std::string,
  t8168c0cbfe27e0636debcd4584da2f46,
  t33f81fdc8a31c3bb7fa1e41b40b7bf7e
> { using variant::variant; };
inline std::ostream &operator<<(std::ostream &os, td1d0857ca32957475d057baccdf24fb1 const &v) {
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
  td1d0857ca32957475d057baccdf24fb1 via;
  double timeout;
  bool operator==(t const &other) const {
    return via == other.via && timeout == other.timeout;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "via:" << r.via << ',';
  os << "timeout:" << r.timeout;
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
