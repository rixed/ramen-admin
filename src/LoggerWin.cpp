// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "LoggerWin.h"

#include <QGridLayout>
#include <QListView>
#include <QStringListModel>

#include "LogModel.h"
#include "Logger.h"
#include "LoggerView.h"

LoggerWin::LoggerWin(QWidget *parent)
    : SavedWindow("LoggerWindow", "RmAdmin logs", true, parent) {
  LogModel *logModel = new LogModel(this);

  logger = new Logger(this);

  loggerView = new LoggerView(this);
  loggerView->setModel(logModel);
  setCentralWidget(loggerView);

  connect(logger, &Logger::newMessage, logModel, &LogModel::append);
}
