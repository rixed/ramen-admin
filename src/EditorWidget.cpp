// vim: sw=2 ts=2 sts=2 expandtab tw=80
#include "EditorWidget.h"

#include <QDebug>

#include "AtomicWidget.h"
#include "KArrEditor.h"
#include "KBoolEditor.h"
#include "KCharEditor.h"
#include "KCidrEditor.h"
#include "KFloatEditor.h"
#include "KIntEditor.h"
#include "KIpEditor.h"
#include "KLabel.h"
#include "KLineEdit.h"
#include "KNullableEditor.h"
#include "KRecEditor.h"
#include "KTextEdit.h"
#include "KTupEditor.h"
#include "KVecEditor.h"
#include "KVoidEditor.h"
#include "MakeSyncValue.h"
#include "RuntimeStatsViewer.h"
#include "TargetConfigEditor.h"
#include "TimeRangeViewer.h"
#include "WorkerViewer.h"
#include "chart/TimeChartEditWidget.h"
#include "dashboard/DashboardWidgetText.h"
#include "desssergen/raql_type.h"
#include "desssergen/raql_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "misc_dessser.h"
#include "source/SourceInfoViewer.h"

/*
 * Returns an editor widget for the desired raql type:
 * Compared to newEditorWidget, those AtomicWidget has no associated key.
 */

AtomicWidget *newRaqlValueEditorWidget(dessser::gen::raql_type::t const &t,
                                       QWidget *parent) {
  using namespace dessser::gen::raql_type;
  AtomicWidget *editor = nullptr;
  switch (t.type->index()) {
    case Void:
      editor = new KVoidEditor(parent);
      break;
    case Bool:
      editor = new KBoolEditor(parent);
      break;
    case Char:
      editor = new KCharEditor(charOfQString, parent);
      break;
    case Float:
      editor = new KFloatEditor(parent);
      break;
    case String:
      editor = new KLineEdit(parent);
      break;
    case U8:
      editor = new KIntEditor(u8OfQString, parent, 0,
                              std::numeric_limits<uint8_t>::max());
      break;
    case U16:
      editor = new KIntEditor(u16OfQString, parent, 0,
                              std::numeric_limits<uint16_t>::max());
      break;
    case U24:
      editor = new KIntEditor(u24OfQString, parent, 0, 16777216ULL);
      break;
    case U32:
      editor = new KIntEditor(u32OfQString, parent, 0,
                              std::numeric_limits<uint32_t>::max());
      break;
    case U40:
      editor = new KIntEditor(u40OfQString, parent, 0, 1099511627776ULL);
      break;
    case U48:
      editor = new KIntEditor(u48OfQString, parent, 0, 281474976710656ULL);
      break;
    case U56:
      editor = new KIntEditor(u56OfQString, parent, 0, 72057594037927936ULL);
      break;
    case U64:
      editor = new KIntEditor(u64OfQString, parent, 0,
                              std::numeric_limits<uint64_t>::max());
      break;
    case U128:
      editor = new KIntEditor(u128OfQString, parent, 0,
                              std::numeric_limits<uint128_t>::max());
      break;
    case I8:
      editor = new KIntEditor(i8OfQString, parent,
                              std::numeric_limits<int8_t>::min(),
                              std::numeric_limits<int8_t>::max());
      break;
    case I16:
      editor = new KIntEditor(i16OfQString, parent,
                              std::numeric_limits<int16_t>::min(),
                              std::numeric_limits<int16_t>::max());
      break;
    case I24:
      editor = new KIntEditor(i24OfQString, parent, -8388608LL, 8388607);
      break;
    case I32:
      editor = new KIntEditor(i32OfQString, parent,
                              std::numeric_limits<int32_t>::min(),
                              std::numeric_limits<int32_t>::max());
      break;
    case I40:
      editor =
          new KIntEditor(i40OfQString, parent, -549755813888LL, 549755813887LL);
      break;
    case I48:
      editor = new KIntEditor(i48OfQString, parent, -140737488355328LL,
                              140737488355327LL);
      break;
    case I56:
      editor = new KIntEditor(i56OfQString, parent, -36028797018963968LL,
                              36028797018963967LL);
      break;
    case I64:
      editor = new KIntEditor(i64OfQString, parent,
                              std::numeric_limits<int64_t>::min(),
                              std::numeric_limits<int64_t>::max());
      break;
    case I128:
      editor = new KIntEditor(i128OfQString, parent,
                              std::numeric_limits<int128_t>::min(),
                              std::numeric_limits<int128_t>::max());
      break;
    case Ip:
      editor = new KIpEditor(parent);
      break;
    case Cidr:
      editor = new KCidrEditor(parent);
      break;
    /* Compound types: */
    case Tup:
      editor = new KTupEditor(std::get<Tup>(*t.type), parent);
      break;
    case Vec: {
      auto const &vec{std::get<Vec>(*t.type)};
      editor = new KVecEditor(std::get<0>(vec), *std::get<1>(vec), parent);
    } break;
    case Arr:
      editor = new KArrEditor(std::get<Arr>(*t.type), parent);
      break;
    case Rec:
      editor = new KRecEditor(std::get<Rec>(*t.type), parent);
      break;

    default:
      qCritical()
          << "Not implemented: newRaqlValueEditorWidget for raql_type::base"
          << *t.type;
  }

  if (t.nullable) editor = new KNullableEditor(editor);

  return editor;
}

