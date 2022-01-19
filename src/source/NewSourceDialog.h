// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef NEWSOURCEDIALOG_H_190731
#define NEWSOURCEDIALOG_H_190731
#include <QDialog>

class SourceEdit;
class QComboBox;
class QDialogButtonBox;
class QLineEdit;

class NewSourceDialog : public QDialog {
  Q_OBJECT

  QDialogButtonBox *buttonBox;
  QLineEdit *nameEdit;
  SourceEdit *sourceEdit;

 public:
  NewSourceDialog(QWidget *parent = nullptr);

 public slots:
  void clear();

 protected slots:
  void checkValidity();
  void createSource();
};

#endif
