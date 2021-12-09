#ifndef SOURCEINFOVIEWER_H_190801
#define SOURCEINFOVIEWER_H_190801
#include <vector>

#include "AtomicWidget.h"

class QVBoxLayout;

class SourceInfoViewer : public AtomicWidget
{
  Q_OBJECT

  QVBoxLayout *layout;

public:
  SourceInfoViewer(QWidget *parent = nullptr);
  void setEnabled(bool) {}

public slots:
  bool setValue(
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
