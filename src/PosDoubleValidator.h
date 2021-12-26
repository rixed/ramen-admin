// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef POSFLOATVALIDATOR_H_190504
#define POSFLOATVALIDATOR_H_190504
#include <QDoubleValidator>

class PosDoubleValidator : public QDoubleValidator {
  Q_OBJECT

 public:
  PosDoubleValidator(QObject *parent = nullptr) : QDoubleValidator(parent) {
    setBottom(0.);
  }
  ~PosDoubleValidator() {}
};

extern PosDoubleValidator posDoubleValidator;

#endif
