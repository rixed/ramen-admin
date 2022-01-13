// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "colorOfString.h"

#include <cmath>

#include "LoginWin.h"
#include "Menu.h"

/* This tries to return as different colors as possible, thus the paletteSize
 * parameter. Also, when the paletteSize changes the generated colors does not
 * change too much.
 */

static unsigned rescale(unsigned x, unsigned from, unsigned to) {
  Q_ASSERT(x < from);
  return ((double)x / from) * to;
}

static unsigned to256(unsigned x, unsigned from) {
  return rescale(x, from, 256);
}

static double sq(double x) { return x * x; }

/* Subtracting mixing, favoring c1 if p > 0.5.
 * Adapted from https://stackoverflow.com/a/1351485 */
static QColor mix_colors(QColor const &c1, QColor const &c2, double p) {
  double const q{1 - p};
  unsigned const r{unsigned(
      255 - std::sqrt((p * sq(255 - c1.red()) + q * sq(255 - c2.red()))))};
  unsigned const g{unsigned(
      255 - std::sqrt((p * sq(255 - c1.green()) + q * sq(255 - c2.green()))))};
  unsigned const b{unsigned(
      255 - std::sqrt((p * sq(255 - c1.blue()) + q * sq(255 - c2.blue()))))};

  return QColor(r, g, b);
}

QColor colorOfString(QString const &s, double p, bool mix_with_foreground) {
  unsigned const paletteSize{80};

  unsigned const numCat{(unsigned)ceil(std::pow(paletteSize, 1. / 3))};
  uint64_t col{qHash(s)};

  unsigned const r{to256(col % numCat, numCat)};
  col /= numCat;
  unsigned const g{to256(col % numCat, numCat)};
  col /= numCat;
  unsigned const b{to256(col % numCat, numCat)};

  QWidget const *ref{Menu::loginWin};
  QColor const other{Menu::loginWin->palette().color(
      mix_with_foreground ? ref->foregroundRole() : ref->backgroundRole())};
  return mix_colors(other, QColor(r, g, b), p);
}
