// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef BINARYHEATLINE_H_191204
#define BINARYHEATLINE_H_191204
/* A BinaryHeatLine is a HeatLine with only on or off values and a simplified
 * interface. */
#include <QColor>
#include <QPair>
#include <QVector>
#include <optional>

#include "desssergen/time_range.h"
#include "timeline/HeatLine.h"

class BinaryHeatLine : public HeatLine {
  Q_OBJECT

 public:
  BinaryHeatLine(
      qreal beginOftime, qreal endOfTime, bool withCursor = true,
      bool doScroll = true,  // As there is almost no content in there
      QWidget *parent = nullptr);

  void add(qreal start, qreal stop);
  void setArchivedTimes(dessser::gen::time_range::t const &);
};

#endif
