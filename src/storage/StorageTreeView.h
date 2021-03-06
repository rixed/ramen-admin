// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef STORAGETREEVIEW_H_190522
#define STORAGETREEVIEW_H_190522
#include <QTreeView>
/* A simple table displaying all archiving workers with stats related to
 * archival */
class GraphModel;
class QTimer;
class StorageTreeModel;

class StorageTreeView : public QTreeView {
  Q_OBJECT

  QTimer *invalidateModelTimer;

 public:
  StorageTreeView(GraphModel *, StorageTreeModel *, QWidget *parent = nullptr);

 protected slots:
  void expandAndResizeRows(const QModelIndex &, int, int);
  void mayInvalidateModel();
  void doInvalidateModel();
};

#endif
