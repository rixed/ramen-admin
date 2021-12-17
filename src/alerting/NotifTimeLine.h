#ifndef NOTIFTIMELINE_H_191204
#define NOTIFTIMELINE_H_191204
#include <memory>
#include <optional>
#include <string>

#include "timeline/AbstractTimeLine.h"

namespace dessser {
  namespace gen {
    namespace alerting_log { struct t; }
  }
}

class NotifTimeLine : public AbstractTimeLine {
  Q_OBJECT

  std::string const incidentId;

  std::shared_ptr<dessser::gen::alerting_log::t const> selected;

  void paintTick(
    dessser::gen::alerting_log::t const &,
    QPainter *, qreal width, qreal x, qreal y0, qreal y1,
    bool is_selected = false) const;

public:
  // Created empty:
  NotifTimeLine(
    std::string const incidentId,
    qreal beginOfTime, qreal endOfTime,
    bool withCursor = true,
    bool doScroll = true,
    QWidget *parent = nullptr);

protected:
  void paintEvent(QPaintEvent *) override;

  bool event(QEvent *) override;
};

#endif
