#ifndef KARREDITOR_H_211125
#define KARREDITOR_H_211125
/* An editor for a raql_value that's a tuple of other raql values. */
#include <memory>
#include <vector>
#include "dessser/Arr.h"
#include "AtomicWidget.h"

class QVBoxLayout;
class QPushButton;

namespace dessser {
  namespace gen {
    namespace raql_type { struct t; }
  }
}

class KArrEditor : public AtomicWidget
{
  Q_OBJECT

  std::shared_ptr<dessser::gen::raql_type::t const> type;
  // Layout where to find all the editors:
  QVBoxLayout *layout;
  QPushButton *addButton;

  AtomicWidget *editorAt(int) const;
  AtomicWidget *insertNewEditor(int);

  // Tells if there is an editor at that index:
  bool hasEditor(int) const;

public:
  KArrEditor(
    std::shared_ptr<dessser::gen::raql_type::t const>,
    QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

public slots:
  bool setValue(
    std::shared_ptr<dessser::gen::sync_key::t const>,
    std::shared_ptr<dessser::gen::sync_value::t const>);

private slots:
  void addItem();
  void delItem(int);
};

#endif