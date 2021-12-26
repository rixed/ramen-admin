// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef DASHBOARDWIDGETFORM_H_200323
#define DASHBOARDWIDGETFORM_H_200323
#include <string>

#include "AtomicForm.h"

class Dashboard;
class DashboardCopyDialog;
class DashboardWidget;
class QAction;
class QLabel;
class QVBoxLayout;
class QWidget;

/* This is an AtomicForm that's composed of a single AtomicWidget,
 * since all widget values are made of a single KValue. */
class DashboardWidgetForm : public AtomicForm {
  Q_OBJECT

  std::shared_ptr<dessser::gen::sync_key::t const> widgetKey;
  DashboardWidget *widget;

  QVBoxLayout *layout;
  DashboardCopyDialog *copyDialog;
  QWidget *menuFrame;
  QLabel *title;

  QAction *upAction, *downAction;

  void doCopy(bool);

  void switchPosition(std::shared_ptr<dessser::gen::sync_key::t const>,
                      KValue const &);

 public:
  Dashboard *dashboard;

  DashboardWidgetForm(
      std::shared_ptr<dessser::gen::sync_key::t const> widgetKey, Dashboard *,
      QWidget *parent = nullptr);

  ~DashboardWidgetForm();

  void enableArrowsForPosition(size_t idx, size_t count);

  void setExpand(bool);

 protected slots:
  void performCopy();
  void performMove();
  void moveUp();
  void moveDown();
  void setTitle(QString const &);
};

#endif
