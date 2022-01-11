// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "GraphView.h"

#include <QDebug>
#include <QGestureEvent>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QTimer>
#include <QTouchEvent>
#include <cstdlib>
#include <limits>

#include "FunctionItem.h"
#include "ProgramItem.h"
#include "ProgramPartItem.h"
#include "SiteItem.h"
#include "stream/GraphArrow.h"
#include "stream/GraphViewSettings.h"
#include "stream/layout.h"

static bool const verbose{false};

GraphView::GraphView(GraphViewSettings const &settings_, QWidget *parent)
    : QGraphicsView(parent),
      model(nullptr),
      settings(settings_),
      currentScale(1.),
      lastScale(1.) {
  setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
  setDragMode(ScrollHandDrag);
  setRenderHint(QPainter::Antialiasing);
  setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  setScene(&scene);

  layoutTimer = new QTimer(this);
  layoutTimer->setSingleShot(true);
  connect(layoutTimer, &QTimer::timeout, this, &GraphView::startLayout);

  /* Connect selectionChanged to our selectionChanged slot that will then
   * get the first item of the list (should be a singleton) and emit that */
  connect(&scene, &QGraphicsScene::selectionChanged, this,
          &GraphView::selectionChanged);

  grabGesture(Qt::PinchGesture);
  setFocusPolicy(Qt::StrongFocus);
}

QSize GraphView::sizeHint() const {
  /* TODO: compute from components (or rather, cache after components are
   * added/modified) */
  return QSize(200, 500);
}

void GraphView::zoom(qreal ratio) {
  currentScale *= ratio;
  setTransform(QTransform().scale(currentScale, currentScale));
}

void GraphView::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_Plus:
      zoom(1.1);
      return;
    case Qt::Key_Minus:
      zoom(0.9);
      return;
  }

  QGraphicsView::keyPressEvent(event);
}

bool GraphView::event(QEvent *event) {
  if (event->type() == QEvent::Gesture) {
    QGestureEvent *gest{static_cast<QGestureEvent *>(event)};
    if (QGesture *pinch_ = gest->gesture(Qt::PinchGesture)) {
      QPinchGesture *pinch{static_cast<QPinchGesture *>(pinch_)};
      if (pinch->changeFlags() & QPinchGesture::ScaleFactorChanged) {
        lastScale = pinch->totalScaleFactor();
        qreal const scale{currentScale * lastScale};
        setTransform(QTransform().scale(scale, scale));
      }
      if (pinch->state() == Qt::GestureFinished) {
        currentScale *= lastScale;
        lastScale = 1;
      }
      return true;
    }
  }
  return QGraphicsView::event(event);
}

void GraphView::setModel(GraphModel const *model_) {
  Q_ASSERT(!model);
  model = model_;

  // Connect to the model signals to learn about updates (notice the race
  // condition)
  connect(model, &GraphModel::rowsInserted, this, &GraphView::insertRows);
  // TODO: same goes for removal

  // Also the signals allowing us to learn about functions relationships:
  connect(model, &GraphModel::relationAdded, this, &GraphView::relationAdded);
  connect(model, &GraphModel::relationRemoved, this,
          &GraphView::relationRemoved);
}

/* Called when an item is collapsed in the tree view; supposed to also collapse
 * it in the graph view (ie. makes its children invisible) */
void GraphView::collapse(QModelIndex const &index) {
  GraphItem *item{static_cast<GraphItem *>(index.internalPointer())};
  item->setCollapsed(true);
  updateArrows();
}

/* the reverse of the above */
void GraphView::expand(QModelIndex const &index) {
  GraphItem *item{static_cast<GraphItem *>(index.internalPointer())};
  item->setCollapsed(false);
  updateArrows();
}

// Used to select a graph item from the treeview:
void GraphView::select(QModelIndex const &index) {
  GraphItem *item{static_cast<GraphItem *>(index.internalPointer())};

  if (verbose)
    qDebug() << "GraphView::select a" << item->typeName()
             << (item->isCollapsed() ? "(collapsed)" : "");

  // Only allow to select tree leaves:
  ProgramPartItem const *programPart{
      dynamic_cast<ProgramPartItem const *>(item)};
  if (programPart && verbose)
    if (item->isCollapsed() && (!programPart || programPart->actualProgram)) {
      scene.clearSelection();
      if (programPart)
        programPart->actualProgram->setSelected(true);
      else
        item->setSelected(true);
    }
}

