// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "RangeDoubleValidator.h"

#include <vector>

namespace RangeDoubleValidator {

static std::vector<QDoubleValidator *> validators;

QDoubleValidator const *forRange(double min, double max) {
  // Look for a previously created validator for that range:
  for (auto const validator : validators) {
    if (validator->bottom() == min && validator->top() == max) return validator;
  }

  // 1000 decimal digits is the default:
  QDoubleValidator *validator = new QDoubleValidator(min, max, 1000);
  validators.push_back(validator);
  return validator;
}

};  // namespace RangeDoubleValidator
