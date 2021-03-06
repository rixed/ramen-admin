// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef KTUPEDITOR_H_211125
#define KTUPEDITOR_H_211125
/* An editor for a raql_value that's a tuple of other raql values. */
#include <vector>

#include "AtomicWidget.h"
#include "dessser/Arr.h"

namespace dessser {
namespace gen {
namespace raql_type {
struct t;
}
}  // namespace gen
}  // namespace dessser

class KTupEditor : public AtomicWidget {
  Q_OBJECT

  std::vector<AtomicWidget *> editors;

 public:
  KTupEditor(dessser::Arr<std::shared_ptr<dessser::gen::raql_type::t> > const &,
             QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

 public slots:
  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
