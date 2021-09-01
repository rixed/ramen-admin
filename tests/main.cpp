#include <QtTest>

#include "ConfClientTest.h"
#include "Z85Test.h"


int main(int argc, char *argv[])
{
  int status { 0 };

  status |= QTest::qExec(new ConfClientTest, argc, argv);
  status |= QTest::qExec(new Z85Test, argc, argv);

  return status;
}
