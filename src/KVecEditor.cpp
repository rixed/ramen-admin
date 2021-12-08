#include <QVBoxLayout>

#include "desssergen/raql_type.h"
#include "desssergen/raql_value.h"
#include "desssergen/sync_value.h"
#include "EditorWidget.h"
#include "MakeSyncValue.h"

#include "KVecEditor.h"

KVecEditor::KVecEditor(
  unsigned dim,
  dessser::gen::raql_type::t const &typ,
  QWidget *parent)
  : AtomicWidget(parent)
{
  QVBoxLayout *layout = new QVBoxLayout;

  for (unsigned i = 0; i < dim; i++) {
    AtomicWidget *editor = newRaqlValueEditorWidget(typ);
    layout->addWidget(editor);
    connect(editor, &AtomicWidget::inputChanged,
            this, &KVecEditor::inputChanged);
    editors.push_back(editor);
  }

  QWidget *w = new QWidget;
  w->setLayout(layout);
  relayoutWidget(w);
}

std::shared_ptr<dessser::gen::sync_value::t const> KVecEditor::getValue() const
{
  std::shared_ptr<dessser::gen::raql_value::t> res {
    std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VVec>,
      dessser::Arr<std::shared_ptr<dessser::gen::raql_value::t>>()) };
  // Each editors should return a RamenValue:
  for (AtomicWidget const *editor : editors) {
    std::shared_ptr<dessser::gen::sync_value::t const> v { editor->getValue() };
    Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
    std::get<dessser::gen::raql_value::VVec>(*res).push_back(
      std::get<dessser::gen::sync_value::RamenValue>(*v));
  }

  return makeRamenValue(res);
}

void KVecEditor::setEnabled(bool enabled)
{
  for (AtomicWidget *editor : editors) {
    editor->setEnabled(enabled);
  }
}

bool KVecEditor::setValue(
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  // Value is supposed to be a RamenValue.VVec:
  Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
  std::shared_ptr<dessser::gen::raql_value::t const> rv {
    std::get<dessser::gen::sync_value::RamenValue>(*v) };
  Q_ASSERT(rv->index() == dessser::gen::raql_value::VVec);
  dessser::Arr<std::shared_ptr<dessser::gen::raql_value::t>> vec {
    std::get<dessser::gen::raql_value::VVec>(*rv) };
  Q_ASSERT(vec.size() == editors.size());

  bool res { false };
  for (size_t i = 0; i < vec.size(); i++) {
    res = editors[i]->setValue(makeRamenValue(vec[i])) || res;
  }

  if (res) emit valueChanged(v);
  return res;
}
