// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef ABSTRACTTIMELINE_H_191204
#define ABSTRACTTIMELINE_H_191204
/* An AbstractTimeLine is a QWidget that can be scrolled to the left and right
 * up to given limits, or zoomed in and out, and that allows the user to
 * select a time (or a time range).
 *
 * This object displays nothing and is supposed to be overloaded with an
 * actual widget displaying some content, such as a time axis with tick marks
 * or a heat map etc.
 *
 * Not to be confused with QTimeLine, which is not a widget but an object to
 * control animations. */
#include <QColor>
#include <QMouseEvent>
#include <QPair>
#include <QWheelEvent>
#include <QWidget>
#include <optional>

struct TimeRange;

class AbstractTimeLine : public QWidget {
  Q_OBJECT

  Q_PROPERTY(qreal beginOfTime READ beginOfTime WRITE setBeginOfTime NOTIFY
                 beginOfTimeChanged)
  Q_PROPERTY(
      qreal endOfTime READ endOfTime WRITE setEndOfTime NOTIFY endOfTimeChanged)
  Q_PROPERTY(QPair<qreal, qreal> viewPort READ viewPort WRITE setViewPort NOTIFY
                 viewPortChanged)
  Q_PROPERTY(qreal currentTime READ currentTime WRITE setCurrentTime NOTIFY
                 currentTimeChanged USER true)
  Q_PROPERTY(
      QPair<qreal, qreal> selection MEMBER m_selection NOTIFY selectionChanged)
  Q_PROPERTY(bool withCursor MEMBER m_withCursor)
  Q_PROPERTY(bool doScroll READ doScroll CONSTANT)

 protected:
  void mouseMoveEvent(QMouseEvent *) override;
  void mousePressEvent(QMouseEvent *) override;
  void mouseReleaseEvent(QMouseEvent *) override;
  void wheelEvent(QWheelEvent *) override;
  bool event(QEvent *) override;
  void keyPressEvent(QKeyEvent *) override;
#if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)
  void enterEvent(QEnterEvent *) override { hovered = true; }
#else
  void enterEvent(QEvent *) override { hovered = true; }
#endif
  void leaveEvent(QEvent *) override { hovered = false; }
  void paintEvent(QPaintEvent *) override;

  qreal toPixel(qreal) const;
  qreal toTime(qreal) const;

  qreal m_beginOfTime;
  qreal m_endOfTime;
  QPair<qreal, qreal> m_viewPort;
  qreal m_currentTime;
  QPair<qreal, qreal> m_selection;
  bool m_withCursor;
  bool m_doScroll;
  bool hovered;

  QVector<QPair<qreal, qreal> > highlights;

 public:
  AbstractTimeLine(qreal beginOftime, qreal endOfTime, bool withCursor = true,
                   bool doScroll = false, QWidget *parent = nullptr);

  static QColor const cursorColor;
  static QColor const highlightColor;

  QSize sizeHint() const override { return QSize(250, 20); }

  qreal beginOfTime() const { return m_beginOfTime; }
  qreal endOfTime() const { return m_endOfTime; }
  qreal currentTime() const { return m_currentTime; }
  void setBeginOfTime(qreal);
  void setEndOfTime(qreal);

  qreal viewPortWidth() const { return m_viewPort.second - m_viewPort.first; }

  static QPair<qreal, qreal> noSelection;

  bool doScroll() const { return m_doScroll; }

  void highlightRange(QPair<qreal, qreal> const);
  void resetHighlights();

  QPair<qreal, qreal> viewPort() const { return m_viewPort; }

 public slots:
  void setCurrentTime(qreal, bool signal_if_changed = false);

  /* Same as setCurrentTime but takes an x coordinate within the window: */
  void setCurrentPos(int x, bool signal_if_changed = false);

  /* The new viewport will be clipped to the begin and end of times: */
  void setViewPort(QPair<qreal, qreal> const &);

  /* Zoom in or out of the current time. Note that zoom=1 means to have
   * the viewport = begin to end of time, and is therefore the minimum
   * zoom possible. */
  void setZoom(qreal zoom, qreal centerTime);

  /* Move the viewport left or right, by a number of seconds. */
  void moveViewPort(qreal ratio);

  /* Move the view port some amount of pixels compared to the view port we
   * started from (default: current view port): */
  void panViewPort(int const dx, QPair<qreal, qreal> const *origin = nullptr);

  void setSelection(QPair<qreal, qreal> const &);
  void clearSelection();

  /* This matches TimeRangeEditor signals and allow to control both the
   * beginOfTime and endOfTime, so that the TimeRangeEditor controls the
   * large picture while user is still able to zoom the viewport at will.
   * On reception of that signal the zoom is reset so that the full new
   * time range is visible, though. */
  void setTimeRange(TimeRange const &);

  /* Move the time range while keeping the viewport as it was unless it's
   * tracking the beginning of end of the time window: */
  void offset(double dt);

 signals:
  void beginOfTimeChanged(qreal);
  void endOfTimeChanged(qreal);
  void viewPortChanged(QPair<qreal, qreal>);
  void currentTimeChanged(qreal);
  void selectionChanged(QPair<qreal, qreal>);

 private:
  std::optional<int> scrollStart;
  QPair<qreal, qreal> viewPortStartScroll;
  std::optional<qreal> candidateSelectionStart;
};

#endif
