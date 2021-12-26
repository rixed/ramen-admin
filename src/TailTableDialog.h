// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef TAILTABLEDIALOG_H_190810
#define TAILTABLEDIALOG_H_190810
#include <QMainWindow>
#include <memory>

class TailModel;

class TailTableDialog : public QMainWindow {
  Q_OBJECT

 public:
  TailTableDialog(std::shared_ptr<TailModel>, QWidget *parent = nullptr);
};

#endif
