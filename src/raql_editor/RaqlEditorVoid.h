#ifndef RAQL_EDITOR_VOID_H_211124
#define RAQL_EDITOR_VOID_H_211124
/* Editor for a raql_value of type Void */
#include "AtomicWidget.h"

class RaqlEditorVoid : public AtomicWidget
{
  Q_OBJECT

public:
  RaqlEditorVoid(QWidget *parent = nullptr);

  std::shared_ptr<dessser::gen::sync_value::t const> getValue() const;
  void setEnabled(bool);

public slots:
  bool setValue(
    std::shared_ptr<dessser::gen::sync_key::t const>,
    std::shared_ptr<dessser::gen::sync_value::t const>);
};

#endif
