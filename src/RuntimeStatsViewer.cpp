// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "RuntimeStatsViewer.h"

#include <QDebug>
#include <QFormLayout>
#include <QLabel>
#include <QtGlobal>

#include "desssergen/runtime_stats.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc.h"

RuntimeStatsViewer::RuntimeStatsViewer(QWidget *parent) : AtomicWidget(parent) {
  QFormLayout *layout = new QFormLayout;
#define ADD_LABEL(title, var)           \
  do {                                  \
    var = new QLabel;                   \
    layout->addRow(tr(title ":"), var); \
  } while (0);
#define ADD_LABEL_UNIT(title, unit, var) ADD_LABEL(title " (" unit ")", var)
  ADD_LABEL("Stats Time", stats_time);
  ADD_LABEL("First Startup", first_startup);
  ADD_LABEL("Last Startup", last_startup);
  ADD_LABEL("Min. Event-Time", min_etime);
  ADD_LABEL("Max. Event-Time", max_etime);
  ADD_LABEL("First Input", first_input);
  ADD_LABEL("Last Input", last_input);
  ADD_LABEL("First Output", first_output);
  ADD_LABEL("Last Output", last_output);
  // Input can be decomposed in Received and Selected:
  ADD_LABEL("Received Values", tot_in_tuples);
  ADD_LABEL("Selected Values", tot_sel_tuples);
  ADD_LABEL("Filtered Values", tot_out_filtered);
  ADD_LABEL("Output Values", tot_out_tuples);
  ADD_LABEL("Output Errors", tot_out_errs);
  ADD_LABEL_UNIT("Avg. Full Output Size", "bytes", avg_full_bytes);
  ADD_LABEL("Current Group Count", cur_groups);
  ADD_LABEL("Maximum Group count", max_groups);
  ADD_LABEL_UNIT("Received Volume", "bytes", tot_in_bytes);
  ADD_LABEL_UNIT("Output Volume", "bytes", tot_out_bytes);
  ADD_LABEL_UNIT("Waited For Input", "secs", tot_wait_in);
  ADD_LABEL_UNIT("Blocked During Output", "secs", tot_wait_out);
  ADD_LABEL("Firing Notifications", tot_firing_notifs);
  ADD_LABEL("Extinguished Notifications", tot_extinguished_notifs);
  ADD_LABEL_UNIT("CPU Spent", "secs", tot_cpu);
  ADD_LABEL_UNIT("Current RAM Allocated", "bytes", cur_ram);
  ADD_LABEL_UNIT("Max RAM Allocated", "bytes", max_ram);

  QWidget *w = new QWidget;
  w->setLayout(layout);
  relayoutWidget(w);
}

bool RuntimeStatsViewer::setValue(
    std::shared_ptr<dessser::gen::sync_value::t const> v) {
  if (v->index() != dessser::gen::sync_value::RuntimeStats) {
    qCritical() << "Not a RuntimeStats value?!";
    return false;
  }

  std::shared_ptr<dessser::gen::runtime_stats::t> s{
      std::get<dessser::gen::sync_value::RuntimeStats>(*v)};

#define SET_DATE(var) var->setText(stringOfDate(s->var))
  SET_DATE(stats_time);
  SET_DATE(first_startup);
  SET_DATE(last_startup);
#define SET_OPT_DATE(var) \
  var->setText(s->var.has_value() ? stringOfDate(*s->var) : "n.a.")
  SET_OPT_DATE(min_etime);
  SET_OPT_DATE(max_etime);
  SET_OPT_DATE(first_input);
  SET_OPT_DATE(last_input);
  SET_OPT_DATE(first_output);
  SET_OPT_DATE(last_output);
#define SET_NUM(var) var->setText(QString::number(s->var))
  SET_NUM(tot_in_tuples);
  SET_NUM(tot_sel_tuples);
  SET_NUM(tot_out_filtered);
  SET_NUM(tot_out_tuples);
  SET_NUM(tot_out_errs);
  if (s->tot_full_bytes_samples > 0) {
    double avg{(double)s->tot_full_bytes / s->tot_full_bytes_samples};
    avg_full_bytes->setText(QString::number(avg) + QString(" (from ") +
                            QString::number(s->tot_full_bytes_samples) +
                            QString(" samples)"));
  } else {
    avg_full_bytes->setText("no samples");
  }
  SET_NUM(cur_groups);
  SET_NUM(max_groups);
  SET_NUM(tot_in_bytes);
  SET_NUM(tot_out_bytes);
  SET_NUM(tot_wait_in);
  SET_NUM(tot_wait_out);
  SET_NUM(tot_firing_notifs);
  SET_NUM(tot_extinguished_notifs);
  SET_NUM(tot_cpu);
  SET_NUM(cur_ram);
  SET_NUM(max_ram);
  return true;
}
