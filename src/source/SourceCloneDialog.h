#ifndef SOURCECLONEDIALOG_190902
#define SOURCECLONEDIALOG_190902
#include <QDialog>
#include <memory>
#include <string>

class QLineEdit;
class QString;

namespace dessser {
namespace gen {
namespace sync_key {
struct t;
}
namespace sync_value {
struct t;
}
}  // namespace gen
}  // namespace dessser

class SourceCloneDialog : public QDialog {
  Q_OBJECT

  std::string srcPath;
  std::string extension;

  // The value at the time the dialog was opened:
  std::shared_ptr<dessser::gen::sync_value::t const> value;

  QLineEdit *newKeyEdit;

  QPushButton *cloneButton;

 public:
  SourceCloneDialog(std::shared_ptr<dessser::gen::sync_key::t const>,
                    QWidget *parent = nullptr);

 protected slots:
  void cloneSource();
  void validate();
};

#endif
