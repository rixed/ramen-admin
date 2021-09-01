#ifndef USERIDENTITY_H_190719
#define USERIDENTITY_H_190719
#include <optional>
#include <QFile>
#include <QString>

extern std::optional<QString> my_uid;
extern std::optional<std::string> my_errors;
extern std::optional<std::string> my_socket;

struct UserIdentity
{
  bool isValid;
  QString username;
  // All keys are kept in z85 encoded format (for the day they become editable):
  QString srv_pub_key;
  QString clt_pub_key;
  QString clt_priv_key;

  UserIdentity(QFile &);
};

#endif
