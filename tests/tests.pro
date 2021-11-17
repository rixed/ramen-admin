CONFIG += debug c++1z warn_on testcase no_testcase_installs

TARGET = test
QT += core widgets testlib

INCLUDEPATH += .
INCLUDEPATH += ../src

HEADERS += \
  ConfClientTest.h \
  Z85Test.h \
  StringOfIpTest.h

SOURCES += \
  ConfClientTest.cpp \
  Z85Test.cpp \
  StringOfIpTest.cpp \
  main.cpp
