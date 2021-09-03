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
inline bool operator==(tbe8824b6bd92590dbb49ce7f29575869 const &a, tbe8824b6bd92590dbb49ce7f29575869 const &b) {
  return a.create == b.create && a.file == b.file && a.insert == b.insert;
}

inline bool operator!=(tbe8824b6bd92590dbb49ce7f29575869 const &a, tbe8824b6bd92590dbb49ce7f29575869 const &b) {
  return !operator==(a, b);
}
typedef std::tuple<
  std::string,
  std::string
> t8961925d22ebc35140986110e41bc2a4;

struct t34ef5cb3b50881faab30fa24cda711db {
  Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> options;
  uint16_t partition;
  std::string text;
  std::string topic;
  t34ef5cb3b50881faab30fa24cda711db(Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> options_, uint16_t partition_, std::string text_, std::string topic_) : options(options_), partition(partition_), text(text_), topic(topic_) {}
  t34ef5cb3b50881faab30fa24cda711db() = default;
};
inline std::ostream &operator<<(std::ostream &os, t34ef5cb3b50881faab30fa24cda711db const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "partition:" << r.partition << ',';
  os << "text:" << r.text << ',';
  os << "topic:" << r.topic;
  os << '}';
  return os;
}
inline bool operator==(t34ef5cb3b50881faab30fa24cda711db const &a, t34ef5cb3b50881faab30fa24cda711db const &b) {
  return a.options == b.options && a.partition == b.partition && a.text == b.text && a.topic == b.topic;
}

inline bool operator!=(t34ef5cb3b50881faab30fa24cda711db const &a, t34ef5cb3b50881faab30fa24cda711db const &b) {
  return !operator==(a, b);
}
struct tf87a9e0f02ad9bcade189d770d3129cc : public std::variant<
  Void, // Ignore
  std::string, // Exec
  std::string, // SysLog
  ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869, // Sqlite
  ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db // Kafka
> { using variant::variant; };

enum Constr_tf87a9e0f02ad9bcade189d770d3129cc {
  Ignore,
  Exec,
  SysLog,
  Sqlite,
  Kafka,
};

inline bool operator==(tf87a9e0f02ad9bcade189d770d3129cc const &a, tf87a9e0f02ad9bcade189d770d3129cc const &b) {
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
inline bool operator!=(tf87a9e0f02ad9bcade189d770d3129cc const &a, tf87a9e0f02ad9bcade189d770d3129cc const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf87a9e0f02ad9bcade189d770d3129cc const &v) {
  switch (v.index()) {
    case 0: os << "Ignore " << std::get<0>(v); break;
    case 1: os << "Exec " << std::get<1>(v); break;
    case 2: os << "SysLog " << std::get<2>(v); break;
    case 3: os << "Sqlite " << std::get<3>(v); break;
    case 4: os << "Kafka " << std::get<4>(v); break;
  }
  return os;
}

struct t {
  double timeout;
  ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc via;
  t(double timeout_, ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc via_) : timeout(timeout_), via(via_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "timeout:" << r.timeout << ',';
  os << "via:" << r.via;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.timeout == b.timeout && a.via == b.via;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
typedef std::tuple<
  ::dessser::gen::alerting_contact::t*,
  Pointer
> t6895345151933b08a9380e7a927036c0;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_contact::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_contact::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_contact::t6895345151933b08a9380e7a927036c0(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
