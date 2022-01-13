// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TICKS_H_200311
#define TICKS_H_200311
#include <QString>
#include <QtGlobal>
#include <cmath>
#include <vector>
#undef major  // Helps compilation with some older GNU libc

// v is assumed > 0
inline double sameSign(double s, double v) { return s >= 0 ? v : -v; }

inline double logOfBase(int base, double x) {
  return sameSign(x, std::log(std::abs(x) + 1) / std::log(base));
}

struct Tick {
  double pos;  // in value not pixels
  bool major;
  QString label;

  Tick(double p, bool m, QString const &l) : pos(p), major(m), label(l) {}
};

struct Ticks {
  std::vector<Tick> ticks;

  Ticks(double min, double max, bool log = false, int base = 10);
};

#endif
