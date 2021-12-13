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

struct t {
  double certainty;
  double debounce;
  std::optional<double> event_time;
  bool firing;
  std::string name;
  Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> parameters;
  double sent_time;
  dessser::gen::site_name::t_ext site;
  bool test;
  double timeout;
  dessser::gen::fq_name::t_ext worker;
  t(double certainty_, double debounce_, std::optional<double> event_time_, bool firing_, std::string name_, Lst<::dessser::gen::alerting_notification::t491302cf85c6148f165ecf960720a734> parameters_, double sent_time_, dessser::gen::site_name::t_ext site_, bool test_, double timeout_, dessser::gen::fq_name::t_ext worker_) : certainty(certainty_), debounce(debounce_), event_time(event_time_), firing(firing_), name(name_), parameters(parameters_), sent_time(sent_time_), site(site_), test(test_), timeout(timeout_), worker(worker_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.certainty == b.certainty && a.debounce == b.debounce && ((a.event_time && b.event_time && a.event_time.value() == b.event_time.value()) || (!a.event_time && !b.event_time)) && a.firing == b.firing && a.name == b.name && a.parameters == b.parameters && a.sent_time == b.sent_time && ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site) && a.test == b.test && a.timeout == b.timeout && ::dessser::gen::fq_name::Deref(a.worker) == ::dessser::gen::fq_name::Deref(b.worker);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "certainty:" << r.certainty << ',';
  os << "debounce:" << r.debounce << ',';
  if (r.event_time) os << "event_time:" << r.event_time.value() << ',';
  os << "firing:" << r.firing << ',';
  os << "name:" << r.name << ',';
  os << "parameters:" << r.parameters << ',';
  os << "sent_time:" << r.sent_time << ',';
  os << "site:" << r.site << ',';
  os << "test:" << r.test << ',';
  os << "timeout:" << r.timeout << ',';
  os << "worker:" << r.worker;
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
