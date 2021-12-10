#include <iostream>
#include <cassert>
#include <cinttypes>
#include <cstdio>
#include <string>
#include <cmath>
#include <QDateTime>
#include <QLayout>
#include <QLayoutItem>
#include <QModelIndex>
#include <QTreeView>
#include "dessser/runtime.h"  // for operator<< on int128

#include "misc.h"

bool startsWith(std::string const &a, std::string const &b)
{
  if (a.length() < b.length()) return false;
  return 0 == a.compare(0, b.length(), b, 0);
}

bool endsWith(std::string const &a, std::string const &b)
{
  if (a.length() < b.length()) return false;
  return 0 == a.compare(a.length() - b.length(), b.length(), b, 0);
}

std::string const removeExt(std::string const &s, char const c)
{
  size_t i = s.rfind(c);
  if (i == std::string::npos) return s;
  return s.substr(0, i);
}

std::string const srcPathFromProgramName(std::string const &programName)
{
  size_t const i { programName.rfind('#') };
  if (i == std::string::npos) return programName;
  return programName.substr(0, i);
}

std::string const suffixFromProgramName(std::string const &programName)
{
  size_t const i(programName.rfind('#'));
  if (i == std::string::npos) return "";
  return programName.substr(i + 1);
}

QString const removeExtQ(QString const &s, char const c)
{
  int i = s.lastIndexOf(c);
  if (i == -1) return s;
  return s.left(i);
}

QString const removeAmp(QString const &s)
{
  int const i(s.indexOf('&'));

  if (i < 0) return s;

  return s.left(i) + removeAmp(s.right(s.length() - i - 1));
}

bool looks_like_true(QString s_)
{
  QString s = s_.simplified();
  if (s.isEmpty() ||
      s[0] == '0' || s[0] == 'f' || s[0] == 'F') return false;
  return true;
}

QString const stringOfDate(double d)
{
  // TODO: strip optional prefix
  return QDateTime::fromSecsSinceEpoch(d).toString();
}

QString const stringOfDuration(double d)
{
  QString s;

# define REDUCE(secs, unit) \
  if (d > secs) { \
    unsigned unit_ = floor(d / secs); \
    if (s.length() > 0) s += QString(", "); \
    s += QString::number(unit_) + unit; \
    d -= secs * unit_; \
  }

  REDUCE(86400, " days");
  REDUCE(3600, " hours");
  REDUCE(60, " mins");
  REDUCE(1, " secs");
  REDUCE(1e-3, "ms");
  REDUCE(1e-6, "µs");

# undef REDUCE

  return s.isEmpty() ? QString("0 secs") : s;
}

QString const stringOfBytes(size_t z)
{
  QString s;

# define REDUCE(width, symb) \
    if (z >= 1ULL << width) do { \
      size_t const u = z >> width; \
      z &= (1ULL << width) - 1; \
      if (s.length() > 0) s += ' '; \
      s += QString::number(u) + symb; \
    } while (false)

  REDUCE(60, "EiB");
  REDUCE(50, "PiB");
  REDUCE(40, "TiB");
  REDUCE(30, "GiB");
  REDUCE(20, "MiB");
  REDUCE(10, "KiB");
  REDUCE(0, "");

# undef REDUCE

  return s;
}

QString const stringOfBool(bool b)
{
  if (b) return "true";
  return "false";
}

QString const stringOfIp4(uint32_t ip)
{
  return QString::number((ip >> 24U) & 255) + "." +
         QString::number((ip >> 16U) & 255) + "." +
         QString::number((ip >> 8U) & 255) + "." +
         QString::number(ip & 255);
}

QString const stringOfIp6(uint128_t ip)
{
  QStringList words;
  for (int i = 7; i >= 0; i --) {
    unsigned const w = (ip >> (unsigned)(16 * i)) & 0xffffU;
    words = words << QString::number(w, 16);
  }
  // TODO: Replace the longest sequence of "0"s by ""

  return words.join(":");
}

