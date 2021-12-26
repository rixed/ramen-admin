// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef RANGEINTVALIDATOR_H_190504
#define RANGEINTVALIDATOR_H_190504
#include <QIntValidator>

namespace RangeIntValidator {

QIntValidator const *forRange(int min, int max);

};

#endif
