// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef FIXEDTABLEVIEW_H_200408
#define FIXEDTABLEVIEW_H_200408
/* A QTableView with a sizeHint that ask for the actual content size */
#include <QSize>
#include <QTableView>

class FixedTableView : public QTableView {
  Q_OBJECT

 public:
  FixedTableView(QWidget *parent = nullptr);

  QSize sizeHint() const override;
  QSize minimumSizeHint() const override;
};

#endif
