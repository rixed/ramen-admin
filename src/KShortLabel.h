#ifndef KSHORTLABEL_H_190729
#define KSHORTLABEL_H_190729
/* Like a KLabel, but the content will never grow beyond the container size.
 * Based on Qt example at
 * https://doc.qt.io/qt-5/qtwidgets-widgets-elidedlabel-example.html */
#include <QString>
#include "AtomicWidget.h"

namespace dessser {
  namespace gen {
    namespace sync_value { struct t; }
  }
}

class KShortLabel : public AtomicWidget
{
  Q_OBJECT

  QString text;

  int leftMargin, topMargin, rightMargin, bottomMargin;

public:
  KShortLabel(QWidget *parent = nullptr);

  void setContentsMargins(int, int, int, int);

  void setEnabled(bool) {} // not editable

protected:
  void paintEvent(QPaintEvent *event);

public slots:
  bool setValue(
    std::optional<dessser::gen::sync_key::t const> const &,
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
