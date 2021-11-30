#ifndef KCIDREDITOR_H_211125
#define KCIDREDITOR_H_211125
/* An editor for CIDR addresses (either v4 or v6, unless specified otherwise). */
#include "AtomicWidget.h"

class KIntEditor;
class KIpEditor;

class KCidrEditor : public AtomicWidget
{
  Q_OBJECT

  KIpEditor *ipEditor;
  KIntEditor *maskEditor;
  bool allowV4, allowV6;

public:
  KCidrEditor(QWidget *parent = nullptr, bool allow_v4 = true, bool allow_v6 = true);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

public slots:
  bool setValue(
    std::shared_ptr<dessser::gen::sync_key::t const>,
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
