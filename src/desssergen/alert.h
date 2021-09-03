#ifndef DESSSER_GEN_alert
#define DESSSER_GEN_alert
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/field_name.h"
#include "desssergen/simple_filter.h"
#include "desssergen/field_name.h"
#include "desssergen/simple_filter.h"
#include "desssergen/field_name.h"
#include "desssergen/fq_name.h"

namespace dessser::gen::alert {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
typedef std::tuple<
  dessser::gen::field_name::t_ext,
  std::string
> t7d737a471b58c17b56f5c31f8c6e717d;

struct t131662737cd7ca0ff4503bc447b90c1f : public std::variant<
  double, // Absolute
  double // Relative
> { using variant::variant; };

enum Constr_t131662737cd7ca0ff4503bc447b90c1f {
  Absolute,
  Relative,
};

inline bool operator==(t131662737cd7ca0ff4503bc447b90c1f const &a, t131662737cd7ca0ff4503bc447b90c1f const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Absolute
    case 1: return std::get<1>(a) == std::get<1>(b); // Relative
  };
  return false;
}
inline bool operator!=(t131662737cd7ca0ff4503bc447b90c1f const &a, t131662737cd7ca0ff4503bc447b90c1f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t131662737cd7ca0ff4503bc447b90c1f const &v) {
  switch (v.index()) {
    case 0: os << "Absolute " << std::get<0>(v); break;
    case 1: os << "Relative " << std::get<1>(v); break;
  }
  return os;
}

struct tbea317b67d84f7d9cf6a71dc11d82f92 {
  double avg_window;
  ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f max_distance;
  double percentile;
  uint32_t sample_size;
  uint32_t seasonality;
  double smooth_factor;
  tbea317b67d84f7d9cf6a71dc11d82f92(double avg_window_, ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f max_distance_, double percentile_, uint32_t sample_size_, uint32_t seasonality_, double smooth_factor_) : avg_window(avg_window_), max_distance(max_distance_), percentile(percentile_), sample_size(sample_size_), seasonality(seasonality_), smooth_factor(smooth_factor_) {}
  tbea317b67d84f7d9cf6a71dc11d82f92() = default;
};
inline std::ostream &operator<<(std::ostream &os, tbea317b67d84f7d9cf6a71dc11d82f92 const &r) {
  os << '{';
  os << "avg_window:" << r.avg_window << ',';
  os << "max_distance:" << r.max_distance << ',';
  os << "percentile:" << r.percentile << ',';
  os << "sample_size:" << r.sample_size << ',';
  os << "seasonality:" << r.seasonality << ',';
  os << "smooth_factor:" << r.smooth_factor;
  os << '}';
  return os;
}
inline bool operator==(tbea317b67d84f7d9cf6a71dc11d82f92 const &a, tbea317b67d84f7d9cf6a71dc11d82f92 const &b) {
  return a.avg_window == b.avg_window && a.max_distance == b.max_distance && a.percentile == b.percentile && a.sample_size == b.sample_size && a.seasonality == b.seasonality && a.smooth_factor == b.smooth_factor;
}

inline bool operator!=(tbea317b67d84f7d9cf6a71dc11d82f92 const &a, tbea317b67d84f7d9cf6a71dc11d82f92 const &b) {
  return !operator==(a, b);
}
struct t7a02edca1273055c3c437ebec83c4409 : public std::variant<
  double, // Constant
  ::dessser::gen::alert::tbea317b67d84f7d9cf6a71dc11d82f92 // Baseline
> { using variant::variant; };

enum Constr_t7a02edca1273055c3c437ebec83c4409 {
  Constant,
  Baseline,
};

inline bool operator==(t7a02edca1273055c3c437ebec83c4409 const &a, t7a02edca1273055c3c437ebec83c4409 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Constant
    case 1: return std::get<1>(a) == std::get<1>(b); // Baseline
  };
  return false;
}
inline bool operator!=(t7a02edca1273055c3c437ebec83c4409 const &a, t7a02edca1273055c3c437ebec83c4409 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t7a02edca1273055c3c437ebec83c4409 const &v) {
  switch (v.index()) {
    case 0: os << "Constant " << std::get<0>(v); break;
    case 1: os << "Baseline " << std::get<1>(v); break;
  }
  return os;
}

