// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef EDITINHIBITIONDIALOG_H_220208
#define EDITINHIBITIONDIALOG_H_220208
/* A modal dialog containing an AtomicForm to edit a given contact.
 * Closed on submition or cancellation. */
#include <QDialog>
#include <QString>
#include <string>

class AtomicForm;
class AlertingInhibitionEditor;
class QLabel;

class EditInhibitionDialog : public QDialog {
  Q_OBJECT

  QLabel *title;
  AtomicForm *form;
  AlertingInhibitionEditor *editor;

 public:
  EditInhibitionDialog(QWidget *parent = nullptr);

  void reset(QString const &team_name, QString const &contact_name);
};

#endif
