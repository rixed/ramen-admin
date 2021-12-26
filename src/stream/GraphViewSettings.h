// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef GRAPHVIEWSETTINGS_H_190510
#define GRAPHVIEWSETTINGS_H_190510
#include <QFont>
#include <QPointF>

struct GraphViewSettings {
  QFont labelsFont;
  int labelsLineHeight;
  QFont titleFont;
  int titleLineHeight;

  int gridWidth, gridHeight, functionMarginHoriz, programMarginHoriz,
      siteMarginHoriz, functionMarginTop, programMarginTop, siteMarginTop,
      functionMarginBottom, programMarginBottom, siteMarginBottom;

  int labelsHorizMargin;

  unsigned numArrowChannels;
  int arrowChannelWidth;
  int arrowWidth;
  int arrowConnectInY;
  int arrowConnectOutY;

  GraphViewSettings();

  ~GraphViewSettings();

  QPointF pointOfTile(int x, int y) const;
};

#endif
