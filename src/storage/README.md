All objects related to storage
==============================

- StorageForm: The AtomicForm for the total size and recall cost.

- StorageInfoBox: Display various global information in a grid, such as total
  number of archiving workers, total number of archive files, etc.
  Displayed below the StorageForm.

- StorageInfo: A splitter with the StorageForm and then the StorageInfoBox,
  displayed in the upper left corner of the StorageView.

- StorageTreeView: A QTreeView for the StorageTreeModel, displaying storage
  related information on all archiving workers.

- StorageTreeModel: A QSortFilterProxyModel on top of the globalGraphModel.

- StoragePies: A pie chart of allocated or used storage sizes.

- StorageTimeLine: Displays the archived time ranges per worker, as a time line.

- StorageView: A grid with the StorageInfo, the StorageTreeView below, then on
  the right the StoragePies and finally, at the bottom, the StorageTimeLine.

- StorageWin: A SavedWindow with a single StorageView.