static int layoutTimeout{500};  // ms

void GraphView::insertRows(const QModelIndex &parent, int first, int last) {
  // Start (or restart) the layoutTimer to trigger a re-layout in 100ms:
  if (verbose)
    qDebug() << "insertRow in graphModel from" << first << "to" << last;
  layoutTimer->start(layoutTimeout);

  /* We only need to add to the scene the toplevel sites.
   * Other GraphItem objects will be painted because they have this site as
   * their (grand)parent. */
  if (parent.isValid()) return;

  /* Add those new sites in the scene: */
  for (int row = first; row <= last; row++) {
    QModelIndex index{model->index(row, 0, parent)};
    GraphItem *item{static_cast<GraphItem *>(index.internalPointer())};
    SiteItem *siteItem{dynamic_cast<SiteItem *>(item)};
    Q_ASSERT(siteItem);
    scene.addItem(siteItem);
  }
}

void GraphView::updateArrows() {
  // Redo all arrows every time:
  // TODO: if this stick then simplify the following!
  for (auto it = arrows.begin(); it != arrows.end();) {
    GraphArrow *arrow{it->second.first};
    scene.removeItem(arrow);  // reclaim ownership
    delete arrow;             // should remove it from the scene etc...
    it = arrows.erase(it);
  }

  // First, untag all arrows:
  for (auto it = arrows.begin(); it != arrows.end(); it++) {
    it->second.second = false;
  }

#define NB_HMARGINS 3
  int const hmargins[NB_HMARGINS] = {
      settings.siteMarginHoriz + settings.programMarginHoriz +
          settings.functionMarginHoriz,
      settings.siteMarginHoriz + settings.programMarginHoriz,
      settings.siteMarginHoriz};

  for (auto const &it : relations) {
    FunctionItem const *srcFunction{
        static_cast<FunctionItem const *>(it.first)};
    GraphItem const *src{static_cast<GraphItem const *>(srcFunction)};
    GraphItem const *dst{static_cast<GraphItem const *>(it.second)};
    unsigned marginSrc{0}, marginDst{0};
    unsigned const channel{srcFunction->channel};

    while (src && !src->isVisibleTo(nullptr)) {
      src = src->graphicsParent();
      marginSrc++;
    }
    if (!src) continue;  // for some reason even the site is not visible?!
    Q_ASSERT(marginSrc < NB_HMARGINS);

    while (dst && !dst->isVisibleTo(nullptr)) {
      dst = dst->graphicsParent();
      marginDst++;
    }
    if (!dst) continue;
    Q_ASSERT(marginDst < NB_HMARGINS);

    // This may happen because of collapsing
    if (src == dst) continue;

    // Do we have this arrow already?
    auto ait{
        arrows.find(std::pair<GraphItem const *, GraphItem const *>(src, dst))};
    if (ait == arrows.end()) {
      if (verbose)
        qDebug() << "Creating Arrow from" << src->shared->name << ":" << src->x1
                 << "," << src->y1 << "to" << dst->shared->name << ":"
                 << dst->x0 << "," << dst->y0;
      GraphArrow *arrow{new GraphArrow(
          settings, src->x1, src->y1, hmargins[marginSrc], dst->x0, dst->y0,
          hmargins[marginDst], channel, src->color())};
      arrows.insert({{src, dst}, {arrow, true}});
      arrow->setZValue(-1);
      scene.addItem(arrow);
    } else {
      ait->second.second = true;
    }
  }

  // Remove all untagged arrows:
  for (auto it = arrows.begin(); it != arrows.end();) {
    if (it->second.second) {
      it++;
    } else {
      if (verbose)
        qDebug() << "Deleting Arrow from" << it->first.first->sfqName() << "to"
                 << it->first.second->sfqName();
      GraphArrow *arrow{it->second.first};
      scene.removeItem(arrow);  // reclaim ownership
      delete arrow;             // should remove it from the scene etc...
      it = arrows.erase(it);
    }
  }

  /* For some reason Qt is not smart enough to figure out what part of the
   * scene to redraw: */
  scene.update();
}

