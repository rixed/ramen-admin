// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef SERVERINFOWIDGET_H_190923
#define SERVERINFOWIDGET_H_190923
#include <QWidget>
#include <memory>

#include "ConfChange.h"

class QFormLayout;
struct KValue;

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

class ServerInfoWidget : public QWidget {
  Q_OBJECT

  QFormLayout *layout;

  void setKey(dessser::gen::sync_key::t const &, KValue const &);
  void setLabel(QString const &,
                std::shared_ptr<dessser::gen::sync_value::t const>);

 public:
  ServerInfoWidget(QString const &srvUrl, QWidget *parent = nullptr);

 protected slots:
  void onChange(QList<ConfChange> const &);
};

#endif
