// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef WINDGETTOOLS_H_190604
#define WINDGETTOOLS_H_190604
#include <QString>

class QTabWidget;

bool tryFocusTab(QTabWidget *, QString const &);
void focusLastTab(QTabWidget *);

#endif
