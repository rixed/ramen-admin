// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "RamenValueEditor.h"

#include "RamenType.h"

RamenValueEditor *RamenValueEditor::ofType(
    std::shared_ptr<RamenType const> type, RamenValue const *val,
    QWidget *parent) {
  RamenValueEditor *editor = new RamenValueEditor(type, parent);
  editor->setText(val->toQString(std::string()));
  return editor;
}

RamenValue *RamenValueEditor::getValue() const {
  return type->vtyp->valueOfQString(text());
}
