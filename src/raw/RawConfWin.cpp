// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "raw/RawConfWin.h"

#include "ConfTreeWidget.h"

RawConfWin::RawConfWin(QWidget *parent)
    : SavedWindow("ConfigTreeWindow", tr("Raw Configuration"), true, parent) {
  confTreeWidget = new ConfTreeWidget(this);
  setCentralWidget(confTreeWidget);
}
