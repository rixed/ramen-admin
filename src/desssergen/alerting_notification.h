#ifndef DESSSER_GEN_alerting_notification
#define DESSSER_GEN_alerting_notification
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/fq_name.h"
#include "desssergen/site_name.h"

namespace dessser::gen::alerting_notification {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
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

struct t {
  dessser::gen::site_name::t_ext site;
  dessser::gen::fq_name::t_ext worker;
  bool test;
  double sent_time;
  std::optional<double> event_time;
  std::string name;
  bool firing;
  double certainty;
  double debounce;
  double timeout;
  Lst<::dessser::gen::alerting_notification::t720047405469e43c41ae902df9d2c463> parameters;
  t(dessser::gen::site_name::t_ext site_, dessser::gen::fq_name::t_ext worker_, bool test_, double sent_time_, std::optional<double> event_time_, std::string name_, bool firing_, double certainty_, double debounce_, double timeout_, Lst<::dessser::gen::alerting_notification::t720047405469e43c41ae902df9d2c463> parameters_) : site(site_), worker(worker_), test(test_), sent_time(sent_time_), event_time(event_time_), name(name_), firing(firing_), certainty(certainty_), debounce(debounce_), timeout(timeout_), parameters(parameters_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site) && ::dessser::gen::fq_name::Deref(a.worker) == ::dessser::gen::fq_name::Deref(b.worker) && a.test == b.test && a.sent_time == b.sent_time && ((a.event_time && b.event_time && a.event_time.value() == b.event_time.value()) || (!a.event_time && !b.event_time)) && a.name == b.name && a.firing == b.firing && a.certainty == b.certainty && a.debounce == b.debounce && a.timeout == b.timeout && a.parameters == b.parameters;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "site:" << r.site << ',';
  os << "worker:" << r.worker << ',';
  os << "test:" << r.test << ',';
  os << "sent_time:" << r.sent_time << ',';
  if (r.event_time) os << "event_time:" << r.event_time.value() << ',';
  os << "name:" << r.name << ',';
  os << "firing:" << r.firing << ',';
  os << "certainty:" << r.certainty << ',';
  os << "debounce:" << r.debounce << ',';
  os << "timeout:" << r.timeout << ',';
  os << "parameters:" << r.parameters;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t7f2136c011f4f9749d693ec511eb7e45 : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_notification::t> ,
  Pointer
> {
  using tuple::tuple;
  t7f2136c011f4f9749d693ec511eb7e45(std::tuple<std::shared_ptr<::dessser::gen::alerting_notification::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_notification::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7f2136c011f4f9749d693ec511eb7e45 const &a, t7f2136c011f4f9749d693ec511eb7e45 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7f2136c011f4f9749d693ec511eb7e45 const &a, t7f2136c011f4f9749d693ec511eb7e45 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t7f2136c011f4f9749d693ec511eb7e45 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t7f2136c011f4f9749d693ec511eb7e45> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_notification::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::alerting_notification::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45(Pointer)> of_row_binary;
extern std::function<::dessser::gen::alerting_notification::t7f2136c011f4f9749d693ec511eb7e45(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_notification::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
