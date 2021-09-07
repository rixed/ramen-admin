#ifndef KLABEL_H_190505
#define KLABEL_H_190505
/* A small widget displaying an error message that occurred during login, and
 * displayed in the LoginWin */
#include <memory>
#include <string>
#include <QLabel>

#include "KVStore.h"  // for ConfChange

struct KValue;

namespace dessser {
  namespace gen {
    namespace sync_key {
      struct t;
    }
  }
}

class KErrorMsg : public QLabel
{
  Q_OBJECT

  std::shared_ptr<dessser::gen::sync_key::t const> key;

  void displayError(QString const &);

  void setValueFromStore(dessser::gen::sync_key::t const &, KValue const &);
  void warnTimeout(dessser::gen::sync_key::t const &, KValue const &);

public:
  KErrorMsg(QWidget *parent = nullptr);

private slots:
  void onChange(QList<ConfChange> const &);

public slots:
  // Called when the key to monitor (the error key for this client) is known
  void setKey(std::shared_ptr<dessser::gen::sync_key::t const>);
};

#endif
