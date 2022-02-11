// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGCONTACTKAFKAEDITOR_H_220204
#define ALERTINGCONTACTKAFKAEDITOR_H_220204
#include <QWidget>

#include "alerting/AlertingContactViaEditor.h"

class QLineEdit;
class QPlainTextEdit;
class KafkaOptionEdit;
class ListEditor;

class AlertingContactKafkaEditor : public AlertingContactViaEditor {
  Q_OBJECT

  ListEditor *optionsEdit;
  QLineEdit *topicEdit;
  QLineEdit *partitionEdit;
  QPlainTextEdit *textEdit;

 public:
  AlertingContactKafkaEditor(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::alerting_contact::via> getValue()
      const override;

  bool setValue(dessser::gen::alerting_contact::via const &);

  void clear();
};

#endif
