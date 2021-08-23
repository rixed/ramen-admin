#ifndef DESSSER_GEN_runtime_stats
#define DESSSER_GEN_runtime_stats
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
#include <variant>
#include <vector>
#include "dessser/runtime.h"

namespace dessser::gen::runtime_stats {
using dessser::operator<<;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  uint64_t cur_groups;
  uint64_t cur_ram;
  std::optional<double> first_input;
  std::optional<double> first_output;
  double first_startup;
  std::optional<double> last_input;
  std::optional<double> last_output;
  double last_startup;
  std::optional<double> max_etime;
  uint64_t max_groups;
  uint64_t max_ram;
  std::optional<double> min_etime;
  double stats_time;
  double tot_cpu;
  uint64_t tot_extinguished_notifs;
  uint64_t tot_firing_notifs;
  uint64_t tot_full_bytes;
  uint64_t tot_full_bytes_samples;
  uint64_t tot_in_bytes;
  uint64_t tot_in_tuples;
  uint64_t tot_out_bytes;
  uint64_t tot_out_errs;
  uint64_t tot_out_filtered;
  uint64_t tot_out_tuples;
  uint64_t tot_sel_tuples;
  double tot_wait_in;
  double tot_wait_out;
  bool operator==(t const &other) const {
    return cur_groups == other.cur_groups && cur_ram == other.cur_ram && first_input == other.first_input && first_output == other.first_output && first_startup == other.first_startup && last_input == other.last_input && last_output == other.last_output && last_startup == other.last_startup && max_etime == other.max_etime && max_groups == other.max_groups && max_ram == other.max_ram && min_etime == other.min_etime && stats_time == other.stats_time && tot_cpu == other.tot_cpu && tot_extinguished_notifs == other.tot_extinguished_notifs && tot_firing_notifs == other.tot_firing_notifs && tot_full_bytes == other.tot_full_bytes && tot_full_bytes_samples == other.tot_full_bytes_samples && tot_in_bytes == other.tot_in_bytes && tot_in_tuples == other.tot_in_tuples && tot_out_bytes == other.tot_out_bytes && tot_out_errs == other.tot_out_errs && tot_out_filtered == other.tot_out_filtered && tot_out_tuples == other.tot_out_tuples && tot_sel_tuples == other.tot_sel_tuples && tot_wait_in == other.tot_wait_in && tot_wait_out == other.tot_wait_out;
  }
};
inline std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "cur_groups:" << r.cur_groups << ',';
  os << "cur_ram:" << r.cur_ram << ',';
  os << "first_input:" << r.first_input << ',';
  os << "first_output:" << r.first_output << ',';
  os << "first_startup:" << r.first_startup << ',';
  os << "last_input:" << r.last_input << ',';
  os << "last_output:" << r.last_output << ',';
  os << "last_startup:" << r.last_startup << ',';
  os << "max_etime:" << r.max_etime << ',';
  os << "max_groups:" << r.max_groups << ',';
  os << "max_ram:" << r.max_ram << ',';
  os << "min_etime:" << r.min_etime << ',';
  os << "stats_time:" << r.stats_time << ',';
  os << "tot_cpu:" << r.tot_cpu << ',';
  os << "tot_extinguished_notifs:" << r.tot_extinguished_notifs << ',';
  os << "tot_firing_notifs:" << r.tot_firing_notifs << ',';
  os << "tot_full_bytes:" << r.tot_full_bytes << ',';
  os << "tot_full_bytes_samples:" << r.tot_full_bytes_samples << ',';
  os << "tot_in_bytes:" << r.tot_in_bytes << ',';
  os << "tot_in_tuples:" << r.tot_in_tuples << ',';
  os << "tot_out_bytes:" << r.tot_out_bytes << ',';
  os << "tot_out_errs:" << r.tot_out_errs << ',';
  os << "tot_out_filtered:" << r.tot_out_filtered << ',';
  os << "tot_out_tuples:" << r.tot_out_tuples << ',';
  os << "tot_sel_tuples:" << r.tot_sel_tuples << ',';
  os << "tot_wait_in:" << r.tot_wait_in << ',';
  os << "tot_wait_out:" << r.tot_wait_out;
  os << '}';
  return os;
}

typedef std::tuple<
  ::dessser::gen::runtime_stats::t*,
  Pointer
> td7d9e9b8a490b2a0e053496659aaee30;

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::runtime_stats::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::runtime_stats::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::runtime_stats::td7d9e9b8a490b2a0e053496659aaee30(Pointer)> of_row_binary;
typedef t *t_ext;

}
#endif
