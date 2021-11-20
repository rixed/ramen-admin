#ifndef DESSSER_GEN_alerting_contact
#define DESSSER_GEN_alerting_contact
#include <arpa/inet.h>
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
struct tbe8824b6bd92590dbb49ce7f29575869 {
  std::string create;
  std::string file;
  std::string insert;
  tbe8824b6bd92590dbb49ce7f29575869(std::string create_, std::string file_, std::string insert_) : create(create_), file(file_), insert(insert_) {}
  tbe8824b6bd92590dbb49ce7f29575869() = default;
};
inline std::ostream &operator<<(std::ostream &os, tbe8824b6bd92590dbb49ce7f29575869 const &r) {
  os << '{';
  os << "create:" << r.create << ',';
  os << "file:" << r.file << ',';
  os << "insert:" << r.insert;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tbe8824b6bd92590dbb49ce7f29575869> const r) { os << *r; return os; }

inline bool operator==(tbe8824b6bd92590dbb49ce7f29575869 const &a, tbe8824b6bd92590dbb49ce7f29575869 const &b) {
  return a.create == b.create && a.file == b.file && a.insert == b.insert;
}

inline bool operator!=(tbe8824b6bd92590dbb49ce7f29575869 const &a, tbe8824b6bd92590dbb49ce7f29575869 const &b) {
  return !operator==(a, b);
}
struct t284e07c4f4868d983fec7971424a1df8 : public std::tuple<
  std::string,
  std::string
> {
  using tuple::tuple;
  t284e07c4f4868d983fec7971424a1df8(std::tuple<std::string, std::string> p)
    : std::tuple<std::string, std::string>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t284e07c4f4868d983fec7971424a1df8 const &a, t284e07c4f4868d983fec7971424a1df8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t284e07c4f4868d983fec7971424a1df8 const &a, t284e07c4f4868d983fec7971424a1df8 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t284e07c4f4868d983fec7971424a1df8 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

struct t4f5f54104181335488041bad68082286 {
  Lst<::dessser::gen::alerting_contact::t284e07c4f4868d983fec7971424a1df8> options;
  uint16_t partition;
  std::string text;
  std::string topic;
  t4f5f54104181335488041bad68082286(Lst<::dessser::gen::alerting_contact::t284e07c4f4868d983fec7971424a1df8> options_, uint16_t partition_, std::string text_, std::string topic_) : options(options_), partition(partition_), text(text_), topic(topic_) {}
  t4f5f54104181335488041bad68082286() = default;
};
inline std::ostream &operator<<(std::ostream &os, t4f5f54104181335488041bad68082286 const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "partition:" << r.partition << ',';
  os << "text:" << r.text << ',';
  os << "topic:" << r.topic;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t4f5f54104181335488041bad68082286> const r) { os << *r; return os; }

inline bool operator==(t4f5f54104181335488041bad68082286 const &a, t4f5f54104181335488041bad68082286 const &b) {
  return a.options == b.options && a.partition == b.partition && a.text == b.text && a.topic == b.topic;
}

inline bool operator!=(t4f5f54104181335488041bad68082286 const &a, t4f5f54104181335488041bad68082286 const &b) {
  return !operator==(a, b);
}
struct ta2737d85243c228c957e6a89b1a2eaef : public std::variant<
  Void, // Ignore
  std::string, // Exec
  std::string, // SysLog
  ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869, // Sqlite
  ::dessser::gen::alerting_contact::t4f5f54104181335488041bad68082286 // Kafka
> { using variant::variant; };

enum Constr_ta2737d85243c228c957e6a89b1a2eaef {
  Ignore,
  Exec,
  SysLog,
  Sqlite,
  Kafka,
};

inline std::ostream &operator<<(std::ostream &os, ta2737d85243c228c957e6a89b1a2eaef const &v) {
  switch (v.index()) {
    case 0: os << "Ignore" << std::get<0>(v); break;
    case 1: os << "Exec " << std::get<1>(v); break;
    case 2: os << "SysLog " << std::get<2>(v); break;
    case 3: os << "Sqlite " << std::get<3>(v); break;
    case 4: os << "Kafka " << std::get<4>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta2737d85243c228c957e6a89b1a2eaef> const v) { os << *v; return os; }

inline bool operator==(ta2737d85243c228c957e6a89b1a2eaef const &a, ta2737d85243c228c957e6a89b1a2eaef const &b) {
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
inline bool operator!=(ta2737d85243c228c957e6a89b1a2eaef const &a, ta2737d85243c228c957e6a89b1a2eaef const &b) {
  return !operator==(a, b);
}
struct t {
  double timeout;
  ::dessser::gen::alerting_contact::ta2737d85243c228c957e6a89b1a2eaef via;
  t(double timeout_, ::dessser::gen::alerting_contact::ta2737d85243c228c957e6a89b1a2eaef via_) : timeout(timeout_), via(via_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "timeout:" << r.timeout << ',';
  os << "via:" << r.via;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

inline bool operator==(t const &a, t const &b) {
  return a.timeout == b.timeout && a.via == b.via;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t64d64e9c0acacb981f0a90c22987e81e : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_contact::t> ,
  Pointer
> {
  using tuple::tuple;
  t64d64e9c0acacb981f0a90c22987e81e(std::tuple<std::shared_ptr<::dessser::gen::alerting_contact::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_contact::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t64d64e9c0acacb981f0a90c22987e81e const &a, t64d64e9c0acacb981f0a90c22987e81e const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t64d64e9c0acacb981f0a90c22987e81e const &a, t64d64e9c0acacb981f0a90c22987e81e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t64d64e9c0acacb981f0a90c22987e81e const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::alerting_contact::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_contact::t64d64e9c0acacb981f0a90c22987e81e(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
