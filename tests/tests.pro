CONFIG += debug c++1z warn_on testcase no_testcase_installs

TARGET = test
QT += testlib

INCLUDEPATH += .
INCLUDEPATH += ../src

HEADERS += \
  ConfClientTest.h \
  Z85Test.h

SOURCES += \
  ConfClientTest.cpp \
  Z85Test.cpp \
  main.cpp
