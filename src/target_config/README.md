Objects related to Target Config edition
========================================

The Target-config is the list of programs we want to run accompanied with
their runtime parameters.

TargetConfigEditorWin
---------------------

The individual window containing only a TargetConfigEditor.


TargetConfigEditor
------------------

The actual editor for the TargetConfig configuration custom value.  The
TargetConfig value (cf `sync_value.type`) is an array of program names
(source path + optional prefix) and associated parameters.

The TargetConfigEditor is thus mostly a QComboBox listing the entries
followed by a single TargetConfigEntryEditor, which value is reset when
the QToolBox selection changes.

Actually, the QComboBox is followed by a QStackedLayout, which will
display a text rather than the TargetConfigEntryEditor whenever the target
config is entirely empty.

It is also an AtomicWidget for the single key 'target_config'.


TargetConfigEntryEditor
-----------------------

The editor for each individual program.
The program command line parameters are edited by generic editors for the
corresponding RamenValue types and need no specific editor.
