#ifndef DESSSER_GEN_alerting_contact
#define DESSSER_GEN_alerting_contact
#include <functional>
#include <memory>
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
struct t2295780c8d3630e8bc9d277e6fa82e3b {
  std::string file;
  std::string insert;
  std::string create;
  t2295780c8d3630e8bc9d277e6fa82e3b(std::string file_, std::string insert_, std::string create_) : file(file_), insert(insert_), create(create_) {}
  t2295780c8d3630e8bc9d277e6fa82e3b() = default;
};
inline bool operator==(t2295780c8d3630e8bc9d277e6fa82e3b const &a, t2295780c8d3630e8bc9d277e6fa82e3b const &b) {
  return a.file == b.file && a.insert == b.insert && a.create == b.create;
}

inline bool operator!=(t2295780c8d3630e8bc9d277e6fa82e3b const &a, t2295780c8d3630e8bc9d277e6fa82e3b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t2295780c8d3630e8bc9d277e6fa82e3b const &r) {
  os << '{';
  os << "file:" << r.file << ',';
  os << "insert:" << r.insert << ',';
  os << "create:" << r.create;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t2295780c8d3630e8bc9d277e6fa82e3b> const r) { os << *r; return os; }

struct t720047405469e43c41ae902df9d2c463 : public std::tuple<
  std::string,
  std::string
> {
  using tuple::tuple;
};
inline bool operator==(t720047405469e43c41ae902df9d2c463 const &a, t720047405469e43c41ae902df9d2c463 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t720047405469e43c41ae902df9d2c463 const &a, t720047405469e43c41ae902df9d2c463 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t720047405469e43c41ae902df9d2c463 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t720047405469e43c41ae902df9d2c463> const t) { os << *t; return os; }

struct t5a8393235cc21d52708273e644b80be6 {
  Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> options;
  std::string topic;
  uint16_t partition;
  std::string text;
  t5a8393235cc21d52708273e644b80be6(Lst<::dessser::gen::alerting_contact::t720047405469e43c41ae902df9d2c463> options_, std::string topic_, uint16_t partition_, std::string text_) : options(options_), topic(topic_), partition(partition_), text(text_) {}
  t5a8393235cc21d52708273e644b80be6() = default;
};
inline bool operator==(t5a8393235cc21d52708273e644b80be6 const &a, t5a8393235cc21d52708273e644b80be6 const &b) {
  return a.options == b.options && a.topic == b.topic && a.partition == b.partition && a.text == b.text;
}

inline bool operator!=(t5a8393235cc21d52708273e644b80be6 const &a, t5a8393235cc21d52708273e644b80be6 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t5a8393235cc21d52708273e644b80be6 const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "topic:" << r.topic << ',';
  os << "partition:" << r.partition << ',';
  os << "text:" << r.text;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t5a8393235cc21d52708273e644b80be6> const r) { os << *r; return os; }

struct via : public std::variant<
  Void, // Ignore
  std::string, // Exec
  std::string, // SysLog
  ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b, // Sqlite
  ::dessser::gen::alerting_contact::t5a8393235cc21d52708273e644b80be6 // Kafka
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 5 };
};

inline bool operator==(via const &a, via const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Ignore
    case 1: return std::get<1>(a) == std::get<1>(b); // Exec
    case 2: return std::get<2>(a) == std::get<2>(b); // SysLog
    case 3: return std::get<3>(a) == std::get<3>(b); // Sqlite
    case 4: return std::get<4>(a) == std::get<4>(b); // Kafka
  };
  return false;
}
inline bool operator!=(via const &a, via const &b) {
  return !operator==(a, b);
}
enum Constr_via {
  Ignore,
  Exec,
  SysLog,
  Sqlite,
  Kafka,
};

inline std::ostream &operator<<(std::ostream &os, via const &v) {
  switch (v.index()) {
    case 0: os << "Ignore" << std::get<0>(v); break;
    case 1: os << "Exec " << std::get<1>(v); break;
    case 2: os << "SysLog " << std::get<2>(v); break;
    case 3: os << "Sqlite " << std::get<3>(v); break;
    case 4: os << "Kafka " << std::get<4>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<via> const v) { os << *v; return os; }

struct t {
  ::dessser::gen::alerting_contact::via via;
  double timeout;
  t(::dessser::gen::alerting_contact::via via_, double timeout_) : via(via_), timeout(timeout_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.via == b.via && a.timeout == b.timeout;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "via:" << r.via << ',';
  os << "timeout:" << r.timeout;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct ted05cba1f8f5a8627f66e87a358c029b : public std::tuple<
  ::dessser::gen::alerting_contact::via,
  Pointer
> {
  using tuple::tuple;
  ted05cba1f8f5a8627f66e87a358c029b(std::tuple<::dessser::gen::alerting_contact::via, Pointer> p)
    : std::tuple<::dessser::gen::alerting_contact::via, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ted05cba1f8f5a8627f66e87a358c029b const &a, ted05cba1f8f5a8627f66e87a358c029b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ted05cba1f8f5a8627f66e87a358c029b const &a, ted05cba1f8f5a8627f66e87a358c029b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ted05cba1f8f5a8627f66e87a358c029b const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ted05cba1f8f5a8627f66e87a358c029b> const t) { os << *t; return os; }

struct t4dd2ce6c858fde4b72fd30927a9bfbe9 : public std::tuple<
  ::dessser::gen::alerting_contact::t,
  Pointer
> {
  using tuple::tuple;
  t4dd2ce6c858fde4b72fd30927a9bfbe9(std::tuple<::dessser::gen::alerting_contact::t, Pointer> p)
    : std::tuple<::dessser::gen::alerting_contact::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4dd2ce6c858fde4b72fd30927a9bfbe9 const &a, t4dd2ce6c858fde4b72fd30927a9bfbe9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4dd2ce6c858fde4b72fd30927a9bfbe9 const &a, t4dd2ce6c858fde4b72fd30927a9bfbe9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4dd2ce6c858fde4b72fd30927a9bfbe9 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t4dd2ce6c858fde4b72fd30927a9bfbe9> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_contact::via const &,Pointer &)> via_to_row_binary;
extern std::function<Pointer(::dessser::gen::alerting_contact::t const &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_contact::via const &)> via_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::alerting_contact::t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_contact::ted05cba1f8f5a8627f66e87a358c029b(Pointer &)> via_of_row_binary;
extern std::function<::dessser::gen::alerting_contact::t4dd2ce6c858fde4b72fd30927a9bfbe9(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::alerting_contact::t4dd2ce6c858fde4b72fd30927a9bfbe9(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::alerting_contact::t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
