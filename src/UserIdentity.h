// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef USERIDENTITY_H_190719
#define USERIDENTITY_H_190719
#include <QFile>
#include <QString>
#include <optional>

extern std::optional<QString> my_uid;

struct UserIdentity {
  bool isValid;
  QString username;
  // All keys are kept in z85 encoded format (for the day they become
  // editable):
  QString srv_pub_key;
  QString clt_pub_key;
  QString clt_priv_key;

  UserIdentity(QFile &);
};

#endif
