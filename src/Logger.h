// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef LOGGER_H_191025
#define LOGGER_H_191025
#include <QObject>
#include <QString>

QString const logLevel(QtMsgType);

class Logger : public QObject {
  Q_OBJECT

 public:
  Logger(QObject *parent = nullptr);
  ~Logger();

 signals:
  void newMessage(QtMsgType, QString const &);
};

Q_DECLARE_METATYPE(QtMsgType);

#endif
