// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "ListEditor.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

#include "Resources.h"
#include "misc.h"

ListEditor::ListEditor(std::function<QWidget *()> new_entry, QWidget *parent)
    : QWidget(parent), newEntry(new_entry) {
  vboxLayout = new QVBoxLayout;

  QHBoxLayout *bottom_row{new QHBoxLayout};
  Resources *r{Resources::get()};
  addButton = new QPushButton(r->addPixmap, tr("&add"));
  bottom_row->addWidget(addButton);
  vboxLayout->addLayout(bottom_row);

  connect(addButton, &QPushButton::clicked, this, &ListEditor::addItem);

  setLayout(vboxLayout);
}

void ListEditor::setEnabled(bool enabled) {
  addButton->setEnabled(enabled);

  for (int i = 0; true; i++) {
    QWidget *w{itemAt(i)};
    if (!w) break;
    w->setEnabled(enabled);
    // Also enable/disable the del/move buttons
    QLayoutItem *item{vboxLayout->itemAt(i)};
    /* The item is made of a HBoxLayout with the widget as first item and
     * buttons next (see insertWidget): */
    for (int j = 0; true; j++) {
      QLayoutItem *item_{item->layout()->itemAt(j)};
      if (!item_) break;
      QWidget *w_{item_->widget()};
      if (!w_) break;
      w_->setEnabled(enabled);
    }
  }
}

bool ListEditor::hasItem(int i) const {
  /* There are N+1 items in [vboxLayout], the last one being the Add button: */
  return i < vboxLayout->count() - 1;
}

QWidget *ListEditor::itemAt(int i) const {
  if (!hasItem(i)) return nullptr;
  QLayoutItem *item{vboxLayout->itemAt(i)};
  if (!item) return nullptr;
  /* The item is made of a HBoxLayout with the editor as first item
   * (see insertWidget): */
  return item->layout()->itemAt(0)->widget();
}

QWidget *ListEditor::insertWidget(int i) {
  QHBoxLayout *l{new QHBoxLayout};

  QWidget *w{newEntry()};
  l->addWidget(w);

  Resources *r{Resources::get()};
  QPushButton *delButton{new QPushButton(r->deletePixmap, tr("delete"))};
  l->addWidget(delButton);
  connect(delButton, &QPushButton::clicked, [this, i]() { this->delItem(i); });
  // TODO: buttons to move up/down

  vboxLayout->insertLayout(i, l);

  return w;
}

void ListEditor::addItem() {
  /* The layout has N items for the editors, then one more for the add button:
   */
  int const c{vboxLayout->count()};
  Q_ASSERT(c >= 1);
  QWidget *w{insertWidget(c - 1)};
  w->setEnabled(isEnabled());
}

void ListEditor::delItem(int i) {
  if (!hasItem(i)) {
    qWarning() << "No widget at index" << i << ", ignoring";
    return;  // race condition?
  }

  QLayoutItem *item{vboxLayout->itemAt(i)};
  if (!item) return;
  emptyAndDelLayoutItem(vboxLayout, i);
}
