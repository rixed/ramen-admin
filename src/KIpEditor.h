#ifndef KIPEDITOR_H_211125
#define KIPEDITOR_H_211125
/* An editor for IP addresses (either v4 or v6, unless specified otherwise).
 * TODO: something fancier than an input text :) */
#include "AtomicWidget.h"

class QLineEdit;

class KIpEditor : public AtomicWidget
{
  Q_OBJECT

  QLineEdit *lineEdit;
  bool allowV4, allowV6;

public:
  KIpEditor(bool allow_v4 = true, bool allow_v6 = true, QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

public slots:
  bool setValue(
    std::shared_ptr<dessser::gen::sync_key::t const>,
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