struct t {
  Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> carry_csts;
  Lst<dessser::gen::field_name::t_ext> carry_fields;
  dessser::gen::field_name::t_ext column;
  std::string desc_firing;
  std::string desc_recovery;
  std::string desc_title;
  double duration;
  bool enabled;
  std::optional<Lst<dessser::gen::field_name::t_ext>> group_by;
  Lst<dessser::gen::simple_filter::t_ext> having;
  double hysteresis;
  std::string id;
  double ratio;
  dessser::gen::fq_name::t_ext table;
  ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 threshold;
  double time_step;
  Lst<dessser::gen::field_name::t_ext> tops;
  Lst<dessser::gen::simple_filter::t_ext> where;
  t(Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> carry_csts_, Lst<dessser::gen::field_name::t_ext> carry_fields_, dessser::gen::field_name::t_ext column_, std::string desc_firing_, std::string desc_recovery_, std::string desc_title_, double duration_, bool enabled_, std::optional<Lst<dessser::gen::field_name::t_ext>> group_by_, Lst<dessser::gen::simple_filter::t_ext> having_, double hysteresis_, std::string id_, double ratio_, dessser::gen::fq_name::t_ext table_, ::dessser::gen::alert::t7a02edca1273055c3c437ebec83c4409 threshold_, double time_step_, Lst<dessser::gen::field_name::t_ext> tops_, Lst<dessser::gen::simple_filter::t_ext> where_) : carry_csts(carry_csts_), carry_fields(carry_fields_), column(column_), desc_firing(desc_firing_), desc_recovery(desc_recovery_), desc_title(desc_title_), duration(duration_), enabled(enabled_), group_by(group_by_), having(having_), hysteresis(hysteresis_), id(id_), ratio(ratio_), table(table_), threshold(threshold_), time_step(time_step_), tops(tops_), where(where_) {}
  t() = default;
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "carry_csts:" << r.carry_csts << ',';
  os << "carry_fields:" << r.carry_fields << ',';
  os << "column:" << ::dessser::gen::field_name::Deref(r.column) << ',';
  os << "desc_firing:" << r.desc_firing << ',';
  os << "desc_recovery:" << r.desc_recovery << ',';
  os << "desc_title:" << r.desc_title << ',';
  os << "duration:" << r.duration << ',';
  os << "enabled:" << r.enabled << ',';
  if (r.group_by) os << "group_by:" << r.group_by.value() << ',';
  os << "having:" << r.having << ',';
  os << "hysteresis:" << r.hysteresis << ',';
  os << "id:" << r.id << ',';
  os << "ratio:" << r.ratio << ',';
  os << "table:" << ::dessser::gen::fq_name::Deref(r.table) << ',';
  os << "threshold:" << r.threshold << ',';
  os << "time_step:" << r.time_step << ',';
  os << "tops:" << r.tops << ',';
  os << "where:" << r.where;
  os << '}';
  return os;
}
inline bool operator==(t const &a, t const &b) {
  return a.carry_csts == b.carry_csts && a.carry_fields == b.carry_fields && ::dessser::gen::field_name::Deref(a.column) == ::dessser::gen::field_name::Deref(b.column) && a.desc_firing == b.desc_firing && a.desc_recovery == b.desc_recovery && a.desc_title == b.desc_title && a.duration == b.duration && a.enabled == b.enabled && ((a.group_by && b.group_by && a.group_by.value() == b.group_by.value()) || (!a.group_by && !b.group_by)) && a.having == b.having && a.hysteresis == b.hysteresis && a.id == b.id && a.ratio == b.ratio && ::dessser::gen::fq_name::Deref(a.table) == ::dessser::gen::fq_name::Deref(b.table) && a.threshold == b.threshold && a.time_step == b.time_step && a.tops == b.tops && a.where == b.where;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
typedef std::tuple<
  ::dessser::gen::alert::t*,
  Pointer
> t9dbb79f443cdcf3340bfdfbf1b06c337;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::alert::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::alert::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::alert::t9dbb79f443cdcf3340bfdfbf1b06c337(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
