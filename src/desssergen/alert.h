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

inline std::ostream &operator<<(std::ostream &os, t131662737cd7ca0ff4503bc447b90c1f const &v) {
  switch (v.index()) {
    case 0: os << "Absolute " << std::get<0>(v); break;
    case 1: os << "Relative " << std::get<1>(v); break;
  }
  return os;
}

struct t15f69833df1592880c1d902fbea5be5d {
  double avg_window;
  ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f max_distance;
  double percentile;
  uint32_t sample_size;
  uint32_t seasonality;
  double smooth_factor;
  t15f69833df1592880c1d902fbea5be5d(double avg_window_, ::dessser::gen::alert::t131662737cd7ca0ff4503bc447b90c1f max_distance_, double percentile_, uint32_t sample_size_, uint32_t seasonality_, double smooth_factor_) : avg_window(avg_window_), max_distance(max_distance_), percentile(percentile_), sample_size(sample_size_), seasonality(seasonality_), smooth_factor(smooth_factor_) {}
  t15f69833df1592880c1d902fbea5be5d() = default;
  bool operator==(t15f69833df1592880c1d902fbea5be5d const &other) const {
    return avg_window == other.avg_window && max_distance == other.max_distance && percentile == other.percentile && sample_size == other.sample_size && seasonality == other.seasonality && smooth_factor == other.smooth_factor;
  }
};
inline std::ostream &operator<<(std::ostream &os, t15f69833df1592880c1d902fbea5be5d const &r) {
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

struct t11bf6880ce7222a7e645b7724c23c615 : public std::variant<
  double, // Constant
  ::dessser::gen::alert::t15f69833df1592880c1d902fbea5be5d // Baseline
> { using variant::variant; };

enum Constr_t11bf6880ce7222a7e645b7724c23c615 {
  Constant,
  Baseline,
};

inline std::ostream &operator<<(std::ostream &os, t11bf6880ce7222a7e645b7724c23c615 const &v) {
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
  ::dessser::gen::alert::t11bf6880ce7222a7e645b7724c23c615 threshold;
  double time_step;
  Lst<dessser::gen::field_name::t_ext> tops;
  Lst<dessser::gen::simple_filter::t_ext> where;
  t(Lst<::dessser::gen::alert::t7d737a471b58c17b56f5c31f8c6e717d> carry_csts_, Lst<dessser::gen::field_name::t_ext> carry_fields_, dessser::gen::field_name::t_ext column_, std::string desc_firing_, std::string desc_recovery_, std::string desc_title_, double duration_, bool enabled_, std::optional<Lst<dessser::gen::field_name::t_ext>> group_by_, Lst<dessser::gen::simple_filter::t_ext> having_, double hysteresis_, std::string id_, double ratio_, dessser::gen::fq_name::t_ext table_, ::dessser::gen::alert::t11bf6880ce7222a7e645b7724c23c615 threshold_, double time_step_, Lst<dessser::gen::field_name::t_ext> tops_, Lst<dessser::gen::simple_filter::t_ext> where_) : carry_csts(carry_csts_), carry_fields(carry_fields_), column(column_), desc_firing(desc_firing_), desc_recovery(desc_recovery_), desc_title(desc_title_), duration(duration_), enabled(enabled_), group_by(group_by_), having(having_), hysteresis(hysteresis_), id(id_), ratio(ratio_), table(table_), threshold(threshold_), time_step(time_step_), tops(tops_), where(where_) {}
  t() = default;
  bool operator==(t const &other) const {
    return carry_csts == other.carry_csts && carry_fields == other.carry_fields && column == other.column && desc_firing == other.desc_firing && desc_recovery == other.desc_recovery && desc_title == other.desc_title && duration == other.duration && enabled == other.enabled && group_by == other.group_by && having == other.having && hysteresis == other.hysteresis && id == other.id && ratio == other.ratio && table == other.table && threshold == other.threshold && time_step == other.time_step && tops == other.tops && where == other.where;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "carry_csts:" << r.carry_csts << ',';
  os << "carry_fields:" << r.carry_fields << ',';
  os << "column:" << r.column << ',';
  os << "desc_firing:" << r.desc_firing << ',';
  os << "desc_recovery:" << r.desc_recovery << ',';
  os << "desc_title:" << r.desc_title << ',';
  os << "duration:" << r.duration << ',';
  os << "enabled:" << r.enabled << ',';
  os << "group_by:" << r.group_by << ',';
  os << "having:" << r.having << ',';
  os << "hysteresis:" << r.hysteresis << ',';
  os << "id:" << r.id << ',';
  os << "ratio:" << r.ratio << ',';
  os << "table:" << r.table << ',';
  os << "threshold:" << r.threshold << ',';
  os << "time_step:" << r.time_step << ',';
  os << "tops:" << r.tops << ',';
  os << "where:" << r.where;
  os << '}';
  return os;
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

}
#endif
