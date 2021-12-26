// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "ConfTreeDialog.h"

#include "ConfTreeWidget.h"

ConfTreeDialog::ConfTreeDialog(QWidget *parent)
    : SavedWindow("ConfigTreeWindow", tr("Raw Configuration"), true, parent) {
  confTreeWidget = new ConfTreeWidget(this);
  setCentralWidget(confTreeWidget);
}
