#ifndef KRECEDITOR_H_211125
#define KRECEDITOR_H_211125
/* An editor for a raql_value that's a tuple of other raql values. */
#include <string>
#include <utility>
#include <vector>

#include "dessser/Arr.h"
#include "AtomicWidget.h"

namespace dessser {
  namespace gen {
    namespace raql_type { struct named_type; }
  }
}

class KRecEditor : public AtomicWidget
{
  Q_OBJECT

  std::vector<std::pair<std::string, AtomicWidget *>> editors;

public:
  KRecEditor(
    dessser::Arr<std::shared_ptr<dessser::gen::raql_type::named_type>> const &,
    QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

public slots:
  bool setValue(
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
