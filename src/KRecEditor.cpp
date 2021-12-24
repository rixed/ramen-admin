#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

#include "desssergen/raql_type.h"
#include "desssergen/raql_value.h"
#include "desssergen/sync_value.h"
#include "EditorWidget.h"
#include "MakeSyncValue.h"

#include "KRecEditor.h"

KRecEditor::KRecEditor(
  dessser::Arr<std::shared_ptr<dessser::gen::raql_type::named_type>> const &rec,
  QWidget *parent)
  : AtomicWidget(parent)
{
  QVBoxLayout *layout = new QVBoxLayout;

  for (std::shared_ptr<dessser::gen::raql_type::named_type> const &nt : rec) {
    QHBoxLayout *l = new QHBoxLayout;
    std::string const &name { std::get<0>(*nt) };
    l->addWidget(new QLabel(QString::fromStdString(name) + ":"));
    AtomicWidget *editor = newRaqlValueEditorWidget(*std::get<1>(*nt));
    l->addWidget(editor);
    connect(editor, &AtomicWidget::inputChanged,
            this, &KRecEditor::inputChanged);
    editors.emplace_back(name, editor);
    layout->addLayout(l);
  }

  QWidget *w = new QWidget;
  w->setLayout(layout);
  relayoutWidget(w);
}

std::shared_ptr<dessser::gen::sync_value::t const> KRecEditor::getValue() const
{
  std::shared_ptr<dessser::gen::raql_value::t> res {
    std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VRec>,
      dessser::Arr<std::shared_ptr<dessser::gen::raql_value::named_value>>()) };
  // Each editors should return a RamenValue:
  for (auto const &editor : editors) {
    std::shared_ptr<dessser::gen::sync_value::t const> v { editor.second->getValue() };
    Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
    std::get<dessser::gen::raql_value::VRec>(*res).push_back(
      std::make_shared<dessser::gen::raql_value::named_value>(
        editor.first,
        std::get<dessser::gen::sync_value::RamenValue>(*v)));
  }

  return makeRamenValue(res);
}

void KRecEditor::setEnabled(bool enabled)
{
  for (auto const &editor : editors) {
    editor.second->setEnabled(enabled);
  }
}

bool KRecEditor::setValue(
  std::shared_ptr<dessser::gen::sync_value::t const> v)
{
  // Value is supposed to be a RamenValue.VRec:
  Q_ASSERT(v->index() == dessser::gen::sync_value::RamenValue);
  std::shared_ptr<dessser::gen::raql_value::t const> rv {
    std::get<dessser::gen::sync_value::RamenValue>(*v) };
  Q_ASSERT(rv->index() == dessser::gen::raql_value::VRec);
  dessser::Arr<std::shared_ptr<dessser::gen::raql_value::named_value>> rec {
    std::get<dessser::gen::raql_value::VRec>(*rv) };
  Q_ASSERT(rec.size() == editors.size());

  bool res { false };
  for (size_t i = 0; i < rec.size(); i++) {
    for (size_t j = 0; j < editors.size(); j++) {
      if (editors[j].first != std::get<0>(*rec[i])) continue;
      res = editors[i].second->setValue(makeRamenValue(std::get<1>(*rec[i]))) || res;
      break;
    }
  }

  if (res) emit valueChanged(v);
  return res;
}
