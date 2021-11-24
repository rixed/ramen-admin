#include "AtomicWidget.h"
#include "desssergen/raql_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"

#include "KBool.h"
#include "KCharEditor.h"
#include "KFloatEditor.h"
#include "KIntEditor.h"
#include "KLabel.h"
#include "KLineEdit.h"
#include "KTextEdit.h"
#include "MakeSyncValue.h"
#include "SourceInfoViewer.h"
#include "TargetConfigEditor.h"
#include "TimeRangeViewer.h"
#include "WorkerViewer.h"

#include "EditorWidget.h"

/*
 * Return an editor widget for the given key/value:
 */

AtomicWidget *newEditorWidget(
  dessser::gen::sync_value::t const &v,
  std::shared_ptr<dessser::gen::sync_key::t const> k,
  QWidget *parent)
{
  static dessser::gen::sync_key::t const recall_cost {
    std::in_place_index<dessser::gen::sync_key::Storage>,
    std::in_place_index<dessser::gen::sync_key::RecallCost>,
    dessser::VOID };

  AtomicWidget *editor = nullptr;

  switch (v.index()) {
    case dessser::gen::sync_value::RamenValue:
      {
        std::shared_ptr<dessser::gen::raql_value::t const> rv {
          std::get<dessser::gen::sync_value::RamenValue>(v) };
        switch (rv->index()) {
          case dessser::gen::raql_value::VFloat:
            editor =
              k && *k == recall_cost ?
                new KFloatEditor(parent, 0., 1.) :
                new KFloatEditor(parent);
            break;
          case dessser::gen::raql_value::VString:
            editor =
              k && k->index() == dessser::gen::sync_key::Sources ?
                static_cast<AtomicWidget *>(new KTextEdit(parent)) :
                static_cast<AtomicWidget *>(new KLineEdit(parent));
            break;
          case dessser::gen::raql_value::VBool:
            editor = new KBool(parent);
            break;
          case dessser::gen::raql_value::VChar:
            editor = new KCharEditor(charOfQString, parent);
            break;
          case dessser::gen::raql_value::VU8:
            editor = new KIntEditor(u8OfQString, parent, 0,
                                    std::numeric_limits<uint8_t>::max());
            break;
          case dessser::gen::raql_value::VU16:
            editor = new KIntEditor(u16OfQString, parent, 0,
                                    std::numeric_limits<uint16_t>::max());
            break;
          case dessser::gen::raql_value::VU24:
            editor = new KIntEditor(u24OfQString, parent, 0, 16777216ULL);
            break;
          case dessser::gen::raql_value::VU32:
            editor = new KIntEditor(u32OfQString, parent, 0,
                                    std::numeric_limits<uint32_t>::max());
            break;
          case dessser::gen::raql_value::VU40:
            editor = new KIntEditor(u40OfQString, parent, 0, 1099511627776ULL);
            break;
          case dessser::gen::raql_value::VU48:
            editor = new KIntEditor(u48OfQString, parent, 0, 281474976710656ULL);
            break;
          case dessser::gen::raql_value::VU56:
            editor = new KIntEditor(u56OfQString, parent, 0, 72057594037927936ULL);
            break;
          case dessser::gen::raql_value::VU64:
            editor = new KIntEditor(u64OfQString, parent, 0,
                                    std::numeric_limits<uint64_t>::max());
            break;
          case dessser::gen::raql_value::VU128:
            editor = new KIntEditor(u128OfQString, parent, 0,
                                    std::numeric_limits<uint128_t>::max());
            break;
          case dessser::gen::raql_value::VI8:
            editor = new KIntEditor(i8OfQString, parent,
                                    std::numeric_limits<int8_t>::min(),
                                    std::numeric_limits<int8_t>::max());
            break;
          case dessser::gen::raql_value::VI16:
            editor = new KIntEditor(i16OfQString, parent,
                                    std::numeric_limits<int16_t>::min(),
                                    std::numeric_limits<int16_t>::max());
            break;
          case dessser::gen::raql_value::VI24:
            editor = new KIntEditor(i24OfQString, parent, -8388608LL, 8388607);
            break;
          case dessser::gen::raql_value::VI32:
            editor = new KIntEditor(i32OfQString, parent,
                                    std::numeric_limits<int32_t>::min(),
                                    std::numeric_limits<int32_t>::max());
            break;
          case dessser::gen::raql_value::VI40:
            editor = new KIntEditor(i40OfQString, parent, -549755813888LL, 549755813887LL);
            break;
          case dessser::gen::raql_value::VI48:
            editor = new KIntEditor(i48OfQString, parent,
                                    -140737488355328LL, 140737488355327LL);
            break;
          case dessser::gen::raql_value::VI56:
            editor = new KIntEditor(i56OfQString, parent,
                                    -36028797018963968LL, 36028797018963967LL);
            break;
          case dessser::gen::raql_value::VI64:
            editor = new KIntEditor(i64OfQString, parent,
                                    std::numeric_limits<int64_t>::min(),
                                    std::numeric_limits<int64_t>::max());
            break;
          case dessser::gen::raql_value::VI128:
            editor = new KIntEditor(i128OfQString, parent,
                                    std::numeric_limits<int128_t>::min(),
                                    std::numeric_limits<int128_t>::max());
            break;
          default:
            editor = new KLabel(parent);
            break;
        }
        break;
      }
    case dessser::gen::sync_value::Worker:
      editor = new WorkerViewer(parent);
      break;
    case dessser::gen::sync_value::TimeRange:
      editor = new TimeRangeViewer(parent);
      break;
    case dessser::gen::sync_value::SourceInfo:
      editor = new SourceInfoViewer(parent);
      break;
    case dessser::gen::sync_value::TargetConfig:
      editor = new TargetConfigEditor(parent);
      break;
#   if WITH_NON_PORTED_STUFF
    case dessser::gen::sync_value::RuntimeStats:
      editor = new RuntimeStatsViewer(parent);
      break;
    case dessser::gen::sync_value::DashboardWidget:
      {
        dessser::gen::dashboard_widget::t const *dash {
          std::get<dessser::gen::sync_value::DashboardWidget>(v) };
        switch (dash->index()) {
          case dessser::gen::dashboard_widget::Text:
            editor = new DashboardWidgetText(nullptr, parent);
            break;
          case dessser::gen::dashboard_widget::Chart:
            editor = new TimeChartEditWidget(nullptr, nullptr, parent);
            break;
          default:
            Q_ASSERT(false);
            break;
        } ;
        break;
      }
#   endif
    default:
      editor = new KLabel(parent);
      break;
  }

  if (editor && k) editor->setKey(k);
  return editor;
}
