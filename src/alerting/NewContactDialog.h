// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef NEWCONTACTDIALOG_H_220207
#define NEWCONTACTDIALOG_H_220207
#include <QDialog>

class AlertingContactEditor;
class QLabel;
class QLineEdit;

namespace dessser {
namespace gen {
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class NewContactDialog : public QDialog {
  Q_OBJECT

  QString teamName;
  QLineEdit *nameEdit;
  QLabel *title;
  AlertingContactEditor *editor;

 public:
  NewContactDialog(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  QString getTeamName() const;
  QString getContactName() const;

 public slots:
  void reset(QString const &team_name);
};

#endif
