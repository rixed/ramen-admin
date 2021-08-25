#include <QString>
#include <QtTest>

#include "ConfClientTools.cpp"
#include "ConfClientTest.h"

void ConfClientTest::testParseUrl()
{
  QString host;
  quint16 port;
  int res;

  res = parseUrl(host, port, QString("glop"));
  QVERIFY(res == 0);
  QCOMPARE(host, QString("glop"));
  QCOMPARE(port, 29340);

  res = parseUrl(host, port, QString("glop:123"));
  QVERIFY(res == 0);
  QCOMPARE(host, QString("glop"));
  QCOMPARE(port, 123);

  res = parseUrl(host, port, QString("glop:pas_glop"));
  QVERIFY(res != 0);
}
