// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef EDITCONTACTDIALOG_H_220208
#define EDITCONTACTDIALOG_H_220208
/* A modal dialog containing an AtomicForm to edit a given contact.
 * Closed on submition or cancellation. */
#include <QDialog>
#include <QString>

class AtomicForm;
class AlertingContactEditor;
class QLabel;

class EditContactDialog : public QDialog {
  Q_OBJECT

  QLabel *title;
  AtomicForm *form;
  AlertingContactEditor *editor;

 public:
  EditContactDialog(QWidget *parent = nullptr);

  void reset(QString const &team_name, QString const &contact_name);
};

#endif
