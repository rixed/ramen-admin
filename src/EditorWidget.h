#ifndef EDITORWIDGET_H_210913
#define EDITORWIDGET_H_210913
/* Build a widget to edit a given configuration value */
#include <memory>

class QWidget;
class AtomicWidget;
namespace dessser {
namespace gen {
namespace sync_key {
struct t;
}
namespace sync_value {
struct t;
}
namespace raql_type {
struct t;
}
}  // namespace gen
}  // namespace dessser

/* Some keys have additional constraints or specific representations
 * more suitable than the generic editor for that value type.
 * But this is true for other methods of the Value. Let's rather
 * consider that Value can have "styles" depending on their key, which
 * allow them to customize their editor and/or other members. */
AtomicWidget *newEditorWidget(
    dessser::gen::sync_value::t const &,
    std::shared_ptr<dessser::gen::sync_key::t const> =
        std::shared_ptr<dessser::gen::sync_key::t const>(),
    QWidget *parent = nullptr);

AtomicWidget *newRaqlValueEditorWidget(dessser::gen::raql_type::t const &,
                                       QWidget *parent = nullptr);

#endif
