// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "PathSuffixValidator.h"

/* No dots and no slashs. May be empty. */
QValidator::State PathSuffixValidator::validate(QString &input, int &) const {
  if (input.contains('.') || input.contains('/')) return QValidator::Invalid;

  return QValidator::Acceptable;
}
