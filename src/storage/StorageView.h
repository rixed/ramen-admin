// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef STORAGEVIEW_H_190522
#define STORAGEVIEW_H_190522
#include <QWidget>

class GraphModel;

class StorageView : public QWidget {
  Q_OBJECT

 public:
  StorageView(GraphModel *, QWidget *parent = nullptr);
};

#endif
