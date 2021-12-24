#include <algorithm>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolBox>
#include <QVBoxLayout>

#include "desssergen/dashboard_widget.h"
#include "chart/TimeChartFunctionEditor.h"
#include "chart/TimeChartFunctionFieldsModel.h"
#include "FunctionItem.h"
#include "FunctionSelector.h"
#include "GraphModel.h"
#include "misc_dessser.h"

#include "chart/TimeChartFunctionsEditor.h"

static bool const verbose { false };

TimeChartFunctionsEditor::TimeChartFunctionsEditor(QWidget *parent)
  : QWidget(parent)
{
  functions = new QToolBox(this);
  functions->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);

  // TODO: a globalGraphModelWithoutTopHalves
  GraphModel *graph { GraphModel::globalGraphModel };
  functionSelector = new FunctionSelector(graph);
  QPushButton *addButton = new QPushButton(tr("Add"));
  connect(addButton, &QPushButton::clicked,
          this, &TimeChartFunctionsEditor::addCurrentFunction);

  QHBoxLayout *fsLayout = new QHBoxLayout;
  fsLayout->addWidget(functionSelector, 1);
  fsLayout->addWidget(addButton, 0);
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(functions);
  layout->addLayout(fsLayout);
  setLayout(layout);
}

bool TimeChartFunctionsEditor::setValue(
  dessser::gen::dashboard_widget::chart const &v)
{
  if (verbose)
    qDebug() << "TimeChartFunctionsEditor::setValue with" << v.sources.size()
             << "sources and" << v.axes.size() << "axes";

  /* We want the function list to be ordered by FQ name, but the sources in [v]
   * come in no particular order, so let's start by ordering them: */
  std::vector<std::shared_ptr<dessser::gen::dashboard_widget::source>> ordered_sources {
    v.sources };
  std::sort(
    ordered_sources.begin(), ordered_sources.end(),
    [](std::shared_ptr<dessser::gen::dashboard_widget::source> const &a,
       std::shared_ptr<dessser::gen::dashboard_widget::source> const &b)
    {
      int const c1 { a->name->site.compare(b->name->site) };
      if (c1 < 0) return true;
      if (c1 > 0) return false;
      int const c2 { a->name->program.compare(b->name->program) };
      if (c2 < 0) return true;
      if (c2 > 0) return false;
      int const c3 { a->name->function.compare(b->name->function) };
      return c3 <= 0;
    });

  size_t v_i { 0 }; // index in v.sources
  int t_i { 0 }; // index in items
  for (;
    v_i < ordered_sources.size() || t_i < functions->count();
    v_i++, t_i++
  ) {
    if (v_i >= ordered_sources.size()) {
remove_function:
      if (verbose)
        qDebug()
          << "TimeChartFunctionsEditor::setValue: extra function" << t_i << "is gone";
      allFieldsChanged(t_i);
      functions->removeItem(t_i--);
    } else if (t_i >= functions->count()) {
      std::shared_ptr<dessser::gen::dashboard_widget::source const> src {
        ordered_sources[v_i] };
      if (verbose)
        qDebug()
          << "TimeChartFunctionsEditor::setValue: appending new function at" << t_i
          << "for" << QString::fromStdString(src->name->function);
      TimeChartFunctionEditor *e {
        addFunctionByName(src->name->site, src->name->program, src->name->function, true) };
      e->setValue(*src);
      functions->addItem(e, QString::fromStdString(siteFqName(*src->name)));
    } else {
      QString const name_i {
        QString::fromStdString(siteFqName(*ordered_sources[v_i]->name)) };
      int const c { name_i.compare(functions->itemText(t_i)) };
      if (c == 0) {
        if (verbose)
          qDebug() << "TimeChartFunctionsEditor::setValue: updating function" << t_i;
        TimeChartFunctionEditor *e {
          static_cast<TimeChartFunctionEditor *>(functions->widget(t_i)) };
        e->setValue(*ordered_sources[v_i]);
      } else if (c < 0) {
        // v->source comes first
        std::shared_ptr<dessser::gen::dashboard_widget::source const> src {
          ordered_sources[v_i] };
        if (verbose)
          qDebug()
            << "TimeChartFunctionsEditor::setValue: inserting function at" << t_i
            << "for" << QString::fromStdString(src->name->function);
        TimeChartFunctionEditor *e {
          addFunctionByName(src->name->site, src->name->program, src->name->function, true) };
        e->setValue(*src);
        (void)functions->insertItem(t_i, e, name_i);
      } else if (c > 0) {
        /* The current function is no more: */
        v_i--;
        goto remove_function; // will decrement t_i
      }
    }
  }

  return true;
}

