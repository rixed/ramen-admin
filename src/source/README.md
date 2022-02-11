Objects to edit Ramen program sources
=====================================

Members of "source/"
--------------------

- AlertEditor: the AtomicWidget editor for values of type Alert.
  Makes use of an internal NameTreeView to select the field name on which to
  alert.

- PivotEditor: the AtomicWidget editor for values of type Pivot, still TBD.

- FilterEditor: QWidget to edit the alert "simple-filter" values. Composed of a
  lhsEdit and a rhsEdit (QLineEdit) and an opEdit (QComboBox).
  Uses a field name completer for the left-hand-side.

- SourceInfoViewer: An AtomicWidget for the "info" sources. Cannot edit (obviously).

- SourceEdit: a QWidget to edit a source, in any format for which there is a
  value in the configuration. Will switch between various underlying
  AtomicWidget objects for the various supported languages.
  Note that it uses a KTextEdit for RaQL programs.
  Has also a box for errors.

- SourceEditForm: An AtomicForm with a SourceEdit.

- SourcesModel: a QAbstractItemModel for the sources in the configuration.

- SourcesView: A QWidget displaying the selected source.
  Make use internaly of a SourcesTreeView (fed by the above SourcesModel)
  that's a QTreeView displaying the defined sources.

- SourcesWin: The SavedWindow made of the SourcesView.

- NewSourceDialog: A QDialog with a QLineEdit for the new source name, a
  SourceEdit for the actual source and then a box of buttons.

- SourceCloneDialog: A QDialog used to clone a source, asking only for the new
  name (in a QLineEdit).


Non members of "source/"
------------------------

- KTextEdit: a text editors for RaQL (or others) code.
