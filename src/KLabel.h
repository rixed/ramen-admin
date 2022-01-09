// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef KLABEL_H_190505
#define KLABEL_H_190505
/* A Read-only "editor" */
#include "AtomicWidget.h"

class QLabel;

class KLabel : public AtomicWidget {
  Q_OBJECT

  QLabel *label;

 public:
  KLabel(QWidget *parent = nullptr, bool wordWrap = false);

  void setEnabled(bool) {}

 public slots:
  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
