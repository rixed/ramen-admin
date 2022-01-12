// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "colorOfString.h"

#include <cmath>

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

QColor colorOfString(QString const &s) {
  unsigned const paletteSize{80};

  unsigned const numCat{(unsigned)ceil(std::pow(paletteSize, 1. / 3))};
  uint64_t col{qHash(s)};

  unsigned const r{to256(col % numCat, numCat)};
  col /= numCat;
  unsigned const g{to256(col % numCat, numCat)};
  col /= numCat;
  unsigned const b{to256(col % numCat, numCat)};

  return QColor(r, g, b);
}
