#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "desssergen/raql_type.h"
#include "desssergen/raql_value.h"
#include "desssergen/sync_value.h"
#include "EditorWidget.h"
#include "MakeSyncValue.h"
#include "Resources.h"

#include "KArrEditor.h"

KArrEditor::KArrEditor(
  std::shared_ptr<dessser::gen::raql_type::t const> type_,
  QWidget *parent)
  : AtomicWidget(parent),
    type(type_)
{
  layout = new QVBoxLayout;

  QHBoxLayout *l { new QHBoxLayout };
  /* TODO: add a label "empty list" that's made hidden/visible on setValue depending
   * on the emptyness of the list */
  l->addStretch(1);
  Resources *r = Resources::get();
  addButton = new QPushButton(r->addPixmap, tr("&add"));
  l->addWidget(addButton);
  layout->addLayout(l);

  connect(addButton, &QPushButton::clicked,
          this, &KArrEditor::addItem);

  QWidget *w { new QWidget };
  w->setLayout(layout);
  relayoutWidget(w);
}

std::shared_ptr<dessser::gen::sync_value::t const> KArrEditor::getValue() const
{
  std::shared_ptr<dessser::gen::raql_value::t> res {
    std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VArr>,
      dessser::Arr<std::shared_ptr<dessser::gen::raql_value::t>>()) };
  // Each editors should return a RamenValue:
  for (int i = 0; true; i++) {
    AtomicWidget *editor { editorAt(i) };
    if (! editor) break;
    std::shared_ptr<dessser::gen::sync_value::t const> v { editor->getValue() };
    if (! v) return nullptr;
    Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
    std::get<dessser::gen::raql_value::VArr>(*res).push_back(
      std::get<dessser::gen::sync_value::RamenValue>(*v));
  }

  return makeRamenValue(res);
}

void KArrEditor::setEnabled(bool enabled)
{
  addButton->setEnabled(enabled);

  for (int i = 0; true; i++) {
    AtomicWidget *editor { editorAt(i) };
    if (! editor) break;
    editor->setEnabled(enabled);
    // Also enable/disable the del/move buttons
    QLayoutItem *item { layout->itemAt(i) };
    /* The item is made of a HBoxLayout with the editor as first item and
     * buttons next (see insertNewEditor): */
    for (int j = 1; true; j++) {
      QLayoutItem *item_ { item->layout()->itemAt(j) };
      if (! item_) break;
      QWidget *w { item_->widget() };
      if (! w) break;
      w->setEnabled(enabled);
    }
  }
}

bool KArrEditor::setValue(
  std::shared_ptr<dessser::gen::sync_key::t const> k,
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  // Value is supposed to be a RamenValue.VArr:
  Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
  std::shared_ptr<dessser::gen::raql_value::t const> rv {
    std::get<dessser::gen::sync_value::RamenValue>(*v) };
  Q_ASSERT(rv->index() == dessser::gen::raql_value::VArr);
  dessser::Arr<std::shared_ptr<dessser::gen::raql_value::t>> lst {
    std::get<dessser::gen::raql_value::VArr>(*rv) };

  bool res { false };
  for (size_t i = 0; i < lst.size(); i++) {
    AtomicWidget *editor { editorAt(i) };
    if (! editor) editor = insertNewEditor(i);
    res = editor->setValue(nullptr, makeRamenValue(lst[i])) || res;
  }

  if (res) emit valueChanged(k, v);
  return res;
}

bool KArrEditor::hasEditor(int i) const
{
  /* There are N+1 items in [layout], the last one being the Add button: */
  return i < layout->count() - 1;
}

AtomicWidget *KArrEditor::editorAt(int i) const
{
  if (! hasEditor(i)) return nullptr;
  QLayoutItem *item { layout->itemAt(i) };
  if (! item) return nullptr;
  /* The item is made of a HBoxLayout with the editor as first item
   * (see insertNewEditor): */
  return dynamic_cast<AtomicWidget *>(item->layout()->itemAt(0)->widget());
}

AtomicWidget *KArrEditor::insertNewEditor(int i)
{
  QHBoxLayout *l { new QHBoxLayout };

  AtomicWidget *editor { newRaqlValueEditorWidget(*type) };
  connect(editor, &AtomicWidget::inputChanged,
          this, &KArrEditor::inputChanged);
  l->addWidget(editor);

  Resources *r = Resources::get();
  QPushButton *deleteButton { new QPushButton(r->deletePixmap, tr("delete")) };
  l->addWidget(deleteButton);
  connect(deleteButton, &QPushButton::clicked,
          [this, i] () { this->delItem(i); });
  // TODO: buttons to move up/down

  layout->insertLayout(i, l);

  return editor;
}

void KArrEditor::addItem()
{
  /* The layout has N items for the editors, then one more for the add button: */
  int const c { layout->count() };
  Q_ASSERT(c >= 1);
  AtomicWidget *editor { insertNewEditor(c - 1) };
  editor->setEnabled(isEnabled());
}

void KArrEditor::delItem(int i)
{
  if (! hasEditor(i)) {
    qWarning() << "No editor at index" << i << ", ignoring";
    return; // race condition?
  }

  QLayoutItem *item { layout->itemAt(i) };
  if (! item) return;
  emptyAndDelLayoutItem(layout, i);
}
