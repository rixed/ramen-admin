// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef COLOROFSTRING_H_190512
#define COLOROFSTRING_H_190512
#include <QColor>

/* Generate a random color from a string, so that the same string is always
 * associated with the same color, and therefore can be used to represent a
 * site, a program, a function or a field.
 *
 * Those colors are actually just tints away from the foreground or background
 * color in order that the vivid colors reserved for alerting stand out more.
 *
 * The last parameter [p] controls the blending, the resulting color being
 * closer to the foreground (or background) the closer p get to 1. [p]=0 disable
 * the blending.
 */

QColor colorOfString(QString const &, double p = 0.5,
                     bool mix_with_foreground = true);

#endif
