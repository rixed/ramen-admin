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
struct tedc744b39731429fd332c70a96eff197 {
  std::string create;
  std::string file;
  std::string insert;
  tedc744b39731429fd332c70a96eff197(std::string create_, std::string file_, std::string insert_) : create(create_), file(file_), insert(insert_) {}
  tedc744b39731429fd332c70a96eff197() = default;
  bool operator==(tedc744b39731429fd332c70a96eff197 const &other) const {
    return create == other.create && file == other.file && insert == other.insert;
  }
};
inline std::ostream &operator<<(std::ostream &os, tedc744b39731429fd332c70a96eff197 const &r) {
  os << '{';
  os << "create:" << r.create << ',';
  os << "file:" << r.file << ',';
  os << "insert:" << r.insert;
  os << '}';
  return os;
}

typedef std::tuple<
  std::string,
  std::string
> t8961925d22ebc35140986110e41bc2a4;

struct ta162576a07cfd299a8ff50304d654002 {
  Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> options;
  uint16_t partition;
  std::string text;
  std::string topic;
  ta162576a07cfd299a8ff50304d654002(Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> options_, uint16_t partition_, std::string text_, std::string topic_) : options(options_), partition(partition_), text(text_), topic(topic_) {}
  ta162576a07cfd299a8ff50304d654002() = default;
  bool operator==(ta162576a07cfd299a8ff50304d654002 const &other) const {
    return options == other.options && partition == other.partition && text == other.text && topic == other.topic;
  }
};
inline std::ostream &operator<<(std::ostream &os, ta162576a07cfd299a8ff50304d654002 const &r) {
  os << '{';
  os << "options:" << r.options << ',';
  os << "partition:" << r.partition << ',';
  os << "text:" << r.text << ',';
  os << "topic:" << r.topic;
  os << '}';
  return os;
}

struct t6bd20739e5344fd740c540830f53c5c4 : public std::variant<
  Void, // Ignore
  std::string, // Exec
  std::string, // SysLog
  ::dessser::gen::alerting_contact::tedc744b39731429fd332c70a96eff197, // Sqlite
  ::dessser::gen::alerting_contact::ta162576a07cfd299a8ff50304d654002 // Kafka
> { using variant::variant; };

enum Constr_t6bd20739e5344fd740c540830f53c5c4 {
  Ignore,
  Exec,
  SysLog,
  Sqlite,
  Kafka,
};

inline std::ostream &operator<<(std::ostream &os, t6bd20739e5344fd740c540830f53c5c4 const &v) {
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
  ::dessser::gen::alerting_contact::t6bd20739e5344fd740c540830f53c5c4 via;
  t(double timeout_, ::dessser::gen::alerting_contact::t6bd20739e5344fd740c540830f53c5c4 via_) : timeout(timeout_), via(via_) {}
  t() = default;
  bool operator==(t const &other) const {
    return timeout == other.timeout && via == other.via;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "timeout:" << r.timeout << ',';
  os << "via:" << r.via;
  os << '}';
  return os;
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

}
#endif
