#ifndef CONFCLIENTTEST_H_210825
#define CONFCLIENTTEST_H_210825

#include <QObject>

class ConfClientTest : public QObject
{
  Q_OBJECT

private slots:
  void testParseUrl();
};

#endif
