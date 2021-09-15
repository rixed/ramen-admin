#include <QtGlobal>
#include <QDebug>
#include <QFormLayout>
#include <QLabel>
#include <QCheckBox>

#include "desssergen/func_ref.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/worker.h"
#include "MakeSyncValue.h"
#include "misc.h"
#include "misc_dessser.h"
#include "RangeDoubleValidator.h"

#include "WorkerViewer.h"

WorkerViewer::WorkerViewer(QWidget *parent) :
  AtomicWidget(parent)
{
  enabled = new QCheckBox("Enabled");
  enabled->setEnabled(false);
  debug = new QCheckBox("Debug");
  debug->setEnabled(false);
  used = new QCheckBox("In Use");
  used->setEnabled(false);
  QVBoxLayout *flagsLayout = new QVBoxLayout;
  flagsLayout->addWidget(enabled);
  flagsLayout->addWidget(debug);
  flagsLayout->addWidget(used);

  reportPeriod = new QLabel;
  cwd = new QLabel;
  workerSign = new QLabel;
  binSign = new QLabel;
  role = new QLabel;

  params = new QFormLayout;
  parents = new QVBoxLayout;

  QFormLayout *layout = new QFormLayout;
  layout->addRow(tr("Role:"), role);
  layout->addRow(new QLabel(tr("Parameters:")));
  layout->addRow(params);
  layout->addRow(new QLabel(tr("Parents:")));
  layout->addRow(parents);
  layout->addRow(tr("Flags:"), flagsLayout);
  layout->addRow(tr("Report Every:"), reportPeriod);
  layout->addRow(tr("Working Directory:"), cwd);
  layout->addRow(tr("Worker Signatures:"), workerSign);
  layout->addRow(tr("Binary Signatures:"), binSign);

  QWidget *w = new QWidget;
  w->setLayout(layout);
  relayoutWidget(w);
}

void WorkerViewer::setEnabled(bool enabled_)
{
  enabled->setEnabled(enabled_);
  debug->setEnabled(enabled_);
  used->setEnabled(enabled_);
}

static QString const qstringOfRole(dessser::gen::worker::t const &worker)
{
  if (worker.role.index() == dessser::gen::worker::Whole)
    return QString("normal");
  else
    return QString("top-half");
}

static QString const qstringOfRef(dessser::gen::func_ref::t const &ref)
{
  QString const fq {
    QString::fromStdString(ref.program) + "/" +
    QString::fromStdString(ref.func) };
  if (ref.site.size() == 0) return fq;
  return QString::fromStdString(ref.site) + ":" + fq;
}

bool WorkerViewer::setValue(
  std::optional<dessser::gen::sync_key::t const> const &,
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  /* Empty the previous params/parents layouts: */
  while (params->count() > 0) params->removeRow(0);
  emptyLayout(parents);

  if (v->index() == dessser::gen::sync_value::Worker) {
    dessser::gen::worker::t const *w {
      std::get<dessser::gen::sync_value::Worker>(*v) };

    enabled->setChecked(w->enabled);
    debug->setChecked(w->debug);
    used->setChecked(w->is_used);
    reportPeriod->setText(stringOfDuration(w->report_period));
    cwd->setText(QString::fromStdString(w->cwd));
    workerSign->setText(QString::fromStdString(w->worker_signature));
    binSign->setText(QString::fromStdString(w->info_signature));
    role->setText(qstringOfRole(*w));
    if (w->params.size() == 0) {
      QLabel *none = new QLabel("<i>" + tr("none") + "</i>");
      none->setAlignment(Qt::AlignCenter);
      params->addRow(none);
    } else {
      for (auto &p : w->params) {
        params->addRow(
          QString::fromStdString(std::get<0>(p)) + QString(":"),
          new QLabel(raqlValToQString(*std::get<1>(p))));
      }
    }
    if (!w->parents || w->parents->size() == 0) {
      QLabel *none = new QLabel("<i>" + tr("none") + "</i>");
      none->setAlignment(Qt::AlignCenter);
      parents->addWidget(none);
    } else {
      for (auto const &p : *w->parents) {
        QLabel *l { new QLabel(qstringOfRef(*p)) };
        l->setAlignment(Qt::AlignCenter);
        parents->addWidget(l);
      }
    }
    return true;
  } else {
    qCritical() << "Not a Worker value?!";
    return false;
  }
}
