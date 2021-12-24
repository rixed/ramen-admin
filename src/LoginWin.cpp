#include <memory>
#include <QDebug>
#include <QFile>
#include <QLabel>
#include <QMetaObject>
#include <QStatusBar>
#include <QTimer>

#include "ConfClient.h"
#include "LoginWidget.h"
#include "LoginWin.h"
#include "Menu.h"
#include "misc.h"
#include "UserIdentity.h"

LoginWin::LoginWin(
  QString configDir,
  QWidget *parent)
  : SavedWindow("LoginWindow", "User Authentication", false, parent),
    client(nullptr)
{
  loginWidget = new LoginWidget(configDir);
  setCentralWidget(loginWidget);
  connect(loginWidget, &LoginWidget::submitted,
          this, &LoginWin::startConnect);
  connect(loginWidget, &LoginWidget::cancelled,
          this, &LoginWin::exitApp);

  /* As a status bar we will display the error from the confserver in errorMessage
   * and some statistics about the connection. */
  QStatusBar *sb { statusBar() };
  stats = new QLabel;
  sb->addPermanentWidget(stats);
  errorMessage = new KErrorMsg(this);
  sb->addWidget(errorMessage, 1);

  connect(this, &LoginWin::authenticated,
          menu, &Menu::upgradeToFull);

  statsTimer = new QTimer(this);
  connect(statsTimer, &QTimer::timeout,
          this, &LoginWin::refreshStats);
  // Will be started when sync starts
}

LoginWin::~LoginWin()
{
  // Since the process is about to exit there is no need to close the client etc.
}

void LoginWin::focusSubmit()
{
  loginWidget->focusSubmit();
}

void LoginWin::startConnect(
  QString const server, QString const username, QString const idFile)
{
  std::shared_ptr<UserIdentity const> id;
  if (! idFile.isEmpty()) {
    QFile file(idFile);
    id = std::make_shared<UserIdentity>(file);
    if (! id->isValid) {
      qCritical() << "Identity file" << idFile << "is not valid";
      id.reset();
      QCoreApplication::exit(1);
      return;
    }
  }

  // Set the global my_uid
  my_uid = username;
  if (id && id->isValid) my_uid = id->username;

  /* Create the windows that will connect to the kvs->map keys *before*
   * the connection is attempted: */
  Menu::initDialogs(server);

  client = new ConfClient(server, username, id, kvs);
  connect(client, &ConfClient::knownErrKey,
          errorMessage, &KErrorMsg::setKey);
  connect(client, &ConfClient::connectionProgressed,
          this, &LoginWin::syncProgress);
  connect(client, &ConfClient::connectionFatalError,
          this, &LoginWin::syncFailed);

  loginWidget->setSubmitStatus("");
}

void LoginWin::exitApp()
{
  QCoreApplication::quit();
}

void LoginWin::refreshStats()
{
  QString const statusMsg {
    tr("%1 (%2) ⥮ %3 (%4)").
      arg(QString::number(client->sentMsgs),
          stringOfBytes(client->sentBytes),
          QString::number(client->rcvdMsgs),
          stringOfBytes(client->rcvdBytes)) };
  stats->setText(statusMsg);
}

void LoginWin::setStatusMsg(SyncStatus const status)
{

  if (! errMsg.isEmpty()) {
    QStatusBar *sb { statusBar() };
    sb->setStyleSheet("background-color: pink;");
    sb->showMessage(errMsg);
  }

  QString const statusMsg { status.message() };
  loginWidget->setSubmitStatus(statusMsg);
}

void LoginWin::syncProgress(SyncStatus const status)
{
  setStatusMsg(status);
  // Start the actual interface as soon as synchronization starts:
  if (status.get() == SyncStatus::Status::Synchronizing) {
    emit authenticated();
    statsTimer->start(500);
    //hide();
  }
}

void LoginWin::syncFailed(SyncStatus const lastStatus, QString const &msg)
{
  errMsg = msg;
  setStatusMsg(lastStatus);
}
