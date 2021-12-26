// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef NEWDASHBOARDDIALOG_H_200304
#define NEWDASHBOARDDIALOG_H_200304
#include <QDialog>

class QLineEdit;

class NewDashboardDialog : public QDialog {
  Q_OBJECT

  QLineEdit *nameEdit;

 public:
  NewDashboardDialog(QWidget *parent = nullptr);

 public slots:
  void clear();

 protected slots:
  void createDashboard();
};

#endif
