#include <QtTest>

#include "z85.cpp"
#include "Z85Test.h"

void Z85Test::testZ85Decode()
{
  unsigned char in1[] { "HelloWorld" };
  unsigned char out1[8 + 1];
  ssize_t res = z85_decode(10, in1, sizeof(out1), out1);
  QVERIFY(res == 8);
  out1[res] = '\0';
  QCOMPARE((char *)out1, "\x86\x4F\xD2\x6F\xB5\x59\xF7\x5B");

  unsigned char in2[] { "ERqrFD8m}m0Q?YqAc5i^t3DW+eo!WR?#@?Sp?NN2" };
  unsigned char out2[32 + 1];
  res = z85_decode(40, in2, sizeof(out2), out2);
  QVERIFY(res == 32);
  out2[res] = '\0';
  unsigned char const exp2[32 + 1] =
    { 126, 104, 73, 163, 121, 165, 181, 235, 1, 239, 47, 249, 112, 115, 175, 90, 90, 91, 133, 6, 44, 119, 186, 129, 224, 4, 248, 173, 80, 103, 192, 52, 0 };
  QCOMPARE((char *)out2, (char *)exp2);
}
