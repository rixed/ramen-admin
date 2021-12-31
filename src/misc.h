// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef MISC_H_190603
#define MISC_H_190603
#include <string>

#define SIZEOF_ARRAY(x) (sizeof(x) / sizeof(*(x)))

typedef unsigned __int128 uint128_t;
typedef __int128 int128_t;

bool startsWith(std::string const &, std::string const &);
bool endsWith(std::string const &, std::string const &);

// Remove everything after and including the last occurrence of the given char
std::string const removeExt(std::string const &, char const);

// Remove the optional program name suffix:
std::string const srcPathFromProgramName(std::string const &);
// The other way around: extract the suffix from a program name
std::string const suffixFromProgramName(std::string const &);

#include <QString>

QString const removeExtQ(QString const &, char const);

/* Thanks to KDE bug where menu short-cuts are added: */
QString const removeAmp(QString const &);

bool looks_like_true(QString);

QString const stringOfDate(double);
QString const stringOfDuration(double);
QString const stringOfBytes(size_t);
QString const stringOfBool(bool);
QString const stringOfIp4(uint32_t);
QString const stringOfIp6(uint128_t);
QString const stringOfU128(uint128_t);
QString const stringOfI128(int128_t);

QString const abbrev(int, QString const &);

class QLayout;

void emptyLayout(QLayout *);

std::string demangle(const char *);

/* There are a few global variables that are used if not NULL. When they are
 * deleted, the global variable has to be invalidated before destruction
 * begins. */
template <class T>
void danceOfDel(T **t) {
  if (!*t) return;

  T *tmp = *t;
  *t = nullptr;
  delete tmp;
}

template <class T>
void danceOfDelLater(T **t) {
  if (!*t) return;

  T *tmp = *t;
  *t = nullptr;
  tmp->deleteLater();
}

/* Remove an item from a layout, deleting all the widgets therein (from inner
 * to outer layout): */
void emptyAndDelLayoutItem(QLayout *, int);

/* Don't be too strict when comparing edited values for equality: */

bool isClose(double v1, double v2, double prec = 1e-6);

/* Expand a tree view recursively from a parent.
 * If [but_last] is set, then do not expand the last level (useful to expand
 * ProgramPartItem objects but not the last one so FunctionItem objects stay
 * collapsed). */
class QModelIndex;
class QTreeView;
void expandAllFromParent(QTreeView *, QModelIndex const &, int first, int last,
                         bool but_last = false);

inline bool overlap(double t1, double t2, double u1, double u2) {
  return u1 < t2 && u2 > t1;
}

#include <QDateTime>

inline double getTime() {
  return 0.001 * QDateTime::currentDateTime().toMSecsSinceEpoch();
}

#include <QColor>

/* Returns a color made of a mix of c1 and c2 (100% c1 if ratio is 0 and
 * 100% c2 if ratio is 1) */
QColor blendColor(QColor const &c1, QColor const &c2, double ratio);

#define WITH_BETA_FEATURES (!qEnvironmentVariableIsEmpty("RMADMIN_BETA"))

bool parseIpv4(uint32_t *, QString const &);
bool parseIpv6(uint128_t *, QString const &);

#endif
