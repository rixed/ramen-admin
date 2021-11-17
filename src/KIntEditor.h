#ifndef KINTEDITOR_H_190727
#define KINTEDITOR_H_190727
#include <functional>
#include <optional>
#include <QLineEdit>

#include "AtomicWidget.h"
#include "misc.h"

namespace dessser {
  namespace gen {
    namespace sync_value { struct t; }
  }
}

/* The MOC processor does not handle templates and does not even expand
 * CPP macros at all (Qt<5) or properly (Qt>=5). So we will have to do
 * with only one int editor for all types of integers.
 */

class KIntEditor : public AtomicWidget
{
  Q_OBJECT

  std::function<std::shared_ptr<dessser::gen::sync_value::t>(QString const &)> ofQString;
  QLineEdit *lineEdit;

public:
  KIntEditor(
    std::function<std::shared_ptr<dessser::gen::sync_value::t>(QString const &)>,
    QWidget *parent = nullptr,
    /* For the edition of uint128_t we just do not set any range.
     * BTW, QIntValidator handle only plain boring ints... */
    std::optional<int128_t> min = std::nullopt,
    std::optional<int128_t> max = std::nullopt);

  void setPlaceholderText(QString const s) {
    lineEdit->setPlaceholderText(s);
  }

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

public slots:
  bool setValue(
    std::shared_ptr<dessser::gen::sync_key::t const>,
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
