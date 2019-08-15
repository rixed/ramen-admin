#ifndef RMADMINWIN_H_20190429
#define RMADMINWIN_H_20190429
#include <string>
#include <QWidget>
#include "SavedWindow.h"
#include "SyncStatus.h"
#include "KErrorMsg.h"

class ConfTreeModel;
class SourcesModel;
class GraphModel;
class GraphViewSettings;

class RmAdminWin : public SavedWindow
{
  Q_OBJECT

  SyncStatus connStatus, authStatus, syncStatus;
  void setStatusMsg();
  KErrorMsg *errorMessage;
  ConfTreeModel *confTreeModel;
  SourcesModel *sourcesModel;

public:
  explicit RmAdminWin(GraphModel *, bool with_beta_features, QWidget *parent = nullptr);

signals:

public slots:
  void connProgress(SyncStatus);
  void authProgress(SyncStatus);
  void syncProgress(SyncStatus);
  void setErrorKey(std::string const key) { errorMessage->setKey(key); }
};

#endif
