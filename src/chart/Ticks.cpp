// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "chart/Ticks.h"

#include <QDebug>
#include <cmath>

static constexpr bool verbose{false};

extern inline double logOfBase(int base, double x);
extern inline double sameSign(double sign, double value);

static double valueOfPos(double p, bool log, int base) {
  if (log) {
    return sameSign(p, std::pow(base, std::abs(p)));
  } else {
    return p;
  }
}

static QString labelOfPos(double p, bool log, int base) {
  if (log) {
    double iptr;
    if (0 == std::modf(p, &iptr)) {
      return QString("%1^%2").arg(base).arg(p);
    } else {
      return QString("%1").arg(std::pow(base, p));
    }
  } else {
    return QString("%1").arg(p);
  }
}

Ticks::Ticks(double min_, double max_, bool log, int base) {
  double const min{log ? logOfBase(base, min_) : min_};
  double const max{log ? logOfBase(base, max_) : max_};

  double const d{max - min};
  if (d <= 0) {
    qWarning() << "Ticks: invalid min max range:" << min << "..." << max;
    return;
  }

  double const dist{std::pow(base, std::round(std::log(d) / std::log(base)))};
  double const subDist{dist / base};

  double p{dist * std::floor(min / dist)};
  if (verbose)
    qDebug() << "Ticks: min=" << min << "max=" << max << "dist=" << dist
             << "subDist=" << subDist << "p=" << p;

  for (int i = 0; i < base + 2; i++) {
    ticks.emplace_back(valueOfPos(p, log, base), true,
                       labelOfPos(p, log, base));
    double q{p + subDist};
    for (int j = 1; j < base; j++) {
      ticks.emplace_back(valueOfPos(q, log, base), false,
                         labelOfPos(q, log, base));
      q += subDist;
    }
    p += dist;
    if (p > max + dist) break;
  }
}
