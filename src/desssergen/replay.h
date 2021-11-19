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
struct t8b5761d72d0b8fde816fcaa9bfc21290 : public std::tuple<
  dessser::gen::fq_function_name::t_ext,
  dessser::gen::fq_function_name::t_ext
> {
  using tuple::tuple;
  t8b5761d72d0b8fde816fcaa9bfc21290(std::tuple<dessser::gen::fq_function_name::t_ext, dessser::gen::fq_function_name::t_ext> p)
    : std::tuple<dessser::gen::fq_function_name::t_ext, dessser::gen::fq_function_name::t_ext>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8b5761d72d0b8fde816fcaa9bfc21290 const &a, t8b5761d72d0b8fde816fcaa9bfc21290 const &b) {
  return ::dessser::gen::fq_function_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<0>(b)) && ::dessser::gen::fq_function_name::Deref(std::get<1>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<1>(b));
}
inline bool operator!=(t8b5761d72d0b8fde816fcaa9bfc21290 const &a, t8b5761d72d0b8fde816fcaa9bfc21290 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t8b5761d72d0b8fde816fcaa9bfc21290 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t249796f29bea1f0bea9516f4b3a8f909 : public std::variant<
  dessser::gen::file_path::t_ext, // RingBuf
  dessser::gen::sync_key::t_ext // SyncKey
> { using variant::variant; };

enum Constr_t249796f29bea1f0bea9516f4b3a8f909 {
  RingBuf,
  SyncKey,
};

inline std::ostream &operator<<(std::ostream &os, t249796f29bea1f0bea9516f4b3a8f909 const &v) {
  switch (v.index()) {
    case 0: os << "RingBuf " << ::dessser::gen::file_path::Deref(std::get<0>(v)); break;
    case 1: os << "SyncKey " << ::dessser::gen::sync_key::Deref(std::get<1>(v)); break;
  }
  return os;
}

inline bool operator==(t249796f29bea1f0bea9516f4b3a8f909 const &a, t249796f29bea1f0bea9516f4b3a8f909 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return ::dessser::gen::file_path::Deref(std::get<0>(a)) == ::dessser::gen::file_path::Deref(std::get<0>(b)); // RingBuf
    case 1: return ::dessser::gen::sync_key::Deref(std::get<1>(a)) == ::dessser::gen::sync_key::Deref(std::get<1>(b)); // SyncKey
  };
  return false;
}
inline bool operator!=(t249796f29bea1f0bea9516f4b3a8f909 const &a, t249796f29bea1f0bea9516f4b3a8f909 const &b) {
  return !operator==(a, b);
}
struct t {
  uint16_t channel;
  Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> links;
  ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 recipient;
  double since;
  Arr<dessser::gen::fq_function_name::t_ext> sources;
  dessser::gen::fq_function_name::t_ext target;
  std::string target_fieldmask;
  double timeout_date;
  double until;
  t(uint16_t channel_, Arr<::dessser::gen::replay::t8b5761d72d0b8fde816fcaa9bfc21290> links_, ::dessser::gen::replay::t249796f29bea1f0bea9516f4b3a8f909 recipient_, double since_, Arr<dessser::gen::fq_function_name::t_ext> sources_, dessser::gen::fq_function_name::t_ext target_, std::string target_fieldmask_, double timeout_date_, double until_) : channel(channel_), links(links_), recipient(recipient_), since(since_), sources(sources_), target(target_), target_fieldmask(target_fieldmask_), timeout_date(timeout_date_), until(until_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "channel:" << r.channel << ',';
  os << "links:" << r.links << ',';
  os << "recipient:" << r.recipient << ',';
  os << "since:" << r.since << ',';
  os << "sources:" << r.sources << ',';
  os << "target:" << ::dessser::gen::fq_function_name::Deref(r.target) << ',';
  os << "target_fieldmask:" << r.target_fieldmask << ',';
  os << "timeout_date:" << r.timeout_date << ',';
  os << "until:" << r.until;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.channel == b.channel && a.links == b.links && a.recipient == b.recipient && a.since == b.since && a.sources == b.sources && ::dessser::gen::fq_function_name::Deref(a.target) == ::dessser::gen::fq_function_name::Deref(b.target) && a.target_fieldmask == b.target_fieldmask && a.timeout_date == b.timeout_date && a.until == b.until;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t0e599894aecab3395c467833ad77eb85 : public std::tuple<
  std::shared_ptr<::dessser::gen::replay::t> ,
  Pointer
> {
  using tuple::tuple;
  t0e599894aecab3395c467833ad77eb85(std::tuple<std::shared_ptr<::dessser::gen::replay::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::replay::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0e599894aecab3395c467833ad77eb85 const &a, t0e599894aecab3395c467833ad77eb85 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0e599894aecab3395c467833ad77eb85 const &a, t0e599894aecab3395c467833ad77eb85 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t0e599894aecab3395c467833ad77eb85 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::replay::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::replay::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::replay::t0e599894aecab3395c467833ad77eb85(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t>  r) { os << *r; return os; }

}
#endif
