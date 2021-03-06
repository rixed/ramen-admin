// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef SAVEDWINDOW_H_190813
#define SAVEDWINDOW_H_190813
#include <QMainWindow>
#include <QString>
#include <optional>

/* Like QMainWindow but with some adjustments, such as saving/restoring
 * the window position, thus the name. */

extern bool saveWindowVisibility;

class Menu;
class QCloseEvent;

class SavedWindow : public QMainWindow {
  Q_OBJECT

  QString windowName;

 public:
  Menu *menu;

  SavedWindow(QString const &windowName, QString const &windowTitle,
              bool fullMenu, QWidget *parent,
              std::optional<bool> visibility = std::nullopt);

 protected:
  void closeEvent(QCloseEvent *);
};

#endif
