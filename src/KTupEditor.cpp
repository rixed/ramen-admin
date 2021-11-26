#include <QVBoxLayout>

#include "desssergen/raql_type.h"
#include "desssergen/raql_value.h"
#include "desssergen/sync_value.h"
#include "EditorWidget.h"
#include "MakeSyncValue.h"

#include "KTupEditor.h"

KTupEditor::KTupEditor(
  dessser::Arr<std::shared_ptr<dessser::gen::raql_type::t>> const &tup,
  QWidget *parent)
  : AtomicWidget(parent)
{
  QVBoxLayout *layout = new QVBoxLayout;

  for (std::shared_ptr<dessser::gen::raql_type::t const> t : tup) {
    AtomicWidget *editor = newRaqlValueEditorWidget(*t);
    layout->addWidget(editor);
    connect(editor, &AtomicWidget::inputChanged,
            this, &KTupEditor::inputChanged);
    editors.push_back(editor);
  }

  QWidget *w = new QWidget;
  w->setLayout(layout);
  relayoutWidget(w);
}

std::shared_ptr<dessser::gen::sync_value::t const> KTupEditor::getValue() const
{
  std::shared_ptr<dessser::gen::raql_value::t> res {
    std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VTup>,
      dessser::Arr<std::shared_ptr<dessser::gen::raql_value::t>>()) };
  // Each editors should return a RamenValue:
  for (AtomicWidget const *editor : editors) {
    std::shared_ptr<dessser::gen::sync_value::t const> v { editor->getValue() };
    Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
    std::get<dessser::gen::raql_value::VTup>(*res).push_back(
      std::get<dessser::gen::sync_value::RamenValue>(*v));
  }

  return makeRamenValue(res);
}

void KTupEditor::setEnabled(bool enabled)
{
  for (AtomicWidget *editor : editors) {
    editor->setEnabled(enabled);
  }
}

bool KTupEditor::setValue(
  std::shared_ptr<dessser::gen::sync_key::t const> k,
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  // Value is supposed to be a RamenValue.VTup:
  Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
  std::shared_ptr<dessser::gen::raql_value::t const> rv {
    std::get<dessser::gen::sync_value::RamenValue>(*v) };
  Q_ASSERT(rv->index() == dessser::gen::raql_value::VTup);
  dessser::Arr<std::shared_ptr<dessser::gen::raql_value::t>> tup {
    std::get<dessser::gen::raql_value::VTup>(*rv) };
  Q_ASSERT(tup.size() == editors.size());

  bool res { false };
  for (size_t i = 0; i < tup.size(); i++) {
    res = res || editors[i]->setValue(nullptr, makeRamenValue(tup[i]));
  }

  if (res) emit valueChanged(k, v);
  return res;
}
