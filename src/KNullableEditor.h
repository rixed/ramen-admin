#ifndef KNULLABLEEDITOR_H_190727
#define KNULLABLEEDITOR_H_190727

#include "AtomicWidget.h"
#include "misc.h"

class QRadioButton;

namespace dessser {
namespace gen {
namespace sync_value {
struct t;
}
namespace sync_key {
struct t;
}
}  // namespace gen
}  // namespace dessser

/* The MOC processor does not handle templates and does not even expand
 * CPP macros at all (Qt<5) or properly (Qt>=5). So we will have to do
 * with only one int editor for all types of integers.
 */

class KNullableEditor : public AtomicWidget {
  Q_OBJECT

  AtomicWidget *editor;
  QRadioButton *nullButton, *notNullButton;

 public:
  KNullableEditor(AtomicWidget *editor_, QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

 public slots:
  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);

 private slots:
  void setNull();
  void setNotNull();
};

#endif
