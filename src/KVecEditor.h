// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef KVECEDITOR_H_211125
#define KVECEDITOR_H_211125
/* An editor for a raql_value that's a vector of other raql values. */
#include <vector>

#include "AtomicWidget.h"

namespace dessser {
namespace gen {
namespace raql_type {
struct t;
}
}  // namespace gen
}  // namespace dessser

class KVecEditor : public AtomicWidget {
  Q_OBJECT

  std::vector<AtomicWidget *> editors;

 public:
  KVecEditor(unsigned dim, dessser::gen::raql_type::t const &,
             QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

 public slots:
  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
