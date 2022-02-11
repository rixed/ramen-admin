#ifndef DESSSER_GEN_alerting_inhibition
#define DESSSER_GEN_alerting_inhibition
#include <functional>
#include <memory>
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
  std::string what;
  double start_date;
  double stop_date;
  std::string who;
  std::string why;
  t(std::string what_, double start_date_, double stop_date_, std::string who_, std::string why_) : what(what_), start_date(start_date_), stop_date(stop_date_), who(who_), why(why_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.what == b.what && a.start_date == b.start_date && a.stop_date == b.stop_date && a.who == b.who && a.why == b.why;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "what:" << r.what << ',';
  os << "start_date:" << r.start_date << ',';
  os << "stop_date:" << r.stop_date << ',';
  os << "who:" << r.who << ',';
  os << "why:" << r.why;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct td0766d14326fd014941742c3a29e7ad3 : public std::tuple<
  ::dessser::gen::alerting_inhibition::t,
  Pointer
> {
  using tuple::tuple;
  td0766d14326fd014941742c3a29e7ad3(std::tuple<::dessser::gen::alerting_inhibition::t, Pointer> p)
    : std::tuple<::dessser::gen::alerting_inhibition::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td0766d14326fd014941742c3a29e7ad3 const &a, td0766d14326fd014941742c3a29e7ad3 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td0766d14326fd014941742c3a29e7ad3 const &a, td0766d14326fd014941742c3a29e7ad3 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, td0766d14326fd014941742c3a29e7ad3 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<td0766d14326fd014941742c3a29e7ad3> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alerting_inhibition::t const &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::alerting_inhibition::t const &)> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::alerting_inhibition::td0766d14326fd014941742c3a29e7ad3(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::alerting_inhibition::t const &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
