#include <cassert>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <QtWidgets>
#include <QString>
extern "C" {
# include <caml/memory.h>
# include <caml/alloc.h>
# include <caml/custom.h>
}
#include "misc.h"
#include "RamenValue.h"
#include "RamenType.h"
#include "confValue.h"
#include "confWorkerRole.h"
#include "confWorkerRef.h"
#include "confRCEntryParam.h"
#include "TargetConfigEditor.h"
#include "TimeRangeViewer.h"
#include "RuntimeStatsViewer.h"
#include "WorkerViewer.h"
#include "SourceInfoViewer.h"
#include "KLabel.h"

static bool verbose = true;

namespace conf {

static QString const stringOfValueType(ValueType valueType)
{
  switch (valueType) {
    case ErrorType: return QString("ErrorType");
    case WorkerType: return QString("WorkerType");
    case RetentionType: return QString("RetentionType");
    case TimeRangeType: return QString("TimeRangeType");
    case TupleType: return QString("TupleType");
    case RamenValueType: return QString("RamenValueType");
    case TargetConfigType: return QString("TargetConfigType");
    case SourceInfoType: return QString("SourceInfoType");
    case RuntimeStatsType: return QString("RuntimeStatsType");
    case ReplayType: return QString("ReplayType");
    case ReplayerType: return QString("ReplayerType");
    case AlertType: return QString("AlertType");
  };
  assert(!"invalid valueType");
  return QString();
}

Value::Value(ValueType valueType_) : valueType(valueType_) {}

QString const Value::toQString(Key const &) const
{
  return QString("TODO: toQString for ") + stringOfValueType(valueType);
}

value Value::toOCamlValue() const
{
  assert(!"Don't know how to convert from a base Value");
}

AtomicWidget *Value::editorWidget(Key const &key, QWidget *parent) const
{
  KLabel *editor = new KLabel(parent);
  editor->setKey(key);
  return editor;
}

bool Value::operator==(Value const &other) const
{
  return valueType == other.valueType;
}

bool Value::operator!=(Value const &other) const
{
  return !operator==(other);
}

Value *valueOfOCaml(value v_)
{
  CAMLparam1(v_);
  CAMLlocal4(tmp1_, tmp2_, tmp3_, tmp4_);
  assert(Is_block(v_));
  ValueType valueType = (ValueType)Tag_val(v_);
  Value *ret = nullptr;
  switch (valueType) {
    case ErrorType:
      ret = new Error(
        Double_val(Field(v_, 0)),
        (unsigned)Int_val(Field(v_, 1)),
        String_val(Field(v_, 2)));
      break;
    case WorkerType:
      ret = new Worker(Field(v_, 0));
      break;
    case RetentionType:
      v_ = Field(v_, 0);
      assert(Tag_val(v_) == Double_array_tag);
      ret = new Retention(
        Double_field(v_, 0),
        Double_field(v_, 1));
      break;
    case TimeRangeType:
      ret = new TimeRange(Field(v_, 0));
      break;
    case TupleType:
      ret = new Tuple(
        // If the value is <0 it must have wrapped around in the OCaml side.
        Int_val(Field(v_, 0)),
        Bytes_val(Field(v_, 1)),
        caml_string_length(Field(v_, 1)));
      break;
    case RamenValueType:
      ret = new RamenValueValue(
        RamenValue::ofOCaml(Field(v_, 0)));
      break;
    case TargetConfigType:
      ret = new TargetConfig(Field(v_, 0));
      break;
    case SourceInfoType:
      ret = new SourceInfo(Field(v_, 0));
      break;
    case RuntimeStatsType:
      ret = new RuntimeStats(Field(v_, 0));
      break;
    case ReplayType:
      ret = new Replay(Field(v_, 0));
      break;
    case ReplayerType:
      ret = new Replayer(Field(v_, 0));
      break;
    case AlertType:
      ret = new Alert(Field(v_, 0));
  }
  if (! ret) {
    assert(!"Tag_val(v_) <= AlertType");
  }
  CAMLreturnT(Value *, ret);
}

Value *valueOfQString(ValueType vt, QString const &s)
{
  bool ok = true;
  Value *ret = nullptr;
  switch (vt) {
    case ErrorType:
    case WorkerType:
    case RetentionType:
    case TimeRangeType:
    case TupleType:
    case TargetConfigType:
    case SourceInfoType:
    case RuntimeStatsType:
    case ReplayType:
    case ReplayerType:
    case AlertType:
      assert(!"TODO: valueOfQString for exotic types");
      break;
    case RamenValueType:
      assert(!"Cannot convert to RamenValue without a RamenType");
  }
  if (! ret)
    assert(!"Tag_val(v_) <= AlertType");
  if (! ok)
    std::cerr << "Cannot convert " << s.toStdString() << " into a value" << std::endl;
  return ret;
}

QString const Error::toQString(Key const &) const
{
  return
    stringOfDate(time) + QString(": #") + QString::number(cmdId) + QString(": ") +
    (msg.length() > 0 ? QString::fromStdString(msg) : QString("Ok"));
}

value Error::toOCamlValue() const
{
  assert(!"Don't know how to convert from an Error");
}

bool Error::operator==(Value const &other) const
{
  if (! Value::operator==(other)) return false;
  Error const &o = static_cast<Error const &>(other);
  return cmdId == o.cmdId;
}

Worker::Worker(value v_) : Value(WorkerType)
{
  assert(Wosize_val(v_) == 12);
  enabled = Bool_val(Field(v_, 0));
  debug = Bool_val(Field(v_, 1));
  reportPeriod = Double_val(Field(v_, 2));
  srcPath = String_val(Field(v_, 3));
  workerSign = String_val(Field(v_, 4));
  binSign = String_val(Field(v_, 5));
  used = Bool_val(Field(v_, 6));
  role = WorkerRole::ofOCamlValue(Field(v_, 9));
  // Add the params:
  for (value cons_ = Field(v_, 7); Is_block(cons_); cons_ = Field(cons_, 1)) {
    value p_ = Field(cons_, 0);
    RCEntryParam *p = new RCEntryParam(
      String_val(Field(p_, 0)), // name
      std::shared_ptr<RamenValue const>(RamenValue::ofOCaml(Field(p_, 1))));
    params.push_back(p);
  }
  // Add the parents:
  for (value cons_ = Field(v_, 10); Is_block(cons_); cons_ = Field(cons_, 1)) {
    WorkerRef *p = WorkerRef::ofOCamlValue(Field(cons_, 0));
    parent_refs.push_back(p);
  }
  // TODO: add everything else
}

Worker::~Worker()
{
  if (role) delete role;
  for (auto p : parent_refs) {
    delete p;
  }
}

bool Worker::operator==(Value const &other) const
{
  if (! Value::operator==(other)) return false;
  Worker const &o = static_cast<Worker const &>(other);
  return enabled == o.enabled && debug == o.debug && reportPeriod == o.reportPeriod && srcPath == o.srcPath && workerSign == o.workerSign && binSign == o.binSign && used == o.used && role == o.role;
}

QString const Worker::toQString(Key const &) const
{
  QString s;
  s += QString("Status: ") + (enabled ? QString("enabled") : QString("disabled"));
  s += QString(", Role: ") + role->toQString();
  s += QString(", Source: ") + srcPath;
  return s;
}

AtomicWidget *Worker::editorWidget(Key const &key, QWidget *parent) const
{
  WorkerViewer *editor = new WorkerViewer(parent);
  editor->setKey(key);
  return editor;
}

Retention::Retention(double duration_, double period_) :
  Value(RetentionType), duration(duration_), period(period_) {}

Retention::Retention() : Retention(0., 0.) {}

bool Retention::operator==(Value const &other) const
{
  if (! Value::operator==(other)) return false;
  Retention const &o = static_cast<Retention const &>(other);
  return duration == o.duration && period == o.period;
}

QString const Retention::toQString(Key const &) const
{
  return QString("for ").append(stringOfDuration(duration)).
         append(", every ").append(stringOfDuration(period));
}

value Retention::toOCamlValue() const
{
  assert(!"Don't know how to convert form a Retention");
}

TimeRange::TimeRange(value v_) : Value(TimeRangeType)
{
  while (Is_block(v_)) {
    range.emplace_back(Double_val(Field(Field(v_, 0), 0)),
                       Double_val(Field(Field(v_, 0), 1)),
                       Bool_val(Field(Field(v_, 0), 2)));
    v_ = Field(v_, 1);
  }
}

QString const TimeRange::toQString(Key const &) const
{
  if (0 == range.size()) return QString("empty");

  double duration = 0;
  for (auto p : range) duration += p.t2 - p.t1;

  double const since = range[0].t1;
  double const until = range[range.size()-1].t2;
  bool const openEnded = range[range.size()-1].openEnded;

  QString s = stringOfDuration(duration);
  s += QString(" since ")
     + stringOfDate(since)
     + QString(" until ")
     + (openEnded ? QString("at least ") : QString(""))
     + stringOfDate(until);
  return s;
}

value TimeRange::toOCamlValue() const
{
  assert(!"Don't know how to convert from a TimeRange");
}

AtomicWidget *TimeRange::editorWidget(Key const &key, QWidget *parent) const
{
  TimeRangeViewer *editor = new TimeRangeViewer(parent);
  editor->setKey(key);
  return editor;
}

bool TimeRange::operator==(Value const &other) const
{
  if (! Value::operator==(other)) return false;
  TimeRange const &o = static_cast<TimeRange const &>(other);
  return range == o.range;
}

Tuple::Tuple(unsigned skipped_, unsigned char const *bytes_, size_t size) :
  Value(TupleType), skipped(skipped_), num_words(size / 4)
{
  assert(0 == (size & 3));
  if (verbose)
    std::cout << "New tuple of " << num_words << " words" << std::endl;
  if (bytes_) {
    bytes = new uint32_t[num_words];
    memcpy((void *)bytes, (void *)bytes_, size);
  } else {
    assert(size == 0);
    bytes = nullptr;
  }
}

Tuple::Tuple() : Tuple(0, nullptr, 0) {}

Tuple::~Tuple()
{
  if (bytes) delete[](bytes);
}

QString const Tuple::toQString(Key const &) const
{
  return QString::number(num_words) + QString(" words");
}

RamenValue *Tuple::unserialize(std::shared_ptr<RamenType const> type) const
{
  uint32_t const *start = bytes;
  uint32_t const *max = bytes + num_words;
  RamenValue *v = type->structure->unserialize(start, max, true);
  assert(start == max);
  return v;
}

value Tuple::toOCamlValue() const
{
  assert(!"Don't know how to convert from an Tuple");
}

bool Tuple::operator==(Value const &other) const
{
  if (! Value::operator==(other)) return false;
  Tuple const &o = static_cast<Tuple const &>(other);
  return num_words == o.num_words &&
         0 == memcmp(bytes, o.bytes, num_words * sizeof(uint32_t));
}

// This _does_ alloc on the OCaml heap
value RamenValueValue::toOCamlValue() const
{
  CAMLparam0();
  CAMLlocal1(ret);
  checkInOCamlThread();
  ret = caml_alloc(1, RamenValueType);
  Store_field(ret, 0, v->toOCamlValue());
  CAMLreturn(ret);
}

AtomicWidget *RamenValueValue::editorWidget(Key const &key, QWidget *parent) const
{
  return v->editorWidget(key, parent);
}

bool RamenValueValue::operator==(Value const &other) const
{
  if (! Value::operator==(other)) return false;
  RamenValueValue const &o = static_cast<RamenValueValue const &>(other);
  return *v == *o.v;
}

SourceInfo::SourceInfo(value v_)
{
  md5 = String_val(Field(v_, 0));
  v_ = Field(v_, 1);
  switch (Tag_val(v_)) {
    case 0: // CompiledSourceInfo
      {
        v_ = Field(v_, 0);

        // Iter over the cons cells of the RamenTuple.params:
        params.reserve(10);
        for (value cons_ = Field(v_, 0); Is_block(cons_); cons_ = Field(cons_, 1)) {
          value param_ = Field(cons_, 0);  // the RamenTuple.param
          params.emplace_back(param_);
        }
        // Iter over the cons cells of the function_info:
        infos.reserve(10);
        for (value cons_ = Field(v_, 2); Is_block(cons_); cons_ = Field(cons_, 1)) {
          value func_ = Field(cons_, 0);  // the function_info
          infos.emplace_back(func_);
        }
        if (verbose)
          std::cout << "info is a program with " << params.size() << " params"
                    << " and " << infos.size() << " functions" << std::endl;
      }
      break;
    case 1: // FailedSourceInfo
      {
        v_ = Field(v_, 0);
        assert(1 == Wosize_val(v_)); // only err_msg
        assert(Tag_val(Field(v_, 0)) == String_tag);
        errMsg = QString(String_val(Field(v_, 0)));
        if (verbose)
          std::cout << "info is compil failure: '" << errMsg.toStdString()
                    << "'" << std::endl;
      }
      break;
    default:
      assert(!"Not a detail_source_info?!");
  }
}

bool SourceInfo::operator==(Value const &other) const
{
  if (! Value::operator==(other)) return false;
  SourceInfo const &o = static_cast<SourceInfo const &>(other);
  if (md5 != o.md5) return false;
  if (isInfo()) {
    return o.isInfo(); // in theory, compare params
  } else {
    return !o.isInfo() && errMsg == o.errMsg;
  }
}

QString const SourceInfo::toQString(Key const &) const
{
  if (errMsg.length() > 0) return errMsg;

  QString s("");
  for (auto &info : infos) {
    if (s.length() > 0) s += QString(", ");
    s += info.name;
  }

  return QString("Compiled functions: ") + s;
}

AtomicWidget *SourceInfo::editorWidget(Key const &key, QWidget *parent) const
{
  SourceInfoViewer *editor = new SourceInfoViewer(parent);
  editor->setKey(key);
  return editor;
}

TargetConfig::TargetConfig(value v_)
{
  // Iter over the cons cells:
  while (Is_block(v_)) {
    value pair = Field(v_, 0);  // the pname * rc_entry pair

    assert(Is_block(pair));
    value rce_ = Field(pair, 1);  // the rc_entry
    assert(Is_block(rce_));
    assert(Is_block(Field(pair, 0)));
    RCEntry *rcEntry = new RCEntry(
      String_val(Field(pair, 0)),  // pname
      Bool_val(Field(rce_, 0)),  // enabled
      Bool_val(Field(rce_, 1)),  // debug
      Double_val(Field(rce_, 2)),  // report_period
      String_val(Field(rce_, 4)),  // src_file
      String_val(Field(rce_, 5)),  // on_site (as a string)
      Bool_val(Field(rce_, 6)));  // automatic
    for (value params_ = Field(rce_, 3); Is_block(params_); params_ = Field(params_, 1)) {
      value param_ = Field(params_, 0);  // the name * value
      RCEntryParam *param = new RCEntryParam(
        String_val(Field(param_, 0)),  // name
        std::shared_ptr<RamenValue const>(RamenValue::ofOCaml(Field(param_, 1)))); // value
      rcEntry->addParam(param);
    }
    addEntry(rcEntry);

    v_ = Field(v_, 1);
  }
}

TargetConfig::~TargetConfig()
{
  for (auto entry : entries) {
    delete entry.second;
  }
}

// This _does_ alloc on the OCaml heap
value TargetConfig::toOCamlValue() const
{
  CAMLparam0();
  CAMLlocal4(ret, lst, cons, pair);
  checkInOCamlThread();
  // Then a list of program_name * rc_enrtry:
  lst = Val_emptylist;  // Ala Val_int(0)
  for (auto const it : entries) {
    RCEntry const *entry = it.second;
    pair = caml_alloc_tuple(2);
    Store_field(pair, 0, caml_copy_string(it.first.c_str()));
    Store_field(pair, 1, entry->toOCamlValue());
    cons = caml_alloc(2, Tag_cons);
    Store_field(cons, 1, lst);
    Store_field(cons, 0, pair);
    lst = cons;
  }
  ret = caml_alloc(1, TargetConfigType);
  Store_field(ret, 0, lst);
  CAMLreturn(ret);
}

AtomicWidget *TargetConfig::editorWidget(Key const &key, QWidget *parent) const
{
  TargetConfigEditor *editor = new TargetConfigEditor(parent);
  editor->setKey(key);
  return editor;
}

bool TargetConfig::operator==(Value const &other) const
{
  if (! Value::operator==(other)) return false;
  TargetConfig const &o = static_cast<TargetConfig const &>(other);

  /* To compare the map by RCEntry values (rather than pointer equality)
   * we have to reimplement map comparison here.
   * First, check there is no more keys in other.entries: */
  if (o.entries.size() != entries.size()) return false;

  /* Then, check that all our keys are present with the same value
   * in other: */
  for (auto mapEntry : entries) {
    auto other_entry_it = o.entries.find(mapEntry.first);
    if (other_entry_it == o.entries.end()) return false;
    RCEntry const *other_entry = other_entry_it->second;
    if (*other_entry != *mapEntry.second) return false;
  }

  return true;
}

QString const TargetConfig::toQString(Key const &) const
{
  if (0 == entries.size()) return QString("empty");
  QString s;
  for (auto rce : entries) {
    if (s.length() > 0) s += QString("\n");
    s += QString::fromStdString(rce.second->source);
    s += QString(" as ") + QString::fromStdString(rce.first);
    s += QString(" on ") + QString::fromStdString(rce.second->onSite);
  }
  return s;
}

RuntimeStats::RuntimeStats(value v_) : Value(RuntimeStatsType)
{
# define Uint64_val(x) *(uint64_t *)Data_custom_val(x)
  assert(24 == Wosize_val(v_));
  statsTime = Double_val(Field(v_, 0));
  firstStartup = Double_val(Field(v_, 1));
  lastStartup = Double_val(Field(v_, 2));
  minEventTime = Is_block(Field(v_, 3)) ?
    std::optional<double>(Double_val(Field(Field(v_, 3), 0))) :
    std::optional<double>(),
  maxEventTime = Is_block(Field(v_, 4)) ?
    std::optional<double>(Double_val(Field(Field(v_, 4), 0))) :
    std::optional<double>(),
  firstInput = Is_block(Field(v_, 5)) ?
    std::optional<double>(Double_val(Field(Field(v_, 5), 0))) :
    std::optional<double>(),
  lastInput = Is_block(Field(v_, 6)) ?
    std::optional<double>(Double_val(Field(Field(v_, 6), 0))) :
    std::optional<double>(),
  firstOutput = Is_block(Field(v_, 7)) ?
    std::optional<double>(Double_val(Field(Field(v_, 7), 0))) :
    std::optional<double>(),
  lastOutput = Is_block(Field(v_, 8)) ?
    std::optional<double>(Double_val(Field(Field(v_, 8), 0))) :
    std::optional<double>(),
  totInputTuples = Uint64_val(Field(v_, 9));
  totSelectedTuples = Uint64_val(Field(v_, 10));
  totOutputTuples = Uint64_val(Field(v_, 11));
  totFullBytes = Uint64_val(Field(v_, 12));
  totFullBytesSamples = Uint64_val(Field(v_, 13));
  curGroups = Uint64_val(Field(v_, 14));
  totInputBytes = Uint64_val(Field(v_, 15));
  totOutputBytes = Uint64_val(Field(v_, 16));
  totWaitIn = Double_val(Field(v_, 17));
  totWaitOut = Double_val(Field(v_, 18));
  totFiringNotifs = Uint64_val(Field(v_, 19));
  totExtinguishedNotifs = Uint64_val(Field(v_, 20));
  totCpu = Double_val(Field(v_, 21));
  curRam = Uint64_val(Field(v_, 22));
  maxRam = Uint64_val(Field(v_, 23));
}

QString const RuntimeStats::toQString(Key const &) const
{
  QString s("Stats-time: ");
  s += stringOfDate(statsTime);
  if (maxEventTime)
    s += QString(", front-time: ") + stringOfDate(*maxEventTime);
  return s;
}

AtomicWidget *RuntimeStats::editorWidget(Key const &key, QWidget *parent) const
{
  RuntimeStatsViewer *editor = new RuntimeStatsViewer(parent);
  editor->setKey(key);
  return editor;
}

SiteFq::SiteFq(value v_)
{
  assert(2 == Wosize_val(v_));
  site = String_val(Field(v_, 0));
  fq = String_val(Field(v_, 1));
}

Replay::Replay(value v_) :
  Value(ReplayType)
{
  assert(9 == Wosize_val(v_));
  channel = Long_val(Field(v_, 0));
  target = SiteFq(Field(v_, 1));
  since = Double_val(Field(v_, 3));
  until = Double_val(Field(v_, 4));
  final_ringbuf_file = String_val(Field(v_, 5));
  for (value src_ = Field(v_, 6); Is_block(src_); src_ = Field(src_, 1)) {
    sources.emplace_back(SiteFq(Field(src_, 0)));
  }
  for (value src_ = Field(v_, 7); Is_block(src_); src_ = Field(src_, 1)) {
    links.emplace_back(
      SiteFq(Field(Field(src_, 0), 0)),
      SiteFq(Field(Field(src_, 0), 1)));
  }
  timeout_date = Double_val(Field(v_, 8));
}

QString const Replay::toQString(Key const &) const
{
  QString s("Channel: ");
  s += QString::number(channel);
  s += QString(", to ") + target.toQString();
  s += QString(", since ") + stringOfDate(since);
  s += QString(", until +") + stringOfDuration(until - since);
  s += QString(", involving ") + QString::number(links.size()) + QString(" links.");
  return s;
}

Replayer::Replayer(value v_) : Value(ReplayerType)
{
  assert(6 == Wosize_val(v_));
  // wtv, not used anywhere in the GUI for now
}

Alert::Alert(value v_) : Value(AlertType)
{
  assert(1 == Wosize_val(v_)); // v1
  // wtv, not used anywhere in the GUI for now
}

std::ostream &operator<<(std::ostream &os, Value const &v)
{
  os << v.toQString(Key::null).toStdString();
  return os;
}

};