void GraphView::relationAdded(FunctionItem const *parent,
                              FunctionItem const *child) {
  if (verbose)
    qDebug() << "Add" << parent->sfqName() << "->" << child->sfqName();
  relations.insert(
      std::pair<FunctionItem const *, FunctionItem const *>(parent, child));
  updateArrows();
  layoutTimer->start(layoutTimeout);
}

void GraphView::relationRemoved(FunctionItem const *parent,
                                FunctionItem const *child) {
  if (verbose)
    qDebug() << "Del" << parent->sfqName() << "->" << child->sfqName();
  auto it{relations.find(parent)};
  if (it != relations.end()) {
    relations.erase(it);
    updateArrows();
    layoutTimer->start(layoutTimeout);
  } else {
    qWarning() << "Removal of an unknown relation (good riddance!)";
  }
}

/* Layout is done on the client side for flexibility: so are we free to
 * have a different layout depending on the collapsing state if we decide
 * to take this road, etc.
 * Also, it's easier for the user to interactively update the layout this
 * way.
 * We can still save the result on the server if we want to share the layout
 * with other users. */
void GraphView::startLayout() {
  if (verbose) qDebug() << "Starting a re-layout of the functions";

  if (!model) {
    qWarning() << "Cannot relayout without a model";
    return;
  }

  if (layout::solve(model->sites)) {
    QParallelAnimationGroup *animGroup{new QParallelAnimationGroup};
    int const animDuration{300};  // ms

    for (auto const &siteItem : model->sites) {
      QPointF sitePos{
          settings.pointOfTile(siteItem->x0, siteItem->y0) +
          QPointF(settings.siteMarginHoriz, settings.siteMarginTop)};
      QPropertyAnimation *siteAnim{new QPropertyAnimation(siteItem, "pos")};
      siteAnim->setDuration(animDuration);
      siteAnim->setEndValue(sitePos);
      animGroup->addAnimation(siteAnim);

      // Now position the programs:
      for (auto const &programItem : siteItem->programs) {
        QPointF progPos{
            settings.pointOfTile(programItem->x0 - siteItem->x0,
                                 programItem->y0 - siteItem->y0) +
            QPointF(settings.programMarginHoriz, settings.programMarginTop)};
        QPropertyAnimation *progAnim{
            new QPropertyAnimation(programItem, "pos")};
        progAnim->setDuration(animDuration);
        progAnim->setEndValue(progPos);
        animGroup->addAnimation(progAnim);

        // Finally, we can now position the functions:
        for (auto const &functionItem : programItem->functions) {
          QPointF funcPos{
              settings.pointOfTile(functionItem->x0 - programItem->x0,
                                   functionItem->y0 - programItem->y0) +
              QPointF(settings.functionMarginHoriz,
                      settings.functionMarginTop)};
          QPropertyAnimation *funcAnim{
              new QPropertyAnimation(functionItem, "pos")};
          funcAnim->setDuration(animDuration);
          funcAnim->setEndValue(funcPos);
          animGroup->addAnimation(funcAnim);
        }
      }
    }

    connect(animGroup, &QParallelAnimationGroup::finished, this,
            &GraphView::updateArrows);
    animGroup->start(QAbstractAnimation::DeleteWhenStopped);
  }  // layout succeeded

  // TODO: scene.setSceneRect(global bouning box)?
}

/* When the selection of the scene have changed. Re-emit a simpler signal
 * with the QModelIndex. */
void GraphView::selectionChanged() {
  if (!model) return;

  QList<QGraphicsItem *> items{scene.selectedItems()};
  if (items.empty()) return;

  GraphItem *item{dynamic_cast<GraphItem *>(items.first())};
  if (!item) return;

  if (verbose)
    qDebug() << "GraphView::selectionChanged: selected a" << item->typeName();

  /* If a ProgramItem have been selected, select the last part of the program
   * name instead (usable by the OperationsView): */
  ProgramItem *pi{dynamic_cast<ProgramItem *>(item)};
  if (pi) {
    Q_ASSERT(pi->lastProgramPartItem);
    item = pi->lastProgramPartItem;
  }

  emit selected(item->index(model, 0));
}
