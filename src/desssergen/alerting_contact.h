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

struct t491302cf85c6148f165ecf960720a734 : public std::tuple<
  std::string,
  std::string
> {
  using tuple::tuple;
  t491302cf85c6148f165ecf960720a734(std::tuple<std::string, std::string> p)
    : std::tuple<std::string, std::string>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t491302cf85c6148f165ecf960720a734 const &a, t491302cf85c6148f165ecf960720a734 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t491302cf85c6148f165ecf960720a734 const &a, t491302cf85c6148f165ecf960720a734 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t491302cf85c6148f165ecf960720a734 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t491302cf85c6148f165ecf960720a734> const t) { os << *t; return os; }

struct ta01abe30cb0b3ed10ed8f9629a473d35 {
  Lst<::dessser::gen::alerting_contact::t491302cf85c6148f165ecf960720a734> options;
  std::string topic;
  uint16_t partition;
  std::string text;
  ta01abe30cb0b3ed10ed8f9629a473d35(Lst<::dessser::gen::alerting_contact::t491302cf85c6148f165ecf960720a734> options_, std::string topic_, uint16_t partition_, std::string text_) : options(options_), topic(topic_), partition(partition_), text(text_) {}
  ta01abe30cb0b3ed10ed8f9629a473d35() = default;
};
inline bool operator==(ta01abe30cb0b3ed10ed8f9629a473d35 const &a, ta01abe30cb0b3ed10ed8f9629a473d35 const &b) {
  return a.options == b.options && a.topic == b.topic && a.partition == b.partition && a.text == b.text;
}

inline bool operator!=(ta01abe30cb0b3ed10ed8f9629a473d35 const &a, ta01abe30cb0b3ed10ed8f9629a473d35 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ta01abe30cb0b3ed10ed8f9629a473d35 const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "topic:" << r.topic << ',';
  os << "partition:" << r.partition << ',';
  os << "text:" << r.text;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta01abe30cb0b3ed10ed8f9629a473d35> const r) { os << *r; return os; }

struct t370a948715668202b695a186b099b0c9 : public std::variant<
  Void, // Ignore
  std::string, // Exec
  std::string, // SysLog
  ::dessser::gen::alerting_contact::t2295780c8d3630e8bc9d277e6fa82e3b, // Sqlite
  ::dessser::gen::alerting_contact::ta01abe30cb0b3ed10ed8f9629a473d35 // Kafka
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 5 };
};

inline bool operator==(t370a948715668202b695a186b099b0c9 const &a, t370a948715668202b695a186b099b0c9 const &b) {
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
inline bool operator!=(t370a948715668202b695a186b099b0c9 const &a, t370a948715668202b695a186b099b0c9 const &b) {
  return !operator==(a, b);
}
enum Constr_t370a948715668202b695a186b099b0c9 {
  Ignore,
  Exec,
  SysLog,
  Sqlite,
  Kafka,
};

inline std::ostream &operator<<(std::ostream &os, t370a948715668202b695a186b099b0c9 const &v) {
  switch (v.index()) {
    case 0: os << "Ignore" << std::get<0>(v); break;
    case 1: os << "Exec " << std::get<1>(v); break;
    case 2: os << "SysLog " << std::get<2>(v); break;
    case 3: os << "Sqlite " << std::get<3>(v); break;
    case 4: os << "Kafka " << std::get<4>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t370a948715668202b695a186b099b0c9> const v) { os << *v; return os; }

struct t {
  ::dessser::gen::alerting_contact::t370a948715668202b695a186b099b0c9 via;
  double timeout;
  t(::dessser::gen::alerting_contact::t370a948715668202b695a186b099b0c9 via_, double timeout_) : via(via_), timeout(timeout_) {}
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

struct tf575ebd2244aa6b126ef4291c9e6f8ae : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_contact::t> ,
  Pointer
> {
  using tuple::tuple;
  tf575ebd2244aa6b126ef4291c9e6f8ae(std::tuple<std::shared_ptr<::dessser::gen::alerting_contact::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_contact::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf575ebd2244aa6b126ef4291c9e6f8ae const &a, tf575ebd2244aa6b126ef4291c9e6f8ae const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf575ebd2244aa6b126ef4291c9e6f8ae const &a, tf575ebd2244aa6b126ef4291c9e6f8ae const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf575ebd2244aa6b126ef4291c9e6f8ae const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf575ebd2244aa6b126ef4291c9e6f8ae> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::alerting_contact::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae(Pointer)> of_row_binary;
extern std::function<::dessser::gen::alerting_contact::tf575ebd2244aa6b126ef4291c9e6f8ae(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_contact::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
