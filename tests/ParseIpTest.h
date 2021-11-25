#ifndef PARSEIPTEST_H_211117
#define PARSEIPTEST_H_211117

#include <QObject>

class ParseIpTest : public QObject
{
  Q_OBJECT

private slots:
  void testParseIp4();
  void testParseIp6();
};

#endif
