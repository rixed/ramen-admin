// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "SiteItem.h"

#include <QMarginsF>

#include "GraphModel.h"
#include "ProgramItem.h"
#include "ProgramPartItem.h"
#include "stream/GraphView.h"
#include "stream/GraphViewSettings.h"

SiteItem::SiteItem(std::unique_ptr<Site> site,
                   GraphViewSettings const &settings)
    : GraphItem(nullptr, std::move(site), settings) {
  setZValue(1);
}

/* Reorder both programs and programParts, even if only one of those trees is
 * going to be used for the graph model: */
void SiteItem::reorder(GraphModel *) {
  for (int i = 0; (size_t)i < programs.size(); i++) {
    if (programs[i]->row != i) {
      programs[i]->row = i;
      programs[i]->setPos(30, i * 90);
    }
  }

  for (int i = 0; (size_t)i < programParts.size(); i++) {
    programParts[i]->row = i;
  }

  prepareGeometryChange();
}

std::vector<std::pair<QString const, QString const> > SiteItem::labels() const {
  std::shared_ptr<Site> shr{std::static_pointer_cast<Site>(shared)};

  return {{"#programs", QString::number(programs.size())},
          {"master", shr->isMaster ? (*shr->isMaster ? tr("yes") : tr("no"))
                                   : tr("unknown")}};
}

QRectF SiteItem::operationRect() const {
  QRectF bbox;
  for (auto const &program : programs) {
    QRectF b{program->operationRect()};
    b.translate(program->pos());
    bbox |= b;
  }
  bbox += QMarginsF(settings.programMarginHoriz, settings.programMarginTop,
                    settings.programMarginHoriz, settings.programMarginBottom);
  return bbox;
}

SiteItem::operator QString() const {
  QString s{"Site["};
  s += row;
  s += "]:";
  s += shared->name;
  for (ProgramItem const *program : programs) {
    s += *program;
  }
  return s;
}
