#include <QtGlobal>
#include "dessser/Void.h"

#include "desssergen/raql_value.h"
#include "desssergen/sync_value.h"

#include "raql_editor/RaqlEditorVoid.h"

RaqlEditorVoid::RaqlEditorVoid(QWidget *parent)
  : AtomicWidget(parent)
{
}

std::shared_ptr<dessser::gen::sync_value::t const> RaqlEditorVoid::getValue() const
{
  static std::shared_ptr<dessser::gen::raql_value::t> raql_v {
    std::make_shared<dessser::gen::raql_value::t>(
      std::in_place_index<dessser::gen::raql_value::VUnit>,
      dessser::VOID) };
  static std::shared_ptr<dessser::gen::sync_value::t const> const v {
    std::make_shared<dessser::gen::sync_value::t>(
      std::in_place_index<dessser::gen::sync_value::RamenValue>,
      raql_v) };

  return v;
}

void RaqlEditorVoid::setEnabled(bool)
{
}

bool RaqlEditorVoid::setValue(
  std::shared_ptr<dessser::gen::sync_key::t const>,
  std::shared_ptr<dessser::gen::sync_value::t const>v)
{
  return
    v->index() == dessser::gen::sync_value::RamenValue &&
    std::get<dessser::gen::sync_value::RamenValue>(*v)->index() ==
      dessser::gen::raql_value::VUnit;
}
