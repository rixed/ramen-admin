#ifndef DESSSER_GEN_alerting_inhibition
#define DESSSER_GEN_alerting_inhibition
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::alerting_inhibition {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  double start_date;
  double stop_date;
  std::string what;
  std::string who;
  std::string why;
  t(double start_date_, double stop_date_, std::string what_, std::string who_, std::string why_) : start_date(start_date_), stop_date(stop_date_), what(what_), who(who_), why(why_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "start_date:" << r.start_date << ',';
  os << "stop_date:" << r.stop_date << ',';
  os << "what:" << r.what << ',';
  os << "who:" << r.who << ',';
  os << "why:" << r.why;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.start_date == b.start_date && a.stop_date == b.stop_date && a.what == b.what && a.who == b.who && a.why == b.why;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t7b36490807adef2395f9ec16d5d2062c : public std::tuple<
  ::dessser::gen::alerting_inhibition::t*,
  Pointer
> {
  using tuple::tuple;
  t7b36490807adef2395f9ec16d5d2062c(std::tuple<::dessser::gen::alerting_inhibition::t*, Pointer> p)
    : std::tuple<::dessser::gen::alerting_inhibition::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7b36490807adef2395f9ec16d5d2062c const &a, t7b36490807adef2395f9ec16d5d2062c const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7b36490807adef2395f9ec16d5d2062c const &a, t7b36490807adef2395f9ec16d5d2062c const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t7b36490807adef2395f9ec16d5d2062c const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_inhibition::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_inhibition::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_inhibition::t7b36490807adef2395f9ec16d5d2062c(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
