#ifndef DESSSER_GEN_replay
#define DESSSER_GEN_replay
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/fq_function_name.h"
#include "desssergen/sync_key.h"
#include "desssergen/file_path.h"
#include "desssergen/fq_function_name.h"

namespace dessser::gen::replay {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct tc75d15e003a7ff08bcc9d3be43928a37 : public std::tuple<
  dessser::gen::fq_function_name::t_ext,
  dessser::gen::fq_function_name::t_ext
> {
  using tuple::tuple;
  tc75d15e003a7ff08bcc9d3be43928a37(std::tuple<dessser::gen::fq_function_name::t_ext, dessser::gen::fq_function_name::t_ext> p)
    : std::tuple<dessser::gen::fq_function_name::t_ext, dessser::gen::fq_function_name::t_ext>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc75d15e003a7ff08bcc9d3be43928a37 const &a, tc75d15e003a7ff08bcc9d3be43928a37 const &b) {
  return ::dessser::gen::fq_function_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<0>(b)) && ::dessser::gen::fq_function_name::Deref(std::get<1>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<1>(b));
}
inline bool operator!=(tc75d15e003a7ff08bcc9d3be43928a37 const &a, tc75d15e003a7ff08bcc9d3be43928a37 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc75d15e003a7ff08bcc9d3be43928a37 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc75d15e003a7ff08bcc9d3be43928a37> const t) { os << *t; return os; }

struct tea7c279264063df7624d046b53678d33 : public std::variant<
  dessser::gen::file_path::t_ext, // RingBuf
  dessser::gen::sync_key::t_ext // SyncKey
> { using variant::variant; };

inline bool operator==(tea7c279264063df7624d046b53678d33 const &a, tea7c279264063df7624d046b53678d33 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::file_path::Deref(std::get<0>(a)) == ::dessser::gen::file_path::Deref(std::get<0>(b)); // RingBuf
    case 1: return ::dessser::gen::sync_key::Deref(std::get<1>(a)) == ::dessser::gen::sync_key::Deref(std::get<1>(b)); // SyncKey
  };
  return false;
}
inline bool operator!=(tea7c279264063df7624d046b53678d33 const &a, tea7c279264063df7624d046b53678d33 const &b) {
  return !operator==(a, b);
}
enum Constr_tea7c279264063df7624d046b53678d33 {
  RingBuf,
  SyncKey,
};

inline std::ostream &operator<<(std::ostream &os, tea7c279264063df7624d046b53678d33 const &v) {
  switch (v.index()) {
    case 0: os << "RingBuf " << std::get<0>(v); break;
    case 1: os << "SyncKey " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tea7c279264063df7624d046b53678d33> const v) { os << *v; return os; }

struct t {
  uint16_t channel;
  Arr<::dessser::gen::replay::tc75d15e003a7ff08bcc9d3be43928a37> links;
  ::dessser::gen::replay::tea7c279264063df7624d046b53678d33 recipient;
  double since;
  Arr<dessser::gen::fq_function_name::t_ext> sources;
  dessser::gen::fq_function_name::t_ext target;
  std::string target_fieldmask;
  double timeout_date;
  double until;
  t(uint16_t channel_, Arr<::dessser::gen::replay::tc75d15e003a7ff08bcc9d3be43928a37> links_, ::dessser::gen::replay::tea7c279264063df7624d046b53678d33 recipient_, double since_, Arr<dessser::gen::fq_function_name::t_ext> sources_, dessser::gen::fq_function_name::t_ext target_, std::string target_fieldmask_, double timeout_date_, double until_) : channel(channel_), links(links_), recipient(recipient_), since(since_), sources(sources_), target(target_), target_fieldmask(target_fieldmask_), timeout_date(timeout_date_), until(until_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.channel == b.channel && a.links == b.links && a.recipient == b.recipient && a.since == b.since && a.sources == b.sources && ::dessser::gen::fq_function_name::Deref(a.target) == ::dessser::gen::fq_function_name::Deref(b.target) && a.target_fieldmask == b.target_fieldmask && a.timeout_date == b.timeout_date && a.until == b.until;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
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
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct tec7b3f539b48c1f927aab2bb35ca7970 : public std::tuple<
  std::shared_ptr<::dessser::gen::replay::t> ,
  Pointer
> {
  using tuple::tuple;
  tec7b3f539b48c1f927aab2bb35ca7970(std::tuple<std::shared_ptr<::dessser::gen::replay::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::replay::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tec7b3f539b48c1f927aab2bb35ca7970 const &a, tec7b3f539b48c1f927aab2bb35ca7970 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tec7b3f539b48c1f927aab2bb35ca7970 const &a, tec7b3f539b48c1f927aab2bb35ca7970 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tec7b3f539b48c1f927aab2bb35ca7970 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tec7b3f539b48c1f927aab2bb35ca7970> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::replay::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::replay::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::replay::tec7b3f539b48c1f927aab2bb35ca7970(Pointer)> of_row_binary;
extern std::function<::dessser::gen::replay::tec7b3f539b48c1f927aab2bb35ca7970(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::replay::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
