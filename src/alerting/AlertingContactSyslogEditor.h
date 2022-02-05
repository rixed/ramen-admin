// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGCONTACTSYSLOGEDITOR_H_220204
#define ALERTINGCONTACTSYSLOGEDITOR_H_220204
#include <QWidget>

#include "alerting/AlertingContactViaEditor.h"

class QLineEdit;

class AlertingContactSyslogEditor : public AlertingContactViaEditor {
  Q_OBJECT

  QLineEdit *edit;

 public:
  AlertingContactSyslogEditor(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::alerting_contact::via> getValue()
      const override;

  bool setValue(std::shared_ptr<dessser::gen::alerting_contact::via const>);
};

#endif
