// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef PIVOTEDITOR_H_191129
#define PIVOTEDITOR_H_191129
#include "AtomicWidget.h"

class PivotEditor : public AtomicWidget {
  Q_OBJECT

 public:
  PivotEditor(QWidget *parent = nullptr);

  void setEnabled(bool) {}

  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>) {
    return false;
  }
};

#endif
