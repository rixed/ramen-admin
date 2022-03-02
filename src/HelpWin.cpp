// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "HelpWin.h"

#include <QSplitter>
#include <QString>
#include <QTabWidget>
#include <QTextBrowser>
#include <QUrl>

HelpWin::HelpWin(QWidget *parent)
    : SavedWindow(HELP_WINDOW_NAME, tr("Help"), false, parent) {
  QTextBrowser *langBrowser{new QTextBrowser};
  langBrowser->setSource(QUrl("qrc:doc/raql_toc.html"));

  QTextBrowser *exprBrowser{new QTextBrowser};
  exprBrowser->setSource(QUrl("qrc:toc.html"));

  QTabWidget *tabWidget{new QTabWidget};
  tabWidget->addTab(langBrowser, tr("RaQL language"));
  tabWidget->addTab(exprBrowser, tr("RaQL operators"));

  QTextBrowser *docBrowser{new QTextBrowser};
  docBrowser->setHtml(
      "Click on a link on the left to display the corresponding help.");

  QSplitter *splitter{new QSplitter(Qt::Horizontal)};

  splitter->addWidget(tabWidget);
  splitter->addWidget(docBrowser);
  splitter->setStretchFactor(0, 0);
  splitter->setStretchFactor(1, 1);

  setCentralWidget(splitter);

  /* The default action when clicking on an anchor is to load the new document
   * in the same QTextBrowser. We do not want that for the TOC; Instead we want
   * the new document to open in docBrowser. */
  langBrowser->setOpenLinks(false);
  connect(langBrowser, &QTextBrowser::anchorClicked,
          [docBrowser](QUrl const &link) { docBrowser->setSource(link); });
  exprBrowser->setOpenLinks(false);
  connect(exprBrowser, &QTextBrowser::anchorClicked,
          [docBrowser](QUrl const &link) { docBrowser->setSource(link); });
}
