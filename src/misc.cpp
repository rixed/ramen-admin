// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "misc.h"

#include <QAbstractItemModel>
#include <QDateTime>
#include <QDebug>
#include <QHostAddress>
#include <QLayout>
#include <QLayoutItem>
#include <QModelIndex>
#include <QTreeView>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstring>  // for memcpy
#include <cstring>
#include <iostream>
#include <string>

#include "dessser/runtime.h"  // for operator<< on int128

QDebug operator<<(QDebug debug, int128_t const &i) {
  debug << stringOfI128(i);
  return debug;
}

QDebug operator<<(QDebug debug, uint128_t const &i) {
  debug << stringOfU128(i);
  return debug;
}

bool startsWith(std::string const &a, std::string const &b) {
  if (a.length() < b.length()) return false;
  return 0 == a.compare(0, b.length(), b, 0);
}

bool endsWith(std::string const &a, std::string const &b) {
  if (a.length() < b.length()) return false;
  return 0 == a.compare(a.length() - b.length(), b.length(), b, 0);
}

std::string const removeExt(std::string const &s, char const c) {
  size_t i{s.rfind(c)};
  if (i == std::string::npos) return s;
  return s.substr(0, i);
}

std::string const srcPathFromProgramName(std::string const &programName) {
  size_t const i{programName.rfind('#')};
  if (i == std::string::npos) return programName;
  return programName.substr(0, i);
}

std::string const suffixFromProgramName(std::string const &programName) {
  size_t const i{programName.rfind('#')};
  if (i == std::string::npos) return "";
  return programName.substr(i + 1);
}

QString const removeExtQ(QString const &s, char const c) {
  int i{s.lastIndexOf(c)};
  if (i == -1) return s;
  return s.left(i);
}

QString const removeAmp(QString const &s) {
  int const i{s.indexOf('&')};

  if (i < 0) return s;

  return s.left(i) + removeAmp(s.right(s.length() - i - 1));
}

bool looks_like_true(QString s_) {
  QString s{s_.simplified()};
  if (s.isEmpty() || s[0] == '0' || s[0] == 'f' || s[0] == 'F') return false;
  return true;
}

QString const stringOfDate(double d) {
  // TODO: strip optional prefix
  return QDateTime::fromSecsSinceEpoch(d).toString();
}

static void reduce(QString &s, double &d, double secs, QString const unit) {
  if (d < secs) return;

  int unit_{int(floor(d / secs))};
  if (s.length() > 0) s += QString(", ");
  s += QString::number(unit_) + unit;
  if (unit.back() != 's' && unit_ > 1) s += 's';
  d -= secs * unit_;
}

QString const stringOfDuration(double d) {
  QString s;

  reduce(s, d, 86400, " day");
  reduce(s, d, 3600, " hour");
  reduce(s, d, 60, " min");
  reduce(s, d, 1, " sec");
  reduce(s, d, 1e-3, "ms");
  reduce(s, d, 1e-6, "µs");

  return s.isEmpty() ? QString("0 secs") : s;
}

QString const stringOfBytes(size_t z) {
  QString s;

#define REDUCE(width, symb)           \
  if (z >= 1ULL << width) do {        \
      size_t const u = z >> width;    \
      z &= (1ULL << width) - 1;       \
      if (s.length() > 0) s += ' ';   \
      s += QString::number(u) + symb; \
  } while (false)

  REDUCE(60, "EiB");
  REDUCE(50, "PiB");
  REDUCE(40, "TiB");
  REDUCE(30, "GiB");
  REDUCE(20, "MiB");
  REDUCE(10, "KiB");
  REDUCE(0, "");

#undef REDUCE

  return s;
}

QString const stringOfBool(bool b) {
  if (b) return "true";
  return "false";
}

QString const stringOfIp4(uint32_t ip) {
  return QString::number((ip >> 24U) & 255) + "." +
         QString::number((ip >> 16U) & 255) + "." +
         QString::number((ip >> 8U) & 255) + "." + QString::number(ip & 255);
}

