#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct v_6bc058134828a7663c6e9878f9b39a3c : public std::variant<
  double,
  double
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_6bc058134828a7663c6e9878f9b39a3c const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct v_3803b7ae191c648b9c5667fedf347d4e {
  double avg_window;
  uint32_t sample_size;
  double percentile;
  uint32_t seasonality;
  double smooth_factor;
  v_6bc058134828a7663c6e9878f9b39a3c max_distance;
  bool operator==(v_3803b7ae191c648b9c5667fedf347d4e const &other) const {
    return avg_window == other.avg_window && sample_size == other.sample_size && percentile == other.percentile && seasonality == other.seasonality && smooth_factor == other.smooth_factor && max_distance == other.max_distance;
  }
};
std::ostream &operator<<(std::ostream &os, v_3803b7ae191c648b9c5667fedf347d4e const &r) {
  os << '{';
  os << "avg_window:" << r.avg_window << ',';
  os << "sample_size:" << r.sample_size << ',';
  os << "percentile:" << r.percentile << ',';
  os << "seasonality:" << r.seasonality << ',';
  os << "smooth_factor:" << r.smooth_factor << ',';
  os << "max_distance:" << r.max_distance;
  os << '}';
  return os;
}

struct v_61ea399b3f4cf5e20f4606674ff2217c : public std::variant<
  double,
  v_3803b7ae191c648b9c5667fedf347d4e
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_61ea399b3f4cf5e20f4606674ff2217c const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  *field_name,
  std::string
> b0391754a7662c5a5541af429d4123b4;

struct t {
  *fq_name table;
  *field_name column;
  bool enabled;
  Lst<*simple_filter> where;
  std::optional<Lst<*field_name>> group_by;
  Lst<*simple_filter> having;
  v_61ea399b3f4cf5e20f4606674ff2217c threshold;
  double hysteresis;
  double duration;
  double ratio;
  double time_step;
  Lst<*field_name> tops;
  Lst<*field_name> carry_fields;
  Lst<b0391754a7662c5a5541af429d4123b4> carry_csts;
  std::string id;
  std::string desc_title;
  std::string desc_firing;
  std::string desc_recovery;
  bool operator==(t const &other) const {
    return table == other.table && column == other.column && enabled == other.enabled && where == other.where && group_by == other.group_by && having == other.having && threshold == other.threshold && hysteresis == other.hysteresis && duration == other.duration && ratio == other.ratio && time_step == other.time_step && tops == other.tops && carry_fields == other.carry_fields && carry_csts == other.carry_csts && id == other.id && desc_title == other.desc_title && desc_firing == other.desc_firing && desc_recovery == other.desc_recovery;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "table:" << r.table << ',';
  os << "column:" << r.column << ',';
  os << "enabled:" << r.enabled << ',';
  os << "where:" << r.where << ',';
  os << "group-by:" << r.group_by << ',';
  os << "having:" << r.having << ',';
  os << "threshold:" << r.threshold << ',';
  os << "hysteresis:" << r.hysteresis << ',';
  os << "duration:" << r.duration << ',';
  os << "ratio:" << r.ratio << ',';
  os << "time-step:" << r.time_step << ',';
  os << "tops:" << r.tops << ',';
  os << "carry-fields:" << r.carry_fields << ',';
  os << "carry-csts:" << r.carry_csts << ',';
  os << "id:" << r.id << ',';
  os << "desc-title:" << r.desc_title << ',';
  os << "desc-firing:" << r.desc_firing << ',';
  os << "desc-recovery:" << r.desc_recovery;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

/* ----------- */
/* Definitions */
/* ----------- */
std::function<Pointer(t,Pointer)> to_row_binary;
std::function<Size(t)> sersize_of_row_binary;
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary;

}
