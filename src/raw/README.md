Objects related to raw configuration editor
===========================================

Objects from 'raw/'
-------------------

- RawConfWin: The independent SavedWindow containing a single ConfTreeWidget.

- ConfTreeWidget: A QTreeWidget displaying (a large subset of) the whole
  configuration.

- ConfTreeItem: The items of the ConfTreeWidget, representing a single key.

- RawConfEditorDialog: A QDialog containing just an editor for a specific key.
  Rely on EditorWidget to create an adequate editor.

Other objects
-------------

- EditorWidget: Creates an editor specific for a given key and value.
  Ideally the editor is specialized for that key.
