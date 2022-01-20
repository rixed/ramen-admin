// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef LINENUMBERAREA_H_220119
#define LINENUMBERAREA_H_220119
/* Line numbers for CodeEdit widgets.
 * Largely from https://doc.qt.io/qt-5/qtwidgets-widgets-codeeditor-example.html
 *
 * Important design note worth keeping in mind:
 * "Note that we could simply paint the line numbers directly on the code
 * editor, and drop the LineNumberArea class. However, the QWidget class helps
 * us to scroll() its contents. Also, having a separate widget is the right
 * choice if we wish to extend the editor with breakpoints or other code editor
 * features. The widget would then help in the handling of mouse events."
 */
#include <QSize>
#include <QWidget>

class CodeEdit;

class LineNumberArea : public QWidget {
  Q_OBJECT

  CodeEdit *codeEdit;

 public:
  LineNumberArea(CodeEdit *);

  QSize sizeHint() const override;

 protected:
  void paintEvent(QPaintEvent *) override;
};

#endif
