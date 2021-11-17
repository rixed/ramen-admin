#ifndef STRINGOFIPTEST_H_211117
#define STRINGOFIPTEST_H_211117

#include <QObject>

class StringOfIpTest : public QObject
{
  Q_OBJECT

private slots:
  void testStringOfIp4();
  void testStringOfIp6();
};

#endif
