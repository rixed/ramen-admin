// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef RANGEDOUBLEVALIDATOR_H_190504
#define RANGEDOUBLEVALIDATOR_H_190504
#include <QDoubleValidator>

namespace RangeDoubleValidator {

QDoubleValidator const *forRange(double min, double max);

};

#endif
