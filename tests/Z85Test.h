#ifndef Z85TESTS_H_210831
#define Z85TESTS_H_210831

#include <QObject>

class Z85Test : public QObject
{
  Q_OBJECT

private slots:
  void testZ85Decode();
};

#endif
