// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef RUNTIMESTATSVIEWER_H_190801
#define RUNTIMESTATSVIEWER_H_190801
#include "AtomicWidget.h"

class QLabel;

namespace dessser {
namespace gen {
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class RuntimeStatsViewer : public AtomicWidget {
  Q_OBJECT

  QLabel *stats_time, *first_startup, *last_startup;
  QLabel *min_etime, *max_etime;
  QLabel *first_input, *last_input;
  QLabel *first_output, *last_output;
  QLabel *tot_in_tuples, *tot_sel_tuples, *tot_out_filtered, *tot_out_tuples,
      *tot_out_errs;
  QLabel *avg_full_bytes;
  QLabel *cur_groups, *max_groups;
  QLabel *tot_in_bytes, *tot_out_bytes;
  QLabel *tot_wait_in, *tot_wait_out;
  QLabel *tot_firing_notifs, *tot_extinguished_notifs;
  QLabel *tot_cpu;
  QLabel *cur_ram, *max_ram;

 public:
  RuntimeStatsViewer(QWidget *parent = nullptr);
  void setEnabled(bool) {}

 public slots:
  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
