// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef RAMENSYNTAXHIGHLIGHTER_190729
#define RAMENSYNTAXHIGHLIGHTER_190729
#include <QSyntaxHighlighter>

class RamenSyntaxHighlighter : public QSyntaxHighlighter {
  Q_OBJECT

 public:
  RamenSyntaxHighlighter(QTextDocument *parent = nullptr);

 protected:
  void highlightBlock(const QString &text);
};

#endif