QString const stringOfU128(uint128_t v)
{
  using dessser::operator<<;
  std::ostringstream s;
  s << v;
  return QString::fromStdString(s.str());
}

QString const stringOfI128(int128_t v)
{
  using dessser::operator<<;
  std::ostringstream s;
  s << v;
  return QString::fromStdString(s.str());
}

QString const abbrev(int len, QString const &s)
{
  if (len <= 1) return "…";
  if (len >= s.length()) return s;
  return s.chopped(s.length() - len + 1) + "…";
}

void emptyLayout(QLayout *layout)
{
  QLayoutItem *item;
  while ((item = layout->takeAt(0)) != nullptr) {
    if (item->widget()) item->widget()->setParent(nullptr);
    delete item;
  }
}

#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>

inline std::string demangle(const char *name)
{
  int status = 0;
  std::unique_ptr<char, void(*)(void*)> res {
    abi::__cxa_demangle(name, NULL, NULL, &status), std::free
  };
  return (status==0) ? res.get() : name ;
}

#else

std::string demangle(const char* name)
{
  return name;
}

#endif

bool isClose(double v1, double v2, double prec)
{
  assert(prec > 0);

  double const magnitude = std::fmax(abs(v1), abs(v2));
  if (magnitude < prec) return true;
  double const diff = abs(v1 - v2);
  return (diff / magnitude) < prec;
}

void expandAllFromParent(QTreeView *view, QModelIndex const &parent, int first, int last)
{
  view->expand(parent);
  for (int r = first; r <= last; r ++) {
    QModelIndex const index = view->model()->index(r, 0, parent);
    // recursively:
    int const numChildren = view->model()->rowCount(index);
    expandAllFromParent(view, index, 0, numChildren - 1);
  }
}

QColor blendColor(QColor const &c1, QColor const &c2, double r2)
{
  double const r1(1 - r2);

  return QColor(
    c1.red() * r1 + c2.red() * r2,
    c1.green() * r1 + c2.green() * r2,
    c1.blue() * r1 + c2.blue() * r2,
    c1.alpha() * r1 + c2.alpha() * r2);
}

extern "C" {
#include <arpa/inet.h>
}

bool parseIpv4(uint32_t *ip, QString const &s)
{
  struct in_addr addr;
  if (0 == inet_pton(AF_INET, s.toStdString().c_str(), &addr))
    return false;
  *ip = ntohl(addr.s_addr);
  return true;
}

bool parseIpv6(uint128_t *ip, QString const &s)
{
  static_assert(sizeof(struct in6_addr) == sizeof(uint128_t));
  uint128_t addr;
  if (0 == inet_pton(AF_INET6, s.toStdString().c_str(), &addr))
    return false;
  // Endianness?
  if (ntohs(0x0102) == 0x0102) {
    *ip = addr;
  } else {
    *((uint32_t *)ip + 0) = ntohl(*((uint32_t *)&addr + 3));
    *((uint32_t *)ip + 1) = ntohl(*((uint32_t *)&addr + 2));
    *((uint32_t *)ip + 2) = ntohl(*((uint32_t *)&addr + 1));
    *((uint32_t *)ip + 3) = ntohl(*((uint32_t *)&addr + 0));
  }
  return true;
}

void emptyAndDelLayoutItem(QLayout *l, int i)
{
  Q_ASSERT(i >= 0);
  if (i >= l->count()) return;

  QLayoutItem *item { l->itemAt(i) };
  if (! item) return;

  // The item is either a widget or another layout:
  QWidget *w { item->widget() };
  if (w) {
    l->removeWidget(w);
    w->deleteLater();
  } else {
    QLayout *l_ { item->layout() };
    if (l_) {
      while (l_->count())
        emptyAndDelLayoutItem(l_, 0);
    }
  }

  l->removeItem(item);
}
