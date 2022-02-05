// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGCONTACTIGNOREEDITOR_H_220204
#define ALERTINGCONTACTIGNOREEDITOR_H_220204
#include <QWidget>

#include "alerting/AlertingContactViaEditor.h"

class AlertingContactIgnoreEditor : public AlertingContactViaEditor {
  Q_OBJECT

 public:
  AlertingContactIgnoreEditor(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::alerting_contact::via> getValue()
      const override;

  bool setValue(std::shared_ptr<dessser::gen::alerting_contact::via const>);
};

#endif
