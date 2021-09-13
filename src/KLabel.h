#ifndef KLABEL_H_190505
#define KLABEL_H_190505
#include "AtomicWidget.h"

class QLabel;

class KLabel : public AtomicWidget
{
  Q_OBJECT

  QLabel *label;

public:
  KLabel(QWidget *parent = nullptr, bool wordWrap = false);

  void setEnabled(bool) {}

public slots:
  bool setValue(
    dessser::gen::sync_key::t const &,
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
