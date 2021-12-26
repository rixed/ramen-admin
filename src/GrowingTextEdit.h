// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef GROWINGTEXTEDIT_H_200405
#define GROWINGTEXTEDIT_H_200405
/* A QTextEdit which (preferred) size grows with its content, inspired from
 * https://stackoverflow.com/a/47711588 */
#include <QTextEdit>

class GrowingTextEdit : public QTextEdit {
  Q_OBJECT

 public:
  GrowingTextEdit(QWidget *parent = nullptr);

  QSize sizeHint() const override;

 protected:
  void resizeEvent(QResizeEvent *) override;

 public slots:
  void onTextChange();
};

#endif
