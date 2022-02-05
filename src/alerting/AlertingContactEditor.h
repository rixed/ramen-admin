// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGCONTACTEDITOR_H_220204
#define ALERTINGCONTACTEDITOR_H_220204
/* A combobox to choose the type of contact, and then a widget where to
 * configure the details of the selected type, and then the timeout. */
#include <vector>

#include "AtomicWidget.h"

class QComboBox;
class QLineEdit;
class AlertingContactViaEditor;

class AlertingContactEditor : public AtomicWidget {
  Q_OBJECT

  QComboBox *typeEdit;
  QStackedLayout *stackedLayout;
  QLineEdit *timeoutEditor;

  std::vector<AlertingContactViaEditor *> editors;

 public:
  AlertingContactEditor(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;

  void setEnabled(bool);

 public slots:
  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
