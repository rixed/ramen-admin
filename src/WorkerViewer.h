#ifndef WORKERVIEWER_H_190801
#define WORKERVIEWER_H_190801
#include <vector>
#include "AtomicWidget.h"

class QCheckBox;
class QFormLayout;
class QLabel;
class QVBoxLayout;

class WorkerViewer : public AtomicWidget
{
  Q_OBJECT

  QCheckBox *enabled, *debug, *used;
  QLabel *reportPeriod, *cwd, *workerSign, *binSign;
  QLabel *role;
  QFormLayout *params;
  QVBoxLayout *parents;
  std::vector<QLabel *> parentLabels;

public:
  WorkerViewer(QWidget *parent = nullptr);
  void setEnabled(bool);

public slots:
  bool setValue(
    dessser::gen::sync_key::t const &,
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
