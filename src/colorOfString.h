// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef COLOROFSTRING_H_190512
#define COLOROFSTRING_H_190512
#include <QColor>

/* Generate a random color from a string, so that the same string is always
 * associated with the same color, and therefore can be used to represent a
 * site, a program, a function or a field.
 */

QColor colorOfString(QString const &);

#endif
