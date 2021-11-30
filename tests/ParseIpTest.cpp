#include <QtTest>

#include "misc.h"
#include "ParseIpTest.h"

void ParseIpTest::testParseIp4()
{
  uint32_t ip;
  QVERIFY(!parseIpv4(&ip, ""));
  QVERIFY(!parseIpv4(&ip, "-1.2.3.4"));
  QVERIFY(!parseIpv4(&ip, "342.2.3.4"));
  QVERIFY(!parseIpv4(&ip, "pas glop"));
  QVERIFY(parseIpv4(&ip, "0.0.0.0"));
  QCOMPARE(ip, 0x00000000U);
  QVERIFY(parseIpv4(&ip, "1.2.3.4"));
  QCOMPARE(ip, 0x01020304U);
  QVERIFY(parseIpv4(&ip, "192.168.0.14"));
  QCOMPARE(ip, 0xC0A8000EU);
  QVERIFY(parseIpv4(&ip, "10.0.0.0"));
  QCOMPARE(ip, 0x0A000000U);
}

void ParseIpTest::testParseIp6()
{
  uint128_t ip;
  QVERIFY(parseIpv6(&ip, "0:0:0:0:0:0:3455:1021"));
  QCOMPARE(ip, 0x34551021U);
  QVERIFY(parseIpv6(&ip, "::3455:1021"));
  QCOMPARE(ip, 0x34551021U);
}
