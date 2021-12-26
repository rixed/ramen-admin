// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include <QTabWidget>

bool tryFocusTab(QTabWidget *w, QString const &label) {
  for (int i = 0; i < w->count(); i++) {
    if (w->tabText(i) == label) {
      w->setCurrentIndex(i);
      return true;
    }
  }
  return false;
}

void focusLastTab(QTabWidget *w) { w->setCurrentIndex(w->count() - 1); }
