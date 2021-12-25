#ifndef KCHAREDITOR_H_191029
#define KCHAREDITOR_H_191029
/* TODO: a char selector would be nicer */
#include "KIntEditor.h"

class KCharEditor : public KIntEditor {
 public:
  KCharEditor(std::function<
                  std::shared_ptr<dessser::gen::sync_value::t>(QString const &)>
                  v,
              QWidget *parent = nullptr)
      : KIntEditor(v, parent, std::numeric_limits<char>::min(),
                   std::numeric_limits<char>::max()) {}
};

#endif
