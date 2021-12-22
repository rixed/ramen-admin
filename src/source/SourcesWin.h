#ifndef SOURCESWINWIN_H_20190429
#define SOURCESWINWIN_H_20190429
#include <memory>
#include <string>

#include "SavedWindow.h"
/* The SourcesWindow is the initial window that's opened.
 * It features the SourcesView, aka the code editor.
 * Error messages will also appear in this window status bar. */

#define SOURCE_EDITOR_WINDOW_NAME "EditorWindow"

class QWidget;
class SourcesModel;
class SourcesView;

namespace dessser {
  namespace gen {
    namespace sync_key { struct t; }
  }
}

class SourcesWin : public SavedWindow
{
  Q_OBJECT

  SourcesModel *sourcesModel;
  SourcesView *sourcesView;

public:
  explicit SourcesWin(QWidget *parent = nullptr);

public slots:
  // Show a specific path (TODO: optional extension?)
  void showFile(std::string const &path);

  // Show a specific key (FIXME: currently ignores the extension):
  void showFile(std::shared_ptr<dessser::gen::sync_key::t const>);
};

#endif
