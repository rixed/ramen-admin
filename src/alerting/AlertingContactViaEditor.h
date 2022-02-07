// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ALERTINGCONTACTVIAEDITOR_H_220204
#define ALERTINGCONTACTVIAEDITOR_H_220204
#include <QWidget>
#include <memory>

namespace dessser {
namespace gen {
namespace alerting_contact {
struct via;
}
}  // namespace gen
}  // namespace dessser

class AlertingContactViaEditor : public QWidget {
  Q_OBJECT

 public:
  AlertingContactViaEditor(QWidget *parent = nullptr);

  virtual std::shared_ptr<dessser::gen::alerting_contact::via> getValue()
      const = 0;

  virtual bool setValue(
      std::shared_ptr<dessser::gen::alerting_contact::via const>) = 0;

  virtual void clear() = 0;
};

#endif
