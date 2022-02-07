// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGCONTACTSQLITEEDITOR_H_220204
#define ALERTINGCONTACTSQLITEEDITOR_H_220204
#include <QWidget>

class QLineEdit;
class QPlainTextEdit;

#include "alerting/AlertingContactViaEditor.h"

class AlertingContactSqliteEditor : public AlertingContactViaEditor {
  Q_OBJECT

  QLineEdit *fileEdit;
  QPlainTextEdit *createEdit;
  QPlainTextEdit *insertEdit;

 public:
  AlertingContactSqliteEditor(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::alerting_contact::via> getValue()
      const override;

  bool setValue(std::shared_ptr<dessser::gen::alerting_contact::via const>);

  void clear();
};

#endif
