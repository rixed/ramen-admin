#include <QAbstractItemView>
#include <QComboBox>
#include <QCompleter>
#include <QDebug>
#include <QHBoxLayout>
#include <QLineEdit>

#include "desssergen/simple_filter.h"
#include "NamesTree.h"

#include "source/FilterEditor.h"

static bool const verbose { false };

FilterEditor::FilterEditor(QWidget *parent)
  : QWidget(parent)
{
  lhsEdit = new QLineEdit;
  lhsEdit->setPlaceholderText(tr("field name"));
  opEdit = new QComboBox;
  opEdit->addItem("=", "=");
  opEdit->addItem("≠", "!=");
  opEdit->addItem("<", "<");
  opEdit->addItem("≤", "<=");
  opEdit->addItem(">", ">");
  opEdit->addItem("≥", ">=");
  rhsEdit = new QLineEdit;
  rhsEdit->setPlaceholderText(tr("value"));

  QHBoxLayout *layout { new QHBoxLayout };
  layout->addWidget(lhsEdit);
  layout->addWidget(opEdit);
  layout->addWidget(rhsEdit);
  setLayout(layout);

  connect(lhsEdit, &QLineEdit::textChanged,
          this, &FilterEditor::inputChanged);
  connect(opEdit, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &FilterEditor::inputChanged);
  connect(rhsEdit, &QLineEdit::textChanged,
          this, &FilterEditor::inputChanged);
}

bool FilterEditor::isEmpty() const
{
  return lhsEdit->text().isEmpty() &&
         rhsEdit->text().isEmpty();
}

bool FilterEditor::hasValidInput() const
{
  return !lhsEdit->text().isEmpty() &&
         !rhsEdit->text().isEmpty();
}

void FilterEditor::setEnabled(bool enabled)
{
  lhsEdit->setEnabled(enabled);
  rhsEdit->setEnabled(enabled);
  opEdit->setEnabled(enabled);
}

void FilterEditor::setFunction(QModelIndex const &root)
{
  if (verbose)
    qDebug() << "FilterEditor: set new completer";

  if (completer) completer->deleteLater();
  completer =
    new NamesCompleter(NamesTree::globalNamesTreeAnySites, this, root);
  completer->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
  lhsEdit->setCompleter(completer);
}

bool FilterEditor::setValue(dessser::gen::simple_filter::t const &v)
{
  lhsEdit->setText(QString::fromStdString(v.lhs));
  rhsEdit->setText(QString::fromStdString(v.rhs));

  int opIndex { opEdit->findData(QString::fromStdString(v.op)) };
  if (opIndex < 0) {
    qCritical() << "FilterEditor: cannot find operator for"
                << QString::fromStdString(v.op);
    return false;
  }
  opEdit->setCurrentIndex(opIndex);

  return true;
}

std::shared_ptr<dessser::gen::simple_filter::t> FilterEditor::getValue() const
{
  return std::make_shared<dessser::gen::simple_filter::t>(
    lhsEdit->text().toStdString(),
    opEdit->currentData().toString().toStdString(),
    rhsEdit->text().toStdString());
}

void FilterEditor::clear()
{
  lhsEdit->clear();
  rhsEdit->clear();
  opEdit->setCurrentIndex(0);
}

// TODO: constant literal QString
static QString const opDescription(QString const &s)
{
  if (s == "=") return " is equal to ";
  if (s == "!=") return " is different than ";
  if (s == "<") return " is strictly less than ";
  if (s == "<=") return " is less than ";
  if (s == ">") return " is strictly greater than ";
  if (s == ">=") return " is greater than ";
  return s;  // ?
}

QString const FilterEditor::description(
  QString const &prefix, QString const &suffix)
{
  QString const lhs { lhsEdit->text() };
  QString const op { opEdit->currentData().toString() };
  QString const rhs { rhsEdit->text() };

  if (lhs.isEmpty() && rhs.isEmpty()) return QString();

  return
    prefix + (lhs.isEmpty() ? "…" : lhs)
           + opDescription(op)
           + (rhs.isEmpty() ? "…" : rhs) + suffix;
}
