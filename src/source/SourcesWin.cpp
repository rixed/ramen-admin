#include <QTabWidget>

#include "misc_dessser.h"
#include "source/SourcesModel.h"
#include "source/SourcesView.h"

#include "source/SourcesWin.h"

SourcesWin::SourcesWin(QWidget *parent) :
  SavedWindow(SOURCE_EDITOR_WINDOW_NAME, tr("Code Editor"), true, parent)
{
  sourcesModel = new SourcesModel(this);
  sourcesView = new SourcesView(sourcesModel, this);
  setCentralWidget(sourcesView);
}

void SourcesWin::showFile(std::string const &keyPrefix)
{
  sourcesView->showFile(keyPrefix);
}

void SourcesWin::showFile(std::shared_ptr<dessser::gen::sync_key::t const> k)
{
  std::optional<std::pair<std::string const, std::string const>> src_path {
    srcPathOfKey(*k) };

  if (! src_path) return;

  showFile(src_path->first);
}
