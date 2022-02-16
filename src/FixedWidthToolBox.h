// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef FIXEDWIDTHTOOLBOX_H_220216
#define FIXEDWIDTHTOOLBOX_H_220216
/* A QToolBox that growth in width according to its content.
 * you'd think QToolBox would do that, but no. */
#include <QToolBox>

class FixedWidthToolBox : public QToolBox {
  Q_OBJECT

 public:
  FixedWidthToolBox(QWidget *);

  QSize minimumSizeHint() const override;
};

#endif
