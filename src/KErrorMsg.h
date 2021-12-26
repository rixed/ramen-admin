// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef KLABEL_H_190505
#define KLABEL_H_190505
/* A small widget displaying an error message that occurred during login, and
 * displayed in the LoginWin */
#include <QLabel>
#include <memory>
#include <string>

#include "ConfChange.h"

struct KValue;

namespace dessser {
namespace gen {
namespace sync_key {
struct t;
}
}  // namespace gen
}  // namespace dessser

class KErrorMsg : public QLabel {
  Q_OBJECT

  std::shared_ptr<dessser::gen::sync_key::t const> key;

  void displayError(QString const &);

  void setError(dessser::gen::sync_key::t const &, KValue const &);

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
