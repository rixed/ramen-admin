// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef NEWTEAMDIALOG_H_220207
#define NEWTEAMDIALOG_H_220207
#include <QDialog>

class QLineEdit;

class NewTeamDialog : public QDialog {
  Q_OBJECT

  QLineEdit *nameEdit;

 public:
  NewTeamDialog(QWidget *parent = nullptr);

  QString const getValue() const;

 public slots:
  void clear();
};

#endif
