// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "UserIdentity.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtGlobal>
#include <string>

std::optional<QString> my_uid;

static void complain(QFile &file, std::string msg) {
  qCritical() << "File" << file.fileName() << ":"
              << QString::fromStdString(msg);
}

UserIdentity::UserIdentity(QFile &file) {
  isValid = false;
  do {
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      complain(file, "Cannot open");
      break;
    }

    QByteArray txt = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(txt, &error);
    if (doc.isNull()) {
      complain(file, error.errorString().toStdString());
      break;
    }
    if (!doc.isObject()) {
      complain(file, "Cannot parse as JSON");
      break;
    }

    QJsonObject obj = doc.object();

#define GET(field, name)                              \
  if (!obj.contains(name) || !obj[name].isString()) { \
    complain(file, "Cannot find/parse " name);        \
    break;                                            \
  }                                                   \
  field = obj[name].toString()

    GET(username, "username");
    GET(srv_pub_key, "server_public_key");
    GET(clt_pub_key, "client_public_key");
    GET(clt_priv_key, "client_private_key");

    isValid = true;
  } while (false);
}
