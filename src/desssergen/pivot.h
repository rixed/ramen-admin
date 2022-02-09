#ifndef DESSSER_GEN_pivot
#define DESSSER_GEN_pivot
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/simple_filter.h"
#include "desssergen/fq_name.h"

namespace dessser::gen::pivot {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct top {
  uint16_t n;
  std::optional<dessser::gen::field_name::t_ext> by;
  top(uint16_t n_, std::optional<dessser::gen::field_name::t_ext> by_) : n(n_), by(by_) {}
  top() = default;
};
inline bool operator==(top const &a, top const &b) {
  return a.n == b.n && ((a.by && b.by && ::dessser::gen::field_name::Deref(a.by.value()) == ::dessser::gen::field_name::Deref(b.by.value())) || (!a.by && !b.by));
}

inline bool operator!=(top const &a, top const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, top const &r) {
  os << '{';
  os << "n:" << r.n << ',';
  if (r.by) os << "by:" << r.by.value();
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<top> const r) { os << *r; return os; }

struct t059f1fa93342ed0bef3dcabcd095d2f9 {
  dessser::gen::field_name::t_ext name;
  Arr<std::string> types;
  bool count;
  bool first;
  bool last;
  bool min;
  bool max;
  bool sum;
  bool avg;
  Arr<double> percentiles;
  Arr<std::shared_ptr<::dessser::gen::pivot::top> > tops;
  t059f1fa93342ed0bef3dcabcd095d2f9(dessser::gen::field_name::t_ext name_, Arr<std::string> types_, bool count_, bool first_, bool last_, bool min_, bool max_, bool sum_, bool avg_, Arr<double> percentiles_, Arr<std::shared_ptr<::dessser::gen::pivot::top> > tops_) : name(name_), types(types_), count(count_), first(first_), last(last_), min(min_), max(max_), sum(sum_), avg(avg_), percentiles(percentiles_), tops(tops_) {}
  t059f1fa93342ed0bef3dcabcd095d2f9() = default;
};
inline bool operator==(t059f1fa93342ed0bef3dcabcd095d2f9 const &a, t059f1fa93342ed0bef3dcabcd095d2f9 const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && a.types == b.types && a.count == b.count && a.first == b.first && a.last == b.last && a.min == b.min && a.max == b.max && a.sum == b.sum && a.avg == b.avg && a.percentiles == b.percentiles && a.tops == b.tops;
}

inline bool operator!=(t059f1fa93342ed0bef3dcabcd095d2f9 const &a, t059f1fa93342ed0bef3dcabcd095d2f9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t059f1fa93342ed0bef3dcabcd095d2f9 const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "types:" << r.types << ',';
  os << "count:" << r.count << ',';
  os << "first:" << r.first << ',';
  os << "last:" << r.last << ',';
  os << "min:" << r.min << ',';
  os << "max:" << r.max << ',';
  os << "sum:" << r.sum << ',';
  os << "avg:" << r.avg << ',';
  os << "percentiles:" << r.percentiles << ',';
  os << "tops:" << r.tops;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t059f1fa93342ed0bef3dcabcd095d2f9> const r) { os << *r; return os; }

struct t {
  dessser::gen::fq_name::t_ext from;
  Arr<dessser::gen::simple_filter::t_ext> where;
  dessser::gen::field_name::t_ext type_field;
  dessser::gen::field_name::t_ext value_field;
  Arr<::dessser::gen::pivot::t059f1fa93342ed0bef3dcabcd095d2f9> fields;
  Arr<dessser::gen::field_name::t_ext> group_by;
  double duration;
  double max_lateness;
  t(dessser::gen::fq_name::t_ext from_, Arr<dessser::gen::simple_filter::t_ext> where_, dessser::gen::field_name::t_ext type_field_, dessser::gen::field_name::t_ext value_field_, Arr<::dessser::gen::pivot::t059f1fa93342ed0bef3dcabcd095d2f9> fields_, Arr<dessser::gen::field_name::t_ext> group_by_, double duration_, double max_lateness_) : from(from_), where(where_), type_field(type_field_), value_field(value_field_), fields(fields_), group_by(group_by_), duration(duration_), max_lateness(max_lateness_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::fq_name::Deref(a.from) == ::dessser::gen::fq_name::Deref(b.from) && a.where == b.where && ::dessser::gen::field_name::Deref(a.type_field) == ::dessser::gen::field_name::Deref(b.type_field) && ::dessser::gen::field_name::Deref(a.value_field) == ::dessser::gen::field_name::Deref(b.value_field) && a.fields == b.fields && a.group_by == b.group_by && a.duration == b.duration && a.max_lateness == b.max_lateness;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "from:" << r.from << ',';
  os << "where:" << r.where << ',';
  os << "type_field:" << r.type_field << ',';
  os << "value_field:" << r.value_field << ',';
  os << "fields:" << r.fields << ',';
  os << "group_by:" << r.group_by << ',';
  os << "duration:" << r.duration << ',';
  os << "max_lateness:" << r.max_lateness;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const r) { os << *r; return os; }

struct t498521851bf7a2257815e2a638462f1b : public std::tuple<
  std::shared_ptr<::dessser::gen::pivot::top> ,
  Pointer
> {
  using tuple::tuple;
  t498521851bf7a2257815e2a638462f1b(std::tuple<std::shared_ptr<::dessser::gen::pivot::top> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::pivot::top> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t498521851bf7a2257815e2a638462f1b const &a, t498521851bf7a2257815e2a638462f1b const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t498521851bf7a2257815e2a638462f1b const &a, t498521851bf7a2257815e2a638462f1b const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t498521851bf7a2257815e2a638462f1b const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t498521851bf7a2257815e2a638462f1b> const t) { os << *t; return os; }

struct t38a0a078e14635d651c18914486e10a0 : public std::tuple<
  std::shared_ptr<::dessser::gen::pivot::t> ,
  Pointer
> {
  using tuple::tuple;
  t38a0a078e14635d651c18914486e10a0(std::tuple<std::shared_ptr<::dessser::gen::pivot::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::pivot::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t38a0a078e14635d651c18914486e10a0 const &a, t38a0a078e14635d651c18914486e10a0 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t38a0a078e14635d651c18914486e10a0 const &a, t38a0a078e14635d651c18914486e10a0 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t38a0a078e14635d651c18914486e10a0 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t38a0a078e14635d651c18914486e10a0> const t) { os << *t; return os; }

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::pivot::top> ,Pointer)> top_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::pivot::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::pivot::top> )> top_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::pivot::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::pivot::t498521851bf7a2257815e2a638462f1b(Pointer)> top_of_row_binary;
extern std::function<::dessser::gen::pivot::t38a0a078e14635d651c18914486e10a0(Pointer)> of_row_binary;
extern std::function<::dessser::gen::pivot::t38a0a078e14635d651c18914486e10a0(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::pivot::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
