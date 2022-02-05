// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef LISTEDITOR_H_220204
#define LISTEDITOR_H_220204
/* A widget that can edit list of any QWidget.
 * Offer to add/remove entries and ideally reorder them.
 * Parameterized over the type of QWidgets that constitute the list items. */
#include <QWidget>
#include <functional>
#include <vector>

class QVBoxLayout;
class QPushButton;

class ListEditor : public QWidget {
  Q_OBJECT

  std::vector<QWidget *> items;

  std::function<QWidget *()> newEntry;

  // Layout where to find all the editors:
  QVBoxLayout *vboxLayout;
  QPushButton *addButton;

  QWidget *itemAt(int) const;

  // Tells if there is a widget at that index:
  bool hasItem(int) const;

  QWidget *insertWidget(int);

 public:
  /* [new_entry()] returns the QWidget to be added.
   * Its onChange signal must be connected to ListEditor's inputChanged slot.
   */
  ListEditor(std::function<QWidget *()> new_entry, QWidget *parent = nullptr);

  // Not to be confused with QWidget's slot:
  void setEnabled(bool);

 private slots:
  void addItem();
  void delItem(int);

 signals:
  void inputChanged();
};

#endif
