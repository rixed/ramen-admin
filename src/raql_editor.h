#ifndef RAQL_EDITOR_H_211124
#define RAQL_EDITOR_H_211124
/* Create an atomic widget suitable to edit a Raql value type.
 * See also EditorWidget.h */
#include "raql_editor/RaqlEditorVoid.h"

namespace dessser {
  namespace gen {
    namespace raql_type { struct t; }
  }
}

AtomicWidget *newRaqlValueEditorWidget(
  dessser::gen::raql_type::t const &,
  QWidget *parent = nullptr);

#endif
