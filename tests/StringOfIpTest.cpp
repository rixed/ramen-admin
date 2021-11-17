#include <QtTest>

#include "misc.cpp"
#include "StringOfIpTest.h"

void StringOfIpTest::testStringOfIp4()
{
  QCOMPARE(stringOfIp4(0x01020304U), "1.2.3.4");
  QCOMPARE(stringOfIp4(0xC0A8000EU), "192.168.0.14");
}

void StringOfIpTest::testStringOfIp6()
{
  QCOMPARE(stringOfIp6(0x34551021U), "0:0:0:0:0:0:3455:1021"); // FIXME: "::3455:1021"
}
