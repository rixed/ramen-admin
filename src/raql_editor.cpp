#include <QDebug>

#include "desssergen/raql_type.h"
#include "misc_dessser.h"

#include "raql_editor.h"

/*
 * Return an editor suitable for the given Raql-type.
 * Compared to newEditorWidget, those AtomicWidget has no associated key.
 */

AtomicWidget *newRaqlValueEditorWidget(dessser::gen::raql_type::t const &t, QWidget *parent)
{
  using namespace dessser::gen::raql_type;
  AtomicWidget *editor = nullptr;
  switch (t.type->index()) {
    case Void:
      editor = new RaqlEditorVoid(parent);
      break;

    default:
      qCritical() <<
        "Not implemented: newRaqlValueEditorWidget for raql_type::base" << *t.type;
  }

  // TODO: wrap into a nullable editor that offers to set null (radio?)
  return editor;
}
