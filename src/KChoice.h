// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef KCHOICE_H_190516
#define KCHOICE_H_190516
#include <memory>
#include <utility>
#include <vector>

#include "AtomicWidget.h"

class QRadioButton;
class QWidget;

class KChoice : public AtomicWidget {
  Q_OBJECT

  std::vector<std::pair<QRadioButton *,
                        std::shared_ptr<dessser::gen::sync_value::t const> > >
      choices;

 public:
  KChoice(
      std::vector<std::pair<
          QString const, std::shared_ptr<dessser::gen::sync_value::t const> > >
          labels,
      QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

 public slots:
  bool setValue(std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
