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
  QVBoxLayout *layout = new QVBoxLayout;
  QWidget *w = new QWidget;
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
    Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
    std::get<dessser::gen::raql_value::VArr>(*res).push_back(
      std::get<dessser::gen::sync_value::RamenValue>(*v));
  }

  return makeRamenValue(res);
}

void KArrEditor::setEnabled(bool enabled)
{
  for (int i = 0; true; i++) {
    AtomicWidget *editor { editorAt(i) };
    if (! editor) break;
    editor->setEnabled(enabled);
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

AtomicWidget *KArrEditor::editorAt(int i) const
{
  QLayoutItem *item { layout->itemAt(i) };
  if (! item) return nullptr;
  /* The item is made of a HBoxLayoutm with the editor as first item
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
  QPushButton *deleteButton { new QPushButton(r->deletePixmap, tr("&delete")) };
  l->addWidget(deleteButton);
  // TODO: connect this button
  // TODO: buttons to move up/down

  layout->insertLayout(i, l);

  return editor;
}
