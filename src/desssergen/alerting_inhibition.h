#ifndef DESSSER_GEN_alerting_inhibition
#define DESSSER_GEN_alerting_inhibition
#include <arpa/inet.h>
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
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

inline bool operator==(t const &a, t const &b) {
  return a.start_date == b.start_date && a.stop_date == b.stop_date && a.what == b.what && a.who == b.who && a.why == b.why;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t4595ec1adc4f7355158d53cad66ecc5b : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_inhibition::t> ,
  Pointer
> {
  using tuple::tuple;
  t4595ec1adc4f7355158d53cad66ecc5b(std::tuple<std::shared_ptr<::dessser::gen::alerting_inhibition::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_inhibition::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4595ec1adc4f7355158d53cad66ecc5b const &a, t4595ec1adc4f7355158d53cad66ecc5b const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4595ec1adc4f7355158d53cad66ecc5b const &a, t4595ec1adc4f7355158d53cad66ecc5b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4595ec1adc4f7355158d53cad66ecc5b const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t4595ec1adc4f7355158d53cad66ecc5b> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_inhibition::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::alerting_inhibition::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::alerting_inhibition::t4595ec1adc4f7355158d53cad66ecc5b(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