QString const stringOfIp6(uint128_t ip) {
  QStringList words;
  for (int i = 7; i >= 0; i--) {
    unsigned const w{unsigned(ip >> (unsigned)(16 * i)) & 0xffffU};
    words = words << QString::number(w, 16);
  }
  // TODO: Replace the longest sequence of "0"s by ""

  return words.join(":");
}

QString const stringOfU128(uint128_t v) {
  using dessser::operator<<;
  std::ostringstream s;
  s << v;
  return QString::fromStdString(s.str());
}

QString const stringOfI128(int128_t v) {
  using dessser::operator<<;
  std::ostringstream s;
  s << v;
  return QString::fromStdString(s.str());
}

QString const abbrev(int len, QString const &s) {
  if (len <= 1) return "…";
  if (len >= s.length()) return s;
  return s.chopped(s.length() - len + 1) + "…";
}

void emptyLayout(QLayout *layout) {
  QLayoutItem *item;
  while ((item = layout->takeAt(0)) != nullptr) {
    if (item->widget()) item->widget()->setParent(nullptr);
    delete item;
  }
}

#ifdef __GNUG__
#include <cxxabi.h>

#include <cstdlib>
#include <memory>

inline std::string demangle(const char *name) {
  int status{0};
  std::unique_ptr<char, void (*)(void *)> res{
      abi::__cxa_demangle(name, NULL, NULL, &status), std::free};
  return (status == 0) ? res.get() : name;
}

#else

std::string demangle(const char *name) { return name; }

#endif

bool isClose(double v1, double v2, double prec) {
  Q_ASSERT(prec > 0);

  double const magnitude{std::fmax(abs(v1), abs(v2))};
  if (magnitude < prec) return true;
  double const diff{abs(v1 - v2)};
  return (diff / magnitude) < prec;
}

void expandAllFromParent(QTreeView *view, QModelIndex const &parent, int first,
                         int last, bool but_last) {
  Q_ASSERT(first <= last);
  if (but_last) {  // Find out if all rows are leaves:
    bool is_last{true};
    for (int r = first; r <= last; r++) {
      QModelIndex const index{view->model()->index(r, 0, parent)};
      if (view->model()->rowCount(index) > 0) {
        is_last = false;
        break;
      }
    }
    if (is_last) {
      view->collapse(parent);
      return;
    }
  }
  view->expand(parent);
  for (int r = first; r <= last; r++) {
    QModelIndex const index{view->model()->index(r, 0, parent)};
    // recursively:
    int const num_children{view->model()->rowCount(index)};
    if (num_children > 0)
      expandAllFromParent(view, index, 0, num_children - 1, but_last);
  }
}

QColor blendColor(QColor const &c1, QColor const &c2, double r2) {
  double const r1{1 - r2};

  return QColor(
      c1.red() * r1 + c2.red() * r2, c1.green() * r1 + c2.green() * r2,
      c1.blue() * r1 + c2.blue() * r2, c1.alpha() * r1 + c2.alpha() * r2);
}

bool parseIpv4(uint32_t *ip, QString const &s) {
  QHostAddress addr{s};
  bool ok;
  *ip = addr.toIPv4Address(&ok);
  return ok;
}

bool parseIpv6(uint128_t *ip, QString const &s) {
  QHostAddress addr{s};
  // For some reason there is no `ok-flag` equivalent for IPv6:
  if (addr.isNull()) return false;
  Q_IPV6ADDR ip_{addr.toIPv6Address()};

  // Q_IPV6ADDR stays in network byte order (aka big endian)
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  std::memcpy(ip, &ip_, 16);
#else
  uint8_t *d{reinterpret_cast<uint8_t *>(ip)};
  for (size_t i = 0; i < 16; ++i) d[i] = ip_[15 - i];
#endif

  return true;
}

void emptyAndDelLayoutItem(QLayout *l, int i) {
  Q_ASSERT(i >= 0);
  if (i >= l->count()) return;

  QLayoutItem *item{l->itemAt(i)};
  if (!item) return;

  // The item is either a widget or another layout:
  QWidget *w{item->widget()};
  if (w) {
    l->removeWidget(w);
    w->deleteLater();
  } else {
    QLayout *l_{item->layout()};
    if (l_) {
      while (l_->count()) emptyAndDelLayoutItem(l_, 0);
    }
  }

  l->removeItem(item);
}
