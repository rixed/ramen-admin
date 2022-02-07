// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef NEWINHIBITIONDIALOG_H_220207
#define NEWINHIBITIONDIALOG_H_220207
#include <QDialog>

class AlertingInhibitionEditor;
class QLabel;
class QLineEdit;

namespace dessser {
namespace gen {
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class NewInhibitionDialog : public QDialog {
  Q_OBJECT

  QLabel *title;
  QString teamName;
  QLineEdit *nameEdit;

  AlertingInhibitionEditor *editor;

 public:
  NewInhibitionDialog(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  QString getTeamName() const;
  QString getInhibitionName() const;

 public slots:
  void reset(QString const &team_name);
};

#endif