/*
 * Return an editor widget for the given key/value:
 */

AtomicWidget *newEditorWidget(
    dessser::gen::sync_value::t const &v,
    std::shared_ptr<dessser::gen::sync_key::t const> k, QWidget *parent) {
  static dessser::gen::sync_key::t const recall_cost{
      std::in_place_index<dessser::gen::sync_key::Storage>,
      std::in_place_index<dessser::gen::sync_key::RecallCost>, dessser::Void()};

  AtomicWidget *editor = nullptr;

  switch (v.index()) {
    case dessser::gen::sync_value::RamenValue: {
      std::shared_ptr<dessser::gen::raql_value::t const> rv{
          std::get<dessser::gen::sync_value::RamenValue>(v)};
      switch (rv->index()) {
        case dessser::gen::raql_value::VFloat:
          editor = k && *k == recall_cost ? new KFloatEditor(parent, 0., 1.)
                                          : new KFloatEditor(parent);
          break;
        case dessser::gen::raql_value::VString:
          editor = k && k->index() == dessser::gen::sync_key::Sources
                       ? static_cast<AtomicWidget *>(new KTextEdit(parent))
                       : static_cast<AtomicWidget *>(new KLineEdit(parent));
          break;
        case dessser::gen::raql_value::VBool:
          editor = new KBoolEditor(parent);
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
          editor =
              new KIntEditor(u56OfQString, parent, 0, 72057594037927936ULL);
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
          editor = new KIntEditor(i40OfQString, parent, -549755813888LL,
                                  549755813887LL);
          break;
        case dessser::gen::raql_value::VI48:
          editor = new KIntEditor(i48OfQString, parent, -140737488355328LL,
                                  140737488355327LL);
          break;
        case dessser::gen::raql_value::VI56:
          editor = new KIntEditor(i56OfQString, parent, -36028797018963968LL,
                                  36028797018963967LL);
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
    case dessser::gen::sync_value::RuntimeStats:
      editor = new RuntimeStatsViewer(parent);
      break;
    case dessser::gen::sync_value::DashboardWidget: {
      std::shared_ptr<dessser::gen::dashboard_widget::t const> dash{
          std::get<dessser::gen::sync_value::DashboardWidget>(v)};
      switch (dash->index()) {
        case dessser::gen::dashboard_widget::Text:
          editor = new DashboardWidgetText(nullptr, parent);
          break;
        case dessser::gen::dashboard_widget::Chart:
          editor = new TimeChartEditWidget(nullptr, nullptr, nullptr, parent);
          break;
        default:
          qFatal("newEditorWidget: invalid dash->index()");
          break;
      };
      break;
    }
    default:
      editor = new KLabel(parent);
      break;
  }

  if (editor && k) {
    editor->setKey(k);
    editor->setValueFromStore();
  }
  return editor;
}
