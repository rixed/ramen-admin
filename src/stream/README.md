All objects related to the graph of operations
==============================================

Members of "stream/"
--------------------

- OperationsWin: The main window containing only one OperationsView.

- OperationsView: A QSpliter with a tree view of sites/programs/functions on
  the left (NarrowTreeView) (with a few radio buttons on top to select the
  level of details (LOD)) and the graphical representation of the stream
  operations on the right (GraphView).

- NarrowTreeView: Defined in OperationsView, thin layer on top of a QTreeView
  to force a small width. Uses the graphModel for data.

- GraphView: The graphical representation of the stream of operations.

- GraphViewSettings: A set of graphic settings (colors...) used to configure
  all objects involved in the GraphView. To be replaced by the Qt internal
  setting feature, so that they are actually saved from run to run. Also TODO:
  a setting editor!

- GraphArrow: Graphical drawing of arrows from functions to functions in the GraphView.

- layout: A solver for the layout of components in the GraphView

Non-members of "stream/"
------------------------

