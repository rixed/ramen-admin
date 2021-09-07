#ifndef SERVERINFOWIDGET_H_190923
#define SERVERINFOWIDGET_H_190923
#include <memory>
#include <QWidget>

#include "KVStore.h"  // for ConfChange

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
  }
}

class ServerInfoWidget : public QWidget
{
  Q_OBJECT

  QFormLayout *layout;

  void setKey(dessser::gen::sync_key::t const &, KValue const &);
  void setLabel(QString const &, std::shared_ptr<dessser::gen::sync_value::t const>);

public:
  ServerInfoWidget(QString const &srvUrl, QWidget *parent = nullptr);

protected slots:
  void onChange(QList<ConfChange> const &);
};

#endif