void TimeChartFunctionsEditor::setEnabled(bool enabled)
{
  functions->setEnabled(enabled);
  functionSelector->setEnabled(enabled);
}

void TimeChartFunctionsEditor::allFieldsChanged(int tab_idx)
{
  TimeChartFunctionEditor *e {
    static_cast<TimeChartFunctionEditor *>(functions->widget(tab_idx)) };
  dessser::gen::dashboard_widget::source const &source { e->model->source };
  for (std::shared_ptr<dessser::gen::dashboard_widget::field> const &field : source.fields) {
    if (verbose)
      qDebug() << "TimeChartFunctionsEditor::allFieldsChanged for column" << field->column;
    emit fieldChanged(source.name->site, source.name->program,
                      source.name->function, field->column);
  }
}

void TimeChartFunctionsEditor::addCurrentFunction()
{
  FunctionItem *f { functionSelector->getCurrent() };
  if (! f) {
    qDebug() << "Must select a function";
    return;
  }

  std::shared_ptr<Function> function {
    std::dynamic_pointer_cast<Function>(f->shared) };
  if (! function) {
    qWarning() << "No such function";
    return;
  }

  addOrFocus(
    function->siteName,
    function->programName,
    function->name.toStdString(),
    true);
}

void TimeChartFunctionsEditor::addOrFocus(
  std::string const &site,
  std::string const &program,
  std::string const &function,
  bool customizable)
{
  QString const fqName {
    QString::fromStdString(site) + ":" +
    QString::fromStdString(program) + "/" +
    QString::fromStdString(function) };

  int t_i;
  for (t_i = 0; t_i < functions->count(); t_i++) {
    int const c(fqName.compare(functions->itemText(t_i)));
    if (c == 0) {
      /* If this function is already in the list, just focus it: */
      functions->setCurrentIndex(t_i);
      return;
    } else if (c < 0) {
      break;
    }
  }

  /* Create a new function editor */
  if (verbose)
    qDebug() << "Insert new function at index" << t_i;

  TimeChartFunctionEditor *e {
    addFunctionByName(site, program, function, customizable) };
  dessser::gen::dashboard_widget::source defaultSrc {
    std::make_shared<dessser::gen::fq_function_name::t>(site, program, function),
    true,  // visible
    {} // fields
  };
  e->setValue(defaultSrc);
  (void)functions->insertItem(t_i, e, fqName);
  functions->setCurrentIndex(t_i);
}

TimeChartFunctionEditor *TimeChartFunctionsEditor::addFunctionByName(
  std::string const &site,
  std::string const &program,
  std::string const &function,
  bool customizable)
{
  std::shared_ptr<Function const> const f {
    Function::find(
      QString::fromStdString(site),
      QString::fromStdString(program),
      QString::fromStdString(function)) };

  if (! f) {
    qCritical() << "Customized function does not exist yet!";
    return nullptr;
  }

  if (verbose)
    qDebug().nospace()
      << "TimeChartFunctionsEditor: adding function "
      << f->siteName << ':' << f->fqName;

  TimeChartFunctionEditor *e {
    new TimeChartFunctionEditor(site, program, function, customizable) };

  connect(e, &TimeChartFunctionEditor::fieldChanged,
          this, &TimeChartFunctionsEditor::fieldChanged);

  if (customizable) {
    connect(e, &TimeChartFunctionEditor::customizedFunction,
            this, &TimeChartFunctionsEditor::addCustomizedFunction);
  }

  return e;
}

void TimeChartFunctionsEditor::addCustomizedFunction(
  std::string const &site,
  std::string const &program,
  std::string const &function)
{
  if (verbose)
    qDebug() << "TimeChartFunctionsEditor: adding a customized function";
  addOrFocus(site, program, function, false);
}
