// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGINHIBITIONEDITOR_H_220204
#define ALERTINGINHIBITIONEDITOR_H_220204
#include <string>
#include <vector>

#include "AtomicWidget.h"

class AlertingInhibitionViaEditor;
class QDateTimeEdit;
class QLabel;
class QLineEdit;
class QPlainTextEdit;

class AlertingInhibitionEditor : public AtomicWidget {
  Q_OBJECT

  QLineEdit *whatEditor;
  QDateTimeEdit *startEditor;
  QDateTimeEdit *stopEditor;
  QPlainTextEdit *whyEditor;
  QLabel *whoLabel;
  std::string who;  // Save the initial creator

 public:
  AlertingInhibitionEditor(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;

  void setEnabled(bool);

  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);

  void clear();
};

#endif
