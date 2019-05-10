#include "ProgramItem.h"
#include "SiteItem.h"
#include "OperationsModel.h"

SiteItem::SiteItem(OperationsItem *treeParent, QString const &name) :
  OperationsItem(treeParent, name, Qt::green)
{
  updateFrame();
}

SiteItem::~SiteItem()
{
  for (ProgramItem *program : programs) {
    delete program;
  }
}

QVariant SiteItem::data(int column) const
{
  assert(column == 0);
  return QVariant(name);
}

void SiteItem::reorder(OperationsModel const *model)
{
  for (int i = 0; (size_t)i < programs.size(); i++) {
    if (programs[i]->row != i) {
      programs[i]->row = i;
      programs[i]->setPos(30, i * 90);
      emit model->positionChanged(model->createIndex(i, 0, static_cast<OperationsItem *>(programs[i])));
    }
  }
  updateFrame();
}

std::vector<std::pair<QString const, QString const>> SiteItem::graphLabels() const
{
  return {
    { "name", name },
    { "#programs", QString::number(programs.size()) },
    { "master",
      isMaster ? (*isMaster ? tr("yes") : tr("no")) : tr("unknown") }
  };
}

QRectF SiteItem::boundingRect() const
{
  QRectF bbox = OperationsItem::boundingRect();
  for (auto program : programs) {
    QRectF b = program->boundingRect();
    b.translate(program->pos());
    bbox |= b;
  }
  return bbox;
}
