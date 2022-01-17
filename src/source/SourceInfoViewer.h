// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef SOURCEINFOVIEWER_H_190801
#define SOURCEINFOVIEWER_H_190801
#include <vector>

#include "AtomicWidget.h"

class QVBoxLayout;
class QStackedLayout;

class SourceInfoViewer : public AtomicWidget {
  Q_OBJECT

  /* Either the editor in RO or an error message in RW mode */
  QStackedLayout *stackedLayout;
  int readOnlyIndex, readWriteIndex;

  /* Storing all the widgets required to display a value */
  QVBoxLayout *readOnlyLayout;

 public:
  SourceInfoViewer(QWidget *parent = nullptr);

  void setEnabled(bool);

 public slots:
  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
