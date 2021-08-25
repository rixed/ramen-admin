CONFIG += c++1z warn_on testcase no_testcase_installs

TARGET = test
QT += testlib

INCLUDEPATH += .
INCLUDEPATH += ../src

HEADERS += \
  ConfClientTest.h

SOURCES += \
  ConfClientTest.cpp \
  main.cpp
