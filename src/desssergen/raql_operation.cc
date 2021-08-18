#include <algorithm>
#include <arpa/inet.h>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <random>
#include <tuple>
#include <utility>
#include <variant>
#include <vector>
#include "dessser/runtime.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_net_protocol.h"
#include "desssergen/field_name.h"
#include "desssergen/event_time.h"
#include "desssergen/field_type.h"
#include "desssergen/field_type.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_expr.h"
#include "desssergen/function_name.h"
#include "desssergen/raql_flush_method.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/event_time.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/raql_expr.h"
#include "desssergen/field_name.h"
#include "desssergen/raql_select_field.h"


namespace dessser::gen::raql_operation {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct tf0c8d4f3070907529cc1a83f8baf6fab : public std::tuple<
  uint32_t,
  std::optional<dessser::gen::raql_expr::t_ext>,
  Lst<dessser::gen::raql_expr::t_ext>
> { using tuple::tuple; };
struct te10a95f610a64bfb7ccea542c54f0a25 : public std::variant<
  Void,
  std::string,
  Void
> { using variant::variant; };
struct t9b471a57e45588f3795bf9ca91c31ff6 : public std::tuple<
  te10a95f610a64bfb7ccea542c54f0a25,
  std::optional<std::string>,
  dessser::gen::function_name::t_ext
> { using tuple::tuple; };
struct t;
struct t;
struct t7c6bbe37b66fb3a66c00c4bd1bfc4369 : public std::variant<
  t9b471a57e45588f3795bf9ca91c31ff6,
  t*
> { using variant::variant; };
struct t;
struct ta2fe18cae70948742cabb6081fd22a0c {
  Lst<dessser::gen::raql_select_field::t_ext> fields;
  std::optional<Lst<dessser::gen::field_name::t_ext>> and_all_others;
  std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> sort;
  dessser::gen::raql_expr::t_ext where;
  std::optional<dessser::gen::event_time::t_ext> event_time;
  Lst<dessser::gen::raql_expr::t_ext> notifications;
  Lst<dessser::gen::raql_expr::t_ext> key;
  dessser::gen::raql_expr::t_ext commit_cond;
  bool commit_before;
  dessser::gen::raql_flush_method::t_ext flush_how;
  Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> from;
  std::optional<dessser::gen::raql_expr::t_ext> every;
  Lst<dessser::gen::field_name::t_ext> factors;
  bool operator==(ta2fe18cae70948742cabb6081fd22a0c const &other) const {
    return fields == other.fields && and_all_others == other.and_all_others && sort == other.sort && where == other.where && event_time == other.event_time && notifications == other.notifications && key == other.key && commit_cond == other.commit_cond && commit_before == other.commit_before && flush_how == other.flush_how && from == other.from && every == other.every && factors == other.factors;
  }
};
struct ta828a76692b94aa6a15973ace224bedc {
  dessser::gen::raql_expr::t_ext fname;
  std::optional<dessser::gen::raql_expr::t_ext> preprocessor;
  dessser::gen::raql_expr::t_ext unlink;
  bool operator==(ta828a76692b94aa6a15973ace224bedc const &other) const {
    return fname == other.fname && preprocessor == other.preprocessor && unlink == other.unlink;
  }
};
typedef std::tuple<
  std::string,
  dessser::gen::raql_expr::t_ext
> tcd17c85cefeae7a860c0732c05eaeaed;

struct tee7dccc2726e2723462077a878a69c99 {
  dessser::gen::raql_expr::t_ext after_max_secs;
  dessser::gen::raql_expr::t_ext after_max_events;
  bool operator==(tee7dccc2726e2723462077a878a69c99 const &other) const {
    return after_max_secs == other.after_max_secs && after_max_events == other.after_max_events;
  }
};
struct t6f8c1c936ce8cf2fe9dc881177aa3e62 : public std::variant<
  Void,
  dessser::gen::raql_expr::t_ext,
  Void,
  tee7dccc2726e2723462077a878a69c99
> { using variant::variant; };
struct te6ac276a1b6044b9474a56a7da93a611 {
  Lst<tcd17c85cefeae7a860c0732c05eaeaed> options;
  dessser::gen::raql_expr::t_ext topic;
  std::optional<dessser::gen::raql_expr::t_ext> partitions;
  t6f8c1c936ce8cf2fe9dc881177aa3e62 restart_from;
  bool operator==(te6ac276a1b6044b9474a56a7da93a611 const &other) const {
    return options == other.options && topic == other.topic && partitions == other.partitions && restart_from == other.restart_from;
  }
};
struct tf708b6568b9bac184e3f5da3a64f4419 : public std::variant<
  ta828a76692b94aa6a15973ace224bedc,
  te6ac276a1b6044b9474a56a7da93a611
> { using variant::variant; };
struct tc1ee34cdd9bdb8371d318bb284a788a8 {
  char separator;
  std::string null;
  bool may_quote;
  std::string escape_seq;
  Lst<dessser::gen::field_type::t_ext> fields;
  bool vectors_of_chars_as_string;
  bool clickhouse_syntax;
  bool operator==(tc1ee34cdd9bdb8371d318bb284a788a8 const &other) const {
    return separator == other.separator && null == other.null && may_quote == other.may_quote && escape_seq == other.escape_seq && fields == other.fields && vectors_of_chars_as_string == other.vectors_of_chars_as_string && clickhouse_syntax == other.clickhouse_syntax;
  }
};
struct t570dd118e4f520aece0574b2f62e7634 : public std::variant<
  tc1ee34cdd9bdb8371d318bb284a788a8,
  Lst<dessser::gen::field_type::t_ext>
> { using variant::variant; };
struct t1d5c57287ee550c3ccac78b88bba5862 {
  tf708b6568b9bac184e3f5da3a64f4419 source;
  t570dd118e4f520aece0574b2f62e7634 format;
  std::optional<dessser::gen::event_time::t_ext> event_time;
  Lst<dessser::gen::field_name::t_ext> factors;
  bool operator==(t1d5c57287ee550c3ccac78b88bba5862 const &other) const {
    return source == other.source && format == other.format && event_time == other.event_time && factors == other.factors;
  }
};
struct t9ddff9e1963b15ba493db1f8dadd34fb {
  std::string net_addr;
  uint16_t port;
  dessser::gen::raql_net_protocol::t_ext proto;
  Lst<dessser::gen::field_name::t_ext> factors;
  bool operator==(t9ddff9e1963b15ba493db1f8dadd34fb const &other) const {
    return net_addr == other.net_addr && port == other.port && proto == other.proto && factors == other.factors;
  }
};
struct t;
struct t : public std::variant<
  ta2fe18cae70948742cabb6081fd22a0c,
  t1d5c57287ee550c3ccac78b88bba5862,
  t9ddff9e1963b15ba493db1f8dadd34fb
> { using variant::variant; };
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

struct t;
typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

struct t;
struct t;
struct t;
typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  Lst<dessser::gen::raql_select_field::t_ext>,
  Pointer
> ta9047710b0a6cdbb6cf02e2ae071242e;

typedef std::tuple<
  dessser::gen::raql_select_field::t_ext,
  Pointer
> t385fc99bd06c53216a5de778dea0dc6e;

struct t;
struct t;
typedef std::tuple<
  std::optional<Lst<dessser::gen::field_name::t_ext>>,
  Pointer
> t885b8962b524dff3368f7a529f1d466b;

typedef std::tuple<
  Lst<dessser::gen::field_name::t_ext>,
  Pointer
> t0dfa866705b76efff53e4aa97228a967;

typedef std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> t273a2b7978f5b466a128a51c1cc4a27b;

struct t;
struct t;
typedef std::tuple<
  std::optional<tf0c8d4f3070907529cc1a83f8baf6fab>,
  Pointer
> t3b4feade6f60da4ba5d645f756688083;

typedef std::tuple<
  std::optional<dessser::gen::raql_expr::t_ext>,
  Pointer
> tf1063a6af8c1fb72f0e0ee089d43d040;

typedef std::tuple<
  dessser::gen::raql_expr::t_ext,
  Pointer
> t1113e6691818baaf60a775527f6cc1ac;

typedef std::tuple<
  Lst<dessser::gen::raql_expr::t_ext>,
  Pointer
> t0067a338c0fc91b6a811c8df70d4c87a;

struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  std::optional<dessser::gen::event_time::t_ext>,
  Pointer
> te3858ac581a2bb69ede2f45fc6f9aff4;

typedef std::tuple<
  dessser::gen::event_time::t_ext,
  Pointer
> te8ff255b34432f8503a86cf675cbafe6;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  bool,
  Pointer
> t4138de986e20d18b01e4c493dc9d5451;

struct t;
struct t;
typedef std::tuple<
  dessser::gen::raql_flush_method::t_ext,
  Pointer
> t01507690afb11d3b148862b712bad5a5;

struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369>,
  Pointer
> t5c362d56d9dbfb12c2e68c4ed4a25c50;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  t7c6bbe37b66fb3a66c00c4bd1bfc4369,
  Pointer
> t2a2e361c672135221e41ae1e54a712a2;

struct t;
struct t;
typedef std::tuple<
  te10a95f610a64bfb7ccea542c54f0a25,
  Pointer
> tf0d49dee148c406cd202993cce2a4a2d;

typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

struct t;
struct t;
typedef std::tuple<
  std::optional<std::string>,
  Pointer
> t3fbff88eef4e4c8bc42b06e5ad07ea51;

struct t;
struct t;
typedef std::tuple<
  dessser::gen::function_name::t_ext,
  Pointer
> tc7d3fcfd06c0f02b3732e1754a18402b;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  tf708b6568b9bac184e3f5da3a64f4419,
  Pointer
> t1313b4ee18248dd765ed6ae8b0058504;

typedef std::tuple<
  Lst<tcd17c85cefeae7a860c0732c05eaeaed>,
  Pointer
> t20007ff08d465535358862e7faf3b556;

typedef std::tuple<
  std::string,
  Pointer
> tef94b55d8809251f13165d9a05bd9d0e;

typedef std::tuple<
  t6f8c1c936ce8cf2fe9dc881177aa3e62,
  Pointer
> tae0102a98baabe959d4e6cb1e047e44b;

struct t;
struct t;
typedef std::tuple<
  t570dd118e4f520aece0574b2f62e7634,
  Pointer
> t61bdb3f643c3108bb612fc36951fce20;

typedef std::tuple<
  char,
  Pointer
> t9c427530664aa522ce95ad420b884056;

typedef std::tuple<
  Lst<dessser::gen::field_type::t_ext>,
  Pointer
> tfba505af7788ece275315330d94bba2e;

typedef std::tuple<
  dessser::gen::field_type::t_ext,
  Pointer
> t2f09fa79b0bdf1902e3b53bc7e485604;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  dessser::gen::raql_net_protocol::t_ext,
  Pointer
> t09401f6cfd6a52d2f08b29ed5a55a113;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS][[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]; format: [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]; event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" "Ptr")
      (let "ssum_dst_810" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "srec_dst_924"
            (let "srec_dst_923"
              (let "srec_dst_907"
                (let "srec_dst_906"
                  (let "srec_dst_905"
                    (let "srec_dst_904"
                      (let "srec_dst_898"
                        (let "srec_dst_892"
                          (let "srec_dst_891"
                            (let "srec_dst_890"
                              (let "srec_dst_881"
                                (let "srec_dst_875"
                                  (let "dst_ref_872"
                                    (make-vec
                                      (let "leb128_sz_870" (make-vec (cardinality (get-field "fields" (get-alt "Aggregate" (param 0)))))
                                        (let "leb128_ptr_871" (make-vec (identifier "ssum_dst_810"))
                                          (seq
                                            (while
                                              (seq
                                                (set-vec (u8 0) (identifier "leb128_ptr_871")
                                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_871"))
                                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_870"))) 
                                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_870"))) 
                                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_870"))) (u8 128)))))
                                                (set-vec (u8 0) (identifier "leb128_sz_870") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_870")) (u8 7))) 
                                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_870")) (u32 0))) 
                                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_871"))))))
                                    (let "n_ref_873" (make-vec (i32 0))
                                      (seq
                                        (for-each "x_874" (get-field "fields" (get-alt "Aggregate" (param 0)))
                                          (seq (set-vec (u8 0) (identifier "dst_ref_872") (apply (ext-identifier raql_select_field to-row-binary) (identifier "x_874") (unsafe-nth (u8 0) (identifier "dst_ref_872"))))
                                            (set-vec (u8 0) (identifier "n_ref_873") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_873")))))) 
                                        (unsafe-nth (u8 0) (identifier "dst_ref_872")))))
                                  (if (is-null (get-field "and_all_others" (get-alt "Aggregate" (param 0)))) 
                                    (write-u8 (identifier "srec_dst_875") (u8 1))
                                    (let "dst_ref_878"
                                      (make-vec
                                        (let "leb128_sz_876" (make-vec (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))
                                          (let "leb128_ptr_877" (make-vec (write-u8 (identifier "srec_dst_875") (u8 0)))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_877")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_877"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_876"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_876"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_876"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_876") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_876")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_876")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_877"))))))
                                      (let "n_ref_879" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_880" (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_878") (apply (ext-identifier field_name to-row-binary) (identifier "x_880") (unsafe-nth (u8 0) (identifier "dst_ref_878"))))
                                              (set-vec (u8 0) (identifier "n_ref_879") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_879")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_878")))))))
                                (if (is-null (get-field "sort" (get-alt "Aggregate" (param 0)))) 
                                  (write-u8 (identifier "srec_dst_881") (u8 1))
                                  (let "stup_dst_884"
                                    (let "stup_dst_883"
                                      (let "stup_dst_882" (write-u8 (identifier "srec_dst_881") (u8 0))
                                        (write-u32 little-endian (identifier "stup_dst_882") (get-item 0 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                      (if (is-null (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) 
                                        (write-u8 (identifier "stup_dst_883") (u8 1))
                                        (apply (ext-identifier raql_expr to-row-binary) (force (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) (write-u8 (identifier "stup_dst_883") (u8 0)))))
                                    (let "dst_ref_887"
                                      (make-vec
                                        (let "leb128_sz_885" (make-vec (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                          (let "leb128_ptr_886" (make-vec (identifier "stup_dst_884"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_886")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_886"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_885"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_885"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_885"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_885") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_885")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_885")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_886"))))))
                                      (let "n_ref_888" (make-vec (i32 0))
                                        (seq
                                          (for-each "x_889" (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))
                                            (seq (set-vec (u8 0) (identifier "dst_ref_887") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_889") (unsafe-nth (u8 0) (identifier "dst_ref_887"))))
                                              (set-vec (u8 0) (identifier "n_ref_888") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_888")))))) 
                                          (unsafe-nth (u8 0) (identifier "dst_ref_887")))))))) 
                              (apply (ext-identifier raql_expr to-row-binary) (get-field "where" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_890")))
                            (if (is-null (get-field "event_time" (get-alt "Aggregate" (param 0)))) 
                              (write-u8 (identifier "srec_dst_891") (u8 1))
                              (apply (ext-identifier event_time to-row-binary) (force (get-field "event_time" (get-alt "Aggregate" (param 0)))) (write-u8 (identifier "srec_dst_891") (u8 0)))))
                          (let "dst_ref_895"
                            (make-vec
                              (let "leb128_sz_893" (make-vec (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0)))))
                                (let "leb128_ptr_894" (make-vec (identifier "srec_dst_892"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_894")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_894"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_893"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_893"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_893"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_893") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_893")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_893")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_894"))))))
                            (let "n_ref_896" (make-vec (i32 0))
                              (seq
                                (for-each "x_897" (get-field "notifications" (get-alt "Aggregate" (param 0)))
                                  (seq (set-vec (u8 0) (identifier "dst_ref_895") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_897") (unsafe-nth (u8 0) (identifier "dst_ref_895"))))
                                    (set-vec (u8 0) (identifier "n_ref_896") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_896")))))) 
                                (unsafe-nth (u8 0) (identifier "dst_ref_895"))))))
                        (let "dst_ref_901"
                          (make-vec
                            (let "leb128_sz_899" (make-vec (cardinality (get-field "key" (get-alt "Aggregate" (param 0)))))
                              (let "leb128_ptr_900" (make-vec (identifier "srec_dst_898"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_900")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_900"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_899"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_899"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_899"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_899") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_899")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_899")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_900"))))))
                          (let "n_ref_902" (make-vec (i32 0))
                            (seq
                              (for-each "x_903" (get-field "key" (get-alt "Aggregate" (param 0)))
                                (seq (set-vec (u8 0) (identifier "dst_ref_901") (apply (ext-identifier raql_expr to-row-binary) (identifier "x_903") (unsafe-nth (u8 0) (identifier "dst_ref_901"))))
                                  (set-vec (u8 0) (identifier "n_ref_902") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_902")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_901")))))) 
                      (apply (ext-identifier raql_expr to-row-binary) (get-field "commit_cond" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_904")))
                    (write-u8 (identifier "srec_dst_905") (u8-of-bool (get-field "commit_before" (get-alt "Aggregate" (param 0))))))
                  (apply (ext-identifier raql_flush_method to-row-binary) (get-field "flush_how" (get-alt "Aggregate" (param 0))) (identifier "srec_dst_906")))
                (let "dst_ref_910"
                  (make-vec
                    (let "leb128_sz_908" (make-vec (cardinality (get-field "from" (get-alt "Aggregate" (param 0)))))
                      (let "leb128_ptr_909" (make-vec (identifier "srec_dst_907"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_909")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_909"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_908"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_908"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_908"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_908") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_908")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_908")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_909"))))))
                  (let "n_ref_911" (make-vec (i32 0))
                    (seq
                      (for-each "x_912" (get-field "from" (get-alt "Aggregate" (param 0)))
                        (seq
                          (set-vec (u8 0) (identifier "dst_ref_910")
                            (let "ssum_dst_914" (write-u16 little-endian (unsafe-nth (u8 0) (identifier "dst_ref_910")) (label-of (identifier "x_912")))
                              (if (eq (u16 0) (label-of (identifier "x_912")))
                                (let "stup_dst_922"
                                  (let "stup_dst_919"
                                    (let "ssum_dst_916" (write-u16 little-endian (identifier "ssum_dst_914") (label-of (get-item 0 (get-alt "NamedOperation" (identifier "x_912")))))
                                      (if (eq (u16 0) (label-of (get-item 0 (get-alt "NamedOperation" (identifier "x_912"))))) 
                                        (identifier "ssum_dst_916")
                                        (if (eq (u16 1) (label-of (get-item 0 (get-alt "NamedOperation" (identifier "x_912")))))
                                          (write-bytes
                                            (let "leb128_sz_917" (make-vec (string-length (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (identifier "x_912"))))))
                                              (let "leb128_ptr_918" (make-vec (identifier "ssum_dst_916"))
                                                (seq
                                                  (while
                                                    (seq
                                                      (set-vec (u8 0) 
                                                        (identifier "leb128_ptr_918")
                                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_918"))
                                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_917"))) 
                                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_917"))) 
                                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_917"))) (u8 128)))))
                                                      (set-vec (u8 0) (identifier "leb128_sz_917") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_917")) (u8 7)))
                                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_917")) (u32 0))) 
                                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_918"))))) 
                                            (bytes-of-string (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (identifier "x_912"))))))
                                          (seq (assert (eq (label-of (get-item 0 (get-alt "NamedOperation" (identifier "x_912")))) (u16 2))) (identifier "ssum_dst_916")))))
                                    (if (is-null (get-item 1 (get-alt "NamedOperation" (identifier "x_912")))) 
                                      (write-u8 (identifier "stup_dst_919") (u8 1))
                                      (write-bytes
                                        (let "leb128_sz_920" (make-vec (string-length (force (get-item 1 (get-alt "NamedOperation" (identifier "x_912"))))))
                                          (let "leb128_ptr_921" (make-vec (write-u8 (identifier "stup_dst_919") (u8 0)))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_921")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_921"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_920"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_920"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_920"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_920") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_920")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_920")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_921"))))) 
                                        (bytes-of-string (force (get-item 1 (get-alt "NamedOperation" (identifier "x_912"))))))))
                                  (apply (ext-identifier function_name to-row-binary) (get-item 2 (get-alt "NamedOperation" (identifier "x_912"))) (identifier "stup_dst_922")))
                                (seq (assert (eq (label-of (identifier "x_912")) (u16 1))) (apply (myself "Ptr") (get-alt "SubQuery" (identifier "x_912")) (identifier "ssum_dst_914"))))))
                          (set-vec (u8 0) (identifier "n_ref_911") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_911")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_910"))))))
              (if (is-null (get-field "every" (get-alt "Aggregate" (param 0)))) 
                (write-u8 (identifier "srec_dst_923") (u8 1)) (apply (ext-identifier raql_expr to-row-binary) (force (get-field "every" (get-alt "Aggregate" (param 0)))) (write-u8 (identifier "srec_dst_923") (u8 0)))))
            (let "dst_ref_927"
              (make-vec
                (let "leb128_sz_925" (make-vec (cardinality (get-field "factors" (get-alt "Aggregate" (param 0)))))
                  (let "leb128_ptr_926" (make-vec (identifier "srec_dst_924"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_926")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_926"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_925"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_925"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_925"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_925") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_925")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_925")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_926"))))))
              (let "n_ref_928" (make-vec (i32 0))
                (seq
                  (for-each "x_929" (get-field "factors" (get-alt "Aggregate" (param 0)))
                    (seq (set-vec (u8 0) (identifier "dst_ref_927") (apply (ext-identifier field_name to-row-binary) (identifier "x_929") (unsafe-nth (u8 0) (identifier "dst_ref_927"))))
                      (set-vec (u8 0) (identifier "n_ref_928") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_928")))))) 
                  (unsafe-nth (u8 0) (identifier "dst_ref_927"))))))
          (if (eq (u16 1) (label-of (param 0)))
            (let "srec_dst_864"
              (let "srec_dst_863"
                (let "srec_dst_840"
                  (let "ssum_dst_822" (write-u16 little-endian (identifier "ssum_dst_810") (label-of (get-field "source" (get-alt "ReadExternal" (param 0)))))
                    (if (eq (u16 0) (label-of (get-field "source" (get-alt "ReadExternal" (param 0)))))
                      (let "srec_dst_839"
                        (let "srec_dst_838" (apply (ext-identifier raql_expr to-row-binary) (get-field "fname" (get-alt "File" (get-field "source" (get-alt "ReadExternal" (param 0))))) (identifier "ssum_dst_822"))
                          (if (is-null (get-field "preprocessor" (get-alt "File" (get-field "source" (get-alt "ReadExternal" (param 0)))))) 
                            (write-u8 (identifier "srec_dst_838") (u8 1))
                            (apply (ext-identifier raql_expr to-row-binary) 
                              (force (get-field "preprocessor" (get-alt "File" (get-field "source" (get-alt "ReadExternal" (param 0)))))) 
                              (write-u8 (identifier "srec_dst_838") (u8 0)))))
                        (apply (ext-identifier raql_expr to-row-binary) (get-field "unlink" (get-alt "File" (get-field "source" (get-alt "ReadExternal" (param 0))))) (identifier "srec_dst_839")))
                      (seq (assert (eq (label-of (get-field "source" (get-alt "ReadExternal" (param 0)))) (u16 1)))
                        (let "srec_dst_834"
                          (let "srec_dst_833"
                            (let "srec_dst_832"
                              (let "dst_ref_825"
                                (make-vec
                                  (let "leb128_sz_823" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))))
                                    (let "leb128_ptr_824" (make-vec (identifier "ssum_dst_822"))
                                      (seq
                                        (while
                                          (seq
                                            (set-vec (u8 0) (identifier "leb128_ptr_824")
                                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_824"))
                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_823"))) 
                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_823"))) 
                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_823"))) (u8 128)))))
                                            (set-vec (u8 0) (identifier "leb128_sz_823") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_823")) (u8 7))) 
                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_823")) (u32 0))) 
                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_824"))))))
                                (let "n_ref_826" (make-vec (i32 0))
                                  (seq
                                    (for-each "x_827" (get-field "options" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))
                                      (seq
                                        (set-vec (u8 0) (identifier "dst_ref_825")
                                          (let "stup_dst_831"
                                            (let "stup_dst_828" (unsafe-nth (u8 0) (identifier "dst_ref_825"))
                                              (write-bytes
                                                (let "leb128_sz_829" 
                                                  (make-vec (string-length (get-item 0 (identifier "x_827"))))
                                                  (let "leb128_ptr_830" 
                                                    (make-vec (identifier "stup_dst_828"))
                                                    (seq
                                                      (while
                                                        (seq
                                                          (set-vec (u8 0) 
                                                            (identifier "leb128_ptr_830")
                                                            (write-u8 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_830"))
                                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_829"))) 
                                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_829"))) 
                                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_829"))) (u8 128)))))
                                                          (set-vec (u8 0) (identifier "leb128_sz_829") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_829")) (u8 7)))
                                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_829")) (u32 0))) 
                                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_830"))))) 
                                                (bytes-of-string (get-item 0 (identifier "x_827"))))) 
                                            (apply (ext-identifier raql_expr to-row-binary) (get-item 1 (identifier "x_827")) (identifier "stup_dst_831"))))
                                        (set-vec (u8 0) (identifier "n_ref_826") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_826")))))) 
                                    (unsafe-nth (u8 0) (identifier "dst_ref_825")))))
                              (apply (ext-identifier raql_expr to-row-binary) (get-field "topic" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0))))) (identifier "srec_dst_832")))
                            (if (is-null (get-field "partitions" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))) 
                              (write-u8 (identifier "srec_dst_833") (u8 1))
                              (apply (ext-identifier raql_expr to-row-binary) 
                                (force (get-field "partitions" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))) 
                                (write-u8 (identifier "srec_dst_833") (u8 0)))))
                          (let "label1_835" (label-of (get-field "restart_from" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0))))))
                            (let "ssum_dst_836" (write-u16 little-endian (identifier "srec_dst_834") (identifier "label1_835"))
                              (if (eq (u16 0) (identifier "label1_835")) 
                                (identifier "ssum_dst_836")
                                (if (eq (u16 1) (identifier "label1_835"))
                                  (apply (ext-identifier raql_expr to-row-binary) 
                                    (get-alt "OffsetFromEnd" (get-field "restart_from" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))) 
                                    (identifier "ssum_dst_836"))
                                  (if (eq (u16 2) (identifier "label1_835")) 
                                    (identifier "ssum_dst_836")
                                    (seq (assert (eq (identifier "label1_835") (u16 3)))
                                      (let "srec_dst_837"
                                        (apply (ext-identifier raql_expr to-row-binary)
                                          (get-field "after_max_secs" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))))
                                          (identifier "ssum_dst_836"))
                                        (apply (ext-identifier raql_expr to-row-binary)
                                          (get-field "after_max_events" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))))
                                          (identifier "srec_dst_837")))))))))))))
                  (let "ssum_dst_842" (write-u16 little-endian (identifier "srec_dst_840") (label-of (get-field "format" (get-alt "ReadExternal" (param 0)))))
                    (if (eq (u16 0) (label-of (get-field "format" (get-alt "ReadExternal" (param 0)))))
                      (let "srec_dst_862"
                        (let "srec_dst_861"
                          (let "srec_dst_855"
                            (let "srec_dst_852"
                              (let "srec_dst_851"
                                (let "srec_dst_848" (write-u8 (identifier "ssum_dst_842") (u8-of-char (get-field "separator" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0)))))))
                                  (write-bytes
                                    (let "leb128_sz_849" (make-vec (string-length (get-field "null" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0)))))))
                                      (let "leb128_ptr_850" (make-vec (identifier "srec_dst_848"))
                                        (seq
                                          (while
                                            (seq
                                              (set-vec (u8 0) (identifier "leb128_ptr_850")
                                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_850"))
                                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_849"))) 
                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_849"))) 
                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_849"))) (u8 128)))))
                                              (set-vec (u8 0) (identifier "leb128_sz_849") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_849")) (u8 7))) 
                                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_849")) (u32 0))) 
                                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_850"))))) 
                                    (bytes-of-string (get-field "null" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0))))))))
                                (write-u8 (identifier "srec_dst_851") (u8-of-bool (get-field "may_quote" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0))))))))
                              (write-bytes
                                (let "leb128_sz_853" (make-vec (string-length (get-field "escape_seq" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0)))))))
                                  (let "leb128_ptr_854" (make-vec (identifier "srec_dst_852"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_854")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_854"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_853"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_853"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_853"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_853") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_853")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_853")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_854"))))) 
                                (bytes-of-string (get-field "escape_seq" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0))))))))
                            (let "dst_ref_858"
                              (make-vec
                                (let "leb128_sz_856" (make-vec (cardinality (get-field "fields" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0)))))))
                                  (let "leb128_ptr_857" (make-vec (identifier "srec_dst_855"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_857")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_857"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_856"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_856"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_856"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_856") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_856")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_856")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_857"))))))
                              (let "n_ref_859" (make-vec (i32 0))
                                (seq
                                  (for-each "x_860" (get-field "fields" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0)))))
                                    (seq (set-vec (u8 0) (identifier "dst_ref_858") (apply (ext-identifier field_type to-row-binary) (identifier "x_860") (unsafe-nth (u8 0) (identifier "dst_ref_858"))))
                                      (set-vec (u8 0) (identifier "n_ref_859") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_859")))))) 
                                  (unsafe-nth (u8 0) (identifier "dst_ref_858"))))))
                          (write-u8 (identifier "srec_dst_861") (u8-of-bool (get-field "vectors_of_chars_as_string" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0))))))))
                        (write-u8 (identifier "srec_dst_862") (u8-of-bool (get-field "clickhouse_syntax" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0))))))))
                      (seq (assert (eq (label-of (get-field "format" (get-alt "ReadExternal" (param 0)))) (u16 1)))
                        (let "dst_ref_845"
                          (make-vec
                            (let "leb128_sz_843" (make-vec (cardinality (get-alt "RowBinary" (get-field "format" (get-alt "ReadExternal" (param 0))))))
                              (let "leb128_ptr_844" (make-vec (identifier "ssum_dst_842"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_844")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_844"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_843"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_843"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_843"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_843") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_843")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_843")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_844"))))))
                          (let "n_ref_846" (make-vec (i32 0))
                            (seq
                              (for-each "x_847" (get-alt "RowBinary" (get-field "format" (get-alt "ReadExternal" (param 0))))
                                (seq (set-vec (u8 0) (identifier "dst_ref_845") (apply (ext-identifier field_type to-row-binary) (identifier "x_847") (unsafe-nth (u8 0) (identifier "dst_ref_845"))))
                                  (set-vec (u8 0) (identifier "n_ref_846") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_846")))))) 
                              (unsafe-nth (u8 0) (identifier "dst_ref_845")))))))))
                (if (is-null (get-field "event_time" (get-alt "ReadExternal" (param 0)))) 
                  (write-u8 (identifier "srec_dst_863") (u8 1)) (apply (ext-identifier event_time to-row-binary) (force (get-field "event_time" (get-alt "ReadExternal" (param 0)))) (write-u8 (identifier "srec_dst_863") (u8 0)))))
              (let "dst_ref_867"
                (make-vec
                  (let "leb128_sz_865" (make-vec (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0)))))
                    (let "leb128_ptr_866" (make-vec (identifier "srec_dst_864"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_866")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_866"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_865"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_865"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_865"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_865") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_865")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_865")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_866"))))))
                (let "n_ref_868" (make-vec (i32 0))
                  (seq
                    (for-each "x_869" (get-field "factors" (get-alt "ReadExternal" (param 0)))
                      (seq (set-vec (u8 0) (identifier "dst_ref_867") (apply (ext-identifier field_name to-row-binary) (identifier "x_869") (unsafe-nth (u8 0) (identifier "dst_ref_867"))))
                        (set-vec (u8 0) (identifier "n_ref_868") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_868")))))) 
                    (unsafe-nth (u8 0) (identifier "dst_ref_867"))))))
            (seq (assert (eq (label-of (param 0)) (u16 2)))
              (let "srec_dst_815"
                (let "srec_dst_814"
                  (let "srec_dst_813"
                    (write-bytes
                      (let "leb128_sz_811" (make-vec (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0)))))
                        (let "leb128_ptr_812" (make-vec (identifier "ssum_dst_810"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_812")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_812"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_811"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_811"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_811"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_811") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_811")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_811")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_812"))))) 
                      (bytes-of-string (get-field "net_addr" (get-alt "ListenFor" (param 0))))) 
                    (write-u16 little-endian (identifier "srec_dst_813") (get-field "port" (get-alt "ListenFor" (param 0)))))
                  (apply (ext-identifier raql_net_protocol to-row-binary) (get-field "proto" (get-alt "ListenFor" (param 0))) (identifier "srec_dst_814")))
                (let "dst_ref_818"
                  (make-vec
                    (let "leb128_sz_816" (make-vec (cardinality (get-field "factors" (get-alt "ListenFor" (param 0)))))
                      (let "leb128_ptr_817" (make-vec (identifier "srec_dst_815"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_817")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_817"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_816"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_816"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_816"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_816") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_816")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_816")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_817"))))))
                  (let "n_ref_819" (make-vec (i32 0))
                    (seq
                      (for-each "x_820" (get-field "factors" (get-alt "ListenFor" (param 0)))
                        (seq (set-vec (u8 0) (identifier "dst_ref_818") (apply (ext-identifier field_name to-row-binary) (identifier "x_820") (unsafe-nth (u8 0) (identifier "dst_ref_818"))))
                          (set-vec (u8 0) (identifier "n_ref_819") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_819")))))) 
                      (unsafe-nth (u8 0) (identifier "dst_ref_818")))))))))))
 */
static std::function<Pointer(t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t*,Pointer)> fun0 { [&fun0](t* p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0->index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_810 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t(p_0->index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        ta2fe18cae70948742cabb6081fd22a0c id_8 { std::get<0>(*p_0) };
        Lst<dessser::gen::raql_select_field::t_ext> id_9 { id_8.fields };
        uint32_t id_10 { id_9.size() };
        Vec<1, uint32_t> id_11 {  id_10  };
        Pointer let_res_12;
        {
          Vec<1, uint32_t> leb128_sz_870 { id_11 };
          Vec<1, Pointer> id_13 {  ssum_dst_810  };
          Pointer let_res_14;
          {
            Vec<1, Pointer> leb128_ptr_871 { id_13 };
            bool while_flag_15 { true };
            do {
              uint8_t id_16 { 0 };
              uint8_t id_17 { 0 };
              Pointer id_18 { leb128_ptr_871[id_17] };
              uint32_t id_19 { 128U };
              uint8_t id_20 { 0 };
              uint32_t id_21 { leb128_sz_870[id_20] };
              bool id_22 { bool(id_19 > id_21) };
              uint8_t choose_res_23;
              if (id_22) {
                uint8_t id_24 { 0 };
                uint32_t id_25 { leb128_sz_870[id_24] };
                uint8_t id_26 { uint8_t(id_25) };
                choose_res_23 = id_26;
              } else {
                uint8_t id_27 { 0 };
                uint32_t id_28 { leb128_sz_870[id_27] };
                uint8_t id_29 { uint8_t(id_28) };
                uint8_t id_30 { 128 };
                uint8_t id_31 { uint8_t(id_29 | id_30) };
                choose_res_23 = id_31;
              }
              Pointer id_32 { id_18.writeU8(choose_res_23) };
              Void id_33 { ((void)(leb128_ptr_871[id_16] = id_32), VOID) };
              (void)id_33;
              uint8_t id_34 { 0 };
              uint8_t id_35 { 0 };
              uint32_t id_36 { leb128_sz_870[id_35] };
              uint8_t id_37 { 7 };
              uint32_t id_38 { uint32_t(id_36 >> id_37) };
              Void id_39 { ((void)(leb128_sz_870[id_34] = id_38), VOID) };
              (void)id_39;
              uint8_t id_40 { 0 };
              uint32_t id_41 { leb128_sz_870[id_40] };
              uint32_t id_42 { 0U };
              bool id_43 { bool(id_41 > id_42) };
              while_flag_15 = id_43;
              if (while_flag_15) {
                (void)VOID;
              }
            } while (while_flag_15);
            (void)VOID;
            uint8_t id_44 { 0 };
            Pointer id_45 { leb128_ptr_871[id_44] };
            let_res_14 = id_45;
          }
          let_res_12 = let_res_14;
        }
        Vec<1, Pointer> id_46 {  let_res_12  };
        Pointer let_res_47;
        {
          Vec<1, Pointer> dst_ref_872 { id_46 };
          int32_t id_48 { 0L };
          Vec<1, int32_t> id_49 {  id_48  };
          Pointer let_res_50;
          {
            Vec<1, int32_t> n_ref_873 { id_49 };
            ta2fe18cae70948742cabb6081fd22a0c id_51 { std::get<0>(*p_0) };
            Lst<dessser::gen::raql_select_field::t_ext> id_52 { id_51.fields };
            for (dessser::gen::raql_select_field::t_ext x_874 : id_52) {
              uint8_t id_53 { 0 };
              auto fun54 { dessser::gen::raql_select_field::to_row_binary };
              uint8_t id_55 { 0 };
              Pointer id_56 { dst_ref_872[id_55] };
              Pointer id_57 { fun54(x_874, id_56) };
              Void id_58 { ((void)(dst_ref_872[id_53] = id_57), VOID) };
              (void)id_58;
              uint8_t id_59 { 0 };
              int32_t id_60 { 1L };
              uint8_t id_61 { 0 };
              int32_t id_62 { n_ref_873[id_61] };
              int32_t id_63 { int32_t(id_60 + id_62) };
              Void id_64 { ((void)(n_ref_873[id_59] = id_63), VOID) };
              (void)id_64;
              (void)id_64;
            }
            (void)VOID;
            uint8_t id_65 { 0 };
            Pointer id_66 { dst_ref_872[id_65] };
            let_res_50 = id_66;
          }
          let_res_47 = let_res_50;
        }
        Pointer let_res_67;
        {
          Pointer srec_dst_875 { let_res_47 };
          ta2fe18cae70948742cabb6081fd22a0c id_68 { std::get<0>(*p_0) };
          std::optional<Lst<dessser::gen::field_name::t_ext>> id_69 { id_68.and_all_others };
          bool id_70 { !(id_69.has_value ()) };
          Pointer choose_res_71;
          if (id_70) {
            uint8_t id_72 { 1 };
            Pointer id_73 { srec_dst_875.writeU8(id_72) };
            choose_res_71 = id_73;
          } else {
            ta2fe18cae70948742cabb6081fd22a0c id_74 { std::get<0>(*p_0) };
            std::optional<Lst<dessser::gen::field_name::t_ext>> id_75 { id_74.and_all_others };
            Lst<dessser::gen::field_name::t_ext> id_76 { id_75.value() };
            uint32_t id_77 { id_76.size() };
            Vec<1, uint32_t> id_78 {  id_77  };
            Pointer let_res_79;
            {
              Vec<1, uint32_t> leb128_sz_876 { id_78 };
              uint8_t id_80 { 0 };
              Pointer id_81 { srec_dst_875.writeU8(id_80) };
              Vec<1, Pointer> id_82 {  id_81  };
              Pointer let_res_83;
              {
                Vec<1, Pointer> leb128_ptr_877 { id_82 };
                bool while_flag_84 { true };
                do {
                  uint8_t id_85 { 0 };
                  uint8_t id_86 { 0 };
                  Pointer id_87 { leb128_ptr_877[id_86] };
                  uint32_t id_88 { 128U };
                  uint8_t id_89 { 0 };
                  uint32_t id_90 { leb128_sz_876[id_89] };
                  bool id_91 { bool(id_88 > id_90) };
                  uint8_t choose_res_92;
                  if (id_91) {
                    uint8_t id_93 { 0 };
                    uint32_t id_94 { leb128_sz_876[id_93] };
                    uint8_t id_95 { uint8_t(id_94) };
                    choose_res_92 = id_95;
                  } else {
                    uint8_t id_96 { 0 };
                    uint32_t id_97 { leb128_sz_876[id_96] };
                    uint8_t id_98 { uint8_t(id_97) };
                    uint8_t id_99 { 128 };
                    uint8_t id_100 { uint8_t(id_98 | id_99) };
                    choose_res_92 = id_100;
                  }
                  Pointer id_101 { id_87.writeU8(choose_res_92) };
                  Void id_102 { ((void)(leb128_ptr_877[id_85] = id_101), VOID) };
                  (void)id_102;
                  uint8_t id_103 { 0 };
                  uint8_t id_104 { 0 };
                  uint32_t id_105 { leb128_sz_876[id_104] };
                  uint8_t id_106 { 7 };
                  uint32_t id_107 { uint32_t(id_105 >> id_106) };
                  Void id_108 { ((void)(leb128_sz_876[id_103] = id_107), VOID) };
                  (void)id_108;
                  uint8_t id_109 { 0 };
                  uint32_t id_110 { leb128_sz_876[id_109] };
                  uint32_t id_111 { 0U };
                  bool id_112 { bool(id_110 > id_111) };
                  while_flag_84 = id_112;
                  if (while_flag_84) {
                    (void)VOID;
                  }
                } while (while_flag_84);
                (void)VOID;
                uint8_t id_113 { 0 };
                Pointer id_114 { leb128_ptr_877[id_113] };
                let_res_83 = id_114;
              }
              let_res_79 = let_res_83;
            }
            Vec<1, Pointer> id_115 {  let_res_79  };
            Pointer let_res_116;
            {
              Vec<1, Pointer> dst_ref_878 { id_115 };
              int32_t id_117 { 0L };
              Vec<1, int32_t> id_118 {  id_117  };
              Pointer let_res_119;
              {
                Vec<1, int32_t> n_ref_879 { id_118 };
                ta2fe18cae70948742cabb6081fd22a0c id_120 { std::get<0>(*p_0) };
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_121 { id_120.and_all_others };
                Lst<dessser::gen::field_name::t_ext> id_122 { id_121.value() };
                for (dessser::gen::field_name::t_ext x_880 : id_122) {
                  uint8_t id_123 { 0 };
                  auto fun124 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_125 { 0 };
                  Pointer id_126 { dst_ref_878[id_125] };
                  Pointer id_127 { fun124(x_880, id_126) };
                  Void id_128 { ((void)(dst_ref_878[id_123] = id_127), VOID) };
                  (void)id_128;
                  uint8_t id_129 { 0 };
                  int32_t id_130 { 1L };
                  uint8_t id_131 { 0 };
                  int32_t id_132 { n_ref_879[id_131] };
                  int32_t id_133 { int32_t(id_130 + id_132) };
                  Void id_134 { ((void)(n_ref_879[id_129] = id_133), VOID) };
                  (void)id_134;
                  (void)id_134;
                }
                (void)VOID;
                uint8_t id_135 { 0 };
                Pointer id_136 { dst_ref_878[id_135] };
                let_res_119 = id_136;
              }
              let_res_116 = let_res_119;
            }
            choose_res_71 = let_res_116;
          }
          let_res_67 = choose_res_71;
        }
        Pointer let_res_137;
        {
          Pointer srec_dst_881 { let_res_67 };
          ta2fe18cae70948742cabb6081fd22a0c id_138 { std::get<0>(*p_0) };
          std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_139 { id_138.sort };
          bool id_140 { !(id_139.has_value ()) };
          Pointer choose_res_141;
          if (id_140) {
            uint8_t id_142 { 1 };
            Pointer id_143 { srec_dst_881.writeU8(id_142) };
            choose_res_141 = id_143;
          } else {
            uint8_t id_144 { 0 };
            Pointer id_145 { srec_dst_881.writeU8(id_144) };
            Pointer let_res_146;
            {
              Pointer stup_dst_882 { id_145 };
              ta2fe18cae70948742cabb6081fd22a0c id_147 { std::get<0>(*p_0) };
              std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_148 { id_147.sort };
              tf0c8d4f3070907529cc1a83f8baf6fab id_149 { id_148.value() };
              uint32_t id_150 { std::get<0>(id_149) };
              Pointer id_151 { stup_dst_882.writeU32Le(id_150) };
              let_res_146 = id_151;
            }
            Pointer let_res_152;
            {
              Pointer stup_dst_883 { let_res_146 };
              ta2fe18cae70948742cabb6081fd22a0c id_153 { std::get<0>(*p_0) };
              std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_154 { id_153.sort };
              tf0c8d4f3070907529cc1a83f8baf6fab id_155 { id_154.value() };
              std::optional<dessser::gen::raql_expr::t_ext> id_156 { std::get<1>(id_155) };
              bool id_157 { !(id_156.has_value ()) };
              Pointer choose_res_158;
              if (id_157) {
                uint8_t id_159 { 1 };
                Pointer id_160 { stup_dst_883.writeU8(id_159) };
                choose_res_158 = id_160;
              } else {
                auto fun161 { dessser::gen::raql_expr::to_row_binary };
                ta2fe18cae70948742cabb6081fd22a0c id_162 { std::get<0>(*p_0) };
                std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_163 { id_162.sort };
                tf0c8d4f3070907529cc1a83f8baf6fab id_164 { id_163.value() };
                std::optional<dessser::gen::raql_expr::t_ext> id_165 { std::get<1>(id_164) };
                dessser::gen::raql_expr::t_ext id_166 { id_165.value() };
                uint8_t id_167 { 0 };
                Pointer id_168 { stup_dst_883.writeU8(id_167) };
                Pointer id_169 { fun161(id_166, id_168) };
                choose_res_158 = id_169;
              }
              let_res_152 = choose_res_158;
            }
            Pointer let_res_170;
            {
              Pointer stup_dst_884 { let_res_152 };
              ta2fe18cae70948742cabb6081fd22a0c id_171 { std::get<0>(*p_0) };
              std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_172 { id_171.sort };
              tf0c8d4f3070907529cc1a83f8baf6fab id_173 { id_172.value() };
              Lst<dessser::gen::raql_expr::t_ext> id_174 { std::get<2>(id_173) };
              uint32_t id_175 { id_174.size() };
              Vec<1, uint32_t> id_176 {  id_175  };
              Pointer let_res_177;
              {
                Vec<1, uint32_t> leb128_sz_885 { id_176 };
                Vec<1, Pointer> id_178 {  stup_dst_884  };
                Pointer let_res_179;
                {
                  Vec<1, Pointer> leb128_ptr_886 { id_178 };
                  bool while_flag_180 { true };
                  do {
                    uint8_t id_181 { 0 };
                    uint8_t id_182 { 0 };
                    Pointer id_183 { leb128_ptr_886[id_182] };
                    uint32_t id_184 { 128U };
                    uint8_t id_185 { 0 };
                    uint32_t id_186 { leb128_sz_885[id_185] };
                    bool id_187 { bool(id_184 > id_186) };
                    uint8_t choose_res_188;
                    if (id_187) {
                      uint8_t id_189 { 0 };
                      uint32_t id_190 { leb128_sz_885[id_189] };
                      uint8_t id_191 { uint8_t(id_190) };
                      choose_res_188 = id_191;
                    } else {
                      uint8_t id_192 { 0 };
                      uint32_t id_193 { leb128_sz_885[id_192] };
                      uint8_t id_194 { uint8_t(id_193) };
                      uint8_t id_195 { 128 };
                      uint8_t id_196 { uint8_t(id_194 | id_195) };
                      choose_res_188 = id_196;
                    }
                    Pointer id_197 { id_183.writeU8(choose_res_188) };
                    Void id_198 { ((void)(leb128_ptr_886[id_181] = id_197), VOID) };
                    (void)id_198;
                    uint8_t id_199 { 0 };
                    uint8_t id_200 { 0 };
                    uint32_t id_201 { leb128_sz_885[id_200] };
                    uint8_t id_202 { 7 };
                    uint32_t id_203 { uint32_t(id_201 >> id_202) };
                    Void id_204 { ((void)(leb128_sz_885[id_199] = id_203), VOID) };
                    (void)id_204;
                    uint8_t id_205 { 0 };
                    uint32_t id_206 { leb128_sz_885[id_205] };
                    uint32_t id_207 { 0U };
                    bool id_208 { bool(id_206 > id_207) };
                    while_flag_180 = id_208;
                    if (while_flag_180) {
                      (void)VOID;
                    }
                  } while (while_flag_180);
                  (void)VOID;
                  uint8_t id_209 { 0 };
                  Pointer id_210 { leb128_ptr_886[id_209] };
                  let_res_179 = id_210;
                }
                let_res_177 = let_res_179;
              }
              Vec<1, Pointer> id_211 {  let_res_177  };
              Pointer let_res_212;
              {
                Vec<1, Pointer> dst_ref_887 { id_211 };
                int32_t id_213 { 0L };
                Vec<1, int32_t> id_214 {  id_213  };
                Pointer let_res_215;
                {
                  Vec<1, int32_t> n_ref_888 { id_214 };
                  ta2fe18cae70948742cabb6081fd22a0c id_216 { std::get<0>(*p_0) };
                  std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_217 { id_216.sort };
                  tf0c8d4f3070907529cc1a83f8baf6fab id_218 { id_217.value() };
                  Lst<dessser::gen::raql_expr::t_ext> id_219 { std::get<2>(id_218) };
                  for (dessser::gen::raql_expr::t_ext x_889 : id_219) {
                    uint8_t id_220 { 0 };
                    auto fun221 { dessser::gen::raql_expr::to_row_binary };
                    uint8_t id_222 { 0 };
                    Pointer id_223 { dst_ref_887[id_222] };
                    Pointer id_224 { fun221(x_889, id_223) };
                    Void id_225 { ((void)(dst_ref_887[id_220] = id_224), VOID) };
                    (void)id_225;
                    uint8_t id_226 { 0 };
                    int32_t id_227 { 1L };
                    uint8_t id_228 { 0 };
                    int32_t id_229 { n_ref_888[id_228] };
                    int32_t id_230 { int32_t(id_227 + id_229) };
                    Void id_231 { ((void)(n_ref_888[id_226] = id_230), VOID) };
                    (void)id_231;
                    (void)id_231;
                  }
                  (void)VOID;
                  uint8_t id_232 { 0 };
                  Pointer id_233 { dst_ref_887[id_232] };
                  let_res_215 = id_233;
                }
                let_res_212 = let_res_215;
              }
              let_res_170 = let_res_212;
            }
            choose_res_141 = let_res_170;
          }
          let_res_137 = choose_res_141;
        }
        Pointer let_res_234;
        {
          Pointer srec_dst_890 { let_res_137 };
          auto fun235 { dessser::gen::raql_expr::to_row_binary };
          ta2fe18cae70948742cabb6081fd22a0c id_236 { std::get<0>(*p_0) };
          dessser::gen::raql_expr::t_ext id_237 { id_236.where };
          Pointer id_238 { fun235(id_237, srec_dst_890) };
          let_res_234 = id_238;
        }
        Pointer let_res_239;
        {
          Pointer srec_dst_891 { let_res_234 };
          ta2fe18cae70948742cabb6081fd22a0c id_240 { std::get<0>(*p_0) };
          std::optional<dessser::gen::event_time::t_ext> id_241 { id_240.event_time };
          bool id_242 { !(id_241.has_value ()) };
          Pointer choose_res_243;
          if (id_242) {
            uint8_t id_244 { 1 };
            Pointer id_245 { srec_dst_891.writeU8(id_244) };
            choose_res_243 = id_245;
          } else {
            auto fun246 { dessser::gen::event_time::to_row_binary };
            ta2fe18cae70948742cabb6081fd22a0c id_247 { std::get<0>(*p_0) };
            std::optional<dessser::gen::event_time::t_ext> id_248 { id_247.event_time };
            dessser::gen::event_time::t_ext id_249 { id_248.value() };
            uint8_t id_250 { 0 };
            Pointer id_251 { srec_dst_891.writeU8(id_250) };
            Pointer id_252 { fun246(id_249, id_251) };
            choose_res_243 = id_252;
          }
          let_res_239 = choose_res_243;
        }
        Pointer let_res_253;
        {
          Pointer srec_dst_892 { let_res_239 };
          ta2fe18cae70948742cabb6081fd22a0c id_254 { std::get<0>(*p_0) };
          Lst<dessser::gen::raql_expr::t_ext> id_255 { id_254.notifications };
          uint32_t id_256 { id_255.size() };
          Vec<1, uint32_t> id_257 {  id_256  };
          Pointer let_res_258;
          {
            Vec<1, uint32_t> leb128_sz_893 { id_257 };
            Vec<1, Pointer> id_259 {  srec_dst_892  };
            Pointer let_res_260;
            {
              Vec<1, Pointer> leb128_ptr_894 { id_259 };
              bool while_flag_261 { true };
              do {
                uint8_t id_262 { 0 };
                uint8_t id_263 { 0 };
                Pointer id_264 { leb128_ptr_894[id_263] };
                uint32_t id_265 { 128U };
                uint8_t id_266 { 0 };
                uint32_t id_267 { leb128_sz_893[id_266] };
                bool id_268 { bool(id_265 > id_267) };
                uint8_t choose_res_269;
                if (id_268) {
                  uint8_t id_270 { 0 };
                  uint32_t id_271 { leb128_sz_893[id_270] };
                  uint8_t id_272 { uint8_t(id_271) };
                  choose_res_269 = id_272;
                } else {
                  uint8_t id_273 { 0 };
                  uint32_t id_274 { leb128_sz_893[id_273] };
                  uint8_t id_275 { uint8_t(id_274) };
                  uint8_t id_276 { 128 };
                  uint8_t id_277 { uint8_t(id_275 | id_276) };
                  choose_res_269 = id_277;
                }
                Pointer id_278 { id_264.writeU8(choose_res_269) };
                Void id_279 { ((void)(leb128_ptr_894[id_262] = id_278), VOID) };
                (void)id_279;
                uint8_t id_280 { 0 };
                uint8_t id_281 { 0 };
                uint32_t id_282 { leb128_sz_893[id_281] };
                uint8_t id_283 { 7 };
                uint32_t id_284 { uint32_t(id_282 >> id_283) };
                Void id_285 { ((void)(leb128_sz_893[id_280] = id_284), VOID) };
                (void)id_285;
                uint8_t id_286 { 0 };
                uint32_t id_287 { leb128_sz_893[id_286] };
                uint32_t id_288 { 0U };
                bool id_289 { bool(id_287 > id_288) };
                while_flag_261 = id_289;
                if (while_flag_261) {
                  (void)VOID;
                }
              } while (while_flag_261);
              (void)VOID;
              uint8_t id_290 { 0 };
              Pointer id_291 { leb128_ptr_894[id_290] };
              let_res_260 = id_291;
            }
            let_res_258 = let_res_260;
          }
          Vec<1, Pointer> id_292 {  let_res_258  };
          Pointer let_res_293;
          {
            Vec<1, Pointer> dst_ref_895 { id_292 };
            int32_t id_294 { 0L };
            Vec<1, int32_t> id_295 {  id_294  };
            Pointer let_res_296;
            {
              Vec<1, int32_t> n_ref_896 { id_295 };
              ta2fe18cae70948742cabb6081fd22a0c id_297 { std::get<0>(*p_0) };
              Lst<dessser::gen::raql_expr::t_ext> id_298 { id_297.notifications };
              for (dessser::gen::raql_expr::t_ext x_897 : id_298) {
                uint8_t id_299 { 0 };
                auto fun300 { dessser::gen::raql_expr::to_row_binary };
                uint8_t id_301 { 0 };
                Pointer id_302 { dst_ref_895[id_301] };
                Pointer id_303 { fun300(x_897, id_302) };
                Void id_304 { ((void)(dst_ref_895[id_299] = id_303), VOID) };
                (void)id_304;
                uint8_t id_305 { 0 };
                int32_t id_306 { 1L };
                uint8_t id_307 { 0 };
                int32_t id_308 { n_ref_896[id_307] };
                int32_t id_309 { int32_t(id_306 + id_308) };
                Void id_310 { ((void)(n_ref_896[id_305] = id_309), VOID) };
                (void)id_310;
                (void)id_310;
              }
              (void)VOID;
              uint8_t id_311 { 0 };
              Pointer id_312 { dst_ref_895[id_311] };
              let_res_296 = id_312;
            }
            let_res_293 = let_res_296;
          }
          let_res_253 = let_res_293;
        }
        Pointer let_res_313;
        {
          Pointer srec_dst_898 { let_res_253 };
          ta2fe18cae70948742cabb6081fd22a0c id_314 { std::get<0>(*p_0) };
          Lst<dessser::gen::raql_expr::t_ext> id_315 { id_314.key };
          uint32_t id_316 { id_315.size() };
          Vec<1, uint32_t> id_317 {  id_316  };
          Pointer let_res_318;
          {
            Vec<1, uint32_t> leb128_sz_899 { id_317 };
            Vec<1, Pointer> id_319 {  srec_dst_898  };
            Pointer let_res_320;
            {
              Vec<1, Pointer> leb128_ptr_900 { id_319 };
              bool while_flag_321 { true };
              do {
                uint8_t id_322 { 0 };
                uint8_t id_323 { 0 };
                Pointer id_324 { leb128_ptr_900[id_323] };
                uint32_t id_325 { 128U };
                uint8_t id_326 { 0 };
                uint32_t id_327 { leb128_sz_899[id_326] };
                bool id_328 { bool(id_325 > id_327) };
                uint8_t choose_res_329;
                if (id_328) {
                  uint8_t id_330 { 0 };
                  uint32_t id_331 { leb128_sz_899[id_330] };
                  uint8_t id_332 { uint8_t(id_331) };
                  choose_res_329 = id_332;
                } else {
                  uint8_t id_333 { 0 };
                  uint32_t id_334 { leb128_sz_899[id_333] };
                  uint8_t id_335 { uint8_t(id_334) };
                  uint8_t id_336 { 128 };
                  uint8_t id_337 { uint8_t(id_335 | id_336) };
                  choose_res_329 = id_337;
                }
                Pointer id_338 { id_324.writeU8(choose_res_329) };
                Void id_339 { ((void)(leb128_ptr_900[id_322] = id_338), VOID) };
                (void)id_339;
                uint8_t id_340 { 0 };
                uint8_t id_341 { 0 };
                uint32_t id_342 { leb128_sz_899[id_341] };
                uint8_t id_343 { 7 };
                uint32_t id_344 { uint32_t(id_342 >> id_343) };
                Void id_345 { ((void)(leb128_sz_899[id_340] = id_344), VOID) };
                (void)id_345;
                uint8_t id_346 { 0 };
                uint32_t id_347 { leb128_sz_899[id_346] };
                uint32_t id_348 { 0U };
                bool id_349 { bool(id_347 > id_348) };
                while_flag_321 = id_349;
                if (while_flag_321) {
                  (void)VOID;
                }
              } while (while_flag_321);
              (void)VOID;
              uint8_t id_350 { 0 };
              Pointer id_351 { leb128_ptr_900[id_350] };
              let_res_320 = id_351;
            }
            let_res_318 = let_res_320;
          }
          Vec<1, Pointer> id_352 {  let_res_318  };
          Pointer let_res_353;
          {
            Vec<1, Pointer> dst_ref_901 { id_352 };
            int32_t id_354 { 0L };
            Vec<1, int32_t> id_355 {  id_354  };
            Pointer let_res_356;
            {
              Vec<1, int32_t> n_ref_902 { id_355 };
              ta2fe18cae70948742cabb6081fd22a0c id_357 { std::get<0>(*p_0) };
              Lst<dessser::gen::raql_expr::t_ext> id_358 { id_357.key };
              for (dessser::gen::raql_expr::t_ext x_903 : id_358) {
                uint8_t id_359 { 0 };
                auto fun360 { dessser::gen::raql_expr::to_row_binary };
                uint8_t id_361 { 0 };
                Pointer id_362 { dst_ref_901[id_361] };
                Pointer id_363 { fun360(x_903, id_362) };
                Void id_364 { ((void)(dst_ref_901[id_359] = id_363), VOID) };
                (void)id_364;
                uint8_t id_365 { 0 };
                int32_t id_366 { 1L };
                uint8_t id_367 { 0 };
                int32_t id_368 { n_ref_902[id_367] };
                int32_t id_369 { int32_t(id_366 + id_368) };
                Void id_370 { ((void)(n_ref_902[id_365] = id_369), VOID) };
                (void)id_370;
                (void)id_370;
              }
              (void)VOID;
              uint8_t id_371 { 0 };
              Pointer id_372 { dst_ref_901[id_371] };
              let_res_356 = id_372;
            }
            let_res_353 = let_res_356;
          }
          let_res_313 = let_res_353;
        }
        Pointer let_res_373;
        {
          Pointer srec_dst_904 { let_res_313 };
          auto fun374 { dessser::gen::raql_expr::to_row_binary };
          ta2fe18cae70948742cabb6081fd22a0c id_375 { std::get<0>(*p_0) };
          dessser::gen::raql_expr::t_ext id_376 { id_375.commit_cond };
          Pointer id_377 { fun374(id_376, srec_dst_904) };
          let_res_373 = id_377;
        }
        Pointer let_res_378;
        {
          Pointer srec_dst_905 { let_res_373 };
          ta2fe18cae70948742cabb6081fd22a0c id_379 { std::get<0>(*p_0) };
          bool id_380 { id_379.commit_before };
          uint8_t id_381 { uint8_t(id_380) };
          Pointer id_382 { srec_dst_905.writeU8(id_381) };
          let_res_378 = id_382;
        }
        Pointer let_res_383;
        {
          Pointer srec_dst_906 { let_res_378 };
          auto fun384 { dessser::gen::raql_flush_method::to_row_binary };
          ta2fe18cae70948742cabb6081fd22a0c id_385 { std::get<0>(*p_0) };
          dessser::gen::raql_flush_method::t_ext id_386 { id_385.flush_how };
          Pointer id_387 { fun384(id_386, srec_dst_906) };
          let_res_383 = id_387;
        }
        Pointer let_res_388;
        {
          Pointer srec_dst_907 { let_res_383 };
          ta2fe18cae70948742cabb6081fd22a0c id_389 { std::get<0>(*p_0) };
          Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_390 { id_389.from };
          uint32_t id_391 { id_390.size() };
          Vec<1, uint32_t> id_392 {  id_391  };
          Pointer let_res_393;
          {
            Vec<1, uint32_t> leb128_sz_908 { id_392 };
            Vec<1, Pointer> id_394 {  srec_dst_907  };
            Pointer let_res_395;
            {
              Vec<1, Pointer> leb128_ptr_909 { id_394 };
              bool while_flag_396 { true };
              do {
                uint8_t id_397 { 0 };
                uint8_t id_398 { 0 };
                Pointer id_399 { leb128_ptr_909[id_398] };
                uint32_t id_400 { 128U };
                uint8_t id_401 { 0 };
                uint32_t id_402 { leb128_sz_908[id_401] };
                bool id_403 { bool(id_400 > id_402) };
                uint8_t choose_res_404;
                if (id_403) {
                  uint8_t id_405 { 0 };
                  uint32_t id_406 { leb128_sz_908[id_405] };
                  uint8_t id_407 { uint8_t(id_406) };
                  choose_res_404 = id_407;
                } else {
                  uint8_t id_408 { 0 };
                  uint32_t id_409 { leb128_sz_908[id_408] };
                  uint8_t id_410 { uint8_t(id_409) };
                  uint8_t id_411 { 128 };
                  uint8_t id_412 { uint8_t(id_410 | id_411) };
                  choose_res_404 = id_412;
                }
                Pointer id_413 { id_399.writeU8(choose_res_404) };
                Void id_414 { ((void)(leb128_ptr_909[id_397] = id_413), VOID) };
                (void)id_414;
                uint8_t id_415 { 0 };
                uint8_t id_416 { 0 };
                uint32_t id_417 { leb128_sz_908[id_416] };
                uint8_t id_418 { 7 };
                uint32_t id_419 { uint32_t(id_417 >> id_418) };
                Void id_420 { ((void)(leb128_sz_908[id_415] = id_419), VOID) };
                (void)id_420;
                uint8_t id_421 { 0 };
                uint32_t id_422 { leb128_sz_908[id_421] };
                uint32_t id_423 { 0U };
                bool id_424 { bool(id_422 > id_423) };
                while_flag_396 = id_424;
                if (while_flag_396) {
                  (void)VOID;
                }
              } while (while_flag_396);
              (void)VOID;
              uint8_t id_425 { 0 };
              Pointer id_426 { leb128_ptr_909[id_425] };
              let_res_395 = id_426;
            }
            let_res_393 = let_res_395;
          }
          Vec<1, Pointer> id_427 {  let_res_393  };
          Pointer let_res_428;
          {
            Vec<1, Pointer> dst_ref_910 { id_427 };
            int32_t id_429 { 0L };
            Vec<1, int32_t> id_430 {  id_429  };
            Pointer let_res_431;
            {
              Vec<1, int32_t> n_ref_911 { id_430 };
              ta2fe18cae70948742cabb6081fd22a0c id_432 { std::get<0>(*p_0) };
              Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_433 { id_432.from };
              for (t7c6bbe37b66fb3a66c00c4bd1bfc4369 x_912 : id_433) {
                uint8_t id_434 { 0 };
                uint8_t id_435 { 0 };
                Pointer id_436 { dst_ref_910[id_435] };
                uint16_t id_437 { uint16_t(x_912.index()) };
                Pointer id_438 { id_436.writeU16Le(id_437) };
                Pointer let_res_439;
                {
                  Pointer ssum_dst_914 { id_438 };
                  uint16_t id_440 { 0 };
                  uint16_t id_441 { uint16_t(x_912.index()) };
                  bool id_442 { bool(id_440 == id_441) };
                  Pointer choose_res_443;
                  if (id_442) {
                    t9b471a57e45588f3795bf9ca91c31ff6 id_444 { std::get<0>(x_912) };
                    te10a95f610a64bfb7ccea542c54f0a25 id_445 { std::get<0>(id_444) };
                    uint16_t id_446 { uint16_t(id_445.index()) };
                    Pointer id_447 { ssum_dst_914.writeU16Le(id_446) };
                    Pointer let_res_448;
                    {
                      Pointer ssum_dst_916 { id_447 };
                      uint16_t id_449 { 0 };
                      t9b471a57e45588f3795bf9ca91c31ff6 id_450 { std::get<0>(x_912) };
                      te10a95f610a64bfb7ccea542c54f0a25 id_451 { std::get<0>(id_450) };
                      uint16_t id_452 { uint16_t(id_451.index()) };
                      bool id_453 { bool(id_449 == id_452) };
                      Pointer choose_res_454;
                      if (id_453) {
                        choose_res_454 = ssum_dst_916;
                      } else {
                        uint16_t id_455 { 1 };
                        t9b471a57e45588f3795bf9ca91c31ff6 id_456 { std::get<0>(x_912) };
                        te10a95f610a64bfb7ccea542c54f0a25 id_457 { std::get<0>(id_456) };
                        uint16_t id_458 { uint16_t(id_457.index()) };
                        bool id_459 { bool(id_455 == id_458) };
                        Pointer choose_res_460;
                        if (id_459) {
                          t9b471a57e45588f3795bf9ca91c31ff6 id_461 { std::get<0>(x_912) };
                          te10a95f610a64bfb7ccea542c54f0a25 id_462 { std::get<0>(id_461) };
                          std::string id_463 { std::get<1>(id_462) };
                          uint32_t id_464 { (uint32_t)id_463.size() };
                          Vec<1, uint32_t> id_465 {  id_464  };
                          Pointer let_res_466;
                          {
                            Vec<1, uint32_t> leb128_sz_917 { id_465 };
                            Vec<1, Pointer> id_467 {  ssum_dst_916  };
                            Pointer let_res_468;
                            {
                              Vec<1, Pointer> leb128_ptr_918 { id_467 };
                              bool while_flag_469 { true };
                              do {
                                uint8_t id_470 { 0 };
                                uint8_t id_471 { 0 };
                                Pointer id_472 { leb128_ptr_918[id_471] };
                                uint32_t id_473 { 128U };
                                uint8_t id_474 { 0 };
                                uint32_t id_475 { leb128_sz_917[id_474] };
                                bool id_476 { bool(id_473 > id_475) };
                                uint8_t choose_res_477;
                                if (id_476) {
                                  uint8_t id_478 { 0 };
                                  uint32_t id_479 { leb128_sz_917[id_478] };
                                  uint8_t id_480 { uint8_t(id_479) };
                                  choose_res_477 = id_480;
                                } else {
                                  uint8_t id_481 { 0 };
                                  uint32_t id_482 { leb128_sz_917[id_481] };
                                  uint8_t id_483 { uint8_t(id_482) };
                                  uint8_t id_484 { 128 };
                                  uint8_t id_485 { uint8_t(id_483 | id_484) };
                                  choose_res_477 = id_485;
                                }
                                Pointer id_486 { id_472.writeU8(choose_res_477) };
                                Void id_487 { ((void)(leb128_ptr_918[id_470] = id_486), VOID) };
                                (void)id_487;
                                uint8_t id_488 { 0 };
                                uint8_t id_489 { 0 };
                                uint32_t id_490 { leb128_sz_917[id_489] };
                                uint8_t id_491 { 7 };
                                uint32_t id_492 { uint32_t(id_490 >> id_491) };
                                Void id_493 { ((void)(leb128_sz_917[id_488] = id_492), VOID) };
                                (void)id_493;
                                uint8_t id_494 { 0 };
                                uint32_t id_495 { leb128_sz_917[id_494] };
                                uint32_t id_496 { 0U };
                                bool id_497 { bool(id_495 > id_496) };
                                while_flag_469 = id_497;
                                if (while_flag_469) {
                                  (void)VOID;
                                }
                              } while (while_flag_469);
                              (void)VOID;
                              uint8_t id_498 { 0 };
                              Pointer id_499 { leb128_ptr_918[id_498] };
                              let_res_468 = id_499;
                            }
                            let_res_466 = let_res_468;
                          }
                          t9b471a57e45588f3795bf9ca91c31ff6 id_500 { std::get<0>(x_912) };
                          te10a95f610a64bfb7ccea542c54f0a25 id_501 { std::get<0>(id_500) };
                          std::string id_502 { std::get<1>(id_501) };
                          Bytes id_503 { id_502 };
                          Pointer id_504 { let_res_466.writeBytes(id_503) };
                          choose_res_460 = id_504;
                        } else {
                          t9b471a57e45588f3795bf9ca91c31ff6 id_505 { std::get<0>(x_912) };
                          te10a95f610a64bfb7ccea542c54f0a25 id_506 { std::get<0>(id_505) };
                          uint16_t id_507 { uint16_t(id_506.index()) };
                          uint16_t id_508 { 2 };
                          bool id_509 { bool(id_507 == id_508) };
                          Void id_510 { ((void)(assert(id_509)), VOID) };
                          (void)id_510;
                          choose_res_460 = ssum_dst_916;
                        }
                        choose_res_454 = choose_res_460;
                      }
                      let_res_448 = choose_res_454;
                    }
                    Pointer let_res_511;
                    {
                      Pointer stup_dst_919 { let_res_448 };
                      t9b471a57e45588f3795bf9ca91c31ff6 id_512 { std::get<0>(x_912) };
                      std::optional<std::string> id_513 { std::get<1>(id_512) };
                      bool id_514 { !(id_513.has_value ()) };
                      Pointer choose_res_515;
                      if (id_514) {
                        uint8_t id_516 { 1 };
                        Pointer id_517 { stup_dst_919.writeU8(id_516) };
                        choose_res_515 = id_517;
                      } else {
                        t9b471a57e45588f3795bf9ca91c31ff6 id_518 { std::get<0>(x_912) };
                        std::optional<std::string> id_519 { std::get<1>(id_518) };
                        std::string id_520 { id_519.value() };
                        uint32_t id_521 { (uint32_t)id_520.size() };
                        Vec<1, uint32_t> id_522 {  id_521  };
                        Pointer let_res_523;
                        {
                          Vec<1, uint32_t> leb128_sz_920 { id_522 };
                          uint8_t id_524 { 0 };
                          Pointer id_525 { stup_dst_919.writeU8(id_524) };
                          Vec<1, Pointer> id_526 {  id_525  };
                          Pointer let_res_527;
                          {
                            Vec<1, Pointer> leb128_ptr_921 { id_526 };
                            bool while_flag_528 { true };
                            do {
                              uint8_t id_529 { 0 };
                              uint8_t id_530 { 0 };
                              Pointer id_531 { leb128_ptr_921[id_530] };
                              uint32_t id_532 { 128U };
                              uint8_t id_533 { 0 };
                              uint32_t id_534 { leb128_sz_920[id_533] };
                              bool id_535 { bool(id_532 > id_534) };
                              uint8_t choose_res_536;
                              if (id_535) {
                                uint8_t id_537 { 0 };
                                uint32_t id_538 { leb128_sz_920[id_537] };
                                uint8_t id_539 { uint8_t(id_538) };
                                choose_res_536 = id_539;
                              } else {
                                uint8_t id_540 { 0 };
                                uint32_t id_541 { leb128_sz_920[id_540] };
                                uint8_t id_542 { uint8_t(id_541) };
                                uint8_t id_543 { 128 };
                                uint8_t id_544 { uint8_t(id_542 | id_543) };
                                choose_res_536 = id_544;
                              }
                              Pointer id_545 { id_531.writeU8(choose_res_536) };
                              Void id_546 { ((void)(leb128_ptr_921[id_529] = id_545), VOID) };
                              (void)id_546;
                              uint8_t id_547 { 0 };
                              uint8_t id_548 { 0 };
                              uint32_t id_549 { leb128_sz_920[id_548] };
                              uint8_t id_550 { 7 };
                              uint32_t id_551 { uint32_t(id_549 >> id_550) };
                              Void id_552 { ((void)(leb128_sz_920[id_547] = id_551), VOID) };
                              (void)id_552;
                              uint8_t id_553 { 0 };
                              uint32_t id_554 { leb128_sz_920[id_553] };
                              uint32_t id_555 { 0U };
                              bool id_556 { bool(id_554 > id_555) };
                              while_flag_528 = id_556;
                              if (while_flag_528) {
                                (void)VOID;
                              }
                            } while (while_flag_528);
                            (void)VOID;
                            uint8_t id_557 { 0 };
                            Pointer id_558 { leb128_ptr_921[id_557] };
                            let_res_527 = id_558;
                          }
                          let_res_523 = let_res_527;
                        }
                        t9b471a57e45588f3795bf9ca91c31ff6 id_559 { std::get<0>(x_912) };
                        std::optional<std::string> id_560 { std::get<1>(id_559) };
                        std::string id_561 { id_560.value() };
                        Bytes id_562 { id_561 };
                        Pointer id_563 { let_res_523.writeBytes(id_562) };
                        choose_res_515 = id_563;
                      }
                      let_res_511 = choose_res_515;
                    }
                    Pointer let_res_564;
                    {
                      Pointer stup_dst_922 { let_res_511 };
                      auto fun565 { dessser::gen::function_name::to_row_binary };
                      t9b471a57e45588f3795bf9ca91c31ff6 id_566 { std::get<0>(x_912) };
                      dessser::gen::function_name::t_ext id_567 { std::get<2>(id_566) };
                      Pointer id_568 { fun565(id_567, stup_dst_922) };
                      let_res_564 = id_568;
                    }
                    choose_res_443 = let_res_564;
                  } else {
                    uint16_t id_569 { uint16_t(x_912.index()) };
                    uint16_t id_570 { 1 };
                    bool id_571 { bool(id_569 == id_570) };
                    Void id_572 { ((void)(assert(id_571)), VOID) };
                    (void)id_572;
                    t* id_573 { std::get<1>(x_912) };
                    Pointer id_574 { fun0(id_573, ssum_dst_914) };
                    choose_res_443 = id_574;
                  }
                  let_res_439 = choose_res_443;
                }
                Void id_575 { ((void)(dst_ref_910[id_434] = let_res_439), VOID) };
                (void)id_575;
                uint8_t id_576 { 0 };
                int32_t id_577 { 1L };
                uint8_t id_578 { 0 };
                int32_t id_579 { n_ref_911[id_578] };
                int32_t id_580 { int32_t(id_577 + id_579) };
                Void id_581 { ((void)(n_ref_911[id_576] = id_580), VOID) };
                (void)id_581;
                (void)id_581;
              }
              (void)VOID;
              uint8_t id_582 { 0 };
              Pointer id_583 { dst_ref_910[id_582] };
              let_res_431 = id_583;
            }
            let_res_428 = let_res_431;
          }
          let_res_388 = let_res_428;
        }
        Pointer let_res_584;
        {
          Pointer srec_dst_923 { let_res_388 };
          ta2fe18cae70948742cabb6081fd22a0c id_585 { std::get<0>(*p_0) };
          std::optional<dessser::gen::raql_expr::t_ext> id_586 { id_585.every };
          bool id_587 { !(id_586.has_value ()) };
          Pointer choose_res_588;
          if (id_587) {
            uint8_t id_589 { 1 };
            Pointer id_590 { srec_dst_923.writeU8(id_589) };
            choose_res_588 = id_590;
          } else {
            auto fun591 { dessser::gen::raql_expr::to_row_binary };
            ta2fe18cae70948742cabb6081fd22a0c id_592 { std::get<0>(*p_0) };
            std::optional<dessser::gen::raql_expr::t_ext> id_593 { id_592.every };
            dessser::gen::raql_expr::t_ext id_594 { id_593.value() };
            uint8_t id_595 { 0 };
            Pointer id_596 { srec_dst_923.writeU8(id_595) };
            Pointer id_597 { fun591(id_594, id_596) };
            choose_res_588 = id_597;
          }
          let_res_584 = choose_res_588;
        }
        Pointer let_res_598;
        {
          Pointer srec_dst_924 { let_res_584 };
          ta2fe18cae70948742cabb6081fd22a0c id_599 { std::get<0>(*p_0) };
          Lst<dessser::gen::field_name::t_ext> id_600 { id_599.factors };
          uint32_t id_601 { id_600.size() };
          Vec<1, uint32_t> id_602 {  id_601  };
          Pointer let_res_603;
          {
            Vec<1, uint32_t> leb128_sz_925 { id_602 };
            Vec<1, Pointer> id_604 {  srec_dst_924  };
            Pointer let_res_605;
            {
              Vec<1, Pointer> leb128_ptr_926 { id_604 };
              bool while_flag_606 { true };
              do {
                uint8_t id_607 { 0 };
                uint8_t id_608 { 0 };
                Pointer id_609 { leb128_ptr_926[id_608] };
                uint32_t id_610 { 128U };
                uint8_t id_611 { 0 };
                uint32_t id_612 { leb128_sz_925[id_611] };
                bool id_613 { bool(id_610 > id_612) };
                uint8_t choose_res_614;
                if (id_613) {
                  uint8_t id_615 { 0 };
                  uint32_t id_616 { leb128_sz_925[id_615] };
                  uint8_t id_617 { uint8_t(id_616) };
                  choose_res_614 = id_617;
                } else {
                  uint8_t id_618 { 0 };
                  uint32_t id_619 { leb128_sz_925[id_618] };
                  uint8_t id_620 { uint8_t(id_619) };
                  uint8_t id_621 { 128 };
                  uint8_t id_622 { uint8_t(id_620 | id_621) };
                  choose_res_614 = id_622;
                }
                Pointer id_623 { id_609.writeU8(choose_res_614) };
                Void id_624 { ((void)(leb128_ptr_926[id_607] = id_623), VOID) };
                (void)id_624;
                uint8_t id_625 { 0 };
                uint8_t id_626 { 0 };
                uint32_t id_627 { leb128_sz_925[id_626] };
                uint8_t id_628 { 7 };
                uint32_t id_629 { uint32_t(id_627 >> id_628) };
                Void id_630 { ((void)(leb128_sz_925[id_625] = id_629), VOID) };
                (void)id_630;
                uint8_t id_631 { 0 };
                uint32_t id_632 { leb128_sz_925[id_631] };
                uint32_t id_633 { 0U };
                bool id_634 { bool(id_632 > id_633) };
                while_flag_606 = id_634;
                if (while_flag_606) {
                  (void)VOID;
                }
              } while (while_flag_606);
              (void)VOID;
              uint8_t id_635 { 0 };
              Pointer id_636 { leb128_ptr_926[id_635] };
              let_res_605 = id_636;
            }
            let_res_603 = let_res_605;
          }
          Vec<1, Pointer> id_637 {  let_res_603  };
          Pointer let_res_638;
          {
            Vec<1, Pointer> dst_ref_927 { id_637 };
            int32_t id_639 { 0L };
            Vec<1, int32_t> id_640 {  id_639  };
            Pointer let_res_641;
            {
              Vec<1, int32_t> n_ref_928 { id_640 };
              ta2fe18cae70948742cabb6081fd22a0c id_642 { std::get<0>(*p_0) };
              Lst<dessser::gen::field_name::t_ext> id_643 { id_642.factors };
              for (dessser::gen::field_name::t_ext x_929 : id_643) {
                uint8_t id_644 { 0 };
                auto fun645 { dessser::gen::field_name::to_row_binary };
                uint8_t id_646 { 0 };
                Pointer id_647 { dst_ref_927[id_646] };
                Pointer id_648 { fun645(x_929, id_647) };
                Void id_649 { ((void)(dst_ref_927[id_644] = id_648), VOID) };
                (void)id_649;
                uint8_t id_650 { 0 };
                int32_t id_651 { 1L };
                uint8_t id_652 { 0 };
                int32_t id_653 { n_ref_928[id_652] };
                int32_t id_654 { int32_t(id_651 + id_653) };
                Void id_655 { ((void)(n_ref_928[id_650] = id_654), VOID) };
                (void)id_655;
                (void)id_655;
              }
              (void)VOID;
              uint8_t id_656 { 0 };
              Pointer id_657 { dst_ref_927[id_656] };
              let_res_641 = id_657;
            }
            let_res_638 = let_res_641;
          }
          let_res_598 = let_res_638;
        }
        choose_res_7 = let_res_598;
      } else {
        uint16_t id_658 { 1 };
        uint16_t id_659 { uint16_t(p_0->index()) };
        bool id_660 { bool(id_658 == id_659) };
        Pointer choose_res_661;
        if (id_660) {
          t1d5c57287ee550c3ccac78b88bba5862 id_662 { std::get<1>(*p_0) };
          tf708b6568b9bac184e3f5da3a64f4419 id_663 { id_662.source };
          uint16_t id_664 { uint16_t(id_663.index()) };
          Pointer id_665 { ssum_dst_810.writeU16Le(id_664) };
          Pointer let_res_666;
          {
            Pointer ssum_dst_822 { id_665 };
            uint16_t id_667 { 0 };
            t1d5c57287ee550c3ccac78b88bba5862 id_668 { std::get<1>(*p_0) };
            tf708b6568b9bac184e3f5da3a64f4419 id_669 { id_668.source };
            uint16_t id_670 { uint16_t(id_669.index()) };
            bool id_671 { bool(id_667 == id_670) };
            Pointer choose_res_672;
            if (id_671) {
              auto fun673 { dessser::gen::raql_expr::to_row_binary };
              t1d5c57287ee550c3ccac78b88bba5862 id_674 { std::get<1>(*p_0) };
              tf708b6568b9bac184e3f5da3a64f4419 id_675 { id_674.source };
              ta828a76692b94aa6a15973ace224bedc id_676 { std::get<0>(id_675) };
              dessser::gen::raql_expr::t_ext id_677 { id_676.fname };
              Pointer id_678 { fun673(id_677, ssum_dst_822) };
              Pointer let_res_679;
              {
                Pointer srec_dst_838 { id_678 };
                t1d5c57287ee550c3ccac78b88bba5862 id_680 { std::get<1>(*p_0) };
                tf708b6568b9bac184e3f5da3a64f4419 id_681 { id_680.source };
                ta828a76692b94aa6a15973ace224bedc id_682 { std::get<0>(id_681) };
                std::optional<dessser::gen::raql_expr::t_ext> id_683 { id_682.preprocessor };
                bool id_684 { !(id_683.has_value ()) };
                Pointer choose_res_685;
                if (id_684) {
                  uint8_t id_686 { 1 };
                  Pointer id_687 { srec_dst_838.writeU8(id_686) };
                  choose_res_685 = id_687;
                } else {
                  auto fun688 { dessser::gen::raql_expr::to_row_binary };
                  t1d5c57287ee550c3ccac78b88bba5862 id_689 { std::get<1>(*p_0) };
                  tf708b6568b9bac184e3f5da3a64f4419 id_690 { id_689.source };
                  ta828a76692b94aa6a15973ace224bedc id_691 { std::get<0>(id_690) };
                  std::optional<dessser::gen::raql_expr::t_ext> id_692 { id_691.preprocessor };
                  dessser::gen::raql_expr::t_ext id_693 { id_692.value() };
                  uint8_t id_694 { 0 };
                  Pointer id_695 { srec_dst_838.writeU8(id_694) };
                  Pointer id_696 { fun688(id_693, id_695) };
                  choose_res_685 = id_696;
                }
                let_res_679 = choose_res_685;
              }
              Pointer let_res_697;
              {
                Pointer srec_dst_839 { let_res_679 };
                auto fun698 { dessser::gen::raql_expr::to_row_binary };
                t1d5c57287ee550c3ccac78b88bba5862 id_699 { std::get<1>(*p_0) };
                tf708b6568b9bac184e3f5da3a64f4419 id_700 { id_699.source };
                ta828a76692b94aa6a15973ace224bedc id_701 { std::get<0>(id_700) };
                dessser::gen::raql_expr::t_ext id_702 { id_701.unlink };
                Pointer id_703 { fun698(id_702, srec_dst_839) };
                let_res_697 = id_703;
              }
              choose_res_672 = let_res_697;
            } else {
              t1d5c57287ee550c3ccac78b88bba5862 id_704 { std::get<1>(*p_0) };
              tf708b6568b9bac184e3f5da3a64f4419 id_705 { id_704.source };
              uint16_t id_706 { uint16_t(id_705.index()) };
              uint16_t id_707 { 1 };
              bool id_708 { bool(id_706 == id_707) };
              Void id_709 { ((void)(assert(id_708)), VOID) };
              (void)id_709;
              t1d5c57287ee550c3ccac78b88bba5862 id_710 { std::get<1>(*p_0) };
              tf708b6568b9bac184e3f5da3a64f4419 id_711 { id_710.source };
              te6ac276a1b6044b9474a56a7da93a611 id_712 { std::get<1>(id_711) };
              Lst<tcd17c85cefeae7a860c0732c05eaeaed> id_713 { id_712.options };
              uint32_t id_714 { id_713.size() };
              Vec<1, uint32_t> id_715 {  id_714  };
              Pointer let_res_716;
              {
                Vec<1, uint32_t> leb128_sz_823 { id_715 };
                Vec<1, Pointer> id_717 {  ssum_dst_822  };
                Pointer let_res_718;
                {
                  Vec<1, Pointer> leb128_ptr_824 { id_717 };
                  bool while_flag_719 { true };
                  do {
                    uint8_t id_720 { 0 };
                    uint8_t id_721 { 0 };
                    Pointer id_722 { leb128_ptr_824[id_721] };
                    uint32_t id_723 { 128U };
                    uint8_t id_724 { 0 };
                    uint32_t id_725 { leb128_sz_823[id_724] };
                    bool id_726 { bool(id_723 > id_725) };
                    uint8_t choose_res_727;
                    if (id_726) {
                      uint8_t id_728 { 0 };
                      uint32_t id_729 { leb128_sz_823[id_728] };
                      uint8_t id_730 { uint8_t(id_729) };
                      choose_res_727 = id_730;
                    } else {
                      uint8_t id_731 { 0 };
                      uint32_t id_732 { leb128_sz_823[id_731] };
                      uint8_t id_733 { uint8_t(id_732) };
                      uint8_t id_734 { 128 };
                      uint8_t id_735 { uint8_t(id_733 | id_734) };
                      choose_res_727 = id_735;
                    }
                    Pointer id_736 { id_722.writeU8(choose_res_727) };
                    Void id_737 { ((void)(leb128_ptr_824[id_720] = id_736), VOID) };
                    (void)id_737;
                    uint8_t id_738 { 0 };
                    uint8_t id_739 { 0 };
                    uint32_t id_740 { leb128_sz_823[id_739] };
                    uint8_t id_741 { 7 };
                    uint32_t id_742 { uint32_t(id_740 >> id_741) };
                    Void id_743 { ((void)(leb128_sz_823[id_738] = id_742), VOID) };
                    (void)id_743;
                    uint8_t id_744 { 0 };
                    uint32_t id_745 { leb128_sz_823[id_744] };
                    uint32_t id_746 { 0U };
                    bool id_747 { bool(id_745 > id_746) };
                    while_flag_719 = id_747;
                    if (while_flag_719) {
                      (void)VOID;
                    }
                  } while (while_flag_719);
                  (void)VOID;
                  uint8_t id_748 { 0 };
                  Pointer id_749 { leb128_ptr_824[id_748] };
                  let_res_718 = id_749;
                }
                let_res_716 = let_res_718;
              }
              Vec<1, Pointer> id_750 {  let_res_716  };
              Pointer let_res_751;
              {
                Vec<1, Pointer> dst_ref_825 { id_750 };
                int32_t id_752 { 0L };
                Vec<1, int32_t> id_753 {  id_752  };
                Pointer let_res_754;
                {
                  Vec<1, int32_t> n_ref_826 { id_753 };
                  t1d5c57287ee550c3ccac78b88bba5862 id_755 { std::get<1>(*p_0) };
                  tf708b6568b9bac184e3f5da3a64f4419 id_756 { id_755.source };
                  te6ac276a1b6044b9474a56a7da93a611 id_757 { std::get<1>(id_756) };
                  Lst<tcd17c85cefeae7a860c0732c05eaeaed> id_758 { id_757.options };
                  for (tcd17c85cefeae7a860c0732c05eaeaed x_827 : id_758) {
                    uint8_t id_759 { 0 };
                    uint8_t id_760 { 0 };
                    Pointer id_761 { dst_ref_825[id_760] };
                    Pointer let_res_762;
                    {
                      Pointer stup_dst_828 { id_761 };
                      std::string id_763 { std::get<0>(x_827) };
                      uint32_t id_764 { (uint32_t)id_763.size() };
                      Vec<1, uint32_t> id_765 {  id_764  };
                      Pointer let_res_766;
                      {
                        Vec<1, uint32_t> leb128_sz_829 { id_765 };
                        Vec<1, Pointer> id_767 {  stup_dst_828  };
                        Pointer let_res_768;
                        {
                          Vec<1, Pointer> leb128_ptr_830 { id_767 };
                          bool while_flag_769 { true };
                          do {
                            uint8_t id_770 { 0 };
                            uint8_t id_771 { 0 };
                            Pointer id_772 { leb128_ptr_830[id_771] };
                            uint32_t id_773 { 128U };
                            uint8_t id_774 { 0 };
                            uint32_t id_775 { leb128_sz_829[id_774] };
                            bool id_776 { bool(id_773 > id_775) };
                            uint8_t choose_res_777;
                            if (id_776) {
                              uint8_t id_778 { 0 };
                              uint32_t id_779 { leb128_sz_829[id_778] };
                              uint8_t id_780 { uint8_t(id_779) };
                              choose_res_777 = id_780;
                            } else {
                              uint8_t id_781 { 0 };
                              uint32_t id_782 { leb128_sz_829[id_781] };
                              uint8_t id_783 { uint8_t(id_782) };
                              uint8_t id_784 { 128 };
                              uint8_t id_785 { uint8_t(id_783 | id_784) };
                              choose_res_777 = id_785;
                            }
                            Pointer id_786 { id_772.writeU8(choose_res_777) };
                            Void id_787 { ((void)(leb128_ptr_830[id_770] = id_786), VOID) };
                            (void)id_787;
                            uint8_t id_788 { 0 };
                            uint8_t id_789 { 0 };
                            uint32_t id_790 { leb128_sz_829[id_789] };
                            uint8_t id_791 { 7 };
                            uint32_t id_792 { uint32_t(id_790 >> id_791) };
                            Void id_793 { ((void)(leb128_sz_829[id_788] = id_792), VOID) };
                            (void)id_793;
                            uint8_t id_794 { 0 };
                            uint32_t id_795 { leb128_sz_829[id_794] };
                            uint32_t id_796 { 0U };
                            bool id_797 { bool(id_795 > id_796) };
                            while_flag_769 = id_797;
                            if (while_flag_769) {
                              (void)VOID;
                            }
                          } while (while_flag_769);
                          (void)VOID;
                          uint8_t id_798 { 0 };
                          Pointer id_799 { leb128_ptr_830[id_798] };
                          let_res_768 = id_799;
                        }
                        let_res_766 = let_res_768;
                      }
                      std::string id_800 { std::get<0>(x_827) };
                      Bytes id_801 { id_800 };
                      Pointer id_802 { let_res_766.writeBytes(id_801) };
                      let_res_762 = id_802;
                    }
                    Pointer let_res_803;
                    {
                      Pointer stup_dst_831 { let_res_762 };
                      auto fun804 { dessser::gen::raql_expr::to_row_binary };
                      dessser::gen::raql_expr::t_ext id_805 { std::get<1>(x_827) };
                      Pointer id_806 { fun804(id_805, stup_dst_831) };
                      let_res_803 = id_806;
                    }
                    Void id_807 { ((void)(dst_ref_825[id_759] = let_res_803), VOID) };
                    (void)id_807;
                    uint8_t id_808 { 0 };
                    int32_t id_809 { 1L };
                    uint8_t id_810 { 0 };
                    int32_t id_811 { n_ref_826[id_810] };
                    int32_t id_812 { int32_t(id_809 + id_811) };
                    Void id_813 { ((void)(n_ref_826[id_808] = id_812), VOID) };
                    (void)id_813;
                    (void)id_813;
                  }
                  (void)VOID;
                  uint8_t id_814 { 0 };
                  Pointer id_815 { dst_ref_825[id_814] };
                  let_res_754 = id_815;
                }
                let_res_751 = let_res_754;
              }
              Pointer let_res_816;
              {
                Pointer srec_dst_832 { let_res_751 };
                auto fun817 { dessser::gen::raql_expr::to_row_binary };
                t1d5c57287ee550c3ccac78b88bba5862 id_818 { std::get<1>(*p_0) };
                tf708b6568b9bac184e3f5da3a64f4419 id_819 { id_818.source };
                te6ac276a1b6044b9474a56a7da93a611 id_820 { std::get<1>(id_819) };
                dessser::gen::raql_expr::t_ext id_821 { id_820.topic };
                Pointer id_822 { fun817(id_821, srec_dst_832) };
                let_res_816 = id_822;
              }
              Pointer let_res_823;
              {
                Pointer srec_dst_833 { let_res_816 };
                t1d5c57287ee550c3ccac78b88bba5862 id_824 { std::get<1>(*p_0) };
                tf708b6568b9bac184e3f5da3a64f4419 id_825 { id_824.source };
                te6ac276a1b6044b9474a56a7da93a611 id_826 { std::get<1>(id_825) };
                std::optional<dessser::gen::raql_expr::t_ext> id_827 { id_826.partitions };
                bool id_828 { !(id_827.has_value ()) };
                Pointer choose_res_829;
                if (id_828) {
                  uint8_t id_830 { 1 };
                  Pointer id_831 { srec_dst_833.writeU8(id_830) };
                  choose_res_829 = id_831;
                } else {
                  auto fun832 { dessser::gen::raql_expr::to_row_binary };
                  t1d5c57287ee550c3ccac78b88bba5862 id_833 { std::get<1>(*p_0) };
                  tf708b6568b9bac184e3f5da3a64f4419 id_834 { id_833.source };
                  te6ac276a1b6044b9474a56a7da93a611 id_835 { std::get<1>(id_834) };
                  std::optional<dessser::gen::raql_expr::t_ext> id_836 { id_835.partitions };
                  dessser::gen::raql_expr::t_ext id_837 { id_836.value() };
                  uint8_t id_838 { 0 };
                  Pointer id_839 { srec_dst_833.writeU8(id_838) };
                  Pointer id_840 { fun832(id_837, id_839) };
                  choose_res_829 = id_840;
                }
                let_res_823 = choose_res_829;
              }
              Pointer let_res_841;
              {
                Pointer srec_dst_834 { let_res_823 };
                t1d5c57287ee550c3ccac78b88bba5862 id_842 { std::get<1>(*p_0) };
                tf708b6568b9bac184e3f5da3a64f4419 id_843 { id_842.source };
                te6ac276a1b6044b9474a56a7da93a611 id_844 { std::get<1>(id_843) };
                t6f8c1c936ce8cf2fe9dc881177aa3e62 id_845 { id_844.restart_from };
                uint16_t id_846 { uint16_t(id_845.index()) };
                Pointer let_res_847;
                {
                  uint16_t label1_835 { id_846 };
                  Pointer id_848 { srec_dst_834.writeU16Le(label1_835) };
                  Pointer let_res_849;
                  {
                    Pointer ssum_dst_836 { id_848 };
                    uint16_t id_850 { 0 };
                    bool id_851 { bool(id_850 == label1_835) };
                    Pointer choose_res_852;
                    if (id_851) {
                      choose_res_852 = ssum_dst_836;
                    } else {
                      uint16_t id_853 { 1 };
                      bool id_854 { bool(id_853 == label1_835) };
                      Pointer choose_res_855;
                      if (id_854) {
                        auto fun856 { dessser::gen::raql_expr::to_row_binary };
                        t1d5c57287ee550c3ccac78b88bba5862 id_857 { std::get<1>(*p_0) };
                        tf708b6568b9bac184e3f5da3a64f4419 id_858 { id_857.source };
                        te6ac276a1b6044b9474a56a7da93a611 id_859 { std::get<1>(id_858) };
                        t6f8c1c936ce8cf2fe9dc881177aa3e62 id_860 { id_859.restart_from };
                        dessser::gen::raql_expr::t_ext id_861 { std::get<1>(id_860) };
                        Pointer id_862 { fun856(id_861, ssum_dst_836) };
                        choose_res_855 = id_862;
                      } else {
                        uint16_t id_863 { 2 };
                        bool id_864 { bool(id_863 == label1_835) };
                        Pointer choose_res_865;
                        if (id_864) {
                          choose_res_865 = ssum_dst_836;
                        } else {
                          uint16_t id_866 { 3 };
                          bool id_867 { bool(label1_835 == id_866) };
                          Void id_868 { ((void)(assert(id_867)), VOID) };
                          (void)id_868;
                          auto fun869 { dessser::gen::raql_expr::to_row_binary };
                          t1d5c57287ee550c3ccac78b88bba5862 id_870 { std::get<1>(*p_0) };
                          tf708b6568b9bac184e3f5da3a64f4419 id_871 { id_870.source };
                          te6ac276a1b6044b9474a56a7da93a611 id_872 { std::get<1>(id_871) };
                          t6f8c1c936ce8cf2fe9dc881177aa3e62 id_873 { id_872.restart_from };
                          tee7dccc2726e2723462077a878a69c99 id_874 { std::get<3>(id_873) };
                          dessser::gen::raql_expr::t_ext id_875 { id_874.after_max_secs };
                          Pointer id_876 { fun869(id_875, ssum_dst_836) };
                          Pointer let_res_877;
                          {
                            Pointer srec_dst_837 { id_876 };
                            auto fun878 { dessser::gen::raql_expr::to_row_binary };
                            t1d5c57287ee550c3ccac78b88bba5862 id_879 { std::get<1>(*p_0) };
                            tf708b6568b9bac184e3f5da3a64f4419 id_880 { id_879.source };
                            te6ac276a1b6044b9474a56a7da93a611 id_881 { std::get<1>(id_880) };
                            t6f8c1c936ce8cf2fe9dc881177aa3e62 id_882 { id_881.restart_from };
                            tee7dccc2726e2723462077a878a69c99 id_883 { std::get<3>(id_882) };
                            dessser::gen::raql_expr::t_ext id_884 { id_883.after_max_events };
                            Pointer id_885 { fun878(id_884, srec_dst_837) };
                            let_res_877 = id_885;
                          }
                          choose_res_865 = let_res_877;
                        }
                        choose_res_855 = choose_res_865;
                      }
                      choose_res_852 = choose_res_855;
                    }
                    let_res_849 = choose_res_852;
                  }
                  let_res_847 = let_res_849;
                }
                let_res_841 = let_res_847;
              }
              choose_res_672 = let_res_841;
            }
            let_res_666 = choose_res_672;
          }
          Pointer let_res_886;
          {
            Pointer srec_dst_840 { let_res_666 };
            t1d5c57287ee550c3ccac78b88bba5862 id_887 { std::get<1>(*p_0) };
            t570dd118e4f520aece0574b2f62e7634 id_888 { id_887.format };
            uint16_t id_889 { uint16_t(id_888.index()) };
            Pointer id_890 { srec_dst_840.writeU16Le(id_889) };
            Pointer let_res_891;
            {
              Pointer ssum_dst_842 { id_890 };
              uint16_t id_892 { 0 };
              t1d5c57287ee550c3ccac78b88bba5862 id_893 { std::get<1>(*p_0) };
              t570dd118e4f520aece0574b2f62e7634 id_894 { id_893.format };
              uint16_t id_895 { uint16_t(id_894.index()) };
              bool id_896 { bool(id_892 == id_895) };
              Pointer choose_res_897;
              if (id_896) {
                t1d5c57287ee550c3ccac78b88bba5862 id_898 { std::get<1>(*p_0) };
                t570dd118e4f520aece0574b2f62e7634 id_899 { id_898.format };
                tc1ee34cdd9bdb8371d318bb284a788a8 id_900 { std::get<0>(id_899) };
                char id_901 { id_900.separator };
                uint8_t id_902 { uint8_t(id_901) };
                Pointer id_903 { ssum_dst_842.writeU8(id_902) };
                Pointer let_res_904;
                {
                  Pointer srec_dst_848 { id_903 };
                  t1d5c57287ee550c3ccac78b88bba5862 id_905 { std::get<1>(*p_0) };
                  t570dd118e4f520aece0574b2f62e7634 id_906 { id_905.format };
                  tc1ee34cdd9bdb8371d318bb284a788a8 id_907 { std::get<0>(id_906) };
                  std::string id_908 { id_907.null };
                  uint32_t id_909 { (uint32_t)id_908.size() };
                  Vec<1, uint32_t> id_910 {  id_909  };
                  Pointer let_res_911;
                  {
                    Vec<1, uint32_t> leb128_sz_849 { id_910 };
                    Vec<1, Pointer> id_912 {  srec_dst_848  };
                    Pointer let_res_913;
                    {
                      Vec<1, Pointer> leb128_ptr_850 { id_912 };
                      bool while_flag_914 { true };
                      do {
                        uint8_t id_915 { 0 };
                        uint8_t id_916 { 0 };
                        Pointer id_917 { leb128_ptr_850[id_916] };
                        uint32_t id_918 { 128U };
                        uint8_t id_919 { 0 };
                        uint32_t id_920 { leb128_sz_849[id_919] };
                        bool id_921 { bool(id_918 > id_920) };
                        uint8_t choose_res_922;
                        if (id_921) {
                          uint8_t id_923 { 0 };
                          uint32_t id_924 { leb128_sz_849[id_923] };
                          uint8_t id_925 { uint8_t(id_924) };
                          choose_res_922 = id_925;
                        } else {
                          uint8_t id_926 { 0 };
                          uint32_t id_927 { leb128_sz_849[id_926] };
                          uint8_t id_928 { uint8_t(id_927) };
                          uint8_t id_929 { 128 };
                          uint8_t id_930 { uint8_t(id_928 | id_929) };
                          choose_res_922 = id_930;
                        }
                        Pointer id_931 { id_917.writeU8(choose_res_922) };
                        Void id_932 { ((void)(leb128_ptr_850[id_915] = id_931), VOID) };
                        (void)id_932;
                        uint8_t id_933 { 0 };
                        uint8_t id_934 { 0 };
                        uint32_t id_935 { leb128_sz_849[id_934] };
                        uint8_t id_936 { 7 };
                        uint32_t id_937 { uint32_t(id_935 >> id_936) };
                        Void id_938 { ((void)(leb128_sz_849[id_933] = id_937), VOID) };
                        (void)id_938;
                        uint8_t id_939 { 0 };
                        uint32_t id_940 { leb128_sz_849[id_939] };
                        uint32_t id_941 { 0U };
                        bool id_942 { bool(id_940 > id_941) };
                        while_flag_914 = id_942;
                        if (while_flag_914) {
                          (void)VOID;
                        }
                      } while (while_flag_914);
                      (void)VOID;
                      uint8_t id_943 { 0 };
                      Pointer id_944 { leb128_ptr_850[id_943] };
                      let_res_913 = id_944;
                    }
                    let_res_911 = let_res_913;
                  }
                  t1d5c57287ee550c3ccac78b88bba5862 id_945 { std::get<1>(*p_0) };
                  t570dd118e4f520aece0574b2f62e7634 id_946 { id_945.format };
                  tc1ee34cdd9bdb8371d318bb284a788a8 id_947 { std::get<0>(id_946) };
                  std::string id_948 { id_947.null };
                  Bytes id_949 { id_948 };
                  Pointer id_950 { let_res_911.writeBytes(id_949) };
                  let_res_904 = id_950;
                }
                Pointer let_res_951;
                {
                  Pointer srec_dst_851 { let_res_904 };
                  t1d5c57287ee550c3ccac78b88bba5862 id_952 { std::get<1>(*p_0) };
                  t570dd118e4f520aece0574b2f62e7634 id_953 { id_952.format };
                  tc1ee34cdd9bdb8371d318bb284a788a8 id_954 { std::get<0>(id_953) };
                  bool id_955 { id_954.may_quote };
                  uint8_t id_956 { uint8_t(id_955) };
                  Pointer id_957 { srec_dst_851.writeU8(id_956) };
                  let_res_951 = id_957;
                }
                Pointer let_res_958;
                {
                  Pointer srec_dst_852 { let_res_951 };
                  t1d5c57287ee550c3ccac78b88bba5862 id_959 { std::get<1>(*p_0) };
                  t570dd118e4f520aece0574b2f62e7634 id_960 { id_959.format };
                  tc1ee34cdd9bdb8371d318bb284a788a8 id_961 { std::get<0>(id_960) };
                  std::string id_962 { id_961.escape_seq };
                  uint32_t id_963 { (uint32_t)id_962.size() };
                  Vec<1, uint32_t> id_964 {  id_963  };
                  Pointer let_res_965;
                  {
                    Vec<1, uint32_t> leb128_sz_853 { id_964 };
                    Vec<1, Pointer> id_966 {  srec_dst_852  };
                    Pointer let_res_967;
                    {
                      Vec<1, Pointer> leb128_ptr_854 { id_966 };
                      bool while_flag_968 { true };
                      do {
                        uint8_t id_969 { 0 };
                        uint8_t id_970 { 0 };
                        Pointer id_971 { leb128_ptr_854[id_970] };
                        uint32_t id_972 { 128U };
                        uint8_t id_973 { 0 };
                        uint32_t id_974 { leb128_sz_853[id_973] };
                        bool id_975 { bool(id_972 > id_974) };
                        uint8_t choose_res_976;
                        if (id_975) {
                          uint8_t id_977 { 0 };
                          uint32_t id_978 { leb128_sz_853[id_977] };
                          uint8_t id_979 { uint8_t(id_978) };
                          choose_res_976 = id_979;
                        } else {
                          uint8_t id_980 { 0 };
                          uint32_t id_981 { leb128_sz_853[id_980] };
                          uint8_t id_982 { uint8_t(id_981) };
                          uint8_t id_983 { 128 };
                          uint8_t id_984 { uint8_t(id_982 | id_983) };
                          choose_res_976 = id_984;
                        }
                        Pointer id_985 { id_971.writeU8(choose_res_976) };
                        Void id_986 { ((void)(leb128_ptr_854[id_969] = id_985), VOID) };
                        (void)id_986;
                        uint8_t id_987 { 0 };
                        uint8_t id_988 { 0 };
                        uint32_t id_989 { leb128_sz_853[id_988] };
                        uint8_t id_990 { 7 };
                        uint32_t id_991 { uint32_t(id_989 >> id_990) };
                        Void id_992 { ((void)(leb128_sz_853[id_987] = id_991), VOID) };
                        (void)id_992;
                        uint8_t id_993 { 0 };
                        uint32_t id_994 { leb128_sz_853[id_993] };
                        uint32_t id_995 { 0U };
                        bool id_996 { bool(id_994 > id_995) };
                        while_flag_968 = id_996;
                        if (while_flag_968) {
                          (void)VOID;
                        }
                      } while (while_flag_968);
                      (void)VOID;
                      uint8_t id_997 { 0 };
                      Pointer id_998 { leb128_ptr_854[id_997] };
                      let_res_967 = id_998;
                    }
                    let_res_965 = let_res_967;
                  }
                  t1d5c57287ee550c3ccac78b88bba5862 id_999 { std::get<1>(*p_0) };
                  t570dd118e4f520aece0574b2f62e7634 id_1000 { id_999.format };
                  tc1ee34cdd9bdb8371d318bb284a788a8 id_1001 { std::get<0>(id_1000) };
                  std::string id_1002 { id_1001.escape_seq };
                  Bytes id_1003 { id_1002 };
                  Pointer id_1004 { let_res_965.writeBytes(id_1003) };
                  let_res_958 = id_1004;
                }
                Pointer let_res_1005;
                {
                  Pointer srec_dst_855 { let_res_958 };
                  t1d5c57287ee550c3ccac78b88bba5862 id_1006 { std::get<1>(*p_0) };
                  t570dd118e4f520aece0574b2f62e7634 id_1007 { id_1006.format };
                  tc1ee34cdd9bdb8371d318bb284a788a8 id_1008 { std::get<0>(id_1007) };
                  Lst<dessser::gen::field_type::t_ext> id_1009 { id_1008.fields };
                  uint32_t id_1010 { id_1009.size() };
                  Vec<1, uint32_t> id_1011 {  id_1010  };
                  Pointer let_res_1012;
                  {
                    Vec<1, uint32_t> leb128_sz_856 { id_1011 };
                    Vec<1, Pointer> id_1013 {  srec_dst_855  };
                    Pointer let_res_1014;
                    {
                      Vec<1, Pointer> leb128_ptr_857 { id_1013 };
                      bool while_flag_1015 { true };
                      do {
                        uint8_t id_1016 { 0 };
                        uint8_t id_1017 { 0 };
                        Pointer id_1018 { leb128_ptr_857[id_1017] };
                        uint32_t id_1019 { 128U };
                        uint8_t id_1020 { 0 };
                        uint32_t id_1021 { leb128_sz_856[id_1020] };
                        bool id_1022 { bool(id_1019 > id_1021) };
                        uint8_t choose_res_1023;
                        if (id_1022) {
                          uint8_t id_1024 { 0 };
                          uint32_t id_1025 { leb128_sz_856[id_1024] };
                          uint8_t id_1026 { uint8_t(id_1025) };
                          choose_res_1023 = id_1026;
                        } else {
                          uint8_t id_1027 { 0 };
                          uint32_t id_1028 { leb128_sz_856[id_1027] };
                          uint8_t id_1029 { uint8_t(id_1028) };
                          uint8_t id_1030 { 128 };
                          uint8_t id_1031 { uint8_t(id_1029 | id_1030) };
                          choose_res_1023 = id_1031;
                        }
                        Pointer id_1032 { id_1018.writeU8(choose_res_1023) };
                        Void id_1033 { ((void)(leb128_ptr_857[id_1016] = id_1032), VOID) };
                        (void)id_1033;
                        uint8_t id_1034 { 0 };
                        uint8_t id_1035 { 0 };
                        uint32_t id_1036 { leb128_sz_856[id_1035] };
                        uint8_t id_1037 { 7 };
                        uint32_t id_1038 { uint32_t(id_1036 >> id_1037) };
                        Void id_1039 { ((void)(leb128_sz_856[id_1034] = id_1038), VOID) };
                        (void)id_1039;
                        uint8_t id_1040 { 0 };
                        uint32_t id_1041 { leb128_sz_856[id_1040] };
                        uint32_t id_1042 { 0U };
                        bool id_1043 { bool(id_1041 > id_1042) };
                        while_flag_1015 = id_1043;
                        if (while_flag_1015) {
                          (void)VOID;
                        }
                      } while (while_flag_1015);
                      (void)VOID;
                      uint8_t id_1044 { 0 };
                      Pointer id_1045 { leb128_ptr_857[id_1044] };
                      let_res_1014 = id_1045;
                    }
                    let_res_1012 = let_res_1014;
                  }
                  Vec<1, Pointer> id_1046 {  let_res_1012  };
                  Pointer let_res_1047;
                  {
                    Vec<1, Pointer> dst_ref_858 { id_1046 };
                    int32_t id_1048 { 0L };
                    Vec<1, int32_t> id_1049 {  id_1048  };
                    Pointer let_res_1050;
                    {
                      Vec<1, int32_t> n_ref_859 { id_1049 };
                      t1d5c57287ee550c3ccac78b88bba5862 id_1051 { std::get<1>(*p_0) };
                      t570dd118e4f520aece0574b2f62e7634 id_1052 { id_1051.format };
                      tc1ee34cdd9bdb8371d318bb284a788a8 id_1053 { std::get<0>(id_1052) };
                      Lst<dessser::gen::field_type::t_ext> id_1054 { id_1053.fields };
                      for (dessser::gen::field_type::t_ext x_860 : id_1054) {
                        uint8_t id_1055 { 0 };
                        auto fun1056 { dessser::gen::field_type::to_row_binary };
                        uint8_t id_1057 { 0 };
                        Pointer id_1058 { dst_ref_858[id_1057] };
                        Pointer id_1059 { fun1056(x_860, id_1058) };
                        Void id_1060 { ((void)(dst_ref_858[id_1055] = id_1059), VOID) };
                        (void)id_1060;
                        uint8_t id_1061 { 0 };
                        int32_t id_1062 { 1L };
                        uint8_t id_1063 { 0 };
                        int32_t id_1064 { n_ref_859[id_1063] };
                        int32_t id_1065 { int32_t(id_1062 + id_1064) };
                        Void id_1066 { ((void)(n_ref_859[id_1061] = id_1065), VOID) };
                        (void)id_1066;
                        (void)id_1066;
                      }
                      (void)VOID;
                      uint8_t id_1067 { 0 };
                      Pointer id_1068 { dst_ref_858[id_1067] };
                      let_res_1050 = id_1068;
                    }
                    let_res_1047 = let_res_1050;
                  }
                  let_res_1005 = let_res_1047;
                }
                Pointer let_res_1069;
                {
                  Pointer srec_dst_861 { let_res_1005 };
                  t1d5c57287ee550c3ccac78b88bba5862 id_1070 { std::get<1>(*p_0) };
                  t570dd118e4f520aece0574b2f62e7634 id_1071 { id_1070.format };
                  tc1ee34cdd9bdb8371d318bb284a788a8 id_1072 { std::get<0>(id_1071) };
                  bool id_1073 { id_1072.vectors_of_chars_as_string };
                  uint8_t id_1074 { uint8_t(id_1073) };
                  Pointer id_1075 { srec_dst_861.writeU8(id_1074) };
                  let_res_1069 = id_1075;
                }
                Pointer let_res_1076;
                {
                  Pointer srec_dst_862 { let_res_1069 };
                  t1d5c57287ee550c3ccac78b88bba5862 id_1077 { std::get<1>(*p_0) };
                  t570dd118e4f520aece0574b2f62e7634 id_1078 { id_1077.format };
                  tc1ee34cdd9bdb8371d318bb284a788a8 id_1079 { std::get<0>(id_1078) };
                  bool id_1080 { id_1079.clickhouse_syntax };
                  uint8_t id_1081 { uint8_t(id_1080) };
                  Pointer id_1082 { srec_dst_862.writeU8(id_1081) };
                  let_res_1076 = id_1082;
                }
                choose_res_897 = let_res_1076;
              } else {
                t1d5c57287ee550c3ccac78b88bba5862 id_1083 { std::get<1>(*p_0) };
                t570dd118e4f520aece0574b2f62e7634 id_1084 { id_1083.format };
                uint16_t id_1085 { uint16_t(id_1084.index()) };
                uint16_t id_1086 { 1 };
                bool id_1087 { bool(id_1085 == id_1086) };
                Void id_1088 { ((void)(assert(id_1087)), VOID) };
                (void)id_1088;
                t1d5c57287ee550c3ccac78b88bba5862 id_1089 { std::get<1>(*p_0) };
                t570dd118e4f520aece0574b2f62e7634 id_1090 { id_1089.format };
                Lst<dessser::gen::field_type::t_ext> id_1091 { std::get<1>(id_1090) };
                uint32_t id_1092 { id_1091.size() };
                Vec<1, uint32_t> id_1093 {  id_1092  };
                Pointer let_res_1094;
                {
                  Vec<1, uint32_t> leb128_sz_843 { id_1093 };
                  Vec<1, Pointer> id_1095 {  ssum_dst_842  };
                  Pointer let_res_1096;
                  {
                    Vec<1, Pointer> leb128_ptr_844 { id_1095 };
                    bool while_flag_1097 { true };
                    do {
                      uint8_t id_1098 { 0 };
                      uint8_t id_1099 { 0 };
                      Pointer id_1100 { leb128_ptr_844[id_1099] };
                      uint32_t id_1101 { 128U };
                      uint8_t id_1102 { 0 };
                      uint32_t id_1103 { leb128_sz_843[id_1102] };
                      bool id_1104 { bool(id_1101 > id_1103) };
                      uint8_t choose_res_1105;
                      if (id_1104) {
                        uint8_t id_1106 { 0 };
                        uint32_t id_1107 { leb128_sz_843[id_1106] };
                        uint8_t id_1108 { uint8_t(id_1107) };
                        choose_res_1105 = id_1108;
                      } else {
                        uint8_t id_1109 { 0 };
                        uint32_t id_1110 { leb128_sz_843[id_1109] };
                        uint8_t id_1111 { uint8_t(id_1110) };
                        uint8_t id_1112 { 128 };
                        uint8_t id_1113 { uint8_t(id_1111 | id_1112) };
                        choose_res_1105 = id_1113;
                      }
                      Pointer id_1114 { id_1100.writeU8(choose_res_1105) };
                      Void id_1115 { ((void)(leb128_ptr_844[id_1098] = id_1114), VOID) };
                      (void)id_1115;
                      uint8_t id_1116 { 0 };
                      uint8_t id_1117 { 0 };
                      uint32_t id_1118 { leb128_sz_843[id_1117] };
                      uint8_t id_1119 { 7 };
                      uint32_t id_1120 { uint32_t(id_1118 >> id_1119) };
                      Void id_1121 { ((void)(leb128_sz_843[id_1116] = id_1120), VOID) };
                      (void)id_1121;
                      uint8_t id_1122 { 0 };
                      uint32_t id_1123 { leb128_sz_843[id_1122] };
                      uint32_t id_1124 { 0U };
                      bool id_1125 { bool(id_1123 > id_1124) };
                      while_flag_1097 = id_1125;
                      if (while_flag_1097) {
                        (void)VOID;
                      }
                    } while (while_flag_1097);
                    (void)VOID;
                    uint8_t id_1126 { 0 };
                    Pointer id_1127 { leb128_ptr_844[id_1126] };
                    let_res_1096 = id_1127;
                  }
                  let_res_1094 = let_res_1096;
                }
                Vec<1, Pointer> id_1128 {  let_res_1094  };
                Pointer let_res_1129;
                {
                  Vec<1, Pointer> dst_ref_845 { id_1128 };
                  int32_t id_1130 { 0L };
                  Vec<1, int32_t> id_1131 {  id_1130  };
                  Pointer let_res_1132;
                  {
                    Vec<1, int32_t> n_ref_846 { id_1131 };
                    t1d5c57287ee550c3ccac78b88bba5862 id_1133 { std::get<1>(*p_0) };
                    t570dd118e4f520aece0574b2f62e7634 id_1134 { id_1133.format };
                    Lst<dessser::gen::field_type::t_ext> id_1135 { std::get<1>(id_1134) };
                    for (dessser::gen::field_type::t_ext x_847 : id_1135) {
                      uint8_t id_1136 { 0 };
                      auto fun1137 { dessser::gen::field_type::to_row_binary };
                      uint8_t id_1138 { 0 };
                      Pointer id_1139 { dst_ref_845[id_1138] };
                      Pointer id_1140 { fun1137(x_847, id_1139) };
                      Void id_1141 { ((void)(dst_ref_845[id_1136] = id_1140), VOID) };
                      (void)id_1141;
                      uint8_t id_1142 { 0 };
                      int32_t id_1143 { 1L };
                      uint8_t id_1144 { 0 };
                      int32_t id_1145 { n_ref_846[id_1144] };
                      int32_t id_1146 { int32_t(id_1143 + id_1145) };
                      Void id_1147 { ((void)(n_ref_846[id_1142] = id_1146), VOID) };
                      (void)id_1147;
                      (void)id_1147;
                    }
                    (void)VOID;
                    uint8_t id_1148 { 0 };
                    Pointer id_1149 { dst_ref_845[id_1148] };
                    let_res_1132 = id_1149;
                  }
                  let_res_1129 = let_res_1132;
                }
                choose_res_897 = let_res_1129;
              }
              let_res_891 = choose_res_897;
            }
            let_res_886 = let_res_891;
          }
          Pointer let_res_1150;
          {
            Pointer srec_dst_863 { let_res_886 };
            t1d5c57287ee550c3ccac78b88bba5862 id_1151 { std::get<1>(*p_0) };
            std::optional<dessser::gen::event_time::t_ext> id_1152 { id_1151.event_time };
            bool id_1153 { !(id_1152.has_value ()) };
            Pointer choose_res_1154;
            if (id_1153) {
              uint8_t id_1155 { 1 };
              Pointer id_1156 { srec_dst_863.writeU8(id_1155) };
              choose_res_1154 = id_1156;
            } else {
              auto fun1157 { dessser::gen::event_time::to_row_binary };
              t1d5c57287ee550c3ccac78b88bba5862 id_1158 { std::get<1>(*p_0) };
              std::optional<dessser::gen::event_time::t_ext> id_1159 { id_1158.event_time };
              dessser::gen::event_time::t_ext id_1160 { id_1159.value() };
              uint8_t id_1161 { 0 };
              Pointer id_1162 { srec_dst_863.writeU8(id_1161) };
              Pointer id_1163 { fun1157(id_1160, id_1162) };
              choose_res_1154 = id_1163;
            }
            let_res_1150 = choose_res_1154;
          }
          Pointer let_res_1164;
          {
            Pointer srec_dst_864 { let_res_1150 };
            t1d5c57287ee550c3ccac78b88bba5862 id_1165 { std::get<1>(*p_0) };
            Lst<dessser::gen::field_name::t_ext> id_1166 { id_1165.factors };
            uint32_t id_1167 { id_1166.size() };
            Vec<1, uint32_t> id_1168 {  id_1167  };
            Pointer let_res_1169;
            {
              Vec<1, uint32_t> leb128_sz_865 { id_1168 };
              Vec<1, Pointer> id_1170 {  srec_dst_864  };
              Pointer let_res_1171;
              {
                Vec<1, Pointer> leb128_ptr_866 { id_1170 };
                bool while_flag_1172 { true };
                do {
                  uint8_t id_1173 { 0 };
                  uint8_t id_1174 { 0 };
                  Pointer id_1175 { leb128_ptr_866[id_1174] };
                  uint32_t id_1176 { 128U };
                  uint8_t id_1177 { 0 };
                  uint32_t id_1178 { leb128_sz_865[id_1177] };
                  bool id_1179 { bool(id_1176 > id_1178) };
                  uint8_t choose_res_1180;
                  if (id_1179) {
                    uint8_t id_1181 { 0 };
                    uint32_t id_1182 { leb128_sz_865[id_1181] };
                    uint8_t id_1183 { uint8_t(id_1182) };
                    choose_res_1180 = id_1183;
                  } else {
                    uint8_t id_1184 { 0 };
                    uint32_t id_1185 { leb128_sz_865[id_1184] };
                    uint8_t id_1186 { uint8_t(id_1185) };
                    uint8_t id_1187 { 128 };
                    uint8_t id_1188 { uint8_t(id_1186 | id_1187) };
                    choose_res_1180 = id_1188;
                  }
                  Pointer id_1189 { id_1175.writeU8(choose_res_1180) };
                  Void id_1190 { ((void)(leb128_ptr_866[id_1173] = id_1189), VOID) };
                  (void)id_1190;
                  uint8_t id_1191 { 0 };
                  uint8_t id_1192 { 0 };
                  uint32_t id_1193 { leb128_sz_865[id_1192] };
                  uint8_t id_1194 { 7 };
                  uint32_t id_1195 { uint32_t(id_1193 >> id_1194) };
                  Void id_1196 { ((void)(leb128_sz_865[id_1191] = id_1195), VOID) };
                  (void)id_1196;
                  uint8_t id_1197 { 0 };
                  uint32_t id_1198 { leb128_sz_865[id_1197] };
                  uint32_t id_1199 { 0U };
                  bool id_1200 { bool(id_1198 > id_1199) };
                  while_flag_1172 = id_1200;
                  if (while_flag_1172) {
                    (void)VOID;
                  }
                } while (while_flag_1172);
                (void)VOID;
                uint8_t id_1201 { 0 };
                Pointer id_1202 { leb128_ptr_866[id_1201] };
                let_res_1171 = id_1202;
              }
              let_res_1169 = let_res_1171;
            }
            Vec<1, Pointer> id_1203 {  let_res_1169  };
            Pointer let_res_1204;
            {
              Vec<1, Pointer> dst_ref_867 { id_1203 };
              int32_t id_1205 { 0L };
              Vec<1, int32_t> id_1206 {  id_1205  };
              Pointer let_res_1207;
              {
                Vec<1, int32_t> n_ref_868 { id_1206 };
                t1d5c57287ee550c3ccac78b88bba5862 id_1208 { std::get<1>(*p_0) };
                Lst<dessser::gen::field_name::t_ext> id_1209 { id_1208.factors };
                for (dessser::gen::field_name::t_ext x_869 : id_1209) {
                  uint8_t id_1210 { 0 };
                  auto fun1211 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_1212 { 0 };
                  Pointer id_1213 { dst_ref_867[id_1212] };
                  Pointer id_1214 { fun1211(x_869, id_1213) };
                  Void id_1215 { ((void)(dst_ref_867[id_1210] = id_1214), VOID) };
                  (void)id_1215;
                  uint8_t id_1216 { 0 };
                  int32_t id_1217 { 1L };
                  uint8_t id_1218 { 0 };
                  int32_t id_1219 { n_ref_868[id_1218] };
                  int32_t id_1220 { int32_t(id_1217 + id_1219) };
                  Void id_1221 { ((void)(n_ref_868[id_1216] = id_1220), VOID) };
                  (void)id_1221;
                  (void)id_1221;
                }
                (void)VOID;
                uint8_t id_1222 { 0 };
                Pointer id_1223 { dst_ref_867[id_1222] };
                let_res_1207 = id_1223;
              }
              let_res_1204 = let_res_1207;
            }
            let_res_1164 = let_res_1204;
          }
          choose_res_661 = let_res_1164;
        } else {
          uint16_t id_1224 { uint16_t(p_0->index()) };
          uint16_t id_1225 { 2 };
          bool id_1226 { bool(id_1224 == id_1225) };
          Void id_1227 { ((void)(assert(id_1226)), VOID) };
          (void)id_1227;
          t9ddff9e1963b15ba493db1f8dadd34fb id_1228 { std::get<2>(*p_0) };
          std::string id_1229 { id_1228.net_addr };
          uint32_t id_1230 { (uint32_t)id_1229.size() };
          Vec<1, uint32_t> id_1231 {  id_1230  };
          Pointer let_res_1232;
          {
            Vec<1, uint32_t> leb128_sz_811 { id_1231 };
            Vec<1, Pointer> id_1233 {  ssum_dst_810  };
            Pointer let_res_1234;
            {
              Vec<1, Pointer> leb128_ptr_812 { id_1233 };
              bool while_flag_1235 { true };
              do {
                uint8_t id_1236 { 0 };
                uint8_t id_1237 { 0 };
                Pointer id_1238 { leb128_ptr_812[id_1237] };
                uint32_t id_1239 { 128U };
                uint8_t id_1240 { 0 };
                uint32_t id_1241 { leb128_sz_811[id_1240] };
                bool id_1242 { bool(id_1239 > id_1241) };
                uint8_t choose_res_1243;
                if (id_1242) {
                  uint8_t id_1244 { 0 };
                  uint32_t id_1245 { leb128_sz_811[id_1244] };
                  uint8_t id_1246 { uint8_t(id_1245) };
                  choose_res_1243 = id_1246;
                } else {
                  uint8_t id_1247 { 0 };
                  uint32_t id_1248 { leb128_sz_811[id_1247] };
                  uint8_t id_1249 { uint8_t(id_1248) };
                  uint8_t id_1250 { 128 };
                  uint8_t id_1251 { uint8_t(id_1249 | id_1250) };
                  choose_res_1243 = id_1251;
                }
                Pointer id_1252 { id_1238.writeU8(choose_res_1243) };
                Void id_1253 { ((void)(leb128_ptr_812[id_1236] = id_1252), VOID) };
                (void)id_1253;
                uint8_t id_1254 { 0 };
                uint8_t id_1255 { 0 };
                uint32_t id_1256 { leb128_sz_811[id_1255] };
                uint8_t id_1257 { 7 };
                uint32_t id_1258 { uint32_t(id_1256 >> id_1257) };
                Void id_1259 { ((void)(leb128_sz_811[id_1254] = id_1258), VOID) };
                (void)id_1259;
                uint8_t id_1260 { 0 };
                uint32_t id_1261 { leb128_sz_811[id_1260] };
                uint32_t id_1262 { 0U };
                bool id_1263 { bool(id_1261 > id_1262) };
                while_flag_1235 = id_1263;
                if (while_flag_1235) {
                  (void)VOID;
                }
              } while (while_flag_1235);
              (void)VOID;
              uint8_t id_1264 { 0 };
              Pointer id_1265 { leb128_ptr_812[id_1264] };
              let_res_1234 = id_1265;
            }
            let_res_1232 = let_res_1234;
          }
          t9ddff9e1963b15ba493db1f8dadd34fb id_1266 { std::get<2>(*p_0) };
          std::string id_1267 { id_1266.net_addr };
          Bytes id_1268 { id_1267 };
          Pointer id_1269 { let_res_1232.writeBytes(id_1268) };
          Pointer let_res_1270;
          {
            Pointer srec_dst_813 { id_1269 };
            t9ddff9e1963b15ba493db1f8dadd34fb id_1271 { std::get<2>(*p_0) };
            uint16_t id_1272 { id_1271.port };
            Pointer id_1273 { srec_dst_813.writeU16Le(id_1272) };
            let_res_1270 = id_1273;
          }
          Pointer let_res_1274;
          {
            Pointer srec_dst_814 { let_res_1270 };
            auto fun1275 { dessser::gen::raql_net_protocol::to_row_binary };
            t9ddff9e1963b15ba493db1f8dadd34fb id_1276 { std::get<2>(*p_0) };
            dessser::gen::raql_net_protocol::t_ext id_1277 { id_1276.proto };
            Pointer id_1278 { fun1275(id_1277, srec_dst_814) };
            let_res_1274 = id_1278;
          }
          Pointer let_res_1279;
          {
            Pointer srec_dst_815 { let_res_1274 };
            t9ddff9e1963b15ba493db1f8dadd34fb id_1280 { std::get<2>(*p_0) };
            Lst<dessser::gen::field_name::t_ext> id_1281 { id_1280.factors };
            uint32_t id_1282 { id_1281.size() };
            Vec<1, uint32_t> id_1283 {  id_1282  };
            Pointer let_res_1284;
            {
              Vec<1, uint32_t> leb128_sz_816 { id_1283 };
              Vec<1, Pointer> id_1285 {  srec_dst_815  };
              Pointer let_res_1286;
              {
                Vec<1, Pointer> leb128_ptr_817 { id_1285 };
                bool while_flag_1287 { true };
                do {
                  uint8_t id_1288 { 0 };
                  uint8_t id_1289 { 0 };
                  Pointer id_1290 { leb128_ptr_817[id_1289] };
                  uint32_t id_1291 { 128U };
                  uint8_t id_1292 { 0 };
                  uint32_t id_1293 { leb128_sz_816[id_1292] };
                  bool id_1294 { bool(id_1291 > id_1293) };
                  uint8_t choose_res_1295;
                  if (id_1294) {
                    uint8_t id_1296 { 0 };
                    uint32_t id_1297 { leb128_sz_816[id_1296] };
                    uint8_t id_1298 { uint8_t(id_1297) };
                    choose_res_1295 = id_1298;
                  } else {
                    uint8_t id_1299 { 0 };
                    uint32_t id_1300 { leb128_sz_816[id_1299] };
                    uint8_t id_1301 { uint8_t(id_1300) };
                    uint8_t id_1302 { 128 };
                    uint8_t id_1303 { uint8_t(id_1301 | id_1302) };
                    choose_res_1295 = id_1303;
                  }
                  Pointer id_1304 { id_1290.writeU8(choose_res_1295) };
                  Void id_1305 { ((void)(leb128_ptr_817[id_1288] = id_1304), VOID) };
                  (void)id_1305;
                  uint8_t id_1306 { 0 };
                  uint8_t id_1307 { 0 };
                  uint32_t id_1308 { leb128_sz_816[id_1307] };
                  uint8_t id_1309 { 7 };
                  uint32_t id_1310 { uint32_t(id_1308 >> id_1309) };
                  Void id_1311 { ((void)(leb128_sz_816[id_1306] = id_1310), VOID) };
                  (void)id_1311;
                  uint8_t id_1312 { 0 };
                  uint32_t id_1313 { leb128_sz_816[id_1312] };
                  uint32_t id_1314 { 0U };
                  bool id_1315 { bool(id_1313 > id_1314) };
                  while_flag_1287 = id_1315;
                  if (while_flag_1287) {
                    (void)VOID;
                  }
                } while (while_flag_1287);
                (void)VOID;
                uint8_t id_1316 { 0 };
                Pointer id_1317 { leb128_ptr_817[id_1316] };
                let_res_1286 = id_1317;
              }
              let_res_1284 = let_res_1286;
            }
            Vec<1, Pointer> id_1318 {  let_res_1284  };
            Pointer let_res_1319;
            {
              Vec<1, Pointer> dst_ref_818 { id_1318 };
              int32_t id_1320 { 0L };
              Vec<1, int32_t> id_1321 {  id_1320  };
              Pointer let_res_1322;
              {
                Vec<1, int32_t> n_ref_819 { id_1321 };
                t9ddff9e1963b15ba493db1f8dadd34fb id_1323 { std::get<2>(*p_0) };
                Lst<dessser::gen::field_name::t_ext> id_1324 { id_1323.factors };
                for (dessser::gen::field_name::t_ext x_820 : id_1324) {
                  uint8_t id_1325 { 0 };
                  auto fun1326 { dessser::gen::field_name::to_row_binary };
                  uint8_t id_1327 { 0 };
                  Pointer id_1328 { dst_ref_818[id_1327] };
                  Pointer id_1329 { fun1326(x_820, id_1328) };
                  Void id_1330 { ((void)(dst_ref_818[id_1325] = id_1329), VOID) };
                  (void)id_1330;
                  uint8_t id_1331 { 0 };
                  int32_t id_1332 { 1L };
                  uint8_t id_1333 { 0 };
                  int32_t id_1334 { n_ref_819[id_1333] };
                  int32_t id_1335 { int32_t(id_1332 + id_1334) };
                  Void id_1336 { ((void)(n_ref_819[id_1331] = id_1335), VOID) };
                  (void)id_1336;
                  (void)id_1336;
                }
                (void)VOID;
                uint8_t id_1337 { 0 };
                Pointer id_1338 { dst_ref_818[id_1337] };
                let_res_1322 = id_1338;
              }
              let_res_1319 = let_res_1322;
            }
            let_res_1279 = let_res_1319;
          }
          choose_res_661 = let_res_1279;
        }
        choose_res_7 = choose_res_661;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS][[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]; format: [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]; event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]")
      (if (eq (u16 0) (label-of (param 0)))
        (let "sz_804"
          (let "sz_803"
            (let "sz_787"
              (let "sz_786"
                (add
                  (let "sz_784"
                    (let "sz_779"
                      (let "sz_774"
                        (let "sz_773"
                          (let "sz_772"
                            (let "sz_764"
                              (let "sz_759"
                                (let "sz_ref_757"
                                  (make-vec
                                    (add (size 2)
                                      (let "n_ref_755" (make-vec (cardinality (get-field "fields" (get-alt "Aggregate" (param 0)))))
                                        (let "lebsz_ref_756" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_755")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_756")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_756") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_756")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_756"))))))))
                                  (seq
                                    (let "repeat_n_758" (make-vec (i32 0))
                                      (while (gt (to-i32 (cardinality (get-field "fields" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_758")))
                                        (seq
                                          (set-vec (u8 0) (identifier "sz_ref_757")
                                            (add (unsafe-nth (u8 0) (identifier "sz_ref_757"))
                                              (apply (ext-identifier raql_select_field sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_758")) (get-field "fields" (get-alt "Aggregate" (param 0)))))))
                                          (set-vec (u8 0) (identifier "repeat_n_758") (add (unsafe-nth (u8 0) (identifier "repeat_n_758")) (i32 1)))))) 
                                    (unsafe-nth (u8 0) (identifier "sz_ref_757"))))
                                (if (is-null (get-field "and_all_others" (get-alt "Aggregate" (param 0)))) 
                                  (add (identifier "sz_759") (size 1))
                                  (add
                                    (let "sz_ref_762"
                                      (make-vec
                                        (add (identifier "sz_759")
                                          (let "n_ref_760" (make-vec (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))
                                            (let "lebsz_ref_761" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_760")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_761")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_761") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_761")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_761"))))))))
                                      (seq
                                        (let "repeat_n_763" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (force (get-field "and_all_others" (get-alt "Aggregate" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_763")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_762")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_762"))
                                                  (apply (ext-identifier field_name sersize-of-row-binary)
                                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_763")) (force (get-field "and_all_others" (get-alt "Aggregate" (param 0))))))))
                                              (set-vec (u8 0) (identifier "repeat_n_763") (add (unsafe-nth (u8 0) (identifier "repeat_n_763")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_762")))) 
                                    (size 1))))
                              (if (is-null (get-field "sort" (get-alt "Aggregate" (param 0)))) 
                                (add (identifier "sz_764") (size 1))
                                (add
                                  (let "sz_767"
                                    (if (is-null (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))) 
                                      (add (add (identifier "sz_764") (size 4)) (size 1))
                                      (add (add (add (identifier "sz_764") (size 4)) (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-item 1 (force (get-field "sort" (get-alt "Aggregate" (param 0))))))))
                                        (size 1)))
                                    (let "sz_ref_770"
                                      (make-vec
                                        (add (identifier "sz_767")
                                          (let "n_ref_768" (make-vec (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))
                                            (let "lebsz_ref_769" (make-vec (u32 1))
                                              (seq
                                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_768")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_769")) (u8 7)))
                                                  (set-vec (u8 0) (identifier "lebsz_ref_769") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_769")) (u32 1)))) 
                                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_769"))))))))
                                      (seq
                                        (let "repeat_n_771" (make-vec (i32 0))
                                          (while (gt (to-i32 (cardinality (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0))))))) (unsafe-nth (u8 0) (identifier "repeat_n_771")))
                                            (seq
                                              (set-vec (u8 0) (identifier "sz_ref_770")
                                                (add (unsafe-nth (u8 0) (identifier "sz_ref_770"))
                                                  (apply (ext-identifier raql_expr sersize-of-row-binary)
                                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_771")) (get-item 2 (force (get-field "sort" (get-alt "Aggregate" (param 0)))))))))
                                              (set-vec (u8 0) (identifier "repeat_n_771") (add (unsafe-nth (u8 0) (identifier "repeat_n_771")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "sz_ref_770"))))) 
                                  (size 1)))) (add (identifier "sz_772") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "where" (get-alt "Aggregate" (param 0))))))
                          (if (is-null (get-field "event_time" (get-alt "Aggregate" (param 0)))) 
                            (add (identifier "sz_773") (size 1))
                            (add (add (identifier "sz_773") (apply (ext-identifier event_time sersize-of-row-binary) (force (get-field "event_time" (get-alt "Aggregate" (param 0)))))) (size 1))))
                        (let "sz_ref_777"
                          (make-vec
                            (add (identifier "sz_774")
                              (let "n_ref_775" (make-vec (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0)))))
                                (let "lebsz_ref_776" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_775")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_776")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_776") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_776")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_776"))))))))
                          (seq
                            (let "repeat_n_778" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "notifications" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_778")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_777")
                                    (add (unsafe-nth (u8 0) (identifier "sz_ref_777"))
                                      (apply (ext-identifier raql_expr sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_778")) (get-field "notifications" (get-alt "Aggregate" (param 0)))))))
                                  (set-vec (u8 0) (identifier "repeat_n_778") (add (unsafe-nth (u8 0) (identifier "repeat_n_778")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_777")))))
                      (let "sz_ref_782"
                        (make-vec
                          (add (identifier "sz_779")
                            (let "n_ref_780" (make-vec (cardinality (get-field "key" (get-alt "Aggregate" (param 0)))))
                              (let "lebsz_ref_781" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_780")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_781")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_781") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_781")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_781"))))))))
                        (seq
                          (let "repeat_n_783" (make-vec (i32 0))
                            (while (gt (to-i32 (cardinality (get-field "key" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_783")))
                              (seq
                                (set-vec (u8 0) (identifier "sz_ref_782")
                                  (add (unsafe-nth (u8 0) (identifier "sz_ref_782"))
                                    (apply (ext-identifier raql_expr sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_783")) (get-field "key" (get-alt "Aggregate" (param 0)))))))
                                (set-vec (u8 0) (identifier "repeat_n_783") (add (unsafe-nth (u8 0) (identifier "repeat_n_783")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "sz_ref_782"))))) 
                    (add (identifier "sz_784") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "commit_cond" (get-alt "Aggregate" (param 0)))))) 
                  (size 1)) (add (identifier "sz_786") (apply (ext-identifier raql_flush_method sersize-of-row-binary) (get-field "flush_how" (get-alt "Aggregate" (param 0))))))
              (let "sz_ref_790"
                (make-vec
                  (add (identifier "sz_787")
                    (let "n_ref_788" (make-vec (cardinality (get-field "from" (get-alt "Aggregate" (param 0)))))
                      (let "lebsz_ref_789" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_788")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_789")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_789") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_789")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_789"))))))))
                (seq
                  (let "repeat_n_791" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "from" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_791")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_790")
                          (let "label2_792" (label-of (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_791")) (get-field "from" (get-alt "Aggregate" (param 0)))))
                            (if (eq (u16 0) (identifier "label2_792"))
                              (let "sz_802"
                                (let "sz_798"
                                  (let "sz_793" (add (unsafe-nth (u8 0) (identifier "sz_ref_790")) (size 2))
                                    (let "label2_794" (label-of (get-item 0 (get-alt "NamedOperation" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_791")) (get-field "from" (get-alt "Aggregate" (param 0)))))))
                                      (if (eq (u16 0) (identifier "label2_794")) 
                                        (add (identifier "sz_793") (size 2))
                                        (if (eq (u16 1) (identifier "label2_794"))
                                          (add (add (identifier "sz_793") (size 2))
                                            (let "wlen_795"
                                              (string-length
                                                (get-alt "TheseSites" (get-item 0 (get-alt "NamedOperation" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_791")) (get-field "from" (get-alt "Aggregate" (param 0))))))))
                                              (add
                                                (let "n_ref_796" (make-vec (identifier "wlen_795"))
                                                  (let "lebsz_ref_797" 
                                                    (make-vec (u32 1))
                                                    (seq
                                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_796")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_797")) (u8 7)))
                                                        (set-vec (u8 0) (identifier "lebsz_ref_797") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_797")) (u32 1)))) 
                                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_797")))))) 
                                                (size-of-u32 (identifier "wlen_795"))))) 
                                          (seq (assert (eq (identifier "label2_794") (u16 2))) (add (identifier "sz_793") (size 2)))))))
                                  (if (is-null (get-item 1 (get-alt "NamedOperation" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_791")) (get-field "from" (get-alt "Aggregate" (param 0)))))))
                                    (add (identifier "sz_798") (size 1))
                                    (add
                                      (add (identifier "sz_798")
                                        (let "wlen_799"
                                          (string-length (force (get-item 1 (get-alt "NamedOperation" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_791")) (get-field "from" (get-alt "Aggregate" (param 0))))))))
                                          (add
                                            (let "n_ref_800" (make-vec (identifier "wlen_799"))
                                              (let "lebsz_ref_801" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_800")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_801")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_801") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_801")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_801")))))) 
                                            (size-of-u32 (identifier "wlen_799"))))) 
                                      (size 1))))
                                (add (identifier "sz_802")
                                  (apply (ext-identifier function_name sersize-of-row-binary)
                                    (get-item 2 (get-alt "NamedOperation" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_791")) (get-field "from" (get-alt "Aggregate" (param 0)))))))))
                              (seq (assert (eq (identifier "label2_792") (u16 1)))
                                (add (add (unsafe-nth (u8 0) (identifier "sz_ref_790")) (size 2))
                                  (apply (myself "Size") (get-alt "SubQuery" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_791")) (get-field "from" (get-alt "Aggregate" (param 0)))))))))))
                        (set-vec (u8 0) (identifier "repeat_n_791") (add (unsafe-nth (u8 0) (identifier "repeat_n_791")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_790")))))
            (if (is-null (get-field "every" (get-alt "Aggregate" (param 0)))) 
              (add (identifier "sz_803") (size 1)) (add (add (identifier "sz_803") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "every" (get-alt "Aggregate" (param 0)))))) (size 1))))
          (let "sz_ref_807"
            (make-vec
              (add (identifier "sz_804")
                (let "n_ref_805" (make-vec (cardinality (get-field "factors" (get-alt "Aggregate" (param 0)))))
                  (let "lebsz_ref_806" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_805")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_806")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_806") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_806")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_806"))))))))
            (seq
              (let "repeat_n_808" (make-vec (i32 0))
                (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "Aggregate" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_808")))
                  (seq
                    (set-vec (u8 0) (identifier "sz_ref_807")
                      (add (unsafe-nth (u8 0) (identifier "sz_ref_807"))
                        (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_808")) (get-field "factors" (get-alt "Aggregate" (param 0)))))))
                    (set-vec (u8 0) (identifier "repeat_n_808") (add (unsafe-nth (u8 0) (identifier "repeat_n_808")) (i32 1)))))) 
              (unsafe-nth (u8 0) (identifier "sz_ref_807")))))
        (if (eq (u16 1) (label-of (param 0)))
          (let "sz_749"
            (let "sz_748"
              (let "sz_725"
                (if (eq (u16 0) (label-of (get-field "source" (get-alt "ReadExternal" (param 0)))))
                  (let "sz_724"
                    (let "sz_723" (add (size 4) (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "fname" (get-alt "File" (get-field "source" (get-alt "ReadExternal" (param 0)))))))
                      (if (is-null (get-field "preprocessor" (get-alt "File" (get-field "source" (get-alt "ReadExternal" (param 0)))))) 
                        (add (identifier "sz_723") (size 1))
                        (add (add (identifier "sz_723") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "preprocessor" (get-alt "File" (get-field "source" (get-alt "ReadExternal" (param 0))))))))
                          (size 1)))) (add (identifier "sz_724") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "unlink" (get-alt "File" (get-field "source" (get-alt "ReadExternal" (param 0))))))))
                  (seq (assert (eq (label-of (get-field "source" (get-alt "ReadExternal" (param 0)))) (u16 1)))
                    (let "sz_718"
                      (let "sz_717"
                        (let "sz_716"
                          (let "sz_ref_709"
                            (make-vec
                              (add (size 4)
                                (let "n_ref_707" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))))
                                  (let "lebsz_ref_708" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_707")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_708")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_708") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_708")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_708"))))))))
                            (seq
                              (let "repeat_n_710" (make-vec (i32 0))
                                (while (gt (to-i32 (cardinality (get-field "options" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0))))))) (unsafe-nth (u8 0) (identifier "repeat_n_710")))
                                  (seq
                                    (set-vec (u8 0) (identifier "sz_ref_709")
                                      (let "sz_715"
                                        (let "sz_711" (unsafe-nth (u8 0) (identifier "sz_ref_709"))
                                          (add (identifier "sz_711")
                                            (let "wlen_712"
                                              (string-length
                                                (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_710")) (get-field "options" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0))))))))
                                              (add
                                                (let "n_ref_713" (make-vec (identifier "wlen_712"))
                                                  (let "lebsz_ref_714" 
                                                    (make-vec (u32 1))
                                                    (seq
                                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_713")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_714")) (u8 7)))
                                                        (set-vec (u8 0) (identifier "lebsz_ref_714") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_714")) (u32 1)))) 
                                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_714")))))) 
                                                (size-of-u32 (identifier "wlen_712"))))))
                                        (add (identifier "sz_715")
                                          (apply (ext-identifier raql_expr sersize-of-row-binary)
                                            (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_710")) (get-field "options" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))))))))
                                    (set-vec (u8 0) (identifier "repeat_n_710") (add (unsafe-nth (u8 0) (identifier "repeat_n_710")) (i32 1)))))) 
                              (unsafe-nth (u8 0) (identifier "sz_ref_709"))))
                          (add (identifier "sz_716") (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "topic" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0))))))))
                        (if (is-null (get-field "partitions" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))) 
                          (add (identifier "sz_717") (size 1))
                          (add (add (identifier "sz_717") (apply (ext-identifier raql_expr sersize-of-row-binary) (force (get-field "partitions" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0))))))))
                            (size 1))))
                      (let "label2_719" (label-of (get-field "restart_from" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0))))))
                        (if (eq (u16 0) (identifier "label2_719")) (add (identifier "sz_718") (size 2))
                          (if (eq (u16 1) (identifier "label2_719"))
                            (add (add (identifier "sz_718") (size 2))
                              (apply (ext-identifier raql_expr sersize-of-row-binary) (get-alt "OffsetFromEnd" (get-field "restart_from" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0))))))))
                            (if (eq (u16 2) (identifier "label2_719")) 
                              (add (identifier "sz_718") (size 2))
                              (seq (assert (eq (identifier "label2_719") (u16 3)))
                                (let "sz_721"
                                  (add (add (identifier "sz_718") (size 2))
                                    (apply (ext-identifier raql_expr sersize-of-row-binary)
                                      (get-field "after_max_secs" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0)))))))))
                                  (add (identifier "sz_721")
                                    (apply (ext-identifier raql_expr sersize-of-row-binary)
                                      (get-field "after_max_events" (get-alt "UseKafkaGroupCoordinator" (get-field "restart_from" (get-alt "Kafka" (get-field "source" (get-alt "ReadExternal" (param 0))))))))))))))))))
                (if (eq (u16 0) (label-of (get-field "format" (get-alt "ReadExternal" (param 0)))))
                  (add
                    (add
                      (let "sz_741"
                        (let "sz_737"
                          (add
                            (add (add (add (identifier "sz_725") (size 2)) (size 1))
                              (add
                                (let "n_ref_734" (make-vec (string-length (get-field "null" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0)))))))
                                  (let "lebsz_ref_735" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_734")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_735")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_735") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_735")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_735")))))) 
                                (size-of-u32 (string-length (get-field "null" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0))))))))) 
                            (size 1))
                          (add (identifier "sz_737")
                            (add
                              (let "n_ref_739" (make-vec (string-length (get-field "escape_seq" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0)))))))
                                (let "lebsz_ref_740" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_739")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_740")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_740") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_740")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_740")))))) 
                              (size-of-u32 (string-length (get-field "escape_seq" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0))))))))))
                        (let "sz_ref_744"
                          (make-vec
                            (add (identifier "sz_741")
                              (let "n_ref_742" (make-vec (cardinality (get-field "fields" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0)))))))
                                (let "lebsz_ref_743" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_742")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_743")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_743") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_743")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_743"))))))))
                          (seq
                            (let "repeat_n_745" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "fields" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0))))))) (unsafe-nth (u8 0) (identifier "repeat_n_745")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_744")
                                    (add (unsafe-nth (u8 0) (identifier "sz_ref_744"))
                                      (apply (ext-identifier field_type sersize-of-row-binary)
                                        (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_745")) (get-field "fields" (get-alt "CSV" (get-field "format" (get-alt "ReadExternal" (param 0)))))))))
                                  (set-vec (u8 0) (identifier "repeat_n_745") (add (unsafe-nth (u8 0) (identifier "repeat_n_745")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_744"))))) 
                      (size 1)) (size 1))
                  (seq (assert (eq (label-of (get-field "format" (get-alt "ReadExternal" (param 0)))) (u16 1)))
                    (let "sz_ref_729"
                      (make-vec
                        (add (add (identifier "sz_725") (size 2))
                          (let "n_ref_727" (make-vec (cardinality (get-alt "RowBinary" (get-field "format" (get-alt "ReadExternal" (param 0))))))
                            (let "lebsz_ref_728" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_727")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_728")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_728") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_728")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_728"))))))))
                      (seq
                        (let "repeat_n_730" (make-vec (i32 0))
                          (while (gt (to-i32 (cardinality (get-alt "RowBinary" (get-field "format" (get-alt "ReadExternal" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_730")))
                            (seq
                              (set-vec (u8 0) (identifier "sz_ref_729")
                                (add (unsafe-nth (u8 0) (identifier "sz_ref_729"))
                                  (apply (ext-identifier field_type sersize-of-row-binary)
                                    (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_730")) (get-alt "RowBinary" (get-field "format" (get-alt "ReadExternal" (param 0))))))))
                              (set-vec (u8 0) (identifier "repeat_n_730") (add (unsafe-nth (u8 0) (identifier "repeat_n_730")) (i32 1)))))) 
                        (unsafe-nth (u8 0) (identifier "sz_ref_729")))))))
              (if (is-null (get-field "event_time" (get-alt "ReadExternal" (param 0)))) 
                (add (identifier "sz_748") (size 1)) (add (add (identifier "sz_748") (apply (ext-identifier event_time sersize-of-row-binary) (force (get-field "event_time" (get-alt "ReadExternal" (param 0)))))) (size 1))))
            (let "sz_ref_752"
              (make-vec
                (add (identifier "sz_749")
                  (let "n_ref_750" (make-vec (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0)))))
                    (let "lebsz_ref_751" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_750")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_751")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_751") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_751")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_751"))))))))
              (seq
                (let "repeat_n_753" (make-vec (i32 0))
                  (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "ReadExternal" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_753")))
                    (seq
                      (set-vec (u8 0) (identifier "sz_ref_752")
                        (add (unsafe-nth (u8 0) (identifier "sz_ref_752"))
                          (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_753")) (get-field "factors" (get-alt "ReadExternal" (param 0)))))))
                      (set-vec (u8 0) (identifier "repeat_n_753") (add (unsafe-nth (u8 0) (identifier "repeat_n_753")) (i32 1)))))) 
                (unsafe-nth (u8 0) (identifier "sz_ref_752")))))
          (seq (assert (eq (label-of (param 0)) (u16 2)))
            (let "sz_699"
              (let "sz_698"
                (add
                  (add (size 2)
                    (add
                      (let "n_ref_695" (make-vec (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0)))))
                        (let "lebsz_ref_696" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_695")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_696")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_696") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_696")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_696")))))) 
                      (size-of-u32 (string-length (get-field "net_addr" (get-alt "ListenFor" (param 0))))))) 
                  (size 2)) (add (identifier "sz_698") (apply (ext-identifier raql_net_protocol sersize-of-row-binary) (get-field "proto" (get-alt "ListenFor" (param 0))))))
              (let "sz_ref_702"
                (make-vec
                  (add (identifier "sz_699")
                    (let "n_ref_700" (make-vec (cardinality (get-field "factors" (get-alt "ListenFor" (param 0)))))
                      (let "lebsz_ref_701" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_700")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_701")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_701") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_701")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_701"))))))))
                (seq
                  (let "repeat_n_703" (make-vec (i32 0))
                    (while (gt (to-i32 (cardinality (get-field "factors" (get-alt "ListenFor" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_703")))
                      (seq
                        (set-vec (u8 0) (identifier "sz_ref_702")
                          (add (unsafe-nth (u8 0) (identifier "sz_ref_702"))
                            (apply (ext-identifier field_name sersize-of-row-binary) (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_703")) (get-field "factors" (get-alt "ListenFor" (param 0)))))))
                        (set-vec (u8 0) (identifier "repeat_n_703") (add (unsafe-nth (u8 0) (identifier "repeat_n_703")) (i32 1)))))) 
                  (unsafe-nth (u8 0) (identifier "sz_ref_702")))))))))
 */
static std::function<Size(t*)> sersize_of_row_binary_init()
{
  std::function<Size(t*)> fun1339 { [&fun1339](t* p_0) {
    uint16_t id_1340 { 0 };
    uint16_t id_1341 { uint16_t(p_0->index()) };
    bool id_1342 { bool(id_1340 == id_1341) };
    Size choose_res_1343;
    if (id_1342) {
      Size id_1344 { 2UL };
      ta2fe18cae70948742cabb6081fd22a0c id_1345 { std::get<0>(*p_0) };
      Lst<dessser::gen::raql_select_field::t_ext> id_1346 { id_1345.fields };
      uint32_t id_1347 { id_1346.size() };
      Vec<1, uint32_t> id_1348 {  id_1347  };
      Size let_res_1349;
      {
        Vec<1, uint32_t> n_ref_755 { id_1348 };
        uint32_t id_1350 { 1U };
        Vec<1, uint32_t> id_1351 {  id_1350  };
        Size let_res_1352;
        {
          Vec<1, uint32_t> lebsz_ref_756 { id_1351 };
          bool while_flag_1353 { true };
          do {
            uint8_t id_1354 { 0 };
            uint32_t id_1355 { n_ref_755[id_1354] };
            uint8_t id_1356 { 0 };
            uint32_t id_1357 { lebsz_ref_756[id_1356] };
            uint8_t id_1358 { 7 };
            uint32_t id_1359 { uint32_t(id_1357 << id_1358) };
            bool id_1360 { bool(id_1355 >= id_1359) };
            while_flag_1353 = id_1360;
            if (while_flag_1353) {
              uint8_t id_1361 { 0 };
              uint8_t id_1362 { 0 };
              uint32_t id_1363 { lebsz_ref_756[id_1362] };
              uint32_t id_1364 { 1U };
              uint32_t id_1365 { uint32_t(id_1363 + id_1364) };
              Void id_1366 { ((void)(lebsz_ref_756[id_1361] = id_1365), VOID) };
              (void)id_1366;
            }
          } while (while_flag_1353);
          (void)VOID;
          uint8_t id_1367 { 0 };
          uint32_t id_1368 { lebsz_ref_756[id_1367] };
          Size id_1369 { Size(id_1368) };
          let_res_1352 = id_1369;
        }
        let_res_1349 = let_res_1352;
      }
      Size id_1370 { Size(id_1344 + let_res_1349) };
      Vec<1, Size> id_1371 {  id_1370  };
      Size let_res_1372;
      {
        Vec<1, Size> sz_ref_757 { id_1371 };
        int32_t id_1373 { 0L };
        Vec<1, int32_t> id_1374 {  id_1373  };
        {
          Vec<1, int32_t> repeat_n_758 { id_1374 };
          bool while_flag_1375 { true };
          do {
            ta2fe18cae70948742cabb6081fd22a0c id_1376 { std::get<0>(*p_0) };
            Lst<dessser::gen::raql_select_field::t_ext> id_1377 { id_1376.fields };
            uint32_t id_1378 { id_1377.size() };
            int32_t id_1379 { int32_t(id_1378) };
            uint8_t id_1380 { 0 };
            int32_t id_1381 { repeat_n_758[id_1380] };
            bool id_1382 { bool(id_1379 > id_1381) };
            while_flag_1375 = id_1382;
            if (while_flag_1375) {
              uint8_t id_1383 { 0 };
              uint8_t id_1384 { 0 };
              Size id_1385 { sz_ref_757[id_1384] };
              auto fun1386 { dessser::gen::raql_select_field::sersize_of_row_binary };
              uint8_t id_1387 { 0 };
              int32_t id_1388 { repeat_n_758[id_1387] };
              ta2fe18cae70948742cabb6081fd22a0c id_1389 { std::get<0>(*p_0) };
              Lst<dessser::gen::raql_select_field::t_ext> id_1390 { id_1389.fields };
              dessser::gen::raql_select_field::t_ext id_1391 { id_1390[id_1388] };
              Size id_1392 { fun1386(id_1391) };
              Size id_1393 { Size(id_1385 + id_1392) };
              Void id_1394 { ((void)(sz_ref_757[id_1383] = id_1393), VOID) };
              (void)id_1394;
              uint8_t id_1395 { 0 };
              uint8_t id_1396 { 0 };
              int32_t id_1397 { repeat_n_758[id_1396] };
              int32_t id_1398 { 1L };
              int32_t id_1399 { int32_t(id_1397 + id_1398) };
              Void id_1400 { ((void)(repeat_n_758[id_1395] = id_1399), VOID) };
              (void)id_1400;
              (void)id_1400;
            }
          } while (while_flag_1375);
          (void)VOID;
        }
        (void)VOID;
        uint8_t id_1401 { 0 };
        Size id_1402 { sz_ref_757[id_1401] };
        let_res_1372 = id_1402;
      }
      Size let_res_1403;
      {
        Size sz_759 { let_res_1372 };
        ta2fe18cae70948742cabb6081fd22a0c id_1404 { std::get<0>(*p_0) };
        std::optional<Lst<dessser::gen::field_name::t_ext>> id_1405 { id_1404.and_all_others };
        bool id_1406 { !(id_1405.has_value ()) };
        Size choose_res_1407;
        if (id_1406) {
          Size id_1408 { 1UL };
          Size id_1409 { Size(sz_759 + id_1408) };
          choose_res_1407 = id_1409;
        } else {
          ta2fe18cae70948742cabb6081fd22a0c id_1410 { std::get<0>(*p_0) };
          std::optional<Lst<dessser::gen::field_name::t_ext>> id_1411 { id_1410.and_all_others };
          Lst<dessser::gen::field_name::t_ext> id_1412 { id_1411.value() };
          uint32_t id_1413 { id_1412.size() };
          Vec<1, uint32_t> id_1414 {  id_1413  };
          Size let_res_1415;
          {
            Vec<1, uint32_t> n_ref_760 { id_1414 };
            uint32_t id_1416 { 1U };
            Vec<1, uint32_t> id_1417 {  id_1416  };
            Size let_res_1418;
            {
              Vec<1, uint32_t> lebsz_ref_761 { id_1417 };
              bool while_flag_1419 { true };
              do {
                uint8_t id_1420 { 0 };
                uint32_t id_1421 { n_ref_760[id_1420] };
                uint8_t id_1422 { 0 };
                uint32_t id_1423 { lebsz_ref_761[id_1422] };
                uint8_t id_1424 { 7 };
                uint32_t id_1425 { uint32_t(id_1423 << id_1424) };
                bool id_1426 { bool(id_1421 >= id_1425) };
                while_flag_1419 = id_1426;
                if (while_flag_1419) {
                  uint8_t id_1427 { 0 };
                  uint8_t id_1428 { 0 };
                  uint32_t id_1429 { lebsz_ref_761[id_1428] };
                  uint32_t id_1430 { 1U };
                  uint32_t id_1431 { uint32_t(id_1429 + id_1430) };
                  Void id_1432 { ((void)(lebsz_ref_761[id_1427] = id_1431), VOID) };
                  (void)id_1432;
                }
              } while (while_flag_1419);
              (void)VOID;
              uint8_t id_1433 { 0 };
              uint32_t id_1434 { lebsz_ref_761[id_1433] };
              Size id_1435 { Size(id_1434) };
              let_res_1418 = id_1435;
            }
            let_res_1415 = let_res_1418;
          }
          Size id_1436 { Size(sz_759 + let_res_1415) };
          Vec<1, Size> id_1437 {  id_1436  };
          Size let_res_1438;
          {
            Vec<1, Size> sz_ref_762 { id_1437 };
            int32_t id_1439 { 0L };
            Vec<1, int32_t> id_1440 {  id_1439  };
            {
              Vec<1, int32_t> repeat_n_763 { id_1440 };
              bool while_flag_1441 { true };
              do {
                ta2fe18cae70948742cabb6081fd22a0c id_1442 { std::get<0>(*p_0) };
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_1443 { id_1442.and_all_others };
                Lst<dessser::gen::field_name::t_ext> id_1444 { id_1443.value() };
                uint32_t id_1445 { id_1444.size() };
                int32_t id_1446 { int32_t(id_1445) };
                uint8_t id_1447 { 0 };
                int32_t id_1448 { repeat_n_763[id_1447] };
                bool id_1449 { bool(id_1446 > id_1448) };
                while_flag_1441 = id_1449;
                if (while_flag_1441) {
                  uint8_t id_1450 { 0 };
                  uint8_t id_1451 { 0 };
                  Size id_1452 { sz_ref_762[id_1451] };
                  auto fun1453 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_1454 { 0 };
                  int32_t id_1455 { repeat_n_763[id_1454] };
                  ta2fe18cae70948742cabb6081fd22a0c id_1456 { std::get<0>(*p_0) };
                  std::optional<Lst<dessser::gen::field_name::t_ext>> id_1457 { id_1456.and_all_others };
                  Lst<dessser::gen::field_name::t_ext> id_1458 { id_1457.value() };
                  dessser::gen::field_name::t_ext id_1459 { id_1458[id_1455] };
                  Size id_1460 { fun1453(id_1459) };
                  Size id_1461 { Size(id_1452 + id_1460) };
                  Void id_1462 { ((void)(sz_ref_762[id_1450] = id_1461), VOID) };
                  (void)id_1462;
                  uint8_t id_1463 { 0 };
                  uint8_t id_1464 { 0 };
                  int32_t id_1465 { repeat_n_763[id_1464] };
                  int32_t id_1466 { 1L };
                  int32_t id_1467 { int32_t(id_1465 + id_1466) };
                  Void id_1468 { ((void)(repeat_n_763[id_1463] = id_1467), VOID) };
                  (void)id_1468;
                  (void)id_1468;
                }
              } while (while_flag_1441);
              (void)VOID;
            }
            (void)VOID;
            uint8_t id_1469 { 0 };
            Size id_1470 { sz_ref_762[id_1469] };
            let_res_1438 = id_1470;
          }
          Size id_1471 { 1UL };
          Size id_1472 { Size(let_res_1438 + id_1471) };
          choose_res_1407 = id_1472;
        }
        let_res_1403 = choose_res_1407;
      }
      Size let_res_1473;
      {
        Size sz_764 { let_res_1403 };
        ta2fe18cae70948742cabb6081fd22a0c id_1474 { std::get<0>(*p_0) };
        std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_1475 { id_1474.sort };
        bool id_1476 { !(id_1475.has_value ()) };
        Size choose_res_1477;
        if (id_1476) {
          Size id_1478 { 1UL };
          Size id_1479 { Size(sz_764 + id_1478) };
          choose_res_1477 = id_1479;
        } else {
          ta2fe18cae70948742cabb6081fd22a0c id_1480 { std::get<0>(*p_0) };
          std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_1481 { id_1480.sort };
          tf0c8d4f3070907529cc1a83f8baf6fab id_1482 { id_1481.value() };
          std::optional<dessser::gen::raql_expr::t_ext> id_1483 { std::get<1>(id_1482) };
          bool id_1484 { !(id_1483.has_value ()) };
          Size choose_res_1485;
          if (id_1484) {
            Size id_1486 { 4UL };
            Size id_1487 { Size(sz_764 + id_1486) };
            Size id_1488 { 1UL };
            Size id_1489 { Size(id_1487 + id_1488) };
            choose_res_1485 = id_1489;
          } else {
            Size id_1490 { 4UL };
            Size id_1491 { Size(sz_764 + id_1490) };
            auto fun1492 { dessser::gen::raql_expr::sersize_of_row_binary };
            ta2fe18cae70948742cabb6081fd22a0c id_1493 { std::get<0>(*p_0) };
            std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_1494 { id_1493.sort };
            tf0c8d4f3070907529cc1a83f8baf6fab id_1495 { id_1494.value() };
            std::optional<dessser::gen::raql_expr::t_ext> id_1496 { std::get<1>(id_1495) };
            dessser::gen::raql_expr::t_ext id_1497 { id_1496.value() };
            Size id_1498 { fun1492(id_1497) };
            Size id_1499 { Size(id_1491 + id_1498) };
            Size id_1500 { 1UL };
            Size id_1501 { Size(id_1499 + id_1500) };
            choose_res_1485 = id_1501;
          }
          Size let_res_1502;
          {
            Size sz_767 { choose_res_1485 };
            ta2fe18cae70948742cabb6081fd22a0c id_1503 { std::get<0>(*p_0) };
            std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_1504 { id_1503.sort };
            tf0c8d4f3070907529cc1a83f8baf6fab id_1505 { id_1504.value() };
            Lst<dessser::gen::raql_expr::t_ext> id_1506 { std::get<2>(id_1505) };
            uint32_t id_1507 { id_1506.size() };
            Vec<1, uint32_t> id_1508 {  id_1507  };
            Size let_res_1509;
            {
              Vec<1, uint32_t> n_ref_768 { id_1508 };
              uint32_t id_1510 { 1U };
              Vec<1, uint32_t> id_1511 {  id_1510  };
              Size let_res_1512;
              {
                Vec<1, uint32_t> lebsz_ref_769 { id_1511 };
                bool while_flag_1513 { true };
                do {
                  uint8_t id_1514 { 0 };
                  uint32_t id_1515 { n_ref_768[id_1514] };
                  uint8_t id_1516 { 0 };
                  uint32_t id_1517 { lebsz_ref_769[id_1516] };
                  uint8_t id_1518 { 7 };
                  uint32_t id_1519 { uint32_t(id_1517 << id_1518) };
                  bool id_1520 { bool(id_1515 >= id_1519) };
                  while_flag_1513 = id_1520;
                  if (while_flag_1513) {
                    uint8_t id_1521 { 0 };
                    uint8_t id_1522 { 0 };
                    uint32_t id_1523 { lebsz_ref_769[id_1522] };
                    uint32_t id_1524 { 1U };
                    uint32_t id_1525 { uint32_t(id_1523 + id_1524) };
                    Void id_1526 { ((void)(lebsz_ref_769[id_1521] = id_1525), VOID) };
                    (void)id_1526;
                  }
                } while (while_flag_1513);
                (void)VOID;
                uint8_t id_1527 { 0 };
                uint32_t id_1528 { lebsz_ref_769[id_1527] };
                Size id_1529 { Size(id_1528) };
                let_res_1512 = id_1529;
              }
              let_res_1509 = let_res_1512;
            }
            Size id_1530 { Size(sz_767 + let_res_1509) };
            Vec<1, Size> id_1531 {  id_1530  };
            Size let_res_1532;
            {
              Vec<1, Size> sz_ref_770 { id_1531 };
              int32_t id_1533 { 0L };
              Vec<1, int32_t> id_1534 {  id_1533  };
              {
                Vec<1, int32_t> repeat_n_771 { id_1534 };
                bool while_flag_1535 { true };
                do {
                  ta2fe18cae70948742cabb6081fd22a0c id_1536 { std::get<0>(*p_0) };
                  std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_1537 { id_1536.sort };
                  tf0c8d4f3070907529cc1a83f8baf6fab id_1538 { id_1537.value() };
                  Lst<dessser::gen::raql_expr::t_ext> id_1539 { std::get<2>(id_1538) };
                  uint32_t id_1540 { id_1539.size() };
                  int32_t id_1541 { int32_t(id_1540) };
                  uint8_t id_1542 { 0 };
                  int32_t id_1543 { repeat_n_771[id_1542] };
                  bool id_1544 { bool(id_1541 > id_1543) };
                  while_flag_1535 = id_1544;
                  if (while_flag_1535) {
                    uint8_t id_1545 { 0 };
                    uint8_t id_1546 { 0 };
                    Size id_1547 { sz_ref_770[id_1546] };
                    auto fun1548 { dessser::gen::raql_expr::sersize_of_row_binary };
                    uint8_t id_1549 { 0 };
                    int32_t id_1550 { repeat_n_771[id_1549] };
                    ta2fe18cae70948742cabb6081fd22a0c id_1551 { std::get<0>(*p_0) };
                    std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_1552 { id_1551.sort };
                    tf0c8d4f3070907529cc1a83f8baf6fab id_1553 { id_1552.value() };
                    Lst<dessser::gen::raql_expr::t_ext> id_1554 { std::get<2>(id_1553) };
                    dessser::gen::raql_expr::t_ext id_1555 { id_1554[id_1550] };
                    Size id_1556 { fun1548(id_1555) };
                    Size id_1557 { Size(id_1547 + id_1556) };
                    Void id_1558 { ((void)(sz_ref_770[id_1545] = id_1557), VOID) };
                    (void)id_1558;
                    uint8_t id_1559 { 0 };
                    uint8_t id_1560 { 0 };
                    int32_t id_1561 { repeat_n_771[id_1560] };
                    int32_t id_1562 { 1L };
                    int32_t id_1563 { int32_t(id_1561 + id_1562) };
                    Void id_1564 { ((void)(repeat_n_771[id_1559] = id_1563), VOID) };
                    (void)id_1564;
                    (void)id_1564;
                  }
                } while (while_flag_1535);
                (void)VOID;
              }
              (void)VOID;
              uint8_t id_1565 { 0 };
              Size id_1566 { sz_ref_770[id_1565] };
              let_res_1532 = id_1566;
            }
            let_res_1502 = let_res_1532;
          }
          Size id_1567 { 1UL };
          Size id_1568 { Size(let_res_1502 + id_1567) };
          choose_res_1477 = id_1568;
        }
        let_res_1473 = choose_res_1477;
      }
      Size let_res_1569;
      {
        Size sz_772 { let_res_1473 };
        auto fun1570 { dessser::gen::raql_expr::sersize_of_row_binary };
        ta2fe18cae70948742cabb6081fd22a0c id_1571 { std::get<0>(*p_0) };
        dessser::gen::raql_expr::t_ext id_1572 { id_1571.where };
        Size id_1573 { fun1570(id_1572) };
        Size id_1574 { Size(sz_772 + id_1573) };
        let_res_1569 = id_1574;
      }
      Size let_res_1575;
      {
        Size sz_773 { let_res_1569 };
        ta2fe18cae70948742cabb6081fd22a0c id_1576 { std::get<0>(*p_0) };
        std::optional<dessser::gen::event_time::t_ext> id_1577 { id_1576.event_time };
        bool id_1578 { !(id_1577.has_value ()) };
        Size choose_res_1579;
        if (id_1578) {
          Size id_1580 { 1UL };
          Size id_1581 { Size(sz_773 + id_1580) };
          choose_res_1579 = id_1581;
        } else {
          auto fun1582 { dessser::gen::event_time::sersize_of_row_binary };
          ta2fe18cae70948742cabb6081fd22a0c id_1583 { std::get<0>(*p_0) };
          std::optional<dessser::gen::event_time::t_ext> id_1584 { id_1583.event_time };
          dessser::gen::event_time::t_ext id_1585 { id_1584.value() };
          Size id_1586 { fun1582(id_1585) };
          Size id_1587 { Size(sz_773 + id_1586) };
          Size id_1588 { 1UL };
          Size id_1589 { Size(id_1587 + id_1588) };
          choose_res_1579 = id_1589;
        }
        let_res_1575 = choose_res_1579;
      }
      Size let_res_1590;
      {
        Size sz_774 { let_res_1575 };
        ta2fe18cae70948742cabb6081fd22a0c id_1591 { std::get<0>(*p_0) };
        Lst<dessser::gen::raql_expr::t_ext> id_1592 { id_1591.notifications };
        uint32_t id_1593 { id_1592.size() };
        Vec<1, uint32_t> id_1594 {  id_1593  };
        Size let_res_1595;
        {
          Vec<1, uint32_t> n_ref_775 { id_1594 };
          uint32_t id_1596 { 1U };
          Vec<1, uint32_t> id_1597 {  id_1596  };
          Size let_res_1598;
          {
            Vec<1, uint32_t> lebsz_ref_776 { id_1597 };
            bool while_flag_1599 { true };
            do {
              uint8_t id_1600 { 0 };
              uint32_t id_1601 { n_ref_775[id_1600] };
              uint8_t id_1602 { 0 };
              uint32_t id_1603 { lebsz_ref_776[id_1602] };
              uint8_t id_1604 { 7 };
              uint32_t id_1605 { uint32_t(id_1603 << id_1604) };
              bool id_1606 { bool(id_1601 >= id_1605) };
              while_flag_1599 = id_1606;
              if (while_flag_1599) {
                uint8_t id_1607 { 0 };
                uint8_t id_1608 { 0 };
                uint32_t id_1609 { lebsz_ref_776[id_1608] };
                uint32_t id_1610 { 1U };
                uint32_t id_1611 { uint32_t(id_1609 + id_1610) };
                Void id_1612 { ((void)(lebsz_ref_776[id_1607] = id_1611), VOID) };
                (void)id_1612;
              }
            } while (while_flag_1599);
            (void)VOID;
            uint8_t id_1613 { 0 };
            uint32_t id_1614 { lebsz_ref_776[id_1613] };
            Size id_1615 { Size(id_1614) };
            let_res_1598 = id_1615;
          }
          let_res_1595 = let_res_1598;
        }
        Size id_1616 { Size(sz_774 + let_res_1595) };
        Vec<1, Size> id_1617 {  id_1616  };
        Size let_res_1618;
        {
          Vec<1, Size> sz_ref_777 { id_1617 };
          int32_t id_1619 { 0L };
          Vec<1, int32_t> id_1620 {  id_1619  };
          {
            Vec<1, int32_t> repeat_n_778 { id_1620 };
            bool while_flag_1621 { true };
            do {
              ta2fe18cae70948742cabb6081fd22a0c id_1622 { std::get<0>(*p_0) };
              Lst<dessser::gen::raql_expr::t_ext> id_1623 { id_1622.notifications };
              uint32_t id_1624 { id_1623.size() };
              int32_t id_1625 { int32_t(id_1624) };
              uint8_t id_1626 { 0 };
              int32_t id_1627 { repeat_n_778[id_1626] };
              bool id_1628 { bool(id_1625 > id_1627) };
              while_flag_1621 = id_1628;
              if (while_flag_1621) {
                uint8_t id_1629 { 0 };
                uint8_t id_1630 { 0 };
                Size id_1631 { sz_ref_777[id_1630] };
                auto fun1632 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_1633 { 0 };
                int32_t id_1634 { repeat_n_778[id_1633] };
                ta2fe18cae70948742cabb6081fd22a0c id_1635 { std::get<0>(*p_0) };
                Lst<dessser::gen::raql_expr::t_ext> id_1636 { id_1635.notifications };
                dessser::gen::raql_expr::t_ext id_1637 { id_1636[id_1634] };
                Size id_1638 { fun1632(id_1637) };
                Size id_1639 { Size(id_1631 + id_1638) };
                Void id_1640 { ((void)(sz_ref_777[id_1629] = id_1639), VOID) };
                (void)id_1640;
                uint8_t id_1641 { 0 };
                uint8_t id_1642 { 0 };
                int32_t id_1643 { repeat_n_778[id_1642] };
                int32_t id_1644 { 1L };
                int32_t id_1645 { int32_t(id_1643 + id_1644) };
                Void id_1646 { ((void)(repeat_n_778[id_1641] = id_1645), VOID) };
                (void)id_1646;
                (void)id_1646;
              }
            } while (while_flag_1621);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_1647 { 0 };
          Size id_1648 { sz_ref_777[id_1647] };
          let_res_1618 = id_1648;
        }
        let_res_1590 = let_res_1618;
      }
      Size let_res_1649;
      {
        Size sz_779 { let_res_1590 };
        ta2fe18cae70948742cabb6081fd22a0c id_1650 { std::get<0>(*p_0) };
        Lst<dessser::gen::raql_expr::t_ext> id_1651 { id_1650.key };
        uint32_t id_1652 { id_1651.size() };
        Vec<1, uint32_t> id_1653 {  id_1652  };
        Size let_res_1654;
        {
          Vec<1, uint32_t> n_ref_780 { id_1653 };
          uint32_t id_1655 { 1U };
          Vec<1, uint32_t> id_1656 {  id_1655  };
          Size let_res_1657;
          {
            Vec<1, uint32_t> lebsz_ref_781 { id_1656 };
            bool while_flag_1658 { true };
            do {
              uint8_t id_1659 { 0 };
              uint32_t id_1660 { n_ref_780[id_1659] };
              uint8_t id_1661 { 0 };
              uint32_t id_1662 { lebsz_ref_781[id_1661] };
              uint8_t id_1663 { 7 };
              uint32_t id_1664 { uint32_t(id_1662 << id_1663) };
              bool id_1665 { bool(id_1660 >= id_1664) };
              while_flag_1658 = id_1665;
              if (while_flag_1658) {
                uint8_t id_1666 { 0 };
                uint8_t id_1667 { 0 };
                uint32_t id_1668 { lebsz_ref_781[id_1667] };
                uint32_t id_1669 { 1U };
                uint32_t id_1670 { uint32_t(id_1668 + id_1669) };
                Void id_1671 { ((void)(lebsz_ref_781[id_1666] = id_1670), VOID) };
                (void)id_1671;
              }
            } while (while_flag_1658);
            (void)VOID;
            uint8_t id_1672 { 0 };
            uint32_t id_1673 { lebsz_ref_781[id_1672] };
            Size id_1674 { Size(id_1673) };
            let_res_1657 = id_1674;
          }
          let_res_1654 = let_res_1657;
        }
        Size id_1675 { Size(sz_779 + let_res_1654) };
        Vec<1, Size> id_1676 {  id_1675  };
        Size let_res_1677;
        {
          Vec<1, Size> sz_ref_782 { id_1676 };
          int32_t id_1678 { 0L };
          Vec<1, int32_t> id_1679 {  id_1678  };
          {
            Vec<1, int32_t> repeat_n_783 { id_1679 };
            bool while_flag_1680 { true };
            do {
              ta2fe18cae70948742cabb6081fd22a0c id_1681 { std::get<0>(*p_0) };
              Lst<dessser::gen::raql_expr::t_ext> id_1682 { id_1681.key };
              uint32_t id_1683 { id_1682.size() };
              int32_t id_1684 { int32_t(id_1683) };
              uint8_t id_1685 { 0 };
              int32_t id_1686 { repeat_n_783[id_1685] };
              bool id_1687 { bool(id_1684 > id_1686) };
              while_flag_1680 = id_1687;
              if (while_flag_1680) {
                uint8_t id_1688 { 0 };
                uint8_t id_1689 { 0 };
                Size id_1690 { sz_ref_782[id_1689] };
                auto fun1691 { dessser::gen::raql_expr::sersize_of_row_binary };
                uint8_t id_1692 { 0 };
                int32_t id_1693 { repeat_n_783[id_1692] };
                ta2fe18cae70948742cabb6081fd22a0c id_1694 { std::get<0>(*p_0) };
                Lst<dessser::gen::raql_expr::t_ext> id_1695 { id_1694.key };
                dessser::gen::raql_expr::t_ext id_1696 { id_1695[id_1693] };
                Size id_1697 { fun1691(id_1696) };
                Size id_1698 { Size(id_1690 + id_1697) };
                Void id_1699 { ((void)(sz_ref_782[id_1688] = id_1698), VOID) };
                (void)id_1699;
                uint8_t id_1700 { 0 };
                uint8_t id_1701 { 0 };
                int32_t id_1702 { repeat_n_783[id_1701] };
                int32_t id_1703 { 1L };
                int32_t id_1704 { int32_t(id_1702 + id_1703) };
                Void id_1705 { ((void)(repeat_n_783[id_1700] = id_1704), VOID) };
                (void)id_1705;
                (void)id_1705;
              }
            } while (while_flag_1680);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_1706 { 0 };
          Size id_1707 { sz_ref_782[id_1706] };
          let_res_1677 = id_1707;
        }
        let_res_1649 = let_res_1677;
      }
      Size let_res_1708;
      {
        Size sz_784 { let_res_1649 };
        auto fun1709 { dessser::gen::raql_expr::sersize_of_row_binary };
        ta2fe18cae70948742cabb6081fd22a0c id_1710 { std::get<0>(*p_0) };
        dessser::gen::raql_expr::t_ext id_1711 { id_1710.commit_cond };
        Size id_1712 { fun1709(id_1711) };
        Size id_1713 { Size(sz_784 + id_1712) };
        let_res_1708 = id_1713;
      }
      Size id_1714 { 1UL };
      Size id_1715 { Size(let_res_1708 + id_1714) };
      Size let_res_1716;
      {
        Size sz_786 { id_1715 };
        auto fun1717 { dessser::gen::raql_flush_method::sersize_of_row_binary };
        ta2fe18cae70948742cabb6081fd22a0c id_1718 { std::get<0>(*p_0) };
        dessser::gen::raql_flush_method::t_ext id_1719 { id_1718.flush_how };
        Size id_1720 { fun1717(id_1719) };
        Size id_1721 { Size(sz_786 + id_1720) };
        let_res_1716 = id_1721;
      }
      Size let_res_1722;
      {
        Size sz_787 { let_res_1716 };
        ta2fe18cae70948742cabb6081fd22a0c id_1723 { std::get<0>(*p_0) };
        Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_1724 { id_1723.from };
        uint32_t id_1725 { id_1724.size() };
        Vec<1, uint32_t> id_1726 {  id_1725  };
        Size let_res_1727;
        {
          Vec<1, uint32_t> n_ref_788 { id_1726 };
          uint32_t id_1728 { 1U };
          Vec<1, uint32_t> id_1729 {  id_1728  };
          Size let_res_1730;
          {
            Vec<1, uint32_t> lebsz_ref_789 { id_1729 };
            bool while_flag_1731 { true };
            do {
              uint8_t id_1732 { 0 };
              uint32_t id_1733 { n_ref_788[id_1732] };
              uint8_t id_1734 { 0 };
              uint32_t id_1735 { lebsz_ref_789[id_1734] };
              uint8_t id_1736 { 7 };
              uint32_t id_1737 { uint32_t(id_1735 << id_1736) };
              bool id_1738 { bool(id_1733 >= id_1737) };
              while_flag_1731 = id_1738;
              if (while_flag_1731) {
                uint8_t id_1739 { 0 };
                uint8_t id_1740 { 0 };
                uint32_t id_1741 { lebsz_ref_789[id_1740] };
                uint32_t id_1742 { 1U };
                uint32_t id_1743 { uint32_t(id_1741 + id_1742) };
                Void id_1744 { ((void)(lebsz_ref_789[id_1739] = id_1743), VOID) };
                (void)id_1744;
              }
            } while (while_flag_1731);
            (void)VOID;
            uint8_t id_1745 { 0 };
            uint32_t id_1746 { lebsz_ref_789[id_1745] };
            Size id_1747 { Size(id_1746) };
            let_res_1730 = id_1747;
          }
          let_res_1727 = let_res_1730;
        }
        Size id_1748 { Size(sz_787 + let_res_1727) };
        Vec<1, Size> id_1749 {  id_1748  };
        Size let_res_1750;
        {
          Vec<1, Size> sz_ref_790 { id_1749 };
          int32_t id_1751 { 0L };
          Vec<1, int32_t> id_1752 {  id_1751  };
          {
            Vec<1, int32_t> repeat_n_791 { id_1752 };
            bool while_flag_1753 { true };
            do {
              ta2fe18cae70948742cabb6081fd22a0c id_1754 { std::get<0>(*p_0) };
              Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_1755 { id_1754.from };
              uint32_t id_1756 { id_1755.size() };
              int32_t id_1757 { int32_t(id_1756) };
              uint8_t id_1758 { 0 };
              int32_t id_1759 { repeat_n_791[id_1758] };
              bool id_1760 { bool(id_1757 > id_1759) };
              while_flag_1753 = id_1760;
              if (while_flag_1753) {
                uint8_t id_1761 { 0 };
                uint8_t id_1762 { 0 };
                int32_t id_1763 { repeat_n_791[id_1762] };
                ta2fe18cae70948742cabb6081fd22a0c id_1764 { std::get<0>(*p_0) };
                Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_1765 { id_1764.from };
                t7c6bbe37b66fb3a66c00c4bd1bfc4369 id_1766 { id_1765[id_1763] };
                uint16_t id_1767 { uint16_t(id_1766.index()) };
                Size let_res_1768;
                {
                  uint16_t label2_792 { id_1767 };
                  uint16_t id_1769 { 0 };
                  bool id_1770 { bool(id_1769 == label2_792) };
                  Size choose_res_1771;
                  if (id_1770) {
                    uint8_t id_1772 { 0 };
                    Size id_1773 { sz_ref_790[id_1772] };
                    Size id_1774 { 2UL };
                    Size id_1775 { Size(id_1773 + id_1774) };
                    Size let_res_1776;
                    {
                      Size sz_793 { id_1775 };
                      uint8_t id_1777 { 0 };
                      int32_t id_1778 { repeat_n_791[id_1777] };
                      ta2fe18cae70948742cabb6081fd22a0c id_1779 { std::get<0>(*p_0) };
                      Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_1780 { id_1779.from };
                      t7c6bbe37b66fb3a66c00c4bd1bfc4369 id_1781 { id_1780[id_1778] };
                      t9b471a57e45588f3795bf9ca91c31ff6 id_1782 { std::get<0>(id_1781) };
                      te10a95f610a64bfb7ccea542c54f0a25 id_1783 { std::get<0>(id_1782) };
                      uint16_t id_1784 { uint16_t(id_1783.index()) };
                      Size let_res_1785;
                      {
                        uint16_t label2_794 { id_1784 };
                        uint16_t id_1786 { 0 };
                        bool id_1787 { bool(id_1786 == label2_794) };
                        Size choose_res_1788;
                        if (id_1787) {
                          Size id_1789 { 2UL };
                          Size id_1790 { Size(sz_793 + id_1789) };
                          choose_res_1788 = id_1790;
                        } else {
                          uint16_t id_1791 { 1 };
                          bool id_1792 { bool(id_1791 == label2_794) };
                          Size choose_res_1793;
                          if (id_1792) {
                            Size id_1794 { 2UL };
                            Size id_1795 { Size(sz_793 + id_1794) };
                            uint8_t id_1796 { 0 };
                            int32_t id_1797 { repeat_n_791[id_1796] };
                            ta2fe18cae70948742cabb6081fd22a0c id_1798 { std::get<0>(*p_0) };
                            Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_1799 { id_1798.from };
                            t7c6bbe37b66fb3a66c00c4bd1bfc4369 id_1800 { id_1799[id_1797] };
                            t9b471a57e45588f3795bf9ca91c31ff6 id_1801 { std::get<0>(id_1800) };
                            te10a95f610a64bfb7ccea542c54f0a25 id_1802 { std::get<0>(id_1801) };
                            std::string id_1803 { std::get<1>(id_1802) };
                            uint32_t id_1804 { (uint32_t)id_1803.size() };
                            Size let_res_1805;
                            {
                              uint32_t wlen_795 { id_1804 };
                              Vec<1, uint32_t> id_1806 {  wlen_795  };
                              Size let_res_1807;
                              {
                                Vec<1, uint32_t> n_ref_796 { id_1806 };
                                uint32_t id_1808 { 1U };
                                Vec<1, uint32_t> id_1809 {  id_1808  };
                                Size let_res_1810;
                                {
                                  Vec<1, uint32_t> lebsz_ref_797 { id_1809 };
                                  bool while_flag_1811 { true };
                                  do {
                                    uint8_t id_1812 { 0 };
                                    uint32_t id_1813 { n_ref_796[id_1812] };
                                    uint8_t id_1814 { 0 };
                                    uint32_t id_1815 { lebsz_ref_797[id_1814] };
                                    uint8_t id_1816 { 7 };
                                    uint32_t id_1817 { uint32_t(id_1815 << id_1816) };
                                    bool id_1818 { bool(id_1813 >= id_1817) };
                                    while_flag_1811 = id_1818;
                                    if (while_flag_1811) {
                                      uint8_t id_1819 { 0 };
                                      uint8_t id_1820 { 0 };
                                      uint32_t id_1821 { lebsz_ref_797[id_1820] };
                                      uint32_t id_1822 { 1U };
                                      uint32_t id_1823 { uint32_t(id_1821 + id_1822) };
                                      Void id_1824 { ((void)(lebsz_ref_797[id_1819] = id_1823), VOID) };
                                      (void)id_1824;
                                    }
                                  } while (while_flag_1811);
                                  (void)VOID;
                                  uint8_t id_1825 { 0 };
                                  uint32_t id_1826 { lebsz_ref_797[id_1825] };
                                  Size id_1827 { Size(id_1826) };
                                  let_res_1810 = id_1827;
                                }
                                let_res_1807 = let_res_1810;
                              }
                              Size id_1828 { Size(wlen_795) };
                              Size id_1829 { Size(let_res_1807 + id_1828) };
                              let_res_1805 = id_1829;
                            }
                            Size id_1830 { Size(id_1795 + let_res_1805) };
                            choose_res_1793 = id_1830;
                          } else {
                            uint16_t id_1831 { 2 };
                            bool id_1832 { bool(label2_794 == id_1831) };
                            Void id_1833 { ((void)(assert(id_1832)), VOID) };
                            (void)id_1833;
                            Size id_1834 { 2UL };
                            Size id_1835 { Size(sz_793 + id_1834) };
                            choose_res_1793 = id_1835;
                          }
                          choose_res_1788 = choose_res_1793;
                        }
                        let_res_1785 = choose_res_1788;
                      }
                      let_res_1776 = let_res_1785;
                    }
                    Size let_res_1836;
                    {
                      Size sz_798 { let_res_1776 };
                      uint8_t id_1837 { 0 };
                      int32_t id_1838 { repeat_n_791[id_1837] };
                      ta2fe18cae70948742cabb6081fd22a0c id_1839 { std::get<0>(*p_0) };
                      Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_1840 { id_1839.from };
                      t7c6bbe37b66fb3a66c00c4bd1bfc4369 id_1841 { id_1840[id_1838] };
                      t9b471a57e45588f3795bf9ca91c31ff6 id_1842 { std::get<0>(id_1841) };
                      std::optional<std::string> id_1843 { std::get<1>(id_1842) };
                      bool id_1844 { !(id_1843.has_value ()) };
                      Size choose_res_1845;
                      if (id_1844) {
                        Size id_1846 { 1UL };
                        Size id_1847 { Size(sz_798 + id_1846) };
                        choose_res_1845 = id_1847;
                      } else {
                        uint8_t id_1848 { 0 };
                        int32_t id_1849 { repeat_n_791[id_1848] };
                        ta2fe18cae70948742cabb6081fd22a0c id_1850 { std::get<0>(*p_0) };
                        Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_1851 { id_1850.from };
                        t7c6bbe37b66fb3a66c00c4bd1bfc4369 id_1852 { id_1851[id_1849] };
                        t9b471a57e45588f3795bf9ca91c31ff6 id_1853 { std::get<0>(id_1852) };
                        std::optional<std::string> id_1854 { std::get<1>(id_1853) };
                        std::string id_1855 { id_1854.value() };
                        uint32_t id_1856 { (uint32_t)id_1855.size() };
                        Size let_res_1857;
                        {
                          uint32_t wlen_799 { id_1856 };
                          Vec<1, uint32_t> id_1858 {  wlen_799  };
                          Size let_res_1859;
                          {
                            Vec<1, uint32_t> n_ref_800 { id_1858 };
                            uint32_t id_1860 { 1U };
                            Vec<1, uint32_t> id_1861 {  id_1860  };
                            Size let_res_1862;
                            {
                              Vec<1, uint32_t> lebsz_ref_801 { id_1861 };
                              bool while_flag_1863 { true };
                              do {
                                uint8_t id_1864 { 0 };
                                uint32_t id_1865 { n_ref_800[id_1864] };
                                uint8_t id_1866 { 0 };
                                uint32_t id_1867 { lebsz_ref_801[id_1866] };
                                uint8_t id_1868 { 7 };
                                uint32_t id_1869 { uint32_t(id_1867 << id_1868) };
                                bool id_1870 { bool(id_1865 >= id_1869) };
                                while_flag_1863 = id_1870;
                                if (while_flag_1863) {
                                  uint8_t id_1871 { 0 };
                                  uint8_t id_1872 { 0 };
                                  uint32_t id_1873 { lebsz_ref_801[id_1872] };
                                  uint32_t id_1874 { 1U };
                                  uint32_t id_1875 { uint32_t(id_1873 + id_1874) };
                                  Void id_1876 { ((void)(lebsz_ref_801[id_1871] = id_1875), VOID) };
                                  (void)id_1876;
                                }
                              } while (while_flag_1863);
                              (void)VOID;
                              uint8_t id_1877 { 0 };
                              uint32_t id_1878 { lebsz_ref_801[id_1877] };
                              Size id_1879 { Size(id_1878) };
                              let_res_1862 = id_1879;
                            }
                            let_res_1859 = let_res_1862;
                          }
                          Size id_1880 { Size(wlen_799) };
                          Size id_1881 { Size(let_res_1859 + id_1880) };
                          let_res_1857 = id_1881;
                        }
                        Size id_1882 { Size(sz_798 + let_res_1857) };
                        Size id_1883 { 1UL };
                        Size id_1884 { Size(id_1882 + id_1883) };
                        choose_res_1845 = id_1884;
                      }
                      let_res_1836 = choose_res_1845;
                    }
                    Size let_res_1885;
                    {
                      Size sz_802 { let_res_1836 };
                      auto fun1886 { dessser::gen::function_name::sersize_of_row_binary };
                      uint8_t id_1887 { 0 };
                      int32_t id_1888 { repeat_n_791[id_1887] };
                      ta2fe18cae70948742cabb6081fd22a0c id_1889 { std::get<0>(*p_0) };
                      Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_1890 { id_1889.from };
                      t7c6bbe37b66fb3a66c00c4bd1bfc4369 id_1891 { id_1890[id_1888] };
                      t9b471a57e45588f3795bf9ca91c31ff6 id_1892 { std::get<0>(id_1891) };
                      dessser::gen::function_name::t_ext id_1893 { std::get<2>(id_1892) };
                      Size id_1894 { fun1886(id_1893) };
                      Size id_1895 { Size(sz_802 + id_1894) };
                      let_res_1885 = id_1895;
                    }
                    choose_res_1771 = let_res_1885;
                  } else {
                    uint16_t id_1896 { 1 };
                    bool id_1897 { bool(label2_792 == id_1896) };
                    Void id_1898 { ((void)(assert(id_1897)), VOID) };
                    (void)id_1898;
                    uint8_t id_1899 { 0 };
                    Size id_1900 { sz_ref_790[id_1899] };
                    Size id_1901 { 2UL };
                    Size id_1902 { Size(id_1900 + id_1901) };
                    uint8_t id_1903 { 0 };
                    int32_t id_1904 { repeat_n_791[id_1903] };
                    ta2fe18cae70948742cabb6081fd22a0c id_1905 { std::get<0>(*p_0) };
                    Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_1906 { id_1905.from };
                    t7c6bbe37b66fb3a66c00c4bd1bfc4369 id_1907 { id_1906[id_1904] };
                    t* id_1908 { std::get<1>(id_1907) };
                    Size id_1909 { fun1339(id_1908) };
                    Size id_1910 { Size(id_1902 + id_1909) };
                    choose_res_1771 = id_1910;
                  }
                  let_res_1768 = choose_res_1771;
                }
                Void id_1911 { ((void)(sz_ref_790[id_1761] = let_res_1768), VOID) };
                (void)id_1911;
                uint8_t id_1912 { 0 };
                uint8_t id_1913 { 0 };
                int32_t id_1914 { repeat_n_791[id_1913] };
                int32_t id_1915 { 1L };
                int32_t id_1916 { int32_t(id_1914 + id_1915) };
                Void id_1917 { ((void)(repeat_n_791[id_1912] = id_1916), VOID) };
                (void)id_1917;
                (void)id_1917;
              }
            } while (while_flag_1753);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_1918 { 0 };
          Size id_1919 { sz_ref_790[id_1918] };
          let_res_1750 = id_1919;
        }
        let_res_1722 = let_res_1750;
      }
      Size let_res_1920;
      {
        Size sz_803 { let_res_1722 };
        ta2fe18cae70948742cabb6081fd22a0c id_1921 { std::get<0>(*p_0) };
        std::optional<dessser::gen::raql_expr::t_ext> id_1922 { id_1921.every };
        bool id_1923 { !(id_1922.has_value ()) };
        Size choose_res_1924;
        if (id_1923) {
          Size id_1925 { 1UL };
          Size id_1926 { Size(sz_803 + id_1925) };
          choose_res_1924 = id_1926;
        } else {
          auto fun1927 { dessser::gen::raql_expr::sersize_of_row_binary };
          ta2fe18cae70948742cabb6081fd22a0c id_1928 { std::get<0>(*p_0) };
          std::optional<dessser::gen::raql_expr::t_ext> id_1929 { id_1928.every };
          dessser::gen::raql_expr::t_ext id_1930 { id_1929.value() };
          Size id_1931 { fun1927(id_1930) };
          Size id_1932 { Size(sz_803 + id_1931) };
          Size id_1933 { 1UL };
          Size id_1934 { Size(id_1932 + id_1933) };
          choose_res_1924 = id_1934;
        }
        let_res_1920 = choose_res_1924;
      }
      Size let_res_1935;
      {
        Size sz_804 { let_res_1920 };
        ta2fe18cae70948742cabb6081fd22a0c id_1936 { std::get<0>(*p_0) };
        Lst<dessser::gen::field_name::t_ext> id_1937 { id_1936.factors };
        uint32_t id_1938 { id_1937.size() };
        Vec<1, uint32_t> id_1939 {  id_1938  };
        Size let_res_1940;
        {
          Vec<1, uint32_t> n_ref_805 { id_1939 };
          uint32_t id_1941 { 1U };
          Vec<1, uint32_t> id_1942 {  id_1941  };
          Size let_res_1943;
          {
            Vec<1, uint32_t> lebsz_ref_806 { id_1942 };
            bool while_flag_1944 { true };
            do {
              uint8_t id_1945 { 0 };
              uint32_t id_1946 { n_ref_805[id_1945] };
              uint8_t id_1947 { 0 };
              uint32_t id_1948 { lebsz_ref_806[id_1947] };
              uint8_t id_1949 { 7 };
              uint32_t id_1950 { uint32_t(id_1948 << id_1949) };
              bool id_1951 { bool(id_1946 >= id_1950) };
              while_flag_1944 = id_1951;
              if (while_flag_1944) {
                uint8_t id_1952 { 0 };
                uint8_t id_1953 { 0 };
                uint32_t id_1954 { lebsz_ref_806[id_1953] };
                uint32_t id_1955 { 1U };
                uint32_t id_1956 { uint32_t(id_1954 + id_1955) };
                Void id_1957 { ((void)(lebsz_ref_806[id_1952] = id_1956), VOID) };
                (void)id_1957;
              }
            } while (while_flag_1944);
            (void)VOID;
            uint8_t id_1958 { 0 };
            uint32_t id_1959 { lebsz_ref_806[id_1958] };
            Size id_1960 { Size(id_1959) };
            let_res_1943 = id_1960;
          }
          let_res_1940 = let_res_1943;
        }
        Size id_1961 { Size(sz_804 + let_res_1940) };
        Vec<1, Size> id_1962 {  id_1961  };
        Size let_res_1963;
        {
          Vec<1, Size> sz_ref_807 { id_1962 };
          int32_t id_1964 { 0L };
          Vec<1, int32_t> id_1965 {  id_1964  };
          {
            Vec<1, int32_t> repeat_n_808 { id_1965 };
            bool while_flag_1966 { true };
            do {
              ta2fe18cae70948742cabb6081fd22a0c id_1967 { std::get<0>(*p_0) };
              Lst<dessser::gen::field_name::t_ext> id_1968 { id_1967.factors };
              uint32_t id_1969 { id_1968.size() };
              int32_t id_1970 { int32_t(id_1969) };
              uint8_t id_1971 { 0 };
              int32_t id_1972 { repeat_n_808[id_1971] };
              bool id_1973 { bool(id_1970 > id_1972) };
              while_flag_1966 = id_1973;
              if (while_flag_1966) {
                uint8_t id_1974 { 0 };
                uint8_t id_1975 { 0 };
                Size id_1976 { sz_ref_807[id_1975] };
                auto fun1977 { dessser::gen::field_name::sersize_of_row_binary };
                uint8_t id_1978 { 0 };
                int32_t id_1979 { repeat_n_808[id_1978] };
                ta2fe18cae70948742cabb6081fd22a0c id_1980 { std::get<0>(*p_0) };
                Lst<dessser::gen::field_name::t_ext> id_1981 { id_1980.factors };
                dessser::gen::field_name::t_ext id_1982 { id_1981[id_1979] };
                Size id_1983 { fun1977(id_1982) };
                Size id_1984 { Size(id_1976 + id_1983) };
                Void id_1985 { ((void)(sz_ref_807[id_1974] = id_1984), VOID) };
                (void)id_1985;
                uint8_t id_1986 { 0 };
                uint8_t id_1987 { 0 };
                int32_t id_1988 { repeat_n_808[id_1987] };
                int32_t id_1989 { 1L };
                int32_t id_1990 { int32_t(id_1988 + id_1989) };
                Void id_1991 { ((void)(repeat_n_808[id_1986] = id_1990), VOID) };
                (void)id_1991;
                (void)id_1991;
              }
            } while (while_flag_1966);
            (void)VOID;
          }
          (void)VOID;
          uint8_t id_1992 { 0 };
          Size id_1993 { sz_ref_807[id_1992] };
          let_res_1963 = id_1993;
        }
        let_res_1935 = let_res_1963;
      }
      choose_res_1343 = let_res_1935;
    } else {
      uint16_t id_1994 { 1 };
      uint16_t id_1995 { uint16_t(p_0->index()) };
      bool id_1996 { bool(id_1994 == id_1995) };
      Size choose_res_1997;
      if (id_1996) {
        uint16_t id_1998 { 0 };
        t1d5c57287ee550c3ccac78b88bba5862 id_1999 { std::get<1>(*p_0) };
        tf708b6568b9bac184e3f5da3a64f4419 id_2000 { id_1999.source };
        uint16_t id_2001 { uint16_t(id_2000.index()) };
        bool id_2002 { bool(id_1998 == id_2001) };
        Size choose_res_2003;
        if (id_2002) {
          Size id_2004 { 4UL };
          auto fun2005 { dessser::gen::raql_expr::sersize_of_row_binary };
          t1d5c57287ee550c3ccac78b88bba5862 id_2006 { std::get<1>(*p_0) };
          tf708b6568b9bac184e3f5da3a64f4419 id_2007 { id_2006.source };
          ta828a76692b94aa6a15973ace224bedc id_2008 { std::get<0>(id_2007) };
          dessser::gen::raql_expr::t_ext id_2009 { id_2008.fname };
          Size id_2010 { fun2005(id_2009) };
          Size id_2011 { Size(id_2004 + id_2010) };
          Size let_res_2012;
          {
            Size sz_723 { id_2011 };
            t1d5c57287ee550c3ccac78b88bba5862 id_2013 { std::get<1>(*p_0) };
            tf708b6568b9bac184e3f5da3a64f4419 id_2014 { id_2013.source };
            ta828a76692b94aa6a15973ace224bedc id_2015 { std::get<0>(id_2014) };
            std::optional<dessser::gen::raql_expr::t_ext> id_2016 { id_2015.preprocessor };
            bool id_2017 { !(id_2016.has_value ()) };
            Size choose_res_2018;
            if (id_2017) {
              Size id_2019 { 1UL };
              Size id_2020 { Size(sz_723 + id_2019) };
              choose_res_2018 = id_2020;
            } else {
              auto fun2021 { dessser::gen::raql_expr::sersize_of_row_binary };
              t1d5c57287ee550c3ccac78b88bba5862 id_2022 { std::get<1>(*p_0) };
              tf708b6568b9bac184e3f5da3a64f4419 id_2023 { id_2022.source };
              ta828a76692b94aa6a15973ace224bedc id_2024 { std::get<0>(id_2023) };
              std::optional<dessser::gen::raql_expr::t_ext> id_2025 { id_2024.preprocessor };
              dessser::gen::raql_expr::t_ext id_2026 { id_2025.value() };
              Size id_2027 { fun2021(id_2026) };
              Size id_2028 { Size(sz_723 + id_2027) };
              Size id_2029 { 1UL };
              Size id_2030 { Size(id_2028 + id_2029) };
              choose_res_2018 = id_2030;
            }
            let_res_2012 = choose_res_2018;
          }
          Size let_res_2031;
          {
            Size sz_724 { let_res_2012 };
            auto fun2032 { dessser::gen::raql_expr::sersize_of_row_binary };
            t1d5c57287ee550c3ccac78b88bba5862 id_2033 { std::get<1>(*p_0) };
            tf708b6568b9bac184e3f5da3a64f4419 id_2034 { id_2033.source };
            ta828a76692b94aa6a15973ace224bedc id_2035 { std::get<0>(id_2034) };
            dessser::gen::raql_expr::t_ext id_2036 { id_2035.unlink };
            Size id_2037 { fun2032(id_2036) };
            Size id_2038 { Size(sz_724 + id_2037) };
            let_res_2031 = id_2038;
          }
          choose_res_2003 = let_res_2031;
        } else {
          t1d5c57287ee550c3ccac78b88bba5862 id_2039 { std::get<1>(*p_0) };
          tf708b6568b9bac184e3f5da3a64f4419 id_2040 { id_2039.source };
          uint16_t id_2041 { uint16_t(id_2040.index()) };
          uint16_t id_2042 { 1 };
          bool id_2043 { bool(id_2041 == id_2042) };
          Void id_2044 { ((void)(assert(id_2043)), VOID) };
          (void)id_2044;
          Size id_2045 { 4UL };
          t1d5c57287ee550c3ccac78b88bba5862 id_2046 { std::get<1>(*p_0) };
          tf708b6568b9bac184e3f5da3a64f4419 id_2047 { id_2046.source };
          te6ac276a1b6044b9474a56a7da93a611 id_2048 { std::get<1>(id_2047) };
          Lst<tcd17c85cefeae7a860c0732c05eaeaed> id_2049 { id_2048.options };
          uint32_t id_2050 { id_2049.size() };
          Vec<1, uint32_t> id_2051 {  id_2050  };
          Size let_res_2052;
          {
            Vec<1, uint32_t> n_ref_707 { id_2051 };
            uint32_t id_2053 { 1U };
            Vec<1, uint32_t> id_2054 {  id_2053  };
            Size let_res_2055;
            {
              Vec<1, uint32_t> lebsz_ref_708 { id_2054 };
              bool while_flag_2056 { true };
              do {
                uint8_t id_2057 { 0 };
                uint32_t id_2058 { n_ref_707[id_2057] };
                uint8_t id_2059 { 0 };
                uint32_t id_2060 { lebsz_ref_708[id_2059] };
                uint8_t id_2061 { 7 };
                uint32_t id_2062 { uint32_t(id_2060 << id_2061) };
                bool id_2063 { bool(id_2058 >= id_2062) };
                while_flag_2056 = id_2063;
                if (while_flag_2056) {
                  uint8_t id_2064 { 0 };
                  uint8_t id_2065 { 0 };
                  uint32_t id_2066 { lebsz_ref_708[id_2065] };
                  uint32_t id_2067 { 1U };
                  uint32_t id_2068 { uint32_t(id_2066 + id_2067) };
                  Void id_2069 { ((void)(lebsz_ref_708[id_2064] = id_2068), VOID) };
                  (void)id_2069;
                }
              } while (while_flag_2056);
              (void)VOID;
              uint8_t id_2070 { 0 };
              uint32_t id_2071 { lebsz_ref_708[id_2070] };
              Size id_2072 { Size(id_2071) };
              let_res_2055 = id_2072;
            }
            let_res_2052 = let_res_2055;
          }
          Size id_2073 { Size(id_2045 + let_res_2052) };
          Vec<1, Size> id_2074 {  id_2073  };
          Size let_res_2075;
          {
            Vec<1, Size> sz_ref_709 { id_2074 };
            int32_t id_2076 { 0L };
            Vec<1, int32_t> id_2077 {  id_2076  };
            {
              Vec<1, int32_t> repeat_n_710 { id_2077 };
              bool while_flag_2078 { true };
              do {
                t1d5c57287ee550c3ccac78b88bba5862 id_2079 { std::get<1>(*p_0) };
                tf708b6568b9bac184e3f5da3a64f4419 id_2080 { id_2079.source };
                te6ac276a1b6044b9474a56a7da93a611 id_2081 { std::get<1>(id_2080) };
                Lst<tcd17c85cefeae7a860c0732c05eaeaed> id_2082 { id_2081.options };
                uint32_t id_2083 { id_2082.size() };
                int32_t id_2084 { int32_t(id_2083) };
                uint8_t id_2085 { 0 };
                int32_t id_2086 { repeat_n_710[id_2085] };
                bool id_2087 { bool(id_2084 > id_2086) };
                while_flag_2078 = id_2087;
                if (while_flag_2078) {
                  uint8_t id_2088 { 0 };
                  uint8_t id_2089 { 0 };
                  Size id_2090 { sz_ref_709[id_2089] };
                  Size let_res_2091;
                  {
                    Size sz_711 { id_2090 };
                    uint8_t id_2092 { 0 };
                    int32_t id_2093 { repeat_n_710[id_2092] };
                    t1d5c57287ee550c3ccac78b88bba5862 id_2094 { std::get<1>(*p_0) };
                    tf708b6568b9bac184e3f5da3a64f4419 id_2095 { id_2094.source };
                    te6ac276a1b6044b9474a56a7da93a611 id_2096 { std::get<1>(id_2095) };
                    Lst<tcd17c85cefeae7a860c0732c05eaeaed> id_2097 { id_2096.options };
                    tcd17c85cefeae7a860c0732c05eaeaed id_2098 { id_2097[id_2093] };
                    std::string id_2099 { std::get<0>(id_2098) };
                    uint32_t id_2100 { (uint32_t)id_2099.size() };
                    Size let_res_2101;
                    {
                      uint32_t wlen_712 { id_2100 };
                      Vec<1, uint32_t> id_2102 {  wlen_712  };
                      Size let_res_2103;
                      {
                        Vec<1, uint32_t> n_ref_713 { id_2102 };
                        uint32_t id_2104 { 1U };
                        Vec<1, uint32_t> id_2105 {  id_2104  };
                        Size let_res_2106;
                        {
                          Vec<1, uint32_t> lebsz_ref_714 { id_2105 };
                          bool while_flag_2107 { true };
                          do {
                            uint8_t id_2108 { 0 };
                            uint32_t id_2109 { n_ref_713[id_2108] };
                            uint8_t id_2110 { 0 };
                            uint32_t id_2111 { lebsz_ref_714[id_2110] };
                            uint8_t id_2112 { 7 };
                            uint32_t id_2113 { uint32_t(id_2111 << id_2112) };
                            bool id_2114 { bool(id_2109 >= id_2113) };
                            while_flag_2107 = id_2114;
                            if (while_flag_2107) {
                              uint8_t id_2115 { 0 };
                              uint8_t id_2116 { 0 };
                              uint32_t id_2117 { lebsz_ref_714[id_2116] };
                              uint32_t id_2118 { 1U };
                              uint32_t id_2119 { uint32_t(id_2117 + id_2118) };
                              Void id_2120 { ((void)(lebsz_ref_714[id_2115] = id_2119), VOID) };
                              (void)id_2120;
                            }
                          } while (while_flag_2107);
                          (void)VOID;
                          uint8_t id_2121 { 0 };
                          uint32_t id_2122 { lebsz_ref_714[id_2121] };
                          Size id_2123 { Size(id_2122) };
                          let_res_2106 = id_2123;
                        }
                        let_res_2103 = let_res_2106;
                      }
                      Size id_2124 { Size(wlen_712) };
                      Size id_2125 { Size(let_res_2103 + id_2124) };
                      let_res_2101 = id_2125;
                    }
                    Size id_2126 { Size(sz_711 + let_res_2101) };
                    let_res_2091 = id_2126;
                  }
                  Size let_res_2127;
                  {
                    Size sz_715 { let_res_2091 };
                    auto fun2128 { dessser::gen::raql_expr::sersize_of_row_binary };
                    uint8_t id_2129 { 0 };
                    int32_t id_2130 { repeat_n_710[id_2129] };
                    t1d5c57287ee550c3ccac78b88bba5862 id_2131 { std::get<1>(*p_0) };
                    tf708b6568b9bac184e3f5da3a64f4419 id_2132 { id_2131.source };
                    te6ac276a1b6044b9474a56a7da93a611 id_2133 { std::get<1>(id_2132) };
                    Lst<tcd17c85cefeae7a860c0732c05eaeaed> id_2134 { id_2133.options };
                    tcd17c85cefeae7a860c0732c05eaeaed id_2135 { id_2134[id_2130] };
                    dessser::gen::raql_expr::t_ext id_2136 { std::get<1>(id_2135) };
                    Size id_2137 { fun2128(id_2136) };
                    Size id_2138 { Size(sz_715 + id_2137) };
                    let_res_2127 = id_2138;
                  }
                  Void id_2139 { ((void)(sz_ref_709[id_2088] = let_res_2127), VOID) };
                  (void)id_2139;
                  uint8_t id_2140 { 0 };
                  uint8_t id_2141 { 0 };
                  int32_t id_2142 { repeat_n_710[id_2141] };
                  int32_t id_2143 { 1L };
                  int32_t id_2144 { int32_t(id_2142 + id_2143) };
                  Void id_2145 { ((void)(repeat_n_710[id_2140] = id_2144), VOID) };
                  (void)id_2145;
                  (void)id_2145;
                }
              } while (while_flag_2078);
              (void)VOID;
            }
            (void)VOID;
            uint8_t id_2146 { 0 };
            Size id_2147 { sz_ref_709[id_2146] };
            let_res_2075 = id_2147;
          }
          Size let_res_2148;
          {
            Size sz_716 { let_res_2075 };
            auto fun2149 { dessser::gen::raql_expr::sersize_of_row_binary };
            t1d5c57287ee550c3ccac78b88bba5862 id_2150 { std::get<1>(*p_0) };
            tf708b6568b9bac184e3f5da3a64f4419 id_2151 { id_2150.source };
            te6ac276a1b6044b9474a56a7da93a611 id_2152 { std::get<1>(id_2151) };
            dessser::gen::raql_expr::t_ext id_2153 { id_2152.topic };
            Size id_2154 { fun2149(id_2153) };
            Size id_2155 { Size(sz_716 + id_2154) };
            let_res_2148 = id_2155;
          }
          Size let_res_2156;
          {
            Size sz_717 { let_res_2148 };
            t1d5c57287ee550c3ccac78b88bba5862 id_2157 { std::get<1>(*p_0) };
            tf708b6568b9bac184e3f5da3a64f4419 id_2158 { id_2157.source };
            te6ac276a1b6044b9474a56a7da93a611 id_2159 { std::get<1>(id_2158) };
            std::optional<dessser::gen::raql_expr::t_ext> id_2160 { id_2159.partitions };
            bool id_2161 { !(id_2160.has_value ()) };
            Size choose_res_2162;
            if (id_2161) {
              Size id_2163 { 1UL };
              Size id_2164 { Size(sz_717 + id_2163) };
              choose_res_2162 = id_2164;
            } else {
              auto fun2165 { dessser::gen::raql_expr::sersize_of_row_binary };
              t1d5c57287ee550c3ccac78b88bba5862 id_2166 { std::get<1>(*p_0) };
              tf708b6568b9bac184e3f5da3a64f4419 id_2167 { id_2166.source };
              te6ac276a1b6044b9474a56a7da93a611 id_2168 { std::get<1>(id_2167) };
              std::optional<dessser::gen::raql_expr::t_ext> id_2169 { id_2168.partitions };
              dessser::gen::raql_expr::t_ext id_2170 { id_2169.value() };
              Size id_2171 { fun2165(id_2170) };
              Size id_2172 { Size(sz_717 + id_2171) };
              Size id_2173 { 1UL };
              Size id_2174 { Size(id_2172 + id_2173) };
              choose_res_2162 = id_2174;
            }
            let_res_2156 = choose_res_2162;
          }
          Size let_res_2175;
          {
            Size sz_718 { let_res_2156 };
            t1d5c57287ee550c3ccac78b88bba5862 id_2176 { std::get<1>(*p_0) };
            tf708b6568b9bac184e3f5da3a64f4419 id_2177 { id_2176.source };
            te6ac276a1b6044b9474a56a7da93a611 id_2178 { std::get<1>(id_2177) };
            t6f8c1c936ce8cf2fe9dc881177aa3e62 id_2179 { id_2178.restart_from };
            uint16_t id_2180 { uint16_t(id_2179.index()) };
            Size let_res_2181;
            {
              uint16_t label2_719 { id_2180 };
              uint16_t id_2182 { 0 };
              bool id_2183 { bool(id_2182 == label2_719) };
              Size choose_res_2184;
              if (id_2183) {
                Size id_2185 { 2UL };
                Size id_2186 { Size(sz_718 + id_2185) };
                choose_res_2184 = id_2186;
              } else {
                uint16_t id_2187 { 1 };
                bool id_2188 { bool(id_2187 == label2_719) };
                Size choose_res_2189;
                if (id_2188) {
                  Size id_2190 { 2UL };
                  Size id_2191 { Size(sz_718 + id_2190) };
                  auto fun2192 { dessser::gen::raql_expr::sersize_of_row_binary };
                  t1d5c57287ee550c3ccac78b88bba5862 id_2193 { std::get<1>(*p_0) };
                  tf708b6568b9bac184e3f5da3a64f4419 id_2194 { id_2193.source };
                  te6ac276a1b6044b9474a56a7da93a611 id_2195 { std::get<1>(id_2194) };
                  t6f8c1c936ce8cf2fe9dc881177aa3e62 id_2196 { id_2195.restart_from };
                  dessser::gen::raql_expr::t_ext id_2197 { std::get<1>(id_2196) };
                  Size id_2198 { fun2192(id_2197) };
                  Size id_2199 { Size(id_2191 + id_2198) };
                  choose_res_2189 = id_2199;
                } else {
                  uint16_t id_2200 { 2 };
                  bool id_2201 { bool(id_2200 == label2_719) };
                  Size choose_res_2202;
                  if (id_2201) {
                    Size id_2203 { 2UL };
                    Size id_2204 { Size(sz_718 + id_2203) };
                    choose_res_2202 = id_2204;
                  } else {
                    uint16_t id_2205 { 3 };
                    bool id_2206 { bool(label2_719 == id_2205) };
                    Void id_2207 { ((void)(assert(id_2206)), VOID) };
                    (void)id_2207;
                    Size id_2208 { 2UL };
                    Size id_2209 { Size(sz_718 + id_2208) };
                    auto fun2210 { dessser::gen::raql_expr::sersize_of_row_binary };
                    t1d5c57287ee550c3ccac78b88bba5862 id_2211 { std::get<1>(*p_0) };
                    tf708b6568b9bac184e3f5da3a64f4419 id_2212 { id_2211.source };
                    te6ac276a1b6044b9474a56a7da93a611 id_2213 { std::get<1>(id_2212) };
                    t6f8c1c936ce8cf2fe9dc881177aa3e62 id_2214 { id_2213.restart_from };
                    tee7dccc2726e2723462077a878a69c99 id_2215 { std::get<3>(id_2214) };
                    dessser::gen::raql_expr::t_ext id_2216 { id_2215.after_max_secs };
                    Size id_2217 { fun2210(id_2216) };
                    Size id_2218 { Size(id_2209 + id_2217) };
                    Size let_res_2219;
                    {
                      Size sz_721 { id_2218 };
                      auto fun2220 { dessser::gen::raql_expr::sersize_of_row_binary };
                      t1d5c57287ee550c3ccac78b88bba5862 id_2221 { std::get<1>(*p_0) };
                      tf708b6568b9bac184e3f5da3a64f4419 id_2222 { id_2221.source };
                      te6ac276a1b6044b9474a56a7da93a611 id_2223 { std::get<1>(id_2222) };
                      t6f8c1c936ce8cf2fe9dc881177aa3e62 id_2224 { id_2223.restart_from };
                      tee7dccc2726e2723462077a878a69c99 id_2225 { std::get<3>(id_2224) };
                      dessser::gen::raql_expr::t_ext id_2226 { id_2225.after_max_events };
                      Size id_2227 { fun2220(id_2226) };
                      Size id_2228 { Size(sz_721 + id_2227) };
                      let_res_2219 = id_2228;
                    }
                    choose_res_2202 = let_res_2219;
                  }
                  choose_res_2189 = choose_res_2202;
                }
                choose_res_2184 = choose_res_2189;
              }
              let_res_2181 = choose_res_2184;
            }
            let_res_2175 = let_res_2181;
          }
          choose_res_2003 = let_res_2175;
        }
        Size let_res_2229;
        {
          Size sz_725 { choose_res_2003 };
          uint16_t id_2230 { 0 };
          t1d5c57287ee550c3ccac78b88bba5862 id_2231 { std::get<1>(*p_0) };
          t570dd118e4f520aece0574b2f62e7634 id_2232 { id_2231.format };
          uint16_t id_2233 { uint16_t(id_2232.index()) };
          bool id_2234 { bool(id_2230 == id_2233) };
          Size choose_res_2235;
          if (id_2234) {
            Size id_2236 { 2UL };
            Size id_2237 { Size(sz_725 + id_2236) };
            Size id_2238 { 1UL };
            Size id_2239 { Size(id_2237 + id_2238) };
            t1d5c57287ee550c3ccac78b88bba5862 id_2240 { std::get<1>(*p_0) };
            t570dd118e4f520aece0574b2f62e7634 id_2241 { id_2240.format };
            tc1ee34cdd9bdb8371d318bb284a788a8 id_2242 { std::get<0>(id_2241) };
            std::string id_2243 { id_2242.null };
            uint32_t id_2244 { (uint32_t)id_2243.size() };
            Vec<1, uint32_t> id_2245 {  id_2244  };
            Size let_res_2246;
            {
              Vec<1, uint32_t> n_ref_734 { id_2245 };
              uint32_t id_2247 { 1U };
              Vec<1, uint32_t> id_2248 {  id_2247  };
              Size let_res_2249;
              {
                Vec<1, uint32_t> lebsz_ref_735 { id_2248 };
                bool while_flag_2250 { true };
                do {
                  uint8_t id_2251 { 0 };
                  uint32_t id_2252 { n_ref_734[id_2251] };
                  uint8_t id_2253 { 0 };
                  uint32_t id_2254 { lebsz_ref_735[id_2253] };
                  uint8_t id_2255 { 7 };
                  uint32_t id_2256 { uint32_t(id_2254 << id_2255) };
                  bool id_2257 { bool(id_2252 >= id_2256) };
                  while_flag_2250 = id_2257;
                  if (while_flag_2250) {
                    uint8_t id_2258 { 0 };
                    uint8_t id_2259 { 0 };
                    uint32_t id_2260 { lebsz_ref_735[id_2259] };
                    uint32_t id_2261 { 1U };
                    uint32_t id_2262 { uint32_t(id_2260 + id_2261) };
                    Void id_2263 { ((void)(lebsz_ref_735[id_2258] = id_2262), VOID) };
                    (void)id_2263;
                  }
                } while (while_flag_2250);
                (void)VOID;
                uint8_t id_2264 { 0 };
                uint32_t id_2265 { lebsz_ref_735[id_2264] };
                Size id_2266 { Size(id_2265) };
                let_res_2249 = id_2266;
              }
              let_res_2246 = let_res_2249;
            }
            t1d5c57287ee550c3ccac78b88bba5862 id_2267 { std::get<1>(*p_0) };
            t570dd118e4f520aece0574b2f62e7634 id_2268 { id_2267.format };
            tc1ee34cdd9bdb8371d318bb284a788a8 id_2269 { std::get<0>(id_2268) };
            std::string id_2270 { id_2269.null };
            uint32_t id_2271 { (uint32_t)id_2270.size() };
            Size id_2272 { Size(id_2271) };
            Size id_2273 { Size(let_res_2246 + id_2272) };
            Size id_2274 { Size(id_2239 + id_2273) };
            Size id_2275 { 1UL };
            Size id_2276 { Size(id_2274 + id_2275) };
            Size let_res_2277;
            {
              Size sz_737 { id_2276 };
              t1d5c57287ee550c3ccac78b88bba5862 id_2278 { std::get<1>(*p_0) };
              t570dd118e4f520aece0574b2f62e7634 id_2279 { id_2278.format };
              tc1ee34cdd9bdb8371d318bb284a788a8 id_2280 { std::get<0>(id_2279) };
              std::string id_2281 { id_2280.escape_seq };
              uint32_t id_2282 { (uint32_t)id_2281.size() };
              Vec<1, uint32_t> id_2283 {  id_2282  };
              Size let_res_2284;
              {
                Vec<1, uint32_t> n_ref_739 { id_2283 };
                uint32_t id_2285 { 1U };
                Vec<1, uint32_t> id_2286 {  id_2285  };
                Size let_res_2287;
                {
                  Vec<1, uint32_t> lebsz_ref_740 { id_2286 };
                  bool while_flag_2288 { true };
                  do {
                    uint8_t id_2289 { 0 };
                    uint32_t id_2290 { n_ref_739[id_2289] };
                    uint8_t id_2291 { 0 };
                    uint32_t id_2292 { lebsz_ref_740[id_2291] };
                    uint8_t id_2293 { 7 };
                    uint32_t id_2294 { uint32_t(id_2292 << id_2293) };
                    bool id_2295 { bool(id_2290 >= id_2294) };
                    while_flag_2288 = id_2295;
                    if (while_flag_2288) {
                      uint8_t id_2296 { 0 };
                      uint8_t id_2297 { 0 };
                      uint32_t id_2298 { lebsz_ref_740[id_2297] };
                      uint32_t id_2299 { 1U };
                      uint32_t id_2300 { uint32_t(id_2298 + id_2299) };
                      Void id_2301 { ((void)(lebsz_ref_740[id_2296] = id_2300), VOID) };
                      (void)id_2301;
                    }
                  } while (while_flag_2288);
                  (void)VOID;
                  uint8_t id_2302 { 0 };
                  uint32_t id_2303 { lebsz_ref_740[id_2302] };
                  Size id_2304 { Size(id_2303) };
                  let_res_2287 = id_2304;
                }
                let_res_2284 = let_res_2287;
              }
              t1d5c57287ee550c3ccac78b88bba5862 id_2305 { std::get<1>(*p_0) };
              t570dd118e4f520aece0574b2f62e7634 id_2306 { id_2305.format };
              tc1ee34cdd9bdb8371d318bb284a788a8 id_2307 { std::get<0>(id_2306) };
              std::string id_2308 { id_2307.escape_seq };
              uint32_t id_2309 { (uint32_t)id_2308.size() };
              Size id_2310 { Size(id_2309) };
              Size id_2311 { Size(let_res_2284 + id_2310) };
              Size id_2312 { Size(sz_737 + id_2311) };
              let_res_2277 = id_2312;
            }
            Size let_res_2313;
            {
              Size sz_741 { let_res_2277 };
              t1d5c57287ee550c3ccac78b88bba5862 id_2314 { std::get<1>(*p_0) };
              t570dd118e4f520aece0574b2f62e7634 id_2315 { id_2314.format };
              tc1ee34cdd9bdb8371d318bb284a788a8 id_2316 { std::get<0>(id_2315) };
              Lst<dessser::gen::field_type::t_ext> id_2317 { id_2316.fields };
              uint32_t id_2318 { id_2317.size() };
              Vec<1, uint32_t> id_2319 {  id_2318  };
              Size let_res_2320;
              {
                Vec<1, uint32_t> n_ref_742 { id_2319 };
                uint32_t id_2321 { 1U };
                Vec<1, uint32_t> id_2322 {  id_2321  };
                Size let_res_2323;
                {
                  Vec<1, uint32_t> lebsz_ref_743 { id_2322 };
                  bool while_flag_2324 { true };
                  do {
                    uint8_t id_2325 { 0 };
                    uint32_t id_2326 { n_ref_742[id_2325] };
                    uint8_t id_2327 { 0 };
                    uint32_t id_2328 { lebsz_ref_743[id_2327] };
                    uint8_t id_2329 { 7 };
                    uint32_t id_2330 { uint32_t(id_2328 << id_2329) };
                    bool id_2331 { bool(id_2326 >= id_2330) };
                    while_flag_2324 = id_2331;
                    if (while_flag_2324) {
                      uint8_t id_2332 { 0 };
                      uint8_t id_2333 { 0 };
                      uint32_t id_2334 { lebsz_ref_743[id_2333] };
                      uint32_t id_2335 { 1U };
                      uint32_t id_2336 { uint32_t(id_2334 + id_2335) };
                      Void id_2337 { ((void)(lebsz_ref_743[id_2332] = id_2336), VOID) };
                      (void)id_2337;
                    }
                  } while (while_flag_2324);
                  (void)VOID;
                  uint8_t id_2338 { 0 };
                  uint32_t id_2339 { lebsz_ref_743[id_2338] };
                  Size id_2340 { Size(id_2339) };
                  let_res_2323 = id_2340;
                }
                let_res_2320 = let_res_2323;
              }
              Size id_2341 { Size(sz_741 + let_res_2320) };
              Vec<1, Size> id_2342 {  id_2341  };
              Size let_res_2343;
              {
                Vec<1, Size> sz_ref_744 { id_2342 };
                int32_t id_2344 { 0L };
                Vec<1, int32_t> id_2345 {  id_2344  };
                {
                  Vec<1, int32_t> repeat_n_745 { id_2345 };
                  bool while_flag_2346 { true };
                  do {
                    t1d5c57287ee550c3ccac78b88bba5862 id_2347 { std::get<1>(*p_0) };
                    t570dd118e4f520aece0574b2f62e7634 id_2348 { id_2347.format };
                    tc1ee34cdd9bdb8371d318bb284a788a8 id_2349 { std::get<0>(id_2348) };
                    Lst<dessser::gen::field_type::t_ext> id_2350 { id_2349.fields };
                    uint32_t id_2351 { id_2350.size() };
                    int32_t id_2352 { int32_t(id_2351) };
                    uint8_t id_2353 { 0 };
                    int32_t id_2354 { repeat_n_745[id_2353] };
                    bool id_2355 { bool(id_2352 > id_2354) };
                    while_flag_2346 = id_2355;
                    if (while_flag_2346) {
                      uint8_t id_2356 { 0 };
                      uint8_t id_2357 { 0 };
                      Size id_2358 { sz_ref_744[id_2357] };
                      auto fun2359 { dessser::gen::field_type::sersize_of_row_binary };
                      uint8_t id_2360 { 0 };
                      int32_t id_2361 { repeat_n_745[id_2360] };
                      t1d5c57287ee550c3ccac78b88bba5862 id_2362 { std::get<1>(*p_0) };
                      t570dd118e4f520aece0574b2f62e7634 id_2363 { id_2362.format };
                      tc1ee34cdd9bdb8371d318bb284a788a8 id_2364 { std::get<0>(id_2363) };
                      Lst<dessser::gen::field_type::t_ext> id_2365 { id_2364.fields };
                      dessser::gen::field_type::t_ext id_2366 { id_2365[id_2361] };
                      Size id_2367 { fun2359(id_2366) };
                      Size id_2368 { Size(id_2358 + id_2367) };
                      Void id_2369 { ((void)(sz_ref_744[id_2356] = id_2368), VOID) };
                      (void)id_2369;
                      uint8_t id_2370 { 0 };
                      uint8_t id_2371 { 0 };
                      int32_t id_2372 { repeat_n_745[id_2371] };
                      int32_t id_2373 { 1L };
                      int32_t id_2374 { int32_t(id_2372 + id_2373) };
                      Void id_2375 { ((void)(repeat_n_745[id_2370] = id_2374), VOID) };
                      (void)id_2375;
                      (void)id_2375;
                    }
                  } while (while_flag_2346);
                  (void)VOID;
                }
                (void)VOID;
                uint8_t id_2376 { 0 };
                Size id_2377 { sz_ref_744[id_2376] };
                let_res_2343 = id_2377;
              }
              let_res_2313 = let_res_2343;
            }
            Size id_2378 { 1UL };
            Size id_2379 { Size(let_res_2313 + id_2378) };
            Size id_2380 { 1UL };
            Size id_2381 { Size(id_2379 + id_2380) };
            choose_res_2235 = id_2381;
          } else {
            t1d5c57287ee550c3ccac78b88bba5862 id_2382 { std::get<1>(*p_0) };
            t570dd118e4f520aece0574b2f62e7634 id_2383 { id_2382.format };
            uint16_t id_2384 { uint16_t(id_2383.index()) };
            uint16_t id_2385 { 1 };
            bool id_2386 { bool(id_2384 == id_2385) };
            Void id_2387 { ((void)(assert(id_2386)), VOID) };
            (void)id_2387;
            Size id_2388 { 2UL };
            Size id_2389 { Size(sz_725 + id_2388) };
            t1d5c57287ee550c3ccac78b88bba5862 id_2390 { std::get<1>(*p_0) };
            t570dd118e4f520aece0574b2f62e7634 id_2391 { id_2390.format };
            Lst<dessser::gen::field_type::t_ext> id_2392 { std::get<1>(id_2391) };
            uint32_t id_2393 { id_2392.size() };
            Vec<1, uint32_t> id_2394 {  id_2393  };
            Size let_res_2395;
            {
              Vec<1, uint32_t> n_ref_727 { id_2394 };
              uint32_t id_2396 { 1U };
              Vec<1, uint32_t> id_2397 {  id_2396  };
              Size let_res_2398;
              {
                Vec<1, uint32_t> lebsz_ref_728 { id_2397 };
                bool while_flag_2399 { true };
                do {
                  uint8_t id_2400 { 0 };
                  uint32_t id_2401 { n_ref_727[id_2400] };
                  uint8_t id_2402 { 0 };
                  uint32_t id_2403 { lebsz_ref_728[id_2402] };
                  uint8_t id_2404 { 7 };
                  uint32_t id_2405 { uint32_t(id_2403 << id_2404) };
                  bool id_2406 { bool(id_2401 >= id_2405) };
                  while_flag_2399 = id_2406;
                  if (while_flag_2399) {
                    uint8_t id_2407 { 0 };
                    uint8_t id_2408 { 0 };
                    uint32_t id_2409 { lebsz_ref_728[id_2408] };
                    uint32_t id_2410 { 1U };
                    uint32_t id_2411 { uint32_t(id_2409 + id_2410) };
                    Void id_2412 { ((void)(lebsz_ref_728[id_2407] = id_2411), VOID) };
                    (void)id_2412;
                  }
                } while (while_flag_2399);
                (void)VOID;
                uint8_t id_2413 { 0 };
                uint32_t id_2414 { lebsz_ref_728[id_2413] };
                Size id_2415 { Size(id_2414) };
                let_res_2398 = id_2415;
              }
              let_res_2395 = let_res_2398;
            }
            Size id_2416 { Size(id_2389 + let_res_2395) };
            Vec<1, Size> id_2417 {  id_2416  };
            Size let_res_2418;
            {
              Vec<1, Size> sz_ref_729 { id_2417 };
              int32_t id_2419 { 0L };
              Vec<1, int32_t> id_2420 {  id_2419  };
              {
                Vec<1, int32_t> repeat_n_730 { id_2420 };
                bool while_flag_2421 { true };
                do {
                  t1d5c57287ee550c3ccac78b88bba5862 id_2422 { std::get<1>(*p_0) };
                  t570dd118e4f520aece0574b2f62e7634 id_2423 { id_2422.format };
                  Lst<dessser::gen::field_type::t_ext> id_2424 { std::get<1>(id_2423) };
                  uint32_t id_2425 { id_2424.size() };
                  int32_t id_2426 { int32_t(id_2425) };
                  uint8_t id_2427 { 0 };
                  int32_t id_2428 { repeat_n_730[id_2427] };
                  bool id_2429 { bool(id_2426 > id_2428) };
                  while_flag_2421 = id_2429;
                  if (while_flag_2421) {
                    uint8_t id_2430 { 0 };
                    uint8_t id_2431 { 0 };
                    Size id_2432 { sz_ref_729[id_2431] };
                    auto fun2433 { dessser::gen::field_type::sersize_of_row_binary };
                    uint8_t id_2434 { 0 };
                    int32_t id_2435 { repeat_n_730[id_2434] };
                    t1d5c57287ee550c3ccac78b88bba5862 id_2436 { std::get<1>(*p_0) };
                    t570dd118e4f520aece0574b2f62e7634 id_2437 { id_2436.format };
                    Lst<dessser::gen::field_type::t_ext> id_2438 { std::get<1>(id_2437) };
                    dessser::gen::field_type::t_ext id_2439 { id_2438[id_2435] };
                    Size id_2440 { fun2433(id_2439) };
                    Size id_2441 { Size(id_2432 + id_2440) };
                    Void id_2442 { ((void)(sz_ref_729[id_2430] = id_2441), VOID) };
                    (void)id_2442;
                    uint8_t id_2443 { 0 };
                    uint8_t id_2444 { 0 };
                    int32_t id_2445 { repeat_n_730[id_2444] };
                    int32_t id_2446 { 1L };
                    int32_t id_2447 { int32_t(id_2445 + id_2446) };
                    Void id_2448 { ((void)(repeat_n_730[id_2443] = id_2447), VOID) };
                    (void)id_2448;
                    (void)id_2448;
                  }
                } while (while_flag_2421);
                (void)VOID;
              }
              (void)VOID;
              uint8_t id_2449 { 0 };
              Size id_2450 { sz_ref_729[id_2449] };
              let_res_2418 = id_2450;
            }
            choose_res_2235 = let_res_2418;
          }
          let_res_2229 = choose_res_2235;
        }
        Size let_res_2451;
        {
          Size sz_748 { let_res_2229 };
          t1d5c57287ee550c3ccac78b88bba5862 id_2452 { std::get<1>(*p_0) };
          std::optional<dessser::gen::event_time::t_ext> id_2453 { id_2452.event_time };
          bool id_2454 { !(id_2453.has_value ()) };
          Size choose_res_2455;
          if (id_2454) {
            Size id_2456 { 1UL };
            Size id_2457 { Size(sz_748 + id_2456) };
            choose_res_2455 = id_2457;
          } else {
            auto fun2458 { dessser::gen::event_time::sersize_of_row_binary };
            t1d5c57287ee550c3ccac78b88bba5862 id_2459 { std::get<1>(*p_0) };
            std::optional<dessser::gen::event_time::t_ext> id_2460 { id_2459.event_time };
            dessser::gen::event_time::t_ext id_2461 { id_2460.value() };
            Size id_2462 { fun2458(id_2461) };
            Size id_2463 { Size(sz_748 + id_2462) };
            Size id_2464 { 1UL };
            Size id_2465 { Size(id_2463 + id_2464) };
            choose_res_2455 = id_2465;
          }
          let_res_2451 = choose_res_2455;
        }
        Size let_res_2466;
        {
          Size sz_749 { let_res_2451 };
          t1d5c57287ee550c3ccac78b88bba5862 id_2467 { std::get<1>(*p_0) };
          Lst<dessser::gen::field_name::t_ext> id_2468 { id_2467.factors };
          uint32_t id_2469 { id_2468.size() };
          Vec<1, uint32_t> id_2470 {  id_2469  };
          Size let_res_2471;
          {
            Vec<1, uint32_t> n_ref_750 { id_2470 };
            uint32_t id_2472 { 1U };
            Vec<1, uint32_t> id_2473 {  id_2472  };
            Size let_res_2474;
            {
              Vec<1, uint32_t> lebsz_ref_751 { id_2473 };
              bool while_flag_2475 { true };
              do {
                uint8_t id_2476 { 0 };
                uint32_t id_2477 { n_ref_750[id_2476] };
                uint8_t id_2478 { 0 };
                uint32_t id_2479 { lebsz_ref_751[id_2478] };
                uint8_t id_2480 { 7 };
                uint32_t id_2481 { uint32_t(id_2479 << id_2480) };
                bool id_2482 { bool(id_2477 >= id_2481) };
                while_flag_2475 = id_2482;
                if (while_flag_2475) {
                  uint8_t id_2483 { 0 };
                  uint8_t id_2484 { 0 };
                  uint32_t id_2485 { lebsz_ref_751[id_2484] };
                  uint32_t id_2486 { 1U };
                  uint32_t id_2487 { uint32_t(id_2485 + id_2486) };
                  Void id_2488 { ((void)(lebsz_ref_751[id_2483] = id_2487), VOID) };
                  (void)id_2488;
                }
              } while (while_flag_2475);
              (void)VOID;
              uint8_t id_2489 { 0 };
              uint32_t id_2490 { lebsz_ref_751[id_2489] };
              Size id_2491 { Size(id_2490) };
              let_res_2474 = id_2491;
            }
            let_res_2471 = let_res_2474;
          }
          Size id_2492 { Size(sz_749 + let_res_2471) };
          Vec<1, Size> id_2493 {  id_2492  };
          Size let_res_2494;
          {
            Vec<1, Size> sz_ref_752 { id_2493 };
            int32_t id_2495 { 0L };
            Vec<1, int32_t> id_2496 {  id_2495  };
            {
              Vec<1, int32_t> repeat_n_753 { id_2496 };
              bool while_flag_2497 { true };
              do {
                t1d5c57287ee550c3ccac78b88bba5862 id_2498 { std::get<1>(*p_0) };
                Lst<dessser::gen::field_name::t_ext> id_2499 { id_2498.factors };
                uint32_t id_2500 { id_2499.size() };
                int32_t id_2501 { int32_t(id_2500) };
                uint8_t id_2502 { 0 };
                int32_t id_2503 { repeat_n_753[id_2502] };
                bool id_2504 { bool(id_2501 > id_2503) };
                while_flag_2497 = id_2504;
                if (while_flag_2497) {
                  uint8_t id_2505 { 0 };
                  uint8_t id_2506 { 0 };
                  Size id_2507 { sz_ref_752[id_2506] };
                  auto fun2508 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_2509 { 0 };
                  int32_t id_2510 { repeat_n_753[id_2509] };
                  t1d5c57287ee550c3ccac78b88bba5862 id_2511 { std::get<1>(*p_0) };
                  Lst<dessser::gen::field_name::t_ext> id_2512 { id_2511.factors };
                  dessser::gen::field_name::t_ext id_2513 { id_2512[id_2510] };
                  Size id_2514 { fun2508(id_2513) };
                  Size id_2515 { Size(id_2507 + id_2514) };
                  Void id_2516 { ((void)(sz_ref_752[id_2505] = id_2515), VOID) };
                  (void)id_2516;
                  uint8_t id_2517 { 0 };
                  uint8_t id_2518 { 0 };
                  int32_t id_2519 { repeat_n_753[id_2518] };
                  int32_t id_2520 { 1L };
                  int32_t id_2521 { int32_t(id_2519 + id_2520) };
                  Void id_2522 { ((void)(repeat_n_753[id_2517] = id_2521), VOID) };
                  (void)id_2522;
                  (void)id_2522;
                }
              } while (while_flag_2497);
              (void)VOID;
            }
            (void)VOID;
            uint8_t id_2523 { 0 };
            Size id_2524 { sz_ref_752[id_2523] };
            let_res_2494 = id_2524;
          }
          let_res_2466 = let_res_2494;
        }
        choose_res_1997 = let_res_2466;
      } else {
        uint16_t id_2525 { uint16_t(p_0->index()) };
        uint16_t id_2526 { 2 };
        bool id_2527 { bool(id_2525 == id_2526) };
        Void id_2528 { ((void)(assert(id_2527)), VOID) };
        (void)id_2528;
        Size id_2529 { 2UL };
        t9ddff9e1963b15ba493db1f8dadd34fb id_2530 { std::get<2>(*p_0) };
        std::string id_2531 { id_2530.net_addr };
        uint32_t id_2532 { (uint32_t)id_2531.size() };
        Vec<1, uint32_t> id_2533 {  id_2532  };
        Size let_res_2534;
        {
          Vec<1, uint32_t> n_ref_695 { id_2533 };
          uint32_t id_2535 { 1U };
          Vec<1, uint32_t> id_2536 {  id_2535  };
          Size let_res_2537;
          {
            Vec<1, uint32_t> lebsz_ref_696 { id_2536 };
            bool while_flag_2538 { true };
            do {
              uint8_t id_2539 { 0 };
              uint32_t id_2540 { n_ref_695[id_2539] };
              uint8_t id_2541 { 0 };
              uint32_t id_2542 { lebsz_ref_696[id_2541] };
              uint8_t id_2543 { 7 };
              uint32_t id_2544 { uint32_t(id_2542 << id_2543) };
              bool id_2545 { bool(id_2540 >= id_2544) };
              while_flag_2538 = id_2545;
              if (while_flag_2538) {
                uint8_t id_2546 { 0 };
                uint8_t id_2547 { 0 };
                uint32_t id_2548 { lebsz_ref_696[id_2547] };
                uint32_t id_2549 { 1U };
                uint32_t id_2550 { uint32_t(id_2548 + id_2549) };
                Void id_2551 { ((void)(lebsz_ref_696[id_2546] = id_2550), VOID) };
                (void)id_2551;
              }
            } while (while_flag_2538);
            (void)VOID;
            uint8_t id_2552 { 0 };
            uint32_t id_2553 { lebsz_ref_696[id_2552] };
            Size id_2554 { Size(id_2553) };
            let_res_2537 = id_2554;
          }
          let_res_2534 = let_res_2537;
        }
        t9ddff9e1963b15ba493db1f8dadd34fb id_2555 { std::get<2>(*p_0) };
        std::string id_2556 { id_2555.net_addr };
        uint32_t id_2557 { (uint32_t)id_2556.size() };
        Size id_2558 { Size(id_2557) };
        Size id_2559 { Size(let_res_2534 + id_2558) };
        Size id_2560 { Size(id_2529 + id_2559) };
        Size id_2561 { 2UL };
        Size id_2562 { Size(id_2560 + id_2561) };
        Size let_res_2563;
        {
          Size sz_698 { id_2562 };
          auto fun2564 { dessser::gen::raql_net_protocol::sersize_of_row_binary };
          t9ddff9e1963b15ba493db1f8dadd34fb id_2565 { std::get<2>(*p_0) };
          dessser::gen::raql_net_protocol::t_ext id_2566 { id_2565.proto };
          Size id_2567 { fun2564(id_2566) };
          Size id_2568 { Size(sz_698 + id_2567) };
          let_res_2563 = id_2568;
        }
        Size let_res_2569;
        {
          Size sz_699 { let_res_2563 };
          t9ddff9e1963b15ba493db1f8dadd34fb id_2570 { std::get<2>(*p_0) };
          Lst<dessser::gen::field_name::t_ext> id_2571 { id_2570.factors };
          uint32_t id_2572 { id_2571.size() };
          Vec<1, uint32_t> id_2573 {  id_2572  };
          Size let_res_2574;
          {
            Vec<1, uint32_t> n_ref_700 { id_2573 };
            uint32_t id_2575 { 1U };
            Vec<1, uint32_t> id_2576 {  id_2575  };
            Size let_res_2577;
            {
              Vec<1, uint32_t> lebsz_ref_701 { id_2576 };
              bool while_flag_2578 { true };
              do {
                uint8_t id_2579 { 0 };
                uint32_t id_2580 { n_ref_700[id_2579] };
                uint8_t id_2581 { 0 };
                uint32_t id_2582 { lebsz_ref_701[id_2581] };
                uint8_t id_2583 { 7 };
                uint32_t id_2584 { uint32_t(id_2582 << id_2583) };
                bool id_2585 { bool(id_2580 >= id_2584) };
                while_flag_2578 = id_2585;
                if (while_flag_2578) {
                  uint8_t id_2586 { 0 };
                  uint8_t id_2587 { 0 };
                  uint32_t id_2588 { lebsz_ref_701[id_2587] };
                  uint32_t id_2589 { 1U };
                  uint32_t id_2590 { uint32_t(id_2588 + id_2589) };
                  Void id_2591 { ((void)(lebsz_ref_701[id_2586] = id_2590), VOID) };
                  (void)id_2591;
                }
              } while (while_flag_2578);
              (void)VOID;
              uint8_t id_2592 { 0 };
              uint32_t id_2593 { lebsz_ref_701[id_2592] };
              Size id_2594 { Size(id_2593) };
              let_res_2577 = id_2594;
            }
            let_res_2574 = let_res_2577;
          }
          Size id_2595 { Size(sz_699 + let_res_2574) };
          Vec<1, Size> id_2596 {  id_2595  };
          Size let_res_2597;
          {
            Vec<1, Size> sz_ref_702 { id_2596 };
            int32_t id_2598 { 0L };
            Vec<1, int32_t> id_2599 {  id_2598  };
            {
              Vec<1, int32_t> repeat_n_703 { id_2599 };
              bool while_flag_2600 { true };
              do {
                t9ddff9e1963b15ba493db1f8dadd34fb id_2601 { std::get<2>(*p_0) };
                Lst<dessser::gen::field_name::t_ext> id_2602 { id_2601.factors };
                uint32_t id_2603 { id_2602.size() };
                int32_t id_2604 { int32_t(id_2603) };
                uint8_t id_2605 { 0 };
                int32_t id_2606 { repeat_n_703[id_2605] };
                bool id_2607 { bool(id_2604 > id_2606) };
                while_flag_2600 = id_2607;
                if (while_flag_2600) {
                  uint8_t id_2608 { 0 };
                  uint8_t id_2609 { 0 };
                  Size id_2610 { sz_ref_702[id_2609] };
                  auto fun2611 { dessser::gen::field_name::sersize_of_row_binary };
                  uint8_t id_2612 { 0 };
                  int32_t id_2613 { repeat_n_703[id_2612] };
                  t9ddff9e1963b15ba493db1f8dadd34fb id_2614 { std::get<2>(*p_0) };
                  Lst<dessser::gen::field_name::t_ext> id_2615 { id_2614.factors };
                  dessser::gen::field_name::t_ext id_2616 { id_2615[id_2613] };
                  Size id_2617 { fun2611(id_2616) };
                  Size id_2618 { Size(id_2610 + id_2617) };
                  Void id_2619 { ((void)(sz_ref_702[id_2608] = id_2618), VOID) };
                  (void)id_2619;
                  uint8_t id_2620 { 0 };
                  uint8_t id_2621 { 0 };
                  int32_t id_2622 { repeat_n_703[id_2621] };
                  int32_t id_2623 { 1L };
                  int32_t id_2624 { int32_t(id_2622 + id_2623) };
                  Void id_2625 { ((void)(repeat_n_703[id_2620] = id_2624), VOID) };
                  (void)id_2625;
                  (void)id_2625;
                }
              } while (while_flag_2600);
              (void)VOID;
            }
            (void)VOID;
            uint8_t id_2626 { 0 };
            Size id_2627 { sz_ref_702[id_2626] };
            let_res_2597 = id_2627;
          }
          let_res_2569 = let_res_2597;
        }
        choose_res_1997 = let_res_2569;
      }
      choose_res_1343 = choose_res_1997;
    }
    return choose_res_1343;
  }
   };
  return fun1339;
}
std::function<Size(t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_690" "make_snd_691"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let "drec_410"
                (let-pair "dlist4_fst_408" "dlist4_snd_409"
                  (let "dlist1_396"
                    (let "leb_ref_387" (make-vec (u32 0))
                      (let "shft_ref_388" (make-vec (u8 0))
                        (let "p_ref_389" (make-vec (identifier "dsum1_snd_64"))
                          (seq
                            (while
                              (let "leb128_390" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_389")))
                                (let-pair "leb128_fst_391" "leb128_snd_392" 
                                  (identifier "leb128_390")
                                  (seq (set-vec (u8 0) (identifier "p_ref_389") (identifier "leb128_snd_392"))
                                    (set-vec (u8 0) (identifier "leb_ref_387")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_391") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_388"))) (unsafe-nth (u8 0) (identifier "leb_ref_387"))))
                                    (set-vec (u8 0) (identifier "shft_ref_388") (add (unsafe-nth (u8 0) (identifier "shft_ref_388")) (u8 7))) 
                                    (ge (identifier "leb128_fst_391") (u8 128))))) 
                              (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_387")) (unsafe-nth (u8 0) (identifier "p_ref_389")))))))
                    (let-pair "dlist1_fst_397" "dlist1_snd_398" (identifier "dlist1_396")
                      (let "inits_src_ref_399" (make-vec (make-tup (end-of-list "$raql_select_field") (identifier "dlist1_snd_398")))
                        (seq
                          (let "repeat_n_400" (make-vec (i32 0))
                            (while (gt (to-i32 (identifier "dlist1_fst_397")) (unsafe-nth (u8 0) (identifier "repeat_n_400")))
                              (seq
                                (let "dlist2_401" (unsafe-nth (u8 0) (identifier "inits_src_ref_399"))
                                  (let-pair "dlist2_fst_402" "dlist2_snd_403" 
                                    (identifier "dlist2_401")
                                    (set-vec (u8 0) (identifier "inits_src_ref_399")
                                      (let-pair "dlist3_fst_405" "dlist3_snd_406" 
                                        (apply (ext-identifier raql_select_field of-row-binary) (identifier "dlist2_snd_403"))
                                        (make-tup (cons (identifier "dlist3_fst_405") (identifier "dlist2_fst_402")) (identifier "dlist3_snd_406"))))))
                                (set-vec (u8 0) (identifier "repeat_n_400") (add (unsafe-nth (u8 0) (identifier "repeat_n_400")) (i32 1)))))) 
                          (unsafe-nth (u8 0) (identifier "inits_src_ref_399")))))) 
                  (make-tup (identity (identifier "dlist4_fst_408")) (identifier "dlist4_snd_409")))
                (let-pair "drec_fst_411" "drec_snd_412" (identifier "drec_410")
                  (let "drec_439"
                    (if (eq (peek-u8 (identifier "drec_snd_412") (size 0)) (u8 1)) 
                      (make-tup (null "$field_name[[]]") (ptr-add (identifier "drec_snd_412") (size 1)))
                      (let-pair "dlist4_fst_434" "dlist4_snd_435"
                        (let "dlist1_422"
                          (let "leb_ref_413" (make-vec (u32 0))
                            (let "shft_ref_414" (make-vec (u8 0))
                              (let "p_ref_415" (make-vec (ptr-add (identifier "drec_snd_412") (size 1)))
                                (seq
                                  (while
                                    (let "leb128_416" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_415")))
                                      (let-pair "leb128_fst_417" "leb128_snd_418" 
                                        (identifier "leb128_416")
                                        (seq (set-vec (u8 0) (identifier "p_ref_415") (identifier "leb128_snd_418"))
                                          (set-vec (u8 0) (identifier "leb_ref_413")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_417") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_414"))) (unsafe-nth (u8 0) (identifier "leb_ref_413"))))
                                          (set-vec (u8 0) (identifier "shft_ref_414") (add (unsafe-nth (u8 0) (identifier "shft_ref_414")) (u8 7))) 
                                          (ge (identifier "leb128_fst_417") (u8 128))))) 
                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_413")) (unsafe-nth (u8 0) (identifier "p_ref_415")))))))
                          (let-pair "dlist1_fst_423" "dlist1_snd_424" 
                            (identifier "dlist1_422")
                            (let "inits_src_ref_425" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_424")))
                              (seq
                                (let "repeat_n_426" (make-vec (i32 0))
                                  (while (gt (to-i32 (identifier "dlist1_fst_423")) (unsafe-nth (u8 0) (identifier "repeat_n_426")))
                                    (seq
                                      (let "dlist2_427" (unsafe-nth (u8 0) (identifier "inits_src_ref_425"))
                                        (let-pair "dlist2_fst_428" "dlist2_snd_429" 
                                          (identifier "dlist2_427")
                                          (set-vec (u8 0) (identifier "inits_src_ref_425")
                                            (let-pair "dlist3_fst_431" "dlist3_snd_432" 
                                              (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_429"))
                                              (make-tup (cons (identifier "dlist3_fst_431") (identifier "dlist2_fst_428")) (identifier "dlist3_snd_432"))))))
                                      (set-vec (u8 0) (identifier "repeat_n_426") (add (unsafe-nth (u8 0) (identifier "repeat_n_426")) (i32 1)))))) 
                                (unsafe-nth (u8 0) (identifier "inits_src_ref_425")))))) 
                        (make-tup (not-null (identity (identifier "dlist4_fst_434"))) (identifier "dlist4_snd_435"))))
                    (let-pair "drec_fst_440" "drec_snd_441" (identifier "drec_439")
                      (let "drec_483"
                        (if (eq (peek-u8 (identifier "drec_snd_441") (size 0)) (u8 1)) 
                          (make-tup (null "(U32; $raql_expr?; $raql_expr[[]])") (ptr-add (identifier "drec_snd_441") (size 1)))
                          (let "dtup_445" (let-pair "du32_fst_443" "du32_snd_444" (read-u32 little-endian (ptr-add (identifier "drec_snd_441") (size 1))) (make-tup (identifier "du32_fst_443") (identifier "du32_snd_444")))
                            (let-pair "dtup_fst_446" "dtup_snd_447" (identifier "dtup_445")
                              (let "dtup_451"
                                (if (eq (peek-u8 (identifier "dtup_snd_447") (size 0)) (u8 1)) 
                                  (make-tup (null "$raql_expr") (ptr-add (identifier "dtup_snd_447") (size 1)))
                                  (let-pair "make1_1_fst_449" "make1_1_snd_450" 
                                    (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "dtup_snd_447") (size 1))) 
                                    (make-tup (not-null (identifier "make1_1_fst_449")) (identifier "make1_1_snd_450"))))
                                (let-pair "dtup_fst_452" "dtup_snd_453" 
                                  (identifier "dtup_451")
                                  (let-pair "dlist4_fst_475" "dlist4_snd_476"
                                    (let "dlist1_463"
                                      (let "leb_ref_454" (make-vec (u32 0))
                                        (let "shft_ref_455" (make-vec (u8 0))
                                          (let "p_ref_456" (make-vec (identifier "dtup_snd_453"))
                                            (seq
                                              (while
                                                (let "leb128_457" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_456")))
                                                  (let-pair "leb128_fst_458" "leb128_snd_459" 
                                                    (identifier "leb128_457")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_456") (identifier "leb128_snd_459"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_454")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_458") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_455")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_454")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_455") (add (unsafe-nth (u8 0) (identifier "shft_ref_455")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_458") (u8 128))))) 
                                                (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_454")) (unsafe-nth (u8 0) (identifier "p_ref_456")))))))
                                      (let-pair "dlist1_fst_464" "dlist1_snd_465" 
                                        (identifier "dlist1_463")
                                        (let "inits_src_ref_466" (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_465")))
                                          (seq
                                            (let "repeat_n_467" (make-vec (i32 0))
                                              (while (gt (to-i32 (identifier "dlist1_fst_464")) (unsafe-nth (u8 0) (identifier "repeat_n_467")))
                                                (seq
                                                  (let "dlist2_468" (unsafe-nth (u8 0) (identifier "inits_src_ref_466"))
                                                    (let-pair "dlist2_fst_469" "dlist2_snd_470" 
                                                      (identifier "dlist2_468")
                                                      (set-vec (u8 0) 
                                                        (identifier "inits_src_ref_466")
                                                        (let-pair "dlist3_fst_472" "dlist3_snd_473" 
                                                          (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_470"))
                                                          (make-tup (cons (identifier "dlist3_fst_472") (identifier "dlist2_fst_469")) (identifier "dlist3_snd_473"))))))
                                                  (set-vec (u8 0) (identifier "repeat_n_467") (add (unsafe-nth (u8 0) (identifier "repeat_n_467")) (i32 1)))))) 
                                            (unsafe-nth (u8 0) (identifier "inits_src_ref_466"))))))
                                    (make-tup (not-null (make-tup (identifier "dtup_fst_446") (identifier "dtup_fst_452") (identity (identifier "dlist4_fst_475")))) (identifier "dlist4_snd_476"))))))))
                        (let-pair "drec_fst_484" "drec_snd_485" (identifier "drec_483")
                          (let "drec_486" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_485"))
                            (let-pair "drec_fst_487" "drec_snd_488" (identifier "drec_486")
                              (let "drec_492"
                                (if (eq (peek-u8 (identifier "drec_snd_488") (size 0)) (u8 1)) 
                                  (make-tup (null "$event_time") (ptr-add (identifier "drec_snd_488") (size 1)))
                                  (let-pair "make1_1_fst_490" "make1_1_snd_491" 
                                    (apply (ext-identifier event_time of-row-binary) (ptr-add (identifier "drec_snd_488") (size 1))) 
                                    (make-tup (not-null (identifier "make1_1_fst_490")) (identifier "make1_1_snd_491"))))
                                (let-pair "drec_fst_493" "drec_snd_494" 
                                  (identifier "drec_492")
                                  (let "drec_518"
                                    (let-pair "dlist4_fst_516" "dlist4_snd_517"
                                      (let "dlist1_504"
                                        (let "leb_ref_495" (make-vec (u32 0))
                                          (let "shft_ref_496" (make-vec (u8 0))
                                            (let "p_ref_497" (make-vec (identifier "drec_snd_494"))
                                              (seq
                                                (while
                                                  (let "leb128_498" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_497")))
                                                    (let-pair "leb128_fst_499" "leb128_snd_500" 
                                                      (identifier "leb128_498")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_497") (identifier "leb128_snd_500"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_495")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_499") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_496")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_495")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_496") (add (unsafe-nth (u8 0) (identifier "shft_ref_496")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_499") (u8 128))))) 
                                                  (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_495")) (unsafe-nth (u8 0) (identifier "p_ref_497")))))))
                                        (let-pair "dlist1_fst_505" "dlist1_snd_506" 
                                          (identifier "dlist1_504")
                                          (let "inits_src_ref_507" (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_506")))
                                            (seq
                                              (let "repeat_n_508" (make-vec (i32 0))
                                                (while (gt (to-i32 (identifier "dlist1_fst_505")) (unsafe-nth (u8 0) (identifier "repeat_n_508")))
                                                  (seq
                                                    (let "dlist2_509" 
                                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_507"))
                                                      (let-pair "dlist2_fst_510" "dlist2_snd_511" 
                                                        (identifier "dlist2_509")
                                                        (set-vec (u8 0) 
                                                          (identifier "inits_src_ref_507")
                                                          (let-pair "dlist3_fst_513" "dlist3_snd_514" 
                                                            (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_511"))
                                                            (make-tup (cons (identifier "dlist3_fst_513") (identifier "dlist2_fst_510")) (identifier "dlist3_snd_514"))))))
                                                    (set-vec (u8 0) (identifier "repeat_n_508") (add (unsafe-nth (u8 0) (identifier "repeat_n_508")) (i32 1)))))) 
                                              (unsafe-nth (u8 0) (identifier "inits_src_ref_507")))))) 
                                      (make-tup (identity (identifier "dlist4_fst_516")) (identifier "dlist4_snd_517")))
                                    (let-pair "drec_fst_519" "drec_snd_520" 
                                      (identifier "drec_518")
                                      (let "drec_544"
                                        (let-pair "dlist4_fst_542" "dlist4_snd_543"
                                          (let "dlist1_530"
                                            (let "leb_ref_521" (make-vec (u32 0))
                                              (let "shft_ref_522" (make-vec (u8 0))
                                                (let "p_ref_523" (make-vec (identifier "drec_snd_520"))
                                                  (seq
                                                    (while
                                                      (let "leb128_524" 
                                                        (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_523")))
                                                        (let-pair "leb128_fst_525" "leb128_snd_526" 
                                                          (identifier "leb128_524")
                                                          (seq (set-vec (u8 0) (identifier "p_ref_523") (identifier "leb128_snd_526"))
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb_ref_521")
                                                              (bit-or 
                                                                (left-shift (to-u32 (bit-and (identifier "leb128_fst_525") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_522")))
                                                                (unsafe-nth (u8 0) (identifier "leb_ref_521")))) 
                                                            (set-vec (u8 0) (identifier "shft_ref_522") (add (unsafe-nth (u8 0) (identifier "shft_ref_522")) (u8 7))) 
                                                            (ge (identifier "leb128_fst_525") (u8 128))))) 
                                                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_521")) (unsafe-nth (u8 0) (identifier "p_ref_523")))))))
                                            (let-pair "dlist1_fst_531" "dlist1_snd_532" 
                                              (identifier "dlist1_530")
                                              (let "inits_src_ref_533" 
                                                (make-vec (make-tup (end-of-list "$raql_expr") (identifier "dlist1_snd_532")))
                                                (seq
                                                  (let "repeat_n_534" 
                                                    (make-vec (i32 0))
                                                    (while (gt (to-i32 (identifier "dlist1_fst_531")) (unsafe-nth (u8 0) (identifier "repeat_n_534")))
                                                      (seq
                                                        (let "dlist2_535" 
                                                          (unsafe-nth (u8 0) (identifier "inits_src_ref_533"))
                                                          (let-pair "dlist2_fst_536" "dlist2_snd_537" 
                                                            (identifier "dlist2_535")
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "inits_src_ref_533")
                                                              (let-pair "dlist3_fst_539" "dlist3_snd_540" 
                                                                (apply (ext-identifier raql_expr of-row-binary) (identifier "dlist2_snd_537"))
                                                                (make-tup (cons (identifier "dlist3_fst_539") (identifier "dlist2_fst_536")) (identifier "dlist3_snd_540"))))))
                                                        (set-vec (u8 0) (identifier "repeat_n_534") (add (unsafe-nth (u8 0) (identifier "repeat_n_534")) (i32 1)))))) 
                                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_533")))))) 
                                          (make-tup (identity (identifier "dlist4_fst_542")) (identifier "dlist4_snd_543")))
                                        (let-pair "drec_fst_545" "drec_snd_546" 
                                          (identifier "drec_544")
                                          (let "drec_547" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_546"))
                                            (let-pair "drec_fst_548" "drec_snd_549" 
                                              (identifier "drec_547")
                                              (let "drec_553" (let-pair "dbool_fst_551" "dbool_snd_552" (read-u8 (identifier "drec_snd_549")) (make-tup (not (eq (identifier "dbool_fst_551") (u8 0))) (identifier "dbool_snd_552")))
                                                (let-pair "drec_fst_554" "drec_snd_555" 
                                                  (identifier "drec_553")
                                                  (let "drec_556" (apply (ext-identifier raql_flush_method of-row-binary) (identifier "drec_snd_555"))
                                                    (let-pair "drec_fst_557" "drec_snd_558" 
                                                      (identifier "drec_556")
                                                      (let "drec_651"
                                                        (let-pair "dlist4_fst_649" "dlist4_snd_650"
                                                          (let "dlist1_568"
                                                            (let "leb_ref_559" 
                                                              (make-vec (u32 0))
                                                              (let "shft_ref_560" 
                                                                (make-vec (u8 0))
                                                                (let "p_ref_561" 
                                                                  (make-vec (identifier "drec_snd_558"))
                                                                  (seq
                                                                    (while
                                                                    (let "leb128_562" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_561")))
                                                                    (let-pair "leb128_fst_563" "leb128_snd_564" 
                                                                    (identifier "leb128_562")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_561") (identifier "leb128_snd_564"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_559")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_563") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_560")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_559")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_560") (add (unsafe-nth (u8 0) (identifier "shft_ref_560")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_563") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_559")) (unsafe-nth (u8 0) (identifier "p_ref_561")))))))
                                                            (let-pair "dlist1_fst_569" "dlist1_snd_570" 
                                                              (identifier "dlist1_568")
                                                              (let "inits_src_ref_571"
                                                                (make-vec
                                                                  (make-tup 
                                                                    (end-of-list "[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]") 
                                                                    (identifier "dlist1_snd_570")))
                                                                (seq
                                                                  (let "repeat_n_572" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_569")) (unsafe-nth (u8 0) (identifier "repeat_n_572")))
                                                                    (seq
                                                                    (let "dlist2_573" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_571"))
                                                                    (let-pair "dlist2_fst_574" "dlist2_snd_575" 
                                                                    (identifier "dlist2_573")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_571")
                                                                    (let-pair "dlist3_fst_646" "dlist3_snd_647"
                                                                    (let "dsum1_582"
                                                                    (let-pair "du16_fst_577" "du16_snd_578" 
                                                                    (read-u16 little-endian (identifier "dlist2_snd_575")) 
                                                                    (make-tup (identifier "du16_fst_577") (identifier "du16_snd_578")))
                                                                    (let-pair "dsum1_fst_583" "dsum1_snd_584" 
                                                                    (identifier "dsum1_582")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_583"))
                                                                    (let "dtup_618"
                                                                    (let "dsum1_594"
                                                                    (let-pair "du16_fst_589" "du16_snd_590" (read-u16 little-endian (identifier "dsum1_snd_584")) (make-tup (identifier "du16_fst_589") (identifier "du16_snd_590")))
                                                                    (let-pair "dsum1_fst_595" "dsum1_snd_596" 
                                                                    (identifier "dsum1_594")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_595")) 
                                                                    (make-tup (construct "[AllSites Void | TheseSites STRING | ThisSite Void]" 0 (nop)) (identifier "dsum1_snd_596"))
                                                                    (if 
                                                                    (eq (u16 1) (identifier "dsum1_fst_595"))
                                                                    (let "dstring1_606"
                                                                    (let "leb_ref_600" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_601" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_602" 
                                                                    (make-vec (identifier "dsum1_snd_596"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_603" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_602")))
                                                                    (let-pair "leb128_fst_604" "leb128_snd_605" 
                                                                    (identifier "leb128_603")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_602") (identifier "leb128_snd_605"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_600")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_604") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_601")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_600")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_601") (add (unsafe-nth (u8 0) (identifier "shft_ref_601")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_604") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_600"))) (unsafe-nth (u8 0) (identifier "p_ref_602")))))))
                                                                    (let-pair "dstring1_fst_607" "dstring1_snd_608" 
                                                                    (identifier "dstring1_606")
                                                                    (let-pair "dstring2_fst_610" "dstring2_snd_611" 
                                                                    (read-bytes (identifier "dstring1_snd_608") (identifier "dstring1_fst_607"))
                                                                    (make-tup (construct "[AllSites Void | TheseSites STRING | ThisSite Void]" 1 (string-of-bytes (identifier "dstring2_fst_610"))) (identifier "dstring2_snd_611")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_595") (u16 2)))
                                                                    (make-tup (construct "[AllSites Void | TheseSites STRING | ThisSite Void]" 2 (nop)) (identifier "dsum1_snd_596")))))))
                                                                    (let-pair "dtup_fst_619" "dtup_snd_620" 
                                                                    (identifier "dtup_618")
                                                                    (let "dtup_636"
                                                                    (if 
                                                                    (eq (peek-u8 (identifier "dtup_snd_620") (size 0)) (u8 1)) 
                                                                    (make-tup (null "STRING") (ptr-add (identifier "dtup_snd_620") (size 1)))
                                                                    (let "dstring1_627"
                                                                    (let "leb_ref_621" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_622" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_623" 
                                                                    (make-vec (ptr-add (identifier "dtup_snd_620") (size 1)))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_624" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_623")))
                                                                    (let-pair "leb128_fst_625" "leb128_snd_626" 
                                                                    (identifier "leb128_624")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_623") (identifier "leb128_snd_626"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_621")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_625") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_622")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_621")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_622") (add (unsafe-nth (u8 0) (identifier "shft_ref_622")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_625") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_621"))) (unsafe-nth (u8 0) (identifier "p_ref_623")))))))
                                                                    (let-pair "dstring1_fst_628" "dstring1_snd_629" 
                                                                    (identifier "dstring1_627")
                                                                    (let-pair "dstring2_fst_631" "dstring2_snd_632" 
                                                                    (read-bytes (identifier "dstring1_snd_629") (identifier "dstring1_fst_628"))
                                                                    (make-tup (not-null (string-of-bytes (identifier "dstring2_fst_631"))) (identifier "dstring2_snd_632"))))))
                                                                    (let-pair "dtup_fst_637" "dtup_snd_638" 
                                                                    (identifier "dtup_636")
                                                                    (let-pair "dtup_fst_640" "dtup_snd_641" 
                                                                    (apply (ext-identifier function_name of-row-binary) (identifier "dtup_snd_638"))
                                                                    (make-tup
                                                                    (construct "[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]" 0
                                                                    (make-tup (identifier "dtup_fst_619") (identifier "dtup_fst_637") (identifier "dtup_fst_640"))) 
                                                                    (identifier "dtup_snd_641")))))))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_583") (u16 1)))
                                                                    (let-pair "dsum2_fst_586" "dsum2_snd_587" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dsum1_snd_584"))
                                                                    (make-tup
                                                                    (construct "[NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS]" 1 (identifier "dsum2_fst_586"))
                                                                    (identifier "dsum2_snd_587"))))))) 
                                                                    (make-tup (cons (identifier "dlist3_fst_646") (identifier "dlist2_fst_574")) (identifier "dlist3_snd_647"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_572") (add (unsafe-nth (u8 0) (identifier "repeat_n_572")) (i32 1))))))
                                                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_571")))))) 
                                                          (make-tup (identity (identifier "dlist4_fst_649")) (identifier "dlist4_snd_650")))
                                                        (let-pair "drec_fst_652" "drec_snd_653" 
                                                          (identifier "drec_651")
                                                          (let "drec_657"
                                                            (if (eq (peek-u8 (identifier "drec_snd_653") (size 0)) (u8 1)) 
                                                              (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_653") (size 1)))
                                                              (let-pair "make1_1_fst_655" "make1_1_snd_656" 
                                                                (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_653") (size 1)))
                                                                (make-tup (not-null (identifier "make1_1_fst_655")) (identifier "make1_1_snd_656"))))
                                                            (let-pair "drec_fst_658" "drec_snd_659" 
                                                              (identifier "drec_657")
                                                              (let-pair "dlist4_fst_681" "dlist4_snd_682"
                                                                (let "dlist1_669"
                                                                  (let "leb_ref_660" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_661" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_662" 
                                                                    (make-vec (identifier "drec_snd_659"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_663" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_662")))
                                                                    (let-pair "leb128_fst_664" "leb128_snd_665" 
                                                                    (identifier "leb128_663")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_662") (identifier "leb128_snd_665"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_660")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_664") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_661")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_660")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_661") (add (unsafe-nth (u8 0) (identifier "shft_ref_661")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_664") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_660")) (unsafe-nth (u8 0) (identifier "p_ref_662")))))))
                                                                  (let-pair "dlist1_fst_670" "dlist1_snd_671" 
                                                                    (identifier "dlist1_669")
                                                                    (let "inits_src_ref_672" 
                                                                    (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_671")))
                                                                    (seq
                                                                    (let "repeat_n_673" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_670")) (unsafe-nth (u8 0) (identifier "repeat_n_673")))
                                                                    (seq
                                                                    (let "dlist2_674" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_672"))
                                                                    (let-pair "dlist2_fst_675" "dlist2_snd_676" 
                                                                    (identifier "dlist2_674")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_672")
                                                                    (let-pair "dlist3_fst_678" "dlist3_snd_679" 
                                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_676"))
                                                                    (make-tup (cons (identifier "dlist3_fst_678") (identifier "dlist2_fst_675")) (identifier "dlist3_snd_679"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_673") (add (unsafe-nth (u8 0) (identifier "repeat_n_673")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_672"))))))
                                                                (make-tup
                                                                  (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS][[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]; format: [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]; event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" 0
                                                                    (make-rec 
                                                                    (string "fields") 
                                                                    (identifier "drec_fst_411") 
                                                                    (string "and_all_others") 
                                                                    (identifier "drec_fst_440") 
                                                                    (string "sort") 
                                                                    (identifier "drec_fst_484") 
                                                                    (string "where") 
                                                                    (identifier "drec_fst_487") 
                                                                    (string "event_time") 
                                                                    (identifier "drec_fst_493") 
                                                                    (string "notifications") 
                                                                    (identifier "drec_fst_519") 
                                                                    (string "key") 
                                                                    (identifier "drec_fst_545") 
                                                                    (string "commit_cond") 
                                                                    (identifier "drec_fst_548") 
                                                                    (string "commit_before") 
                                                                    (identifier "drec_fst_554") 
                                                                    (string "flush_how") 
                                                                    (identifier "drec_fst_557") 
                                                                    (string "from") 
                                                                    (identifier "drec_fst_652") 
                                                                    (string "every") 
                                                                    (identifier "drec_fst_658") 
                                                                    (string "factors") 
                                                                    (identity (identifier "dlist4_fst_681")))) 
                                                                  (identifier "dlist4_snd_682")))))))))))))))))))))))))))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (let "drec_228"
                  (let "dsum1_124" (let-pair "du16_fst_119" "du16_snd_120" (read-u16 little-endian (identifier "dsum1_snd_64")) (make-tup (identifier "du16_fst_119") (identifier "du16_snd_120")))
                    (let-pair "dsum1_fst_125" "dsum1_snd_126" (identifier "dsum1_124")
                      (if (eq (u16 0) (identifier "dsum1_fst_125"))
                        (let "drec_213" (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_126"))
                          (let-pair "drec_fst_214" "drec_snd_215" (identifier "drec_213")
                            (let "drec_219"
                              (if (eq (peek-u8 (identifier "drec_snd_215") (size 0)) (u8 1)) 
                                (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_215") (size 1)))
                                (let-pair "make1_1_fst_217" "make1_1_snd_218" 
                                  (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_215") (size 1))) 
                                  (make-tup (not-null (identifier "make1_1_fst_217")) (identifier "make1_1_snd_218"))))
                              (let-pair "drec_fst_220" "drec_snd_221" 
                                (identifier "drec_219")
                                (let-pair "drec_fst_223" "drec_snd_224" 
                                  (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_221"))
                                  (make-tup
                                    (construct "[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" 0
                                      (make-rec (string "fname") (identifier "drec_fst_214") (string "preprocessor") (identifier "drec_fst_220") (string "unlink") (identifier "drec_fst_223"))) 
                                    (identifier "drec_snd_224")))))))
                        (seq (assert (eq (identifier "dsum1_fst_125") (u16 1)))
                          (let "drec_168"
                            (let-pair "dlist4_fst_166" "dlist4_snd_167"
                              (let "dlist1_136"
                                (let "leb_ref_127" (make-vec (u32 0))
                                  (let "shft_ref_128" (make-vec (u8 0))
                                    (let "p_ref_129" (make-vec (identifier "dsum1_snd_126"))
                                      (seq
                                        (while
                                          (let "leb128_130" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_129")))
                                            (let-pair "leb128_fst_131" "leb128_snd_132" 
                                              (identifier "leb128_130")
                                              (seq (set-vec (u8 0) (identifier "p_ref_129") (identifier "leb128_snd_132"))
                                                (set-vec (u8 0) (identifier "leb_ref_127")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_131") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_128"))) (unsafe-nth (u8 0) (identifier "leb_ref_127"))))
                                                (set-vec (u8 0) (identifier "shft_ref_128") (add (unsafe-nth (u8 0) (identifier "shft_ref_128")) (u8 7))) 
                                                (ge (identifier "leb128_fst_131") (u8 128))))) 
                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_127")) (unsafe-nth (u8 0) (identifier "p_ref_129")))))))
                                (let-pair "dlist1_fst_137" "dlist1_snd_138" 
                                  (identifier "dlist1_136")
                                  (let "inits_src_ref_139" (make-vec (make-tup (end-of-list "(STRING; $raql_expr)") (identifier "dlist1_snd_138")))
                                    (seq
                                      (let "repeat_n_140" (make-vec (i32 0))
                                        (while (gt (to-i32 (identifier "dlist1_fst_137")) (unsafe-nth (u8 0) (identifier "repeat_n_140")))
                                          (seq
                                            (let "dlist2_141" (unsafe-nth (u8 0) (identifier "inits_src_ref_139"))
                                              (let-pair "dlist2_fst_142" "dlist2_snd_143" 
                                                (identifier "dlist2_141")
                                                (set-vec (u8 0) (identifier "inits_src_ref_139")
                                                  (let "dtup_156"
                                                    (let "dstring1_150"
                                                      (let "leb_ref_144" 
                                                        (make-vec (u32 0))
                                                        (let "shft_ref_145" 
                                                          (make-vec (u8 0))
                                                          (let "p_ref_146" 
                                                            (make-vec (identifier "dlist2_snd_143"))
                                                            (seq
                                                              (while
                                                                (let "leb128_147" 
                                                                  (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_146")))
                                                                  (let-pair "leb128_fst_148" "leb128_snd_149" 
                                                                    (identifier "leb128_147")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_146") (identifier "leb128_snd_149"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_144")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_148") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_145")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_144")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_145") (add (unsafe-nth (u8 0) (identifier "shft_ref_145")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_148") (u8 128))))) 
                                                                (nop)) 
                                                              (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_144"))) (unsafe-nth (u8 0) (identifier "p_ref_146")))))))
                                                      (let-pair "dstring1_fst_151" "dstring1_snd_152" 
                                                        (identifier "dstring1_150")
                                                        (let-pair "dstring2_fst_154" "dstring2_snd_155" 
                                                          (read-bytes (identifier "dstring1_snd_152") (identifier "dstring1_fst_151")) 
                                                          (make-tup (string-of-bytes (identifier "dstring2_fst_154")) (identifier "dstring2_snd_155")))))
                                                    (let-pair "dtup_fst_157" "dtup_snd_158" 
                                                      (identifier "dtup_156")
                                                      (let-pair "dtup_fst_160" "dtup_snd_161" 
                                                        (apply (ext-identifier raql_expr of-row-binary) (identifier "dtup_snd_158"))
                                                        (make-tup (cons (make-tup (identifier "dtup_fst_157") (identifier "dtup_fst_160")) (identifier "dlist2_fst_142")) (identifier "dtup_snd_161"))))))))
                                            (set-vec (u8 0) (identifier "repeat_n_140") (add (unsafe-nth (u8 0) (identifier "repeat_n_140")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_139")))))) 
                              (make-tup (identity (identifier "dlist4_fst_166")) (identifier "dlist4_snd_167")))
                            (let-pair "drec_fst_169" "drec_snd_170" (identifier "drec_168")
                              (let "drec_171" (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_170"))
                                (let-pair "drec_fst_172" "drec_snd_173" 
                                  (identifier "drec_171")
                                  (let "drec_177"
                                    (if (eq (peek-u8 (identifier "drec_snd_173") (size 0)) (u8 1)) 
                                      (make-tup (null "$raql_expr") (ptr-add (identifier "drec_snd_173") (size 1)))
                                      (let-pair "make1_1_fst_175" "make1_1_snd_176" 
                                        (apply (ext-identifier raql_expr of-row-binary) (ptr-add (identifier "drec_snd_173") (size 1))) 
                                        (make-tup (not-null (identifier "make1_1_fst_175")) (identifier "make1_1_snd_176"))))
                                    (let-pair "drec_fst_178" "drec_snd_179" 
                                      (identifier "drec_177")
                                      (let-pair "drec_fst_208" "drec_snd_209"
                                        (let "dsum1_186" (let-pair "du16_fst_181" "du16_snd_182" (read-u16 little-endian (identifier "drec_snd_179")) (make-tup (identifier "du16_fst_181") (identifier "du16_snd_182")))
                                          (let-pair "dsum1_fst_187" "dsum1_snd_188" 
                                            (identifier "dsum1_186")
                                            (if (eq (u16 0) (identifier "dsum1_fst_187"))
                                              (make-tup (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 0 (nop))
                                                (identifier "dsum1_snd_188"))
                                              (if (eq (u16 1) (identifier "dsum1_fst_187"))
                                                (let-pair "dsum2_fst_202" "dsum2_snd_203" 
                                                  (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_188"))
                                                  (make-tup
                                                    (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 1
                                                      (identifier "dsum2_fst_202")) 
                                                    (identifier "dsum2_snd_203")))
                                                (if (eq (u16 2) (identifier "dsum1_fst_187"))
                                                  (make-tup
                                                    (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 2 (nop))
                                                    (identifier "dsum1_snd_188"))
                                                  (seq (assert (eq (identifier "dsum1_fst_187") (u16 3)))
                                                    (let "drec_189" (apply (ext-identifier raql_expr of-row-binary) (identifier "dsum1_snd_188"))
                                                      (let-pair "drec_fst_190" "drec_snd_191" 
                                                        (identifier "drec_189")
                                                        (let-pair "drec_fst_193" "drec_snd_194" 
                                                          (apply (ext-identifier raql_expr of-row-binary) (identifier "drec_snd_191"))
                                                          (make-tup
                                                            (construct "[Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]" 3
                                                              (make-rec (string "after_max_secs") (identifier "drec_fst_190") (string "after_max_events") (identifier "drec_fst_193"))) 
                                                            (identifier "drec_snd_194")))))))))))
                                        (make-tup
                                          (construct "[File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]" 1
                                            (make-rec (string "options") 
                                              (identifier "drec_fst_169") 
                                              (string "topic") (identifier "drec_fst_172") 
                                              (string "partitions") (identifier "drec_fst_178") 
                                              (string "restart_from") 
                                              (identifier "drec_fst_208"))) 
                                          (identifier "drec_snd_209")))))))))))))
                  (let-pair "drec_fst_229" "drec_snd_230" (identifier "drec_228")
                    (let "drec_349"
                      (let "dsum1_237" (let-pair "du16_fst_232" "du16_snd_233" (read-u16 little-endian (identifier "drec_snd_230")) (make-tup (identifier "du16_fst_232") (identifier "du16_snd_233")))
                        (let-pair "dsum1_fst_238" "dsum1_snd_239" (identifier "dsum1_237")
                          (if (eq (u16 0) (identifier "dsum1_fst_238"))
                            (let "drec_269" (let-pair "dchar_fst_267" "dchar_snd_268" (read-u8 (identifier "dsum1_snd_239")) (make-tup (char-of-u8 (identifier "dchar_fst_267")) (identifier "dchar_snd_268")))
                              (let-pair "drec_fst_270" "drec_snd_271" 
                                (identifier "drec_269")
                                (let "drec_284"
                                  (let "dstring1_278"
                                    (let "leb_ref_272" (make-vec (u32 0))
                                      (let "shft_ref_273" (make-vec (u8 0))
                                        (let "p_ref_274" (make-vec (identifier "drec_snd_271"))
                                          (seq
                                            (while
                                              (let "leb128_275" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_274")))
                                                (let-pair "leb128_fst_276" "leb128_snd_277" 
                                                  (identifier "leb128_275")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_274") (identifier "leb128_snd_277"))
                                                    (set-vec (u8 0) (identifier "leb_ref_272")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_276") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_273"))) (unsafe-nth (u8 0) (identifier "leb_ref_272"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_273") (add (unsafe-nth (u8 0) (identifier "shft_ref_273")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_276") (u8 128))))) 
                                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_272"))) (unsafe-nth (u8 0) (identifier "p_ref_274")))))))
                                    (let-pair "dstring1_fst_279" "dstring1_snd_280" 
                                      (identifier "dstring1_278")
                                      (let-pair "dstring2_fst_282" "dstring2_snd_283" 
                                        (read-bytes (identifier "dstring1_snd_280") (identifier "dstring1_fst_279")) 
                                        (make-tup (string-of-bytes (identifier "dstring2_fst_282")) (identifier "dstring2_snd_283")))))
                                  (let-pair "drec_fst_285" "drec_snd_286" 
                                    (identifier "drec_284")
                                    (let "drec_290" (let-pair "dbool_fst_288" "dbool_snd_289" (read-u8 (identifier "drec_snd_286")) (make-tup (not (eq (identifier "dbool_fst_288") (u8 0))) (identifier "dbool_snd_289")))
                                      (let-pair "drec_fst_291" "drec_snd_292" 
                                        (identifier "drec_290")
                                        (let "drec_305"
                                          (let "dstring1_299"
                                            (let "leb_ref_293" (make-vec (u32 0))
                                              (let "shft_ref_294" (make-vec (u8 0))
                                                (let "p_ref_295" (make-vec (identifier "drec_snd_292"))
                                                  (seq
                                                    (while
                                                      (let "leb128_296" 
                                                        (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_295")))
                                                        (let-pair "leb128_fst_297" "leb128_snd_298" 
                                                          (identifier "leb128_296")
                                                          (seq (set-vec (u8 0) (identifier "p_ref_295") (identifier "leb128_snd_298"))
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb_ref_293")
                                                              (bit-or 
                                                                (left-shift (to-u32 (bit-and (identifier "leb128_fst_297") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_294")))
                                                                (unsafe-nth (u8 0) (identifier "leb_ref_293")))) 
                                                            (set-vec (u8 0) (identifier "shft_ref_294") (add (unsafe-nth (u8 0) (identifier "shft_ref_294")) (u8 7))) 
                                                            (ge (identifier "leb128_fst_297") (u8 128))))) 
                                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_293"))) (unsafe-nth (u8 0) (identifier "p_ref_295")))))))
                                            (let-pair "dstring1_fst_300" "dstring1_snd_301" 
                                              (identifier "dstring1_299")
                                              (let-pair "dstring2_fst_303" "dstring2_snd_304" 
                                                (read-bytes (identifier "dstring1_snd_301") (identifier "dstring1_fst_300")) 
                                                (make-tup (string-of-bytes (identifier "dstring2_fst_303")) (identifier "dstring2_snd_304")))))
                                          (let-pair "drec_fst_306" "drec_snd_307" 
                                            (identifier "drec_305")
                                            (let "drec_331"
                                              (let-pair "dlist4_fst_329" "dlist4_snd_330"
                                                (let "dlist1_317"
                                                  (let "leb_ref_308" 
                                                    (make-vec (u32 0))
                                                    (let "shft_ref_309" 
                                                      (make-vec (u8 0))
                                                      (let "p_ref_310" 
                                                        (make-vec (identifier "drec_snd_307"))
                                                        (seq
                                                          (while
                                                            (let "leb128_311" 
                                                              (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_310")))
                                                              (let-pair "leb128_fst_312" "leb128_snd_313" 
                                                                (identifier "leb128_311")
                                                                (seq 
                                                                  (set-vec (u8 0) (identifier "p_ref_310") (identifier "leb128_snd_313"))
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_308")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_312") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_309")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_308")))) 
                                                                  (set-vec (u8 0) (identifier "shft_ref_309") (add (unsafe-nth (u8 0) (identifier "shft_ref_309")) (u8 7))) 
                                                                  (ge (identifier "leb128_fst_312") (u8 128))))) 
                                                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_308")) (unsafe-nth (u8 0) (identifier "p_ref_310")))))))
                                                  (let-pair "dlist1_fst_318" "dlist1_snd_319" 
                                                    (identifier "dlist1_317")
                                                    (let "inits_src_ref_320" 
                                                      (make-vec (make-tup (end-of-list "$field_type") (identifier "dlist1_snd_319")))
                                                      (seq
                                                        (let "repeat_n_321" 
                                                          (make-vec (i32 0))
                                                          (while (gt (to-i32 (identifier "dlist1_fst_318")) (unsafe-nth (u8 0) (identifier "repeat_n_321")))
                                                            (seq
                                                              (let "dlist2_322" 
                                                                (unsafe-nth (u8 0) (identifier "inits_src_ref_320"))
                                                                (let-pair "dlist2_fst_323" "dlist2_snd_324" 
                                                                  (identifier "dlist2_322")
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_320")
                                                                    (let-pair "dlist3_fst_326" "dlist3_snd_327" 
                                                                    (apply (ext-identifier field_type of-row-binary) (identifier "dlist2_snd_324"))
                                                                    (make-tup (cons (identifier "dlist3_fst_326") (identifier "dlist2_fst_323")) (identifier "dlist3_snd_327"))))))
                                                              (set-vec (u8 0) (identifier "repeat_n_321") (add (unsafe-nth (u8 0) (identifier "repeat_n_321")) (i32 1)))))) 
                                                        (unsafe-nth (u8 0) (identifier "inits_src_ref_320")))))) 
                                                (make-tup (identity (identifier "dlist4_fst_329")) (identifier "dlist4_snd_330")))
                                              (let-pair "drec_fst_332" "drec_snd_333" 
                                                (identifier "drec_331")
                                                (let "drec_337"
                                                  (let-pair "dbool_fst_335" "dbool_snd_336" (read-u8 (identifier "drec_snd_333")) (make-tup (not (eq (identifier "dbool_fst_335") (u8 0))) (identifier "dbool_snd_336")))
                                                  (let-pair "drec_fst_338" "drec_snd_339" 
                                                    (identifier "drec_337")
                                                    (let-pair "dbool_fst_341" "dbool_snd_342" 
                                                      (read-u8 (identifier "drec_snd_339"))
                                                      (make-tup
                                                        (construct "[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]" 0
                                                          (make-rec (string "separator") 
                                                            (identifier "drec_fst_270") 
                                                            (string "null") 
                                                            (identifier "drec_fst_285") 
                                                            (string "may_quote") 
                                                            (identifier "drec_fst_291") 
                                                            (string "escape_seq") 
                                                            (identifier "drec_fst_306") 
                                                            (string "fields") 
                                                            (identifier "drec_fst_332") 
                                                            (string "vectors_of_chars_as_string") 
                                                            (identifier "drec_fst_338") 
                                                            (string "clickhouse_syntax") 
                                                            (not (eq (identifier "dbool_fst_341") (u8 0))))) 
                                                        (identifier "dbool_snd_342")))))))))))))))
                            (seq (assert (eq (identifier "dsum1_fst_238") (u16 1)))
                              (let-pair "dlist4_fst_261" "dlist4_snd_262"
                                (let "dlist1_249"
                                  (let "leb_ref_240" (make-vec (u32 0))
                                    (let "shft_ref_241" (make-vec (u8 0))
                                      (let "p_ref_242" (make-vec (identifier "dsum1_snd_239"))
                                        (seq
                                          (while
                                            (let "leb128_243" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_242")))
                                              (let-pair "leb128_fst_244" "leb128_snd_245" 
                                                (identifier "leb128_243")
                                                (seq (set-vec (u8 0) (identifier "p_ref_242") (identifier "leb128_snd_245"))
                                                  (set-vec (u8 0) (identifier "leb_ref_240")
                                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_244") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_241"))) (unsafe-nth (u8 0) (identifier "leb_ref_240"))))
                                                  (set-vec (u8 0) (identifier "shft_ref_241") (add (unsafe-nth (u8 0) (identifier "shft_ref_241")) (u8 7))) 
                                                  (ge (identifier "leb128_fst_244") (u8 128))))) 
                                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_240")) (unsafe-nth (u8 0) (identifier "p_ref_242")))))))
                                  (let-pair "dlist1_fst_250" "dlist1_snd_251" 
                                    (identifier "dlist1_249")
                                    (let "inits_src_ref_252" (make-vec (make-tup (end-of-list "$field_type") (identifier "dlist1_snd_251")))
                                      (seq
                                        (let "repeat_n_253" (make-vec (i32 0))
                                          (while (gt (to-i32 (identifier "dlist1_fst_250")) (unsafe-nth (u8 0) (identifier "repeat_n_253")))
                                            (seq
                                              (let "dlist2_254" (unsafe-nth (u8 0) (identifier "inits_src_ref_252"))
                                                (let-pair "dlist2_fst_255" "dlist2_snd_256" 
                                                  (identifier "dlist2_254")
                                                  (set-vec (u8 0) (identifier "inits_src_ref_252")
                                                    (let-pair "dlist3_fst_258" "dlist3_snd_259" 
                                                      (apply (ext-identifier field_type of-row-binary) (identifier "dlist2_snd_256"))
                                                      (make-tup (cons (identifier "dlist3_fst_258") (identifier "dlist2_fst_255")) (identifier "dlist3_snd_259"))))))
                                              (set-vec (u8 0) (identifier "repeat_n_253") (add (unsafe-nth (u8 0) (identifier "repeat_n_253")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "inits_src_ref_252"))))))
                                (make-tup
                                  (construct "[CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]" 1
                                    (identity (identifier "dlist4_fst_261"))) 
                                  (identifier "dlist4_snd_262")))))))
                      (let-pair "drec_fst_350" "drec_snd_351" (identifier "drec_349")
                        (let "drec_355"
                          (if (eq (peek-u8 (identifier "drec_snd_351") (size 0)) (u8 1)) 
                            (make-tup (null "$event_time") (ptr-add (identifier "drec_snd_351") (size 1)))
                            (let-pair "make1_1_fst_353" "make1_1_snd_354" 
                              (apply (ext-identifier event_time of-row-binary) (ptr-add (identifier "drec_snd_351") (size 1))) 
                              (make-tup (not-null (identifier "make1_1_fst_353")) (identifier "make1_1_snd_354"))))
                          (let-pair "drec_fst_356" "drec_snd_357" (identifier "drec_355")
                            (let-pair "dlist4_fst_379" "dlist4_snd_380"
                              (let "dlist1_367"
                                (let "leb_ref_358" (make-vec (u32 0))
                                  (let "shft_ref_359" (make-vec (u8 0))
                                    (let "p_ref_360" (make-vec (identifier "drec_snd_357"))
                                      (seq
                                        (while
                                          (let "leb128_361" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_360")))
                                            (let-pair "leb128_fst_362" "leb128_snd_363" 
                                              (identifier "leb128_361")
                                              (seq (set-vec (u8 0) (identifier "p_ref_360") (identifier "leb128_snd_363"))
                                                (set-vec (u8 0) (identifier "leb_ref_358")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_362") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_359"))) (unsafe-nth (u8 0) (identifier "leb_ref_358"))))
                                                (set-vec (u8 0) (identifier "shft_ref_359") (add (unsafe-nth (u8 0) (identifier "shft_ref_359")) (u8 7))) 
                                                (ge (identifier "leb128_fst_362") (u8 128))))) 
                                          (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_358")) (unsafe-nth (u8 0) (identifier "p_ref_360")))))))
                                (let-pair "dlist1_fst_368" "dlist1_snd_369" 
                                  (identifier "dlist1_367")
                                  (let "inits_src_ref_370" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_369")))
                                    (seq
                                      (let "repeat_n_371" (make-vec (i32 0))
                                        (while (gt (to-i32 (identifier "dlist1_fst_368")) (unsafe-nth (u8 0) (identifier "repeat_n_371")))
                                          (seq
                                            (let "dlist2_372" (unsafe-nth (u8 0) (identifier "inits_src_ref_370"))
                                              (let-pair "dlist2_fst_373" "dlist2_snd_374" 
                                                (identifier "dlist2_372")
                                                (set-vec (u8 0) (identifier "inits_src_ref_370")
                                                  (let-pair "dlist3_fst_376" "dlist3_snd_377" 
                                                    (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_374"))
                                                    (make-tup (cons (identifier "dlist3_fst_376") (identifier "dlist2_fst_373")) (identifier "dlist3_snd_377"))))))
                                            (set-vec (u8 0) (identifier "repeat_n_371") (add (unsafe-nth (u8 0) (identifier "repeat_n_371")) (i32 1)))))) 
                                      (unsafe-nth (u8 0) (identifier "inits_src_ref_370"))))))
                              (make-tup
                                (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS][[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]; format: [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]; event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" 1
                                  (make-rec (string "source") (identifier "drec_fst_229") 
                                    (string "format") (identifier "drec_fst_350") 
                                    (string "event_time") (identifier "drec_fst_356") 
                                    (string "factors") (identity (identifier "dlist4_fst_379")))) 
                                (identifier "dlist4_snd_380")))))))))
                (seq (assert (eq (identifier "dsum1_fst_63") (u16 2)))
                  (let "drec_77"
                    (let "dstring1_71"
                      (let "leb_ref_65" (make-vec (u32 0))
                        (let "shft_ref_66" (make-vec (u8 0))
                          (let "p_ref_67" (make-vec (identifier "dsum1_snd_64"))
                            (seq
                              (while
                                (let "leb128_68" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_67")))
                                  (let-pair "leb128_fst_69" "leb128_snd_70" 
                                    (identifier "leb128_68")
                                    (seq (set-vec (u8 0) (identifier "p_ref_67") (identifier "leb128_snd_70"))
                                      (set-vec (u8 0) (identifier "leb_ref_65")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_69") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_66"))) (unsafe-nth (u8 0) (identifier "leb_ref_65"))))
                                      (set-vec (u8 0) (identifier "shft_ref_66") (add (unsafe-nth (u8 0) (identifier "shft_ref_66")) (u8 7))) 
                                      (ge (identifier "leb128_fst_69") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_65"))) (unsafe-nth (u8 0) (identifier "p_ref_67")))))))
                      (let-pair "dstring1_fst_72" "dstring1_snd_73" (identifier "dstring1_71")
                        (let-pair "dstring2_fst_75" "dstring2_snd_76" 
                          (read-bytes (identifier "dstring1_snd_73") (identifier "dstring1_fst_72")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_75")) (identifier "dstring2_snd_76")))))
                    (let-pair "drec_fst_78" "drec_snd_79" (identifier "drec_77")
                      (let "drec_83" (let-pair "du16_fst_81" "du16_snd_82" (read-u16 little-endian (identifier "drec_snd_79")) (make-tup (identifier "du16_fst_81") (identifier "du16_snd_82")))
                        (let-pair "drec_fst_84" "drec_snd_85" (identifier "drec_83")
                          (let "drec_86" (apply (ext-identifier raql_net_protocol of-row-binary) (identifier "drec_snd_85"))
                            (let-pair "drec_fst_87" "drec_snd_88" (identifier "drec_86")
                              (let-pair "dlist4_fst_110" "dlist4_snd_111"
                                (let "dlist1_98"
                                  (let "leb_ref_89" (make-vec (u32 0))
                                    (let "shft_ref_90" (make-vec (u8 0))
                                      (let "p_ref_91" (make-vec (identifier "drec_snd_88"))
                                        (seq
                                          (while
                                            (let "leb128_92" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_91")))
                                              (let-pair "leb128_fst_93" "leb128_snd_94" 
                                                (identifier "leb128_92")
                                                (seq (set-vec (u8 0) (identifier "p_ref_91") (identifier "leb128_snd_94"))
                                                  (set-vec (u8 0) (identifier "leb_ref_89")
                                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_93") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_90"))) (unsafe-nth (u8 0) (identifier "leb_ref_89"))))
                                                  (set-vec (u8 0) (identifier "shft_ref_90") (add (unsafe-nth (u8 0) (identifier "shft_ref_90")) (u8 7))) 
                                                  (ge (identifier "leb128_fst_93") (u8 128))))) 
                                            (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_89")) (unsafe-nth (u8 0) (identifier "p_ref_91")))))))
                                  (let-pair "dlist1_fst_99" "dlist1_snd_100" 
                                    (identifier "dlist1_98")
                                    (let "inits_src_ref_101" (make-vec (make-tup (end-of-list "$field_name") (identifier "dlist1_snd_100")))
                                      (seq
                                        (let "repeat_n_102" (make-vec (i32 0))
                                          (while (gt (to-i32 (identifier "dlist1_fst_99")) (unsafe-nth (u8 0) (identifier "repeat_n_102")))
                                            (seq
                                              (let "dlist2_103" (unsafe-nth (u8 0) (identifier "inits_src_ref_101"))
                                                (let-pair "dlist2_fst_104" "dlist2_snd_105" 
                                                  (identifier "dlist2_103")
                                                  (set-vec (u8 0) (identifier "inits_src_ref_101")
                                                    (let-pair "dlist3_fst_107" "dlist3_snd_108" 
                                                      (apply (ext-identifier field_name of-row-binary) (identifier "dlist2_snd_105"))
                                                      (make-tup (cons (identifier "dlist3_fst_107") (identifier "dlist2_fst_104")) (identifier "dlist3_snd_108"))))))
                                              (set-vec (u8 0) (identifier "repeat_n_102") (add (unsafe-nth (u8 0) (identifier "repeat_n_102")) (i32 1)))))) 
                                        (unsafe-nth (u8 0) (identifier "inits_src_ref_101"))))))
                                (make-tup
                                  (construct "[Aggregate {fields: $raql_select_field[[]]; and_all_others: $field_name[[]]?; sort: (U32; $raql_expr?; $raql_expr[[]])?; where: $raql_expr; event_time: $event_time?; notifications: $raql_expr[[]]; key: $raql_expr[[]]; commit_cond: $raql_expr; commit_before: BOOL; flush_how: $raql_flush_method; from: [NamedOperation ([AllSites Void | TheseSites STRING | ThisSite Void]; STRING?; $function_name) | SubQuery THIS][[]]; every: $raql_expr?; factors: $field_name[[]]} | ReadExternal {source: [File {fname: $raql_expr; preprocessor: $raql_expr?; unlink: $raql_expr} | Kafka {options: (STRING; $raql_expr)[[]]; topic: $raql_expr; partitions: $raql_expr?; restart_from: [Beginning Void | OffsetFromEnd $raql_expr | SaveInState Void | UseKafkaGroupCoordinator {after_max_secs: $raql_expr; after_max_events: $raql_expr}]}]; format: [CSV {separator: CHAR; null: STRING; may_quote: BOOL; escape_seq: STRING; fields: $field_type[[]]; vectors_of_chars_as_string: BOOL; clickhouse_syntax: BOOL} | RowBinary $field_type[[]]]; event_time: $event_time?; factors: $field_name[[]]} | ListenFor {net_addr: STRING; port: U16; proto: $raql_net_protocol; factors: $field_name[[]]}]" 2
                                    (make-rec (string "net_addr") (identifier "drec_fst_78") 
                                      (string "port") (identifier "drec_fst_84") 
                                      (string "proto") (identifier "drec_fst_87") 
                                      (string "factors") (identity (identifier "dlist4_fst_110")))) 
                                  (identifier "dlist4_snd_111")))))))))))))) 
        (make-tup (identifier "make_fst_690") (identifier "make_snd_691"))))
 */
static std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary_init()
{
  std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> fun2628 { [&fun2628](Pointer p_0) {
    t22a32080ad88ab548b80077a17b7dd46 id_2629 { p_0.readU16Le() };
    t22a32080ad88ab548b80077a17b7dd46 letpair_res_2630;
    {
      auto du16_fst_57 { std::get<0>(id_2629) };
      auto du16_snd_58 { std::get<1>(id_2629) };
      t22a32080ad88ab548b80077a17b7dd46 id_2631 { du16_fst_57, du16_snd_58 };
      letpair_res_2630 = id_2631;
    }
    t45217dce3db5a9a49037839afd0048e8 let_res_2632;
    {
      t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_2630 };
      t45217dce3db5a9a49037839afd0048e8 letpair_res_2633;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_2634 { 0 };
        bool id_2635 { bool(id_2634 == dsum1_fst_63) };
        t45217dce3db5a9a49037839afd0048e8 choose_res_2636;
        if (id_2635) {
          uint32_t id_2637 { 0U };
          Vec<1, uint32_t> id_2638 {  id_2637  };
          t405eb186408556fed8f2c41523c07d13 let_res_2639;
          {
            Vec<1, uint32_t> leb_ref_387 { id_2638 };
            uint8_t id_2640 { 0 };
            Vec<1, uint8_t> id_2641 {  id_2640  };
            t405eb186408556fed8f2c41523c07d13 let_res_2642;
            {
              Vec<1, uint8_t> shft_ref_388 { id_2641 };
              Vec<1, Pointer> id_2643 {  dsum1_snd_64  };
              t405eb186408556fed8f2c41523c07d13 let_res_2644;
              {
                Vec<1, Pointer> p_ref_389 { id_2643 };
                bool while_flag_2645 { true };
                do {
                  uint8_t id_2646 { 0 };
                  Pointer id_2647 { p_ref_389[id_2646] };
                  tb3f98ea670610d40658a618de3ec7b90 id_2648 { id_2647.readU8() };
                  bool let_res_2649;
                  {
                    tb3f98ea670610d40658a618de3ec7b90 leb128_390 { id_2648 };
                    bool letpair_res_2650;
                    {
                      auto leb128_fst_391 { std::get<0>(leb128_390) };
                      auto leb128_snd_392 { std::get<1>(leb128_390) };
                      uint8_t id_2651 { 0 };
                      Void id_2652 { ((void)(p_ref_389[id_2651] = leb128_snd_392), VOID) };
                      (void)id_2652;
                      uint8_t id_2653 { 0 };
                      uint8_t id_2654 { 127 };
                      uint8_t id_2655 { uint8_t(leb128_fst_391 & id_2654) };
                      uint32_t id_2656 { uint32_t(id_2655) };
                      uint8_t id_2657 { 0 };
                      uint8_t id_2658 { shft_ref_388[id_2657] };
                      uint32_t id_2659 { uint32_t(id_2656 << id_2658) };
                      uint8_t id_2660 { 0 };
                      uint32_t id_2661 { leb_ref_387[id_2660] };
                      uint32_t id_2662 { uint32_t(id_2659 | id_2661) };
                      Void id_2663 { ((void)(leb_ref_387[id_2653] = id_2662), VOID) };
                      (void)id_2663;
                      uint8_t id_2664 { 0 };
                      uint8_t id_2665 { 0 };
                      uint8_t id_2666 { shft_ref_388[id_2665] };
                      uint8_t id_2667 { 7 };
                      uint8_t id_2668 { uint8_t(id_2666 + id_2667) };
                      Void id_2669 { ((void)(shft_ref_388[id_2664] = id_2668), VOID) };
                      (void)id_2669;
                      uint8_t id_2670 { 128 };
                      bool id_2671 { bool(leb128_fst_391 >= id_2670) };
                      letpair_res_2650 = id_2671;
                    }
                    let_res_2649 = letpair_res_2650;
                  }
                  while_flag_2645 = let_res_2649;
                  if (while_flag_2645) {
                    (void)VOID;
                  }
                } while (while_flag_2645);
                (void)VOID;
                uint8_t id_2672 { 0 };
                uint32_t id_2673 { leb_ref_387[id_2672] };
                uint8_t id_2674 { 0 };
                Pointer id_2675 { p_ref_389[id_2674] };
                t405eb186408556fed8f2c41523c07d13 id_2676 { id_2673, id_2675 };
                let_res_2644 = id_2676;
              }
              let_res_2642 = let_res_2644;
            }
            let_res_2639 = let_res_2642;
          }
          ta9047710b0a6cdbb6cf02e2ae071242e let_res_2677;
          {
            t405eb186408556fed8f2c41523c07d13 dlist1_396 { let_res_2639 };
            ta9047710b0a6cdbb6cf02e2ae071242e letpair_res_2678;
            {
              auto dlist1_fst_397 { std::get<0>(dlist1_396) };
              auto dlist1_snd_398 { std::get<1>(dlist1_396) };
              Lst<dessser::gen::raql_select_field::t_ext> endoflist_2679;
              ta9047710b0a6cdbb6cf02e2ae071242e id_2680 { endoflist_2679, dlist1_snd_398 };
              Vec<1, ta9047710b0a6cdbb6cf02e2ae071242e> id_2681 {  id_2680  };
              ta9047710b0a6cdbb6cf02e2ae071242e let_res_2682;
              {
                Vec<1, ta9047710b0a6cdbb6cf02e2ae071242e> inits_src_ref_399 { id_2681 };
                int32_t id_2683 { 0L };
                Vec<1, int32_t> id_2684 {  id_2683  };
                {
                  Vec<1, int32_t> repeat_n_400 { id_2684 };
                  bool while_flag_2685 { true };
                  do {
                    int32_t id_2686 { int32_t(dlist1_fst_397) };
                    uint8_t id_2687 { 0 };
                    int32_t id_2688 { repeat_n_400[id_2687] };
                    bool id_2689 { bool(id_2686 > id_2688) };
                    while_flag_2685 = id_2689;
                    if (while_flag_2685) {
                      uint8_t id_2690 { 0 };
                      ta9047710b0a6cdbb6cf02e2ae071242e id_2691 { inits_src_ref_399[id_2690] };
                      {
                        ta9047710b0a6cdbb6cf02e2ae071242e dlist2_401 { id_2691 };
                        {
                          auto dlist2_fst_402 { std::get<0>(dlist2_401) };
                          auto dlist2_snd_403 { std::get<1>(dlist2_401) };
                          uint8_t id_2692 { 0 };
                          auto fun2693 { dessser::gen::raql_select_field::of_row_binary };
                          t385fc99bd06c53216a5de778dea0dc6e id_2694 { fun2693(dlist2_snd_403) };
                          ta9047710b0a6cdbb6cf02e2ae071242e letpair_res_2695;
                          {
                            auto dlist3_fst_405 { std::get<0>(id_2694) };
                            auto dlist3_snd_406 { std::get<1>(id_2694) };
                            Lst<dessser::gen::raql_select_field::t_ext> id_2696 { dlist3_fst_405, dlist2_fst_402 };
                            ta9047710b0a6cdbb6cf02e2ae071242e id_2697 { id_2696, dlist3_snd_406 };
                            letpair_res_2695 = id_2697;
                          }
                          Void id_2698 { ((void)(inits_src_ref_399[id_2692] = letpair_res_2695), VOID) };
                          (void)id_2698;
                        }
                        (void)VOID;
                      }
                      (void)VOID;
                      uint8_t id_2699 { 0 };
                      uint8_t id_2700 { 0 };
                      int32_t id_2701 { repeat_n_400[id_2700] };
                      int32_t id_2702 { 1L };
                      int32_t id_2703 { int32_t(id_2701 + id_2702) };
                      Void id_2704 { ((void)(repeat_n_400[id_2699] = id_2703), VOID) };
                      (void)id_2704;
                      (void)id_2704;
                    }
                  } while (while_flag_2685);
                  (void)VOID;
                }
                (void)VOID;
                uint8_t id_2705 { 0 };
                ta9047710b0a6cdbb6cf02e2ae071242e id_2706 { inits_src_ref_399[id_2705] };
                let_res_2682 = id_2706;
              }
              letpair_res_2678 = let_res_2682;
            }
            let_res_2677 = letpair_res_2678;
          }
          ta9047710b0a6cdbb6cf02e2ae071242e letpair_res_2707;
          {
            auto dlist4_fst_408 { std::get<0>(let_res_2677) };
            auto dlist4_snd_409 { std::get<1>(let_res_2677) };
            ta9047710b0a6cdbb6cf02e2ae071242e id_2708 { dlist4_fst_408, dlist4_snd_409 };
            letpair_res_2707 = id_2708;
          }
          t45217dce3db5a9a49037839afd0048e8 let_res_2709;
          {
            ta9047710b0a6cdbb6cf02e2ae071242e drec_410 { letpair_res_2707 };
            t45217dce3db5a9a49037839afd0048e8 letpair_res_2710;
            {
              auto drec_fst_411 { std::get<0>(drec_410) };
              auto drec_snd_412 { std::get<1>(drec_410) };
              Size id_2711 { 0UL };
              uint8_t id_2712 { drec_snd_412.peekU8(id_2711) };
              uint8_t id_2713 { 1 };
              bool id_2714 { bool(id_2712 == id_2713) };
              t885b8962b524dff3368f7a529f1d466b choose_res_2715;
              if (id_2714) {
                std::optional<Lst<dessser::gen::field_name::t_ext>> id_2716 { std::nullopt };
                Size id_2717 { 1UL };
                Pointer id_2718 { drec_snd_412.skip(id_2717) };
                t885b8962b524dff3368f7a529f1d466b id_2719 { id_2716, id_2718 };
                choose_res_2715 = id_2719;
              } else {
                uint32_t id_2720 { 0U };
                Vec<1, uint32_t> id_2721 {  id_2720  };
                t405eb186408556fed8f2c41523c07d13 let_res_2722;
                {
                  Vec<1, uint32_t> leb_ref_413 { id_2721 };
                  uint8_t id_2723 { 0 };
                  Vec<1, uint8_t> id_2724 {  id_2723  };
                  t405eb186408556fed8f2c41523c07d13 let_res_2725;
                  {
                    Vec<1, uint8_t> shft_ref_414 { id_2724 };
                    Size id_2726 { 1UL };
                    Pointer id_2727 { drec_snd_412.skip(id_2726) };
                    Vec<1, Pointer> id_2728 {  id_2727  };
                    t405eb186408556fed8f2c41523c07d13 let_res_2729;
                    {
                      Vec<1, Pointer> p_ref_415 { id_2728 };
                      bool while_flag_2730 { true };
                      do {
                        uint8_t id_2731 { 0 };
                        Pointer id_2732 { p_ref_415[id_2731] };
                        tb3f98ea670610d40658a618de3ec7b90 id_2733 { id_2732.readU8() };
                        bool let_res_2734;
                        {
                          tb3f98ea670610d40658a618de3ec7b90 leb128_416 { id_2733 };
                          bool letpair_res_2735;
                          {
                            auto leb128_fst_417 { std::get<0>(leb128_416) };
                            auto leb128_snd_418 { std::get<1>(leb128_416) };
                            uint8_t id_2736 { 0 };
                            Void id_2737 { ((void)(p_ref_415[id_2736] = leb128_snd_418), VOID) };
                            (void)id_2737;
                            uint8_t id_2738 { 0 };
                            uint8_t id_2739 { 127 };
                            uint8_t id_2740 { uint8_t(leb128_fst_417 & id_2739) };
                            uint32_t id_2741 { uint32_t(id_2740) };
                            uint8_t id_2742 { 0 };
                            uint8_t id_2743 { shft_ref_414[id_2742] };
                            uint32_t id_2744 { uint32_t(id_2741 << id_2743) };
                            uint8_t id_2745 { 0 };
                            uint32_t id_2746 { leb_ref_413[id_2745] };
                            uint32_t id_2747 { uint32_t(id_2744 | id_2746) };
                            Void id_2748 { ((void)(leb_ref_413[id_2738] = id_2747), VOID) };
                            (void)id_2748;
                            uint8_t id_2749 { 0 };
                            uint8_t id_2750 { 0 };
                            uint8_t id_2751 { shft_ref_414[id_2750] };
                            uint8_t id_2752 { 7 };
                            uint8_t id_2753 { uint8_t(id_2751 + id_2752) };
                            Void id_2754 { ((void)(shft_ref_414[id_2749] = id_2753), VOID) };
                            (void)id_2754;
                            uint8_t id_2755 { 128 };
                            bool id_2756 { bool(leb128_fst_417 >= id_2755) };
                            letpair_res_2735 = id_2756;
                          }
                          let_res_2734 = letpair_res_2735;
                        }
                        while_flag_2730 = let_res_2734;
                        if (while_flag_2730) {
                          (void)VOID;
                        }
                      } while (while_flag_2730);
                      (void)VOID;
                      uint8_t id_2757 { 0 };
                      uint32_t id_2758 { leb_ref_413[id_2757] };
                      uint8_t id_2759 { 0 };
                      Pointer id_2760 { p_ref_415[id_2759] };
                      t405eb186408556fed8f2c41523c07d13 id_2761 { id_2758, id_2760 };
                      let_res_2729 = id_2761;
                    }
                    let_res_2725 = let_res_2729;
                  }
                  let_res_2722 = let_res_2725;
                }
                t0dfa866705b76efff53e4aa97228a967 let_res_2762;
                {
                  t405eb186408556fed8f2c41523c07d13 dlist1_422 { let_res_2722 };
                  t0dfa866705b76efff53e4aa97228a967 letpair_res_2763;
                  {
                    auto dlist1_fst_423 { std::get<0>(dlist1_422) };
                    auto dlist1_snd_424 { std::get<1>(dlist1_422) };
                    Lst<dessser::gen::field_name::t_ext> endoflist_2764;
                    t0dfa866705b76efff53e4aa97228a967 id_2765 { endoflist_2764, dlist1_snd_424 };
                    Vec<1, t0dfa866705b76efff53e4aa97228a967> id_2766 {  id_2765  };
                    t0dfa866705b76efff53e4aa97228a967 let_res_2767;
                    {
                      Vec<1, t0dfa866705b76efff53e4aa97228a967> inits_src_ref_425 { id_2766 };
                      int32_t id_2768 { 0L };
                      Vec<1, int32_t> id_2769 {  id_2768  };
                      {
                        Vec<1, int32_t> repeat_n_426 { id_2769 };
                        bool while_flag_2770 { true };
                        do {
                          int32_t id_2771 { int32_t(dlist1_fst_423) };
                          uint8_t id_2772 { 0 };
                          int32_t id_2773 { repeat_n_426[id_2772] };
                          bool id_2774 { bool(id_2771 > id_2773) };
                          while_flag_2770 = id_2774;
                          if (while_flag_2770) {
                            uint8_t id_2775 { 0 };
                            t0dfa866705b76efff53e4aa97228a967 id_2776 { inits_src_ref_425[id_2775] };
                            {
                              t0dfa866705b76efff53e4aa97228a967 dlist2_427 { id_2776 };
                              {
                                auto dlist2_fst_428 { std::get<0>(dlist2_427) };
                                auto dlist2_snd_429 { std::get<1>(dlist2_427) };
                                uint8_t id_2777 { 0 };
                                auto fun2778 { dessser::gen::field_name::of_row_binary };
                                t273a2b7978f5b466a128a51c1cc4a27b id_2779 { fun2778(dlist2_snd_429) };
                                t0dfa866705b76efff53e4aa97228a967 letpair_res_2780;
                                {
                                  auto dlist3_fst_431 { std::get<0>(id_2779) };
                                  auto dlist3_snd_432 { std::get<1>(id_2779) };
                                  Lst<dessser::gen::field_name::t_ext> id_2781 { dlist3_fst_431, dlist2_fst_428 };
                                  t0dfa866705b76efff53e4aa97228a967 id_2782 { id_2781, dlist3_snd_432 };
                                  letpair_res_2780 = id_2782;
                                }
                                Void id_2783 { ((void)(inits_src_ref_425[id_2777] = letpair_res_2780), VOID) };
                                (void)id_2783;
                              }
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_2784 { 0 };
                            uint8_t id_2785 { 0 };
                            int32_t id_2786 { repeat_n_426[id_2785] };
                            int32_t id_2787 { 1L };
                            int32_t id_2788 { int32_t(id_2786 + id_2787) };
                            Void id_2789 { ((void)(repeat_n_426[id_2784] = id_2788), VOID) };
                            (void)id_2789;
                            (void)id_2789;
                          }
                        } while (while_flag_2770);
                        (void)VOID;
                      }
                      (void)VOID;
                      uint8_t id_2790 { 0 };
                      t0dfa866705b76efff53e4aa97228a967 id_2791 { inits_src_ref_425[id_2790] };
                      let_res_2767 = id_2791;
                    }
                    letpair_res_2763 = let_res_2767;
                  }
                  let_res_2762 = letpair_res_2763;
                }
                t885b8962b524dff3368f7a529f1d466b letpair_res_2792;
                {
                  auto dlist4_fst_434 { std::get<0>(let_res_2762) };
                  auto dlist4_snd_435 { std::get<1>(let_res_2762) };
                  std::optional<Lst<dessser::gen::field_name::t_ext>> id_2793 { dlist4_fst_434 };
                  t885b8962b524dff3368f7a529f1d466b id_2794 { id_2793, dlist4_snd_435 };
                  letpair_res_2792 = id_2794;
                }
                choose_res_2715 = letpair_res_2792;
              }
              t45217dce3db5a9a49037839afd0048e8 let_res_2795;
              {
                t885b8962b524dff3368f7a529f1d466b drec_439 { choose_res_2715 };
                t45217dce3db5a9a49037839afd0048e8 letpair_res_2796;
                {
                  auto drec_fst_440 { std::get<0>(drec_439) };
                  auto drec_snd_441 { std::get<1>(drec_439) };
                  Size id_2797 { 0UL };
                  uint8_t id_2798 { drec_snd_441.peekU8(id_2797) };
                  uint8_t id_2799 { 1 };
                  bool id_2800 { bool(id_2798 == id_2799) };
                  t3b4feade6f60da4ba5d645f756688083 choose_res_2801;
                  if (id_2800) {
                    std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_2802 { std::nullopt };
                    Size id_2803 { 1UL };
                    Pointer id_2804 { drec_snd_441.skip(id_2803) };
                    t3b4feade6f60da4ba5d645f756688083 id_2805 { id_2802, id_2804 };
                    choose_res_2801 = id_2805;
                  } else {
                    Size id_2806 { 1UL };
                    Pointer id_2807 { drec_snd_441.skip(id_2806) };
                    t405eb186408556fed8f2c41523c07d13 id_2808 { id_2807.readU32Le() };
                    t405eb186408556fed8f2c41523c07d13 letpair_res_2809;
                    {
                      auto du32_fst_443 { std::get<0>(id_2808) };
                      auto du32_snd_444 { std::get<1>(id_2808) };
                      t405eb186408556fed8f2c41523c07d13 id_2810 { du32_fst_443, du32_snd_444 };
                      letpair_res_2809 = id_2810;
                    }
                    t3b4feade6f60da4ba5d645f756688083 let_res_2811;
                    {
                      t405eb186408556fed8f2c41523c07d13 dtup_445 { letpair_res_2809 };
                      t3b4feade6f60da4ba5d645f756688083 letpair_res_2812;
                      {
                        auto dtup_fst_446 { std::get<0>(dtup_445) };
                        auto dtup_snd_447 { std::get<1>(dtup_445) };
                        Size id_2813 { 0UL };
                        uint8_t id_2814 { dtup_snd_447.peekU8(id_2813) };
                        uint8_t id_2815 { 1 };
                        bool id_2816 { bool(id_2814 == id_2815) };
                        tf1063a6af8c1fb72f0e0ee089d43d040 choose_res_2817;
                        if (id_2816) {
                          std::optional<dessser::gen::raql_expr::t_ext> id_2818 { std::nullopt };
                          Size id_2819 { 1UL };
                          Pointer id_2820 { dtup_snd_447.skip(id_2819) };
                          tf1063a6af8c1fb72f0e0ee089d43d040 id_2821 { id_2818, id_2820 };
                          choose_res_2817 = id_2821;
                        } else {
                          auto fun2822 { dessser::gen::raql_expr::of_row_binary };
                          Size id_2823 { 1UL };
                          Pointer id_2824 { dtup_snd_447.skip(id_2823) };
                          t1113e6691818baaf60a775527f6cc1ac id_2825 { fun2822(id_2824) };
                          tf1063a6af8c1fb72f0e0ee089d43d040 letpair_res_2826;
                          {
                            auto make1_1_fst_449 { std::get<0>(id_2825) };
                            auto make1_1_snd_450 { std::get<1>(id_2825) };
                            std::optional<dessser::gen::raql_expr::t_ext> id_2827 { make1_1_fst_449 };
                            tf1063a6af8c1fb72f0e0ee089d43d040 id_2828 { id_2827, make1_1_snd_450 };
                            letpair_res_2826 = id_2828;
                          }
                          choose_res_2817 = letpair_res_2826;
                        }
                        t3b4feade6f60da4ba5d645f756688083 let_res_2829;
                        {
                          tf1063a6af8c1fb72f0e0ee089d43d040 dtup_451 { choose_res_2817 };
                          t3b4feade6f60da4ba5d645f756688083 letpair_res_2830;
                          {
                            auto dtup_fst_452 { std::get<0>(dtup_451) };
                            auto dtup_snd_453 { std::get<1>(dtup_451) };
                            uint32_t id_2831 { 0U };
                            Vec<1, uint32_t> id_2832 {  id_2831  };
                            t405eb186408556fed8f2c41523c07d13 let_res_2833;
                            {
                              Vec<1, uint32_t> leb_ref_454 { id_2832 };
                              uint8_t id_2834 { 0 };
                              Vec<1, uint8_t> id_2835 {  id_2834  };
                              t405eb186408556fed8f2c41523c07d13 let_res_2836;
                              {
                                Vec<1, uint8_t> shft_ref_455 { id_2835 };
                                Vec<1, Pointer> id_2837 {  dtup_snd_453  };
                                t405eb186408556fed8f2c41523c07d13 let_res_2838;
                                {
                                  Vec<1, Pointer> p_ref_456 { id_2837 };
                                  bool while_flag_2839 { true };
                                  do {
                                    uint8_t id_2840 { 0 };
                                    Pointer id_2841 { p_ref_456[id_2840] };
                                    tb3f98ea670610d40658a618de3ec7b90 id_2842 { id_2841.readU8() };
                                    bool let_res_2843;
                                    {
                                      tb3f98ea670610d40658a618de3ec7b90 leb128_457 { id_2842 };
                                      bool letpair_res_2844;
                                      {
                                        auto leb128_fst_458 { std::get<0>(leb128_457) };
                                        auto leb128_snd_459 { std::get<1>(leb128_457) };
                                        uint8_t id_2845 { 0 };
                                        Void id_2846 { ((void)(p_ref_456[id_2845] = leb128_snd_459), VOID) };
                                        (void)id_2846;
                                        uint8_t id_2847 { 0 };
                                        uint8_t id_2848 { 127 };
                                        uint8_t id_2849 { uint8_t(leb128_fst_458 & id_2848) };
                                        uint32_t id_2850 { uint32_t(id_2849) };
                                        uint8_t id_2851 { 0 };
                                        uint8_t id_2852 { shft_ref_455[id_2851] };
                                        uint32_t id_2853 { uint32_t(id_2850 << id_2852) };
                                        uint8_t id_2854 { 0 };
                                        uint32_t id_2855 { leb_ref_454[id_2854] };
                                        uint32_t id_2856 { uint32_t(id_2853 | id_2855) };
                                        Void id_2857 { ((void)(leb_ref_454[id_2847] = id_2856), VOID) };
                                        (void)id_2857;
                                        uint8_t id_2858 { 0 };
                                        uint8_t id_2859 { 0 };
                                        uint8_t id_2860 { shft_ref_455[id_2859] };
                                        uint8_t id_2861 { 7 };
                                        uint8_t id_2862 { uint8_t(id_2860 + id_2861) };
                                        Void id_2863 { ((void)(shft_ref_455[id_2858] = id_2862), VOID) };
                                        (void)id_2863;
                                        uint8_t id_2864 { 128 };
                                        bool id_2865 { bool(leb128_fst_458 >= id_2864) };
                                        letpair_res_2844 = id_2865;
                                      }
                                      let_res_2843 = letpair_res_2844;
                                    }
                                    while_flag_2839 = let_res_2843;
                                    if (while_flag_2839) {
                                      (void)VOID;
                                    }
                                  } while (while_flag_2839);
                                  (void)VOID;
                                  uint8_t id_2866 { 0 };
                                  uint32_t id_2867 { leb_ref_454[id_2866] };
                                  uint8_t id_2868 { 0 };
                                  Pointer id_2869 { p_ref_456[id_2868] };
                                  t405eb186408556fed8f2c41523c07d13 id_2870 { id_2867, id_2869 };
                                  let_res_2838 = id_2870;
                                }
                                let_res_2836 = let_res_2838;
                              }
                              let_res_2833 = let_res_2836;
                            }
                            t0067a338c0fc91b6a811c8df70d4c87a let_res_2871;
                            {
                              t405eb186408556fed8f2c41523c07d13 dlist1_463 { let_res_2833 };
                              t0067a338c0fc91b6a811c8df70d4c87a letpair_res_2872;
                              {
                                auto dlist1_fst_464 { std::get<0>(dlist1_463) };
                                auto dlist1_snd_465 { std::get<1>(dlist1_463) };
                                Lst<dessser::gen::raql_expr::t_ext> endoflist_2873;
                                t0067a338c0fc91b6a811c8df70d4c87a id_2874 { endoflist_2873, dlist1_snd_465 };
                                Vec<1, t0067a338c0fc91b6a811c8df70d4c87a> id_2875 {  id_2874  };
                                t0067a338c0fc91b6a811c8df70d4c87a let_res_2876;
                                {
                                  Vec<1, t0067a338c0fc91b6a811c8df70d4c87a> inits_src_ref_466 { id_2875 };
                                  int32_t id_2877 { 0L };
                                  Vec<1, int32_t> id_2878 {  id_2877  };
                                  {
                                    Vec<1, int32_t> repeat_n_467 { id_2878 };
                                    bool while_flag_2879 { true };
                                    do {
                                      int32_t id_2880 { int32_t(dlist1_fst_464) };
                                      uint8_t id_2881 { 0 };
                                      int32_t id_2882 { repeat_n_467[id_2881] };
                                      bool id_2883 { bool(id_2880 > id_2882) };
                                      while_flag_2879 = id_2883;
                                      if (while_flag_2879) {
                                        uint8_t id_2884 { 0 };
                                        t0067a338c0fc91b6a811c8df70d4c87a id_2885 { inits_src_ref_466[id_2884] };
                                        {
                                          t0067a338c0fc91b6a811c8df70d4c87a dlist2_468 { id_2885 };
                                          {
                                            auto dlist2_fst_469 { std::get<0>(dlist2_468) };
                                            auto dlist2_snd_470 { std::get<1>(dlist2_468) };
                                            uint8_t id_2886 { 0 };
                                            auto fun2887 { dessser::gen::raql_expr::of_row_binary };
                                            t1113e6691818baaf60a775527f6cc1ac id_2888 { fun2887(dlist2_snd_470) };
                                            t0067a338c0fc91b6a811c8df70d4c87a letpair_res_2889;
                                            {
                                              auto dlist3_fst_472 { std::get<0>(id_2888) };
                                              auto dlist3_snd_473 { std::get<1>(id_2888) };
                                              Lst<dessser::gen::raql_expr::t_ext> id_2890 { dlist3_fst_472, dlist2_fst_469 };
                                              t0067a338c0fc91b6a811c8df70d4c87a id_2891 { id_2890, dlist3_snd_473 };
                                              letpair_res_2889 = id_2891;
                                            }
                                            Void id_2892 { ((void)(inits_src_ref_466[id_2886] = letpair_res_2889), VOID) };
                                            (void)id_2892;
                                          }
                                          (void)VOID;
                                        }
                                        (void)VOID;
                                        uint8_t id_2893 { 0 };
                                        uint8_t id_2894 { 0 };
                                        int32_t id_2895 { repeat_n_467[id_2894] };
                                        int32_t id_2896 { 1L };
                                        int32_t id_2897 { int32_t(id_2895 + id_2896) };
                                        Void id_2898 { ((void)(repeat_n_467[id_2893] = id_2897), VOID) };
                                        (void)id_2898;
                                        (void)id_2898;
                                      }
                                    } while (while_flag_2879);
                                    (void)VOID;
                                  }
                                  (void)VOID;
                                  uint8_t id_2899 { 0 };
                                  t0067a338c0fc91b6a811c8df70d4c87a id_2900 { inits_src_ref_466[id_2899] };
                                  let_res_2876 = id_2900;
                                }
                                letpair_res_2872 = let_res_2876;
                              }
                              let_res_2871 = letpair_res_2872;
                            }
                            t3b4feade6f60da4ba5d645f756688083 letpair_res_2901;
                            {
                              auto dlist4_fst_475 { std::get<0>(let_res_2871) };
                              auto dlist4_snd_476 { std::get<1>(let_res_2871) };
                              tf0c8d4f3070907529cc1a83f8baf6fab id_2902 { dtup_fst_446, dtup_fst_452, dlist4_fst_475 };
                              std::optional<tf0c8d4f3070907529cc1a83f8baf6fab> id_2903 { id_2902 };
                              t3b4feade6f60da4ba5d645f756688083 id_2904 { id_2903, dlist4_snd_476 };
                              letpair_res_2901 = id_2904;
                            }
                            letpair_res_2830 = letpair_res_2901;
                          }
                          let_res_2829 = letpair_res_2830;
                        }
                        letpair_res_2812 = let_res_2829;
                      }
                      let_res_2811 = letpair_res_2812;
                    }
                    choose_res_2801 = let_res_2811;
                  }
                  t45217dce3db5a9a49037839afd0048e8 let_res_2905;
                  {
                    t3b4feade6f60da4ba5d645f756688083 drec_483 { choose_res_2801 };
                    t45217dce3db5a9a49037839afd0048e8 letpair_res_2906;
                    {
                      auto drec_fst_484 { std::get<0>(drec_483) };
                      auto drec_snd_485 { std::get<1>(drec_483) };
                      auto fun2907 { dessser::gen::raql_expr::of_row_binary };
                      t1113e6691818baaf60a775527f6cc1ac id_2908 { fun2907(drec_snd_485) };
                      t45217dce3db5a9a49037839afd0048e8 let_res_2909;
                      {
                        t1113e6691818baaf60a775527f6cc1ac drec_486 { id_2908 };
                        t45217dce3db5a9a49037839afd0048e8 letpair_res_2910;
                        {
                          auto drec_fst_487 { std::get<0>(drec_486) };
                          auto drec_snd_488 { std::get<1>(drec_486) };
                          Size id_2911 { 0UL };
                          uint8_t id_2912 { drec_snd_488.peekU8(id_2911) };
                          uint8_t id_2913 { 1 };
                          bool id_2914 { bool(id_2912 == id_2913) };
                          te3858ac581a2bb69ede2f45fc6f9aff4 choose_res_2915;
                          if (id_2914) {
                            std::optional<dessser::gen::event_time::t_ext> id_2916 { std::nullopt };
                            Size id_2917 { 1UL };
                            Pointer id_2918 { drec_snd_488.skip(id_2917) };
                            te3858ac581a2bb69ede2f45fc6f9aff4 id_2919 { id_2916, id_2918 };
                            choose_res_2915 = id_2919;
                          } else {
                            auto fun2920 { dessser::gen::event_time::of_row_binary };
                            Size id_2921 { 1UL };
                            Pointer id_2922 { drec_snd_488.skip(id_2921) };
                            te8ff255b34432f8503a86cf675cbafe6 id_2923 { fun2920(id_2922) };
                            te3858ac581a2bb69ede2f45fc6f9aff4 letpair_res_2924;
                            {
                              auto make1_1_fst_490 { std::get<0>(id_2923) };
                              auto make1_1_snd_491 { std::get<1>(id_2923) };
                              std::optional<dessser::gen::event_time::t_ext> id_2925 { make1_1_fst_490 };
                              te3858ac581a2bb69ede2f45fc6f9aff4 id_2926 { id_2925, make1_1_snd_491 };
                              letpair_res_2924 = id_2926;
                            }
                            choose_res_2915 = letpair_res_2924;
                          }
                          t45217dce3db5a9a49037839afd0048e8 let_res_2927;
                          {
                            te3858ac581a2bb69ede2f45fc6f9aff4 drec_492 { choose_res_2915 };
                            t45217dce3db5a9a49037839afd0048e8 letpair_res_2928;
                            {
                              auto drec_fst_493 { std::get<0>(drec_492) };
                              auto drec_snd_494 { std::get<1>(drec_492) };
                              uint32_t id_2929 { 0U };
                              Vec<1, uint32_t> id_2930 {  id_2929  };
                              t405eb186408556fed8f2c41523c07d13 let_res_2931;
                              {
                                Vec<1, uint32_t> leb_ref_495 { id_2930 };
                                uint8_t id_2932 { 0 };
                                Vec<1, uint8_t> id_2933 {  id_2932  };
                                t405eb186408556fed8f2c41523c07d13 let_res_2934;
                                {
                                  Vec<1, uint8_t> shft_ref_496 { id_2933 };
                                  Vec<1, Pointer> id_2935 {  drec_snd_494  };
                                  t405eb186408556fed8f2c41523c07d13 let_res_2936;
                                  {
                                    Vec<1, Pointer> p_ref_497 { id_2935 };
                                    bool while_flag_2937 { true };
                                    do {
                                      uint8_t id_2938 { 0 };
                                      Pointer id_2939 { p_ref_497[id_2938] };
                                      tb3f98ea670610d40658a618de3ec7b90 id_2940 { id_2939.readU8() };
                                      bool let_res_2941;
                                      {
                                        tb3f98ea670610d40658a618de3ec7b90 leb128_498 { id_2940 };
                                        bool letpair_res_2942;
                                        {
                                          auto leb128_fst_499 { std::get<0>(leb128_498) };
                                          auto leb128_snd_500 { std::get<1>(leb128_498) };
                                          uint8_t id_2943 { 0 };
                                          Void id_2944 { ((void)(p_ref_497[id_2943] = leb128_snd_500), VOID) };
                                          (void)id_2944;
                                          uint8_t id_2945 { 0 };
                                          uint8_t id_2946 { 127 };
                                          uint8_t id_2947 { uint8_t(leb128_fst_499 & id_2946) };
                                          uint32_t id_2948 { uint32_t(id_2947) };
                                          uint8_t id_2949 { 0 };
                                          uint8_t id_2950 { shft_ref_496[id_2949] };
                                          uint32_t id_2951 { uint32_t(id_2948 << id_2950) };
                                          uint8_t id_2952 { 0 };
                                          uint32_t id_2953 { leb_ref_495[id_2952] };
                                          uint32_t id_2954 { uint32_t(id_2951 | id_2953) };
                                          Void id_2955 { ((void)(leb_ref_495[id_2945] = id_2954), VOID) };
                                          (void)id_2955;
                                          uint8_t id_2956 { 0 };
                                          uint8_t id_2957 { 0 };
                                          uint8_t id_2958 { shft_ref_496[id_2957] };
                                          uint8_t id_2959 { 7 };
                                          uint8_t id_2960 { uint8_t(id_2958 + id_2959) };
                                          Void id_2961 { ((void)(shft_ref_496[id_2956] = id_2960), VOID) };
                                          (void)id_2961;
                                          uint8_t id_2962 { 128 };
                                          bool id_2963 { bool(leb128_fst_499 >= id_2962) };
                                          letpair_res_2942 = id_2963;
                                        }
                                        let_res_2941 = letpair_res_2942;
                                      }
                                      while_flag_2937 = let_res_2941;
                                      if (while_flag_2937) {
                                        (void)VOID;
                                      }
                                    } while (while_flag_2937);
                                    (void)VOID;
                                    uint8_t id_2964 { 0 };
                                    uint32_t id_2965 { leb_ref_495[id_2964] };
                                    uint8_t id_2966 { 0 };
                                    Pointer id_2967 { p_ref_497[id_2966] };
                                    t405eb186408556fed8f2c41523c07d13 id_2968 { id_2965, id_2967 };
                                    let_res_2936 = id_2968;
                                  }
                                  let_res_2934 = let_res_2936;
                                }
                                let_res_2931 = let_res_2934;
                              }
                              t0067a338c0fc91b6a811c8df70d4c87a let_res_2969;
                              {
                                t405eb186408556fed8f2c41523c07d13 dlist1_504 { let_res_2931 };
                                t0067a338c0fc91b6a811c8df70d4c87a letpair_res_2970;
                                {
                                  auto dlist1_fst_505 { std::get<0>(dlist1_504) };
                                  auto dlist1_snd_506 { std::get<1>(dlist1_504) };
                                  Lst<dessser::gen::raql_expr::t_ext> endoflist_2971;
                                  t0067a338c0fc91b6a811c8df70d4c87a id_2972 { endoflist_2971, dlist1_snd_506 };
                                  Vec<1, t0067a338c0fc91b6a811c8df70d4c87a> id_2973 {  id_2972  };
                                  t0067a338c0fc91b6a811c8df70d4c87a let_res_2974;
                                  {
                                    Vec<1, t0067a338c0fc91b6a811c8df70d4c87a> inits_src_ref_507 { id_2973 };
                                    int32_t id_2975 { 0L };
                                    Vec<1, int32_t> id_2976 {  id_2975  };
                                    {
                                      Vec<1, int32_t> repeat_n_508 { id_2976 };
                                      bool while_flag_2977 { true };
                                      do {
                                        int32_t id_2978 { int32_t(dlist1_fst_505) };
                                        uint8_t id_2979 { 0 };
                                        int32_t id_2980 { repeat_n_508[id_2979] };
                                        bool id_2981 { bool(id_2978 > id_2980) };
                                        while_flag_2977 = id_2981;
                                        if (while_flag_2977) {
                                          uint8_t id_2982 { 0 };
                                          t0067a338c0fc91b6a811c8df70d4c87a id_2983 { inits_src_ref_507[id_2982] };
                                          {
                                            t0067a338c0fc91b6a811c8df70d4c87a dlist2_509 { id_2983 };
                                            {
                                              auto dlist2_fst_510 { std::get<0>(dlist2_509) };
                                              auto dlist2_snd_511 { std::get<1>(dlist2_509) };
                                              uint8_t id_2984 { 0 };
                                              auto fun2985 { dessser::gen::raql_expr::of_row_binary };
                                              t1113e6691818baaf60a775527f6cc1ac id_2986 { fun2985(dlist2_snd_511) };
                                              t0067a338c0fc91b6a811c8df70d4c87a letpair_res_2987;
                                              {
                                                auto dlist3_fst_513 { std::get<0>(id_2986) };
                                                auto dlist3_snd_514 { std::get<1>(id_2986) };
                                                Lst<dessser::gen::raql_expr::t_ext> id_2988 { dlist3_fst_513, dlist2_fst_510 };
                                                t0067a338c0fc91b6a811c8df70d4c87a id_2989 { id_2988, dlist3_snd_514 };
                                                letpair_res_2987 = id_2989;
                                              }
                                              Void id_2990 { ((void)(inits_src_ref_507[id_2984] = letpair_res_2987), VOID) };
                                              (void)id_2990;
                                            }
                                            (void)VOID;
                                          }
                                          (void)VOID;
                                          uint8_t id_2991 { 0 };
                                          uint8_t id_2992 { 0 };
                                          int32_t id_2993 { repeat_n_508[id_2992] };
                                          int32_t id_2994 { 1L };
                                          int32_t id_2995 { int32_t(id_2993 + id_2994) };
                                          Void id_2996 { ((void)(repeat_n_508[id_2991] = id_2995), VOID) };
                                          (void)id_2996;
                                          (void)id_2996;
                                        }
                                      } while (while_flag_2977);
                                      (void)VOID;
                                    }
                                    (void)VOID;
                                    uint8_t id_2997 { 0 };
                                    t0067a338c0fc91b6a811c8df70d4c87a id_2998 { inits_src_ref_507[id_2997] };
                                    let_res_2974 = id_2998;
                                  }
                                  letpair_res_2970 = let_res_2974;
                                }
                                let_res_2969 = letpair_res_2970;
                              }
                              t0067a338c0fc91b6a811c8df70d4c87a letpair_res_2999;
                              {
                                auto dlist4_fst_516 { std::get<0>(let_res_2969) };
                                auto dlist4_snd_517 { std::get<1>(let_res_2969) };
                                t0067a338c0fc91b6a811c8df70d4c87a id_3000 { dlist4_fst_516, dlist4_snd_517 };
                                letpair_res_2999 = id_3000;
                              }
                              t45217dce3db5a9a49037839afd0048e8 let_res_3001;
                              {
                                t0067a338c0fc91b6a811c8df70d4c87a drec_518 { letpair_res_2999 };
                                t45217dce3db5a9a49037839afd0048e8 letpair_res_3002;
                                {
                                  auto drec_fst_519 { std::get<0>(drec_518) };
                                  auto drec_snd_520 { std::get<1>(drec_518) };
                                  uint32_t id_3003 { 0U };
                                  Vec<1, uint32_t> id_3004 {  id_3003  };
                                  t405eb186408556fed8f2c41523c07d13 let_res_3005;
                                  {
                                    Vec<1, uint32_t> leb_ref_521 { id_3004 };
                                    uint8_t id_3006 { 0 };
                                    Vec<1, uint8_t> id_3007 {  id_3006  };
                                    t405eb186408556fed8f2c41523c07d13 let_res_3008;
                                    {
                                      Vec<1, uint8_t> shft_ref_522 { id_3007 };
                                      Vec<1, Pointer> id_3009 {  drec_snd_520  };
                                      t405eb186408556fed8f2c41523c07d13 let_res_3010;
                                      {
                                        Vec<1, Pointer> p_ref_523 { id_3009 };
                                        bool while_flag_3011 { true };
                                        do {
                                          uint8_t id_3012 { 0 };
                                          Pointer id_3013 { p_ref_523[id_3012] };
                                          tb3f98ea670610d40658a618de3ec7b90 id_3014 { id_3013.readU8() };
                                          bool let_res_3015;
                                          {
                                            tb3f98ea670610d40658a618de3ec7b90 leb128_524 { id_3014 };
                                            bool letpair_res_3016;
                                            {
                                              auto leb128_fst_525 { std::get<0>(leb128_524) };
                                              auto leb128_snd_526 { std::get<1>(leb128_524) };
                                              uint8_t id_3017 { 0 };
                                              Void id_3018 { ((void)(p_ref_523[id_3017] = leb128_snd_526), VOID) };
                                              (void)id_3018;
                                              uint8_t id_3019 { 0 };
                                              uint8_t id_3020 { 127 };
                                              uint8_t id_3021 { uint8_t(leb128_fst_525 & id_3020) };
                                              uint32_t id_3022 { uint32_t(id_3021) };
                                              uint8_t id_3023 { 0 };
                                              uint8_t id_3024 { shft_ref_522[id_3023] };
                                              uint32_t id_3025 { uint32_t(id_3022 << id_3024) };
                                              uint8_t id_3026 { 0 };
                                              uint32_t id_3027 { leb_ref_521[id_3026] };
                                              uint32_t id_3028 { uint32_t(id_3025 | id_3027) };
                                              Void id_3029 { ((void)(leb_ref_521[id_3019] = id_3028), VOID) };
                                              (void)id_3029;
                                              uint8_t id_3030 { 0 };
                                              uint8_t id_3031 { 0 };
                                              uint8_t id_3032 { shft_ref_522[id_3031] };
                                              uint8_t id_3033 { 7 };
                                              uint8_t id_3034 { uint8_t(id_3032 + id_3033) };
                                              Void id_3035 { ((void)(shft_ref_522[id_3030] = id_3034), VOID) };
                                              (void)id_3035;
                                              uint8_t id_3036 { 128 };
                                              bool id_3037 { bool(leb128_fst_525 >= id_3036) };
                                              letpair_res_3016 = id_3037;
                                            }
                                            let_res_3015 = letpair_res_3016;
                                          }
                                          while_flag_3011 = let_res_3015;
                                          if (while_flag_3011) {
                                            (void)VOID;
                                          }
                                        } while (while_flag_3011);
                                        (void)VOID;
                                        uint8_t id_3038 { 0 };
                                        uint32_t id_3039 { leb_ref_521[id_3038] };
                                        uint8_t id_3040 { 0 };
                                        Pointer id_3041 { p_ref_523[id_3040] };
                                        t405eb186408556fed8f2c41523c07d13 id_3042 { id_3039, id_3041 };
                                        let_res_3010 = id_3042;
                                      }
                                      let_res_3008 = let_res_3010;
                                    }
                                    let_res_3005 = let_res_3008;
                                  }
                                  t0067a338c0fc91b6a811c8df70d4c87a let_res_3043;
                                  {
                                    t405eb186408556fed8f2c41523c07d13 dlist1_530 { let_res_3005 };
                                    t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3044;
                                    {
                                      auto dlist1_fst_531 { std::get<0>(dlist1_530) };
                                      auto dlist1_snd_532 { std::get<1>(dlist1_530) };
                                      Lst<dessser::gen::raql_expr::t_ext> endoflist_3045;
                                      t0067a338c0fc91b6a811c8df70d4c87a id_3046 { endoflist_3045, dlist1_snd_532 };
                                      Vec<1, t0067a338c0fc91b6a811c8df70d4c87a> id_3047 {  id_3046  };
                                      t0067a338c0fc91b6a811c8df70d4c87a let_res_3048;
                                      {
                                        Vec<1, t0067a338c0fc91b6a811c8df70d4c87a> inits_src_ref_533 { id_3047 };
                                        int32_t id_3049 { 0L };
                                        Vec<1, int32_t> id_3050 {  id_3049  };
                                        {
                                          Vec<1, int32_t> repeat_n_534 { id_3050 };
                                          bool while_flag_3051 { true };
                                          do {
                                            int32_t id_3052 { int32_t(dlist1_fst_531) };
                                            uint8_t id_3053 { 0 };
                                            int32_t id_3054 { repeat_n_534[id_3053] };
                                            bool id_3055 { bool(id_3052 > id_3054) };
                                            while_flag_3051 = id_3055;
                                            if (while_flag_3051) {
                                              uint8_t id_3056 { 0 };
                                              t0067a338c0fc91b6a811c8df70d4c87a id_3057 { inits_src_ref_533[id_3056] };
                                              {
                                                t0067a338c0fc91b6a811c8df70d4c87a dlist2_535 { id_3057 };
                                                {
                                                  auto dlist2_fst_536 { std::get<0>(dlist2_535) };
                                                  auto dlist2_snd_537 { std::get<1>(dlist2_535) };
                                                  uint8_t id_3058 { 0 };
                                                  auto fun3059 { dessser::gen::raql_expr::of_row_binary };
                                                  t1113e6691818baaf60a775527f6cc1ac id_3060 { fun3059(dlist2_snd_537) };
                                                  t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3061;
                                                  {
                                                    auto dlist3_fst_539 { std::get<0>(id_3060) };
                                                    auto dlist3_snd_540 { std::get<1>(id_3060) };
                                                    Lst<dessser::gen::raql_expr::t_ext> id_3062 { dlist3_fst_539, dlist2_fst_536 };
                                                    t0067a338c0fc91b6a811c8df70d4c87a id_3063 { id_3062, dlist3_snd_540 };
                                                    letpair_res_3061 = id_3063;
                                                  }
                                                  Void id_3064 { ((void)(inits_src_ref_533[id_3058] = letpair_res_3061), VOID) };
                                                  (void)id_3064;
                                                }
                                                (void)VOID;
                                              }
                                              (void)VOID;
                                              uint8_t id_3065 { 0 };
                                              uint8_t id_3066 { 0 };
                                              int32_t id_3067 { repeat_n_534[id_3066] };
                                              int32_t id_3068 { 1L };
                                              int32_t id_3069 { int32_t(id_3067 + id_3068) };
                                              Void id_3070 { ((void)(repeat_n_534[id_3065] = id_3069), VOID) };
                                              (void)id_3070;
                                              (void)id_3070;
                                            }
                                          } while (while_flag_3051);
                                          (void)VOID;
                                        }
                                        (void)VOID;
                                        uint8_t id_3071 { 0 };
                                        t0067a338c0fc91b6a811c8df70d4c87a id_3072 { inits_src_ref_533[id_3071] };
                                        let_res_3048 = id_3072;
                                      }
                                      letpair_res_3044 = let_res_3048;
                                    }
                                    let_res_3043 = letpair_res_3044;
                                  }
                                  t0067a338c0fc91b6a811c8df70d4c87a letpair_res_3073;
                                  {
                                    auto dlist4_fst_542 { std::get<0>(let_res_3043) };
                                    auto dlist4_snd_543 { std::get<1>(let_res_3043) };
                                    t0067a338c0fc91b6a811c8df70d4c87a id_3074 { dlist4_fst_542, dlist4_snd_543 };
                                    letpair_res_3073 = id_3074;
                                  }
                                  t45217dce3db5a9a49037839afd0048e8 let_res_3075;
                                  {
                                    t0067a338c0fc91b6a811c8df70d4c87a drec_544 { letpair_res_3073 };
                                    t45217dce3db5a9a49037839afd0048e8 letpair_res_3076;
                                    {
                                      auto drec_fst_545 { std::get<0>(drec_544) };
                                      auto drec_snd_546 { std::get<1>(drec_544) };
                                      auto fun3077 { dessser::gen::raql_expr::of_row_binary };
                                      t1113e6691818baaf60a775527f6cc1ac id_3078 { fun3077(drec_snd_546) };
                                      t45217dce3db5a9a49037839afd0048e8 let_res_3079;
                                      {
                                        t1113e6691818baaf60a775527f6cc1ac drec_547 { id_3078 };
                                        t45217dce3db5a9a49037839afd0048e8 letpair_res_3080;
                                        {
                                          auto drec_fst_548 { std::get<0>(drec_547) };
                                          auto drec_snd_549 { std::get<1>(drec_547) };
                                          tb3f98ea670610d40658a618de3ec7b90 id_3081 { drec_snd_549.readU8() };
                                          t4138de986e20d18b01e4c493dc9d5451 letpair_res_3082;
                                          {
                                            auto dbool_fst_551 { std::get<0>(id_3081) };
                                            auto dbool_snd_552 { std::get<1>(id_3081) };
                                            uint8_t id_3083 { 0 };
                                            bool id_3084 { bool(dbool_fst_551 == id_3083) };
                                            bool id_3085 { ! id_3084 };
                                            t4138de986e20d18b01e4c493dc9d5451 id_3086 { id_3085, dbool_snd_552 };
                                            letpair_res_3082 = id_3086;
                                          }
                                          t45217dce3db5a9a49037839afd0048e8 let_res_3087;
                                          {
                                            t4138de986e20d18b01e4c493dc9d5451 drec_553 { letpair_res_3082 };
                                            t45217dce3db5a9a49037839afd0048e8 letpair_res_3088;
                                            {
                                              auto drec_fst_554 { std::get<0>(drec_553) };
                                              auto drec_snd_555 { std::get<1>(drec_553) };
                                              auto fun3089 { dessser::gen::raql_flush_method::of_row_binary };
                                              t01507690afb11d3b148862b712bad5a5 id_3090 { fun3089(drec_snd_555) };
                                              t45217dce3db5a9a49037839afd0048e8 let_res_3091;
                                              {
                                                t01507690afb11d3b148862b712bad5a5 drec_556 { id_3090 };
                                                t45217dce3db5a9a49037839afd0048e8 letpair_res_3092;
                                                {
                                                  auto drec_fst_557 { std::get<0>(drec_556) };
                                                  auto drec_snd_558 { std::get<1>(drec_556) };
                                                  uint32_t id_3093 { 0U };
                                                  Vec<1, uint32_t> id_3094 {  id_3093  };
                                                  t405eb186408556fed8f2c41523c07d13 let_res_3095;
                                                  {
                                                    Vec<1, uint32_t> leb_ref_559 { id_3094 };
                                                    uint8_t id_3096 { 0 };
                                                    Vec<1, uint8_t> id_3097 {  id_3096  };
                                                    t405eb186408556fed8f2c41523c07d13 let_res_3098;
                                                    {
                                                      Vec<1, uint8_t> shft_ref_560 { id_3097 };
                                                      Vec<1, Pointer> id_3099 {  drec_snd_558  };
                                                      t405eb186408556fed8f2c41523c07d13 let_res_3100;
                                                      {
                                                        Vec<1, Pointer> p_ref_561 { id_3099 };
                                                        bool while_flag_3101 { true };
                                                        do {
                                                          uint8_t id_3102 { 0 };
                                                          Pointer id_3103 { p_ref_561[id_3102] };
                                                          tb3f98ea670610d40658a618de3ec7b90 id_3104 { id_3103.readU8() };
                                                          bool let_res_3105;
                                                          {
                                                            tb3f98ea670610d40658a618de3ec7b90 leb128_562 { id_3104 };
                                                            bool letpair_res_3106;
                                                            {
                                                              auto leb128_fst_563 { std::get<0>(leb128_562) };
                                                              auto leb128_snd_564 { std::get<1>(leb128_562) };
                                                              uint8_t id_3107 { 0 };
                                                              Void id_3108 { ((void)(p_ref_561[id_3107] = leb128_snd_564), VOID) };
                                                              (void)id_3108;
                                                              uint8_t id_3109 { 0 };
                                                              uint8_t id_3110 { 127 };
                                                              uint8_t id_3111 { uint8_t(leb128_fst_563 & id_3110) };
                                                              uint32_t id_3112 { uint32_t(id_3111) };
                                                              uint8_t id_3113 { 0 };
                                                              uint8_t id_3114 { shft_ref_560[id_3113] };
                                                              uint32_t id_3115 { uint32_t(id_3112 << id_3114) };
                                                              uint8_t id_3116 { 0 };
                                                              uint32_t id_3117 { leb_ref_559[id_3116] };
                                                              uint32_t id_3118 { uint32_t(id_3115 | id_3117) };
                                                              Void id_3119 { ((void)(leb_ref_559[id_3109] = id_3118), VOID) };
                                                              (void)id_3119;
                                                              uint8_t id_3120 { 0 };
                                                              uint8_t id_3121 { 0 };
                                                              uint8_t id_3122 { shft_ref_560[id_3121] };
                                                              uint8_t id_3123 { 7 };
                                                              uint8_t id_3124 { uint8_t(id_3122 + id_3123) };
                                                              Void id_3125 { ((void)(shft_ref_560[id_3120] = id_3124), VOID) };
                                                              (void)id_3125;
                                                              uint8_t id_3126 { 128 };
                                                              bool id_3127 { bool(leb128_fst_563 >= id_3126) };
                                                              letpair_res_3106 = id_3127;
                                                            }
                                                            let_res_3105 = letpair_res_3106;
                                                          }
                                                          while_flag_3101 = let_res_3105;
                                                          if (while_flag_3101) {
                                                            (void)VOID;
                                                          }
                                                        } while (while_flag_3101);
                                                        (void)VOID;
                                                        uint8_t id_3128 { 0 };
                                                        uint32_t id_3129 { leb_ref_559[id_3128] };
                                                        uint8_t id_3130 { 0 };
                                                        Pointer id_3131 { p_ref_561[id_3130] };
                                                        t405eb186408556fed8f2c41523c07d13 id_3132 { id_3129, id_3131 };
                                                        let_res_3100 = id_3132;
                                                      }
                                                      let_res_3098 = let_res_3100;
                                                    }
                                                    let_res_3095 = let_res_3098;
                                                  }
                                                  t5c362d56d9dbfb12c2e68c4ed4a25c50 let_res_3133;
                                                  {
                                                    t405eb186408556fed8f2c41523c07d13 dlist1_568 { let_res_3095 };
                                                    t5c362d56d9dbfb12c2e68c4ed4a25c50 letpair_res_3134;
                                                    {
                                                      auto dlist1_fst_569 { std::get<0>(dlist1_568) };
                                                      auto dlist1_snd_570 { std::get<1>(dlist1_568) };
                                                      Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> endoflist_3135;
                                                      t5c362d56d9dbfb12c2e68c4ed4a25c50 id_3136 { endoflist_3135, dlist1_snd_570 };
                                                      Vec<1, t5c362d56d9dbfb12c2e68c4ed4a25c50> id_3137 {  id_3136  };
                                                      t5c362d56d9dbfb12c2e68c4ed4a25c50 let_res_3138;
                                                      {
                                                        Vec<1, t5c362d56d9dbfb12c2e68c4ed4a25c50> inits_src_ref_571 { id_3137 };
                                                        int32_t id_3139 { 0L };
                                                        Vec<1, int32_t> id_3140 {  id_3139  };
                                                        {
                                                          Vec<1, int32_t> repeat_n_572 { id_3140 };
                                                          bool while_flag_3141 { true };
                                                          do {
                                                            int32_t id_3142 { int32_t(dlist1_fst_569) };
                                                            uint8_t id_3143 { 0 };
                                                            int32_t id_3144 { repeat_n_572[id_3143] };
                                                            bool id_3145 { bool(id_3142 > id_3144) };
                                                            while_flag_3141 = id_3145;
                                                            if (while_flag_3141) {
                                                              uint8_t id_3146 { 0 };
                                                              t5c362d56d9dbfb12c2e68c4ed4a25c50 id_3147 { inits_src_ref_571[id_3146] };
                                                              {
                                                                t5c362d56d9dbfb12c2e68c4ed4a25c50 dlist2_573 { id_3147 };
                                                                {
                                                                  auto dlist2_fst_574 { std::get<0>(dlist2_573) };
                                                                  auto dlist2_snd_575 { std::get<1>(dlist2_573) };
                                                                  uint8_t id_3148 { 0 };
                                                                  t22a32080ad88ab548b80077a17b7dd46 id_3149 { dlist2_snd_575.readU16Le() };
                                                                  t22a32080ad88ab548b80077a17b7dd46 letpair_res_3150;
                                                                  {
                                                                    auto du16_fst_577 { std::get<0>(id_3149) };
                                                                    auto du16_snd_578 { std::get<1>(id_3149) };
                                                                    t22a32080ad88ab548b80077a17b7dd46 id_3151 { du16_fst_577, du16_snd_578 };
                                                                    letpair_res_3150 = id_3151;
                                                                  }
                                                                  t2a2e361c672135221e41ae1e54a712a2 let_res_3152;
                                                                  {
                                                                    t22a32080ad88ab548b80077a17b7dd46 dsum1_582 { letpair_res_3150 };
                                                                    t2a2e361c672135221e41ae1e54a712a2 letpair_res_3153;
                                                                    {
                                                                      auto dsum1_fst_583 { std::get<0>(dsum1_582) };
                                                                      auto dsum1_snd_584 { std::get<1>(dsum1_582) };
                                                                      uint16_t id_3154 { 0 };
                                                                      bool id_3155 { bool(id_3154 == dsum1_fst_583) };
                                                                      t2a2e361c672135221e41ae1e54a712a2 choose_res_3156;
                                                                      if (id_3155) {
                                                                        t22a32080ad88ab548b80077a17b7dd46 id_3157 { dsum1_snd_584.readU16Le() };
                                                                        t22a32080ad88ab548b80077a17b7dd46 letpair_res_3158;
                                                                        {
                                                                          auto du16_fst_589 { std::get<0>(id_3157) };
                                                                          auto du16_snd_590 { std::get<1>(id_3157) };
                                                                          t22a32080ad88ab548b80077a17b7dd46 id_3159 { du16_fst_589, du16_snd_590 };
                                                                          letpair_res_3158 = id_3159;
                                                                        }
                                                                        tf0d49dee148c406cd202993cce2a4a2d let_res_3160;
                                                                        {
                                                                          t22a32080ad88ab548b80077a17b7dd46 dsum1_594 { letpair_res_3158 };
                                                                          tf0d49dee148c406cd202993cce2a4a2d letpair_res_3161;
                                                                          {
                                                                            auto dsum1_fst_595 { std::get<0>(dsum1_594) };
                                                                            auto dsum1_snd_596 { std::get<1>(dsum1_594) };
                                                                            uint16_t id_3162 { 0 };
                                                                            bool id_3163 { bool(id_3162 == dsum1_fst_595) };
                                                                            tf0d49dee148c406cd202993cce2a4a2d choose_res_3164;
                                                                            if (id_3163) {
                                                                              (void)VOID;
                                                                              te10a95f610a64bfb7ccea542c54f0a25 id_3165 { std::in_place_index<0>, VOID };
                                                                              tf0d49dee148c406cd202993cce2a4a2d id_3166 { id_3165, dsum1_snd_596 };
                                                                              choose_res_3164 = id_3166;
                                                                            } else {
                                                                              uint16_t id_3167 { 1 };
                                                                              bool id_3168 { bool(id_3167 == dsum1_fst_595) };
                                                                              tf0d49dee148c406cd202993cce2a4a2d choose_res_3169;
                                                                              if (id_3168) {
                                                                                uint32_t id_3170 { 0U };
                                                                                Vec<1, uint32_t> id_3171 {  id_3170  };
                                                                                t8beb80162423aee37bd383e9b6834c9c let_res_3172;
                                                                                {
                                                                                  Vec<1, uint32_t> leb_ref_600 { id_3171 };
                                                                                  uint8_t id_3173 { 0 };
                                                                                  Vec<1, uint8_t> id_3174 {  id_3173  };
                                                                                  t8beb80162423aee37bd383e9b6834c9c let_res_3175;
                                                                                  {
                                                                                    Vec<1, uint8_t> shft_ref_601 { id_3174 };
                                                                                    Vec<1, Pointer> id_3176 {  dsum1_snd_596  };
                                                                                    t8beb80162423aee37bd383e9b6834c9c let_res_3177;
                                                                                    {
                                                                                      Vec<1, Pointer> p_ref_602 { id_3176 };
                                                                                      bool while_flag_3178 { true };
                                                                                      do {
                                                                                        uint8_t id_3179 { 0 };
                                                                                        Pointer id_3180 { p_ref_602[id_3179] };
                                                                                        tb3f98ea670610d40658a618de3ec7b90 id_3181 { id_3180.readU8() };
                                                                                        bool let_res_3182;
                                                                                        {
                                                                                          tb3f98ea670610d40658a618de3ec7b90 leb128_603 { id_3181 };
                                                                                          bool letpair_res_3183;
                                                                                          {
                                                                                            auto leb128_fst_604 { std::get<0>(leb128_603) };
                                                                                            auto leb128_snd_605 { std::get<1>(leb128_603) };
                                                                                            uint8_t id_3184 { 0 };
                                                                                            Void id_3185 { ((void)(p_ref_602[id_3184] = leb128_snd_605), VOID) };
                                                                                            (void)id_3185;
                                                                                            uint8_t id_3186 { 0 };
                                                                                            uint8_t id_3187 { 127 };
                                                                                            uint8_t id_3188 { uint8_t(leb128_fst_604 & id_3187) };
                                                                                            uint32_t id_3189 { uint32_t(id_3188) };
                                                                                            uint8_t id_3190 { 0 };
                                                                                            uint8_t id_3191 { shft_ref_601[id_3190] };
                                                                                            uint32_t id_3192 { uint32_t(id_3189 << id_3191) };
                                                                                            uint8_t id_3193 { 0 };
                                                                                            uint32_t id_3194 { leb_ref_600[id_3193] };
                                                                                            uint32_t id_3195 { uint32_t(id_3192 | id_3194) };
                                                                                            Void id_3196 { ((void)(leb_ref_600[id_3186] = id_3195), VOID) };
                                                                                            (void)id_3196;
                                                                                            uint8_t id_3197 { 0 };
                                                                                            uint8_t id_3198 { 0 };
                                                                                            uint8_t id_3199 { shft_ref_601[id_3198] };
                                                                                            uint8_t id_3200 { 7 };
                                                                                            uint8_t id_3201 { uint8_t(id_3199 + id_3200) };
                                                                                            Void id_3202 { ((void)(shft_ref_601[id_3197] = id_3201), VOID) };
                                                                                            (void)id_3202;
                                                                                            uint8_t id_3203 { 128 };
                                                                                            bool id_3204 { bool(leb128_fst_604 >= id_3203) };
                                                                                            letpair_res_3183 = id_3204;
                                                                                          }
                                                                                          let_res_3182 = letpair_res_3183;
                                                                                        }
                                                                                        while_flag_3178 = let_res_3182;
                                                                                        if (while_flag_3178) {
                                                                                          (void)VOID;
                                                                                        }
                                                                                      } while (while_flag_3178);
                                                                                      (void)VOID;
                                                                                      uint8_t id_3205 { 0 };
                                                                                      uint32_t id_3206 { leb_ref_600[id_3205] };
                                                                                      Size id_3207 { Size(id_3206) };
                                                                                      uint8_t id_3208 { 0 };
                                                                                      Pointer id_3209 { p_ref_602[id_3208] };
                                                                                      t8beb80162423aee37bd383e9b6834c9c id_3210 { id_3207, id_3209 };
                                                                                      let_res_3177 = id_3210;
                                                                                    }
                                                                                    let_res_3175 = let_res_3177;
                                                                                  }
                                                                                  let_res_3172 = let_res_3175;
                                                                                }
                                                                                tf0d49dee148c406cd202993cce2a4a2d let_res_3211;
                                                                                {
                                                                                  t8beb80162423aee37bd383e9b6834c9c dstring1_606 { let_res_3172 };
                                                                                  tf0d49dee148c406cd202993cce2a4a2d letpair_res_3212;
                                                                                  {
                                                                                    auto dstring1_fst_607 { std::get<0>(dstring1_606) };
                                                                                    auto dstring1_snd_608 { std::get<1>(dstring1_606) };
                                                                                    t188345aa49abd0cb47ff73fedc219f08 id_3213 { dstring1_snd_608.readBytes(dstring1_fst_607) };
                                                                                    tf0d49dee148c406cd202993cce2a4a2d letpair_res_3214;
                                                                                    {
                                                                                      auto dstring2_fst_610 { std::get<0>(id_3213) };
                                                                                      auto dstring2_snd_611 { std::get<1>(id_3213) };
                                                                                      std::string id_3215 { dstring2_fst_610.toString() };
                                                                                      te10a95f610a64bfb7ccea542c54f0a25 id_3216 { std::in_place_index<1>, id_3215 };
                                                                                      tf0d49dee148c406cd202993cce2a4a2d id_3217 { id_3216, dstring2_snd_611 };
                                                                                      letpair_res_3214 = id_3217;
                                                                                    }
                                                                                    letpair_res_3212 = letpair_res_3214;
                                                                                  }
                                                                                  let_res_3211 = letpair_res_3212;
                                                                                }
                                                                                choose_res_3169 = let_res_3211;
                                                                              } else {
                                                                                uint16_t id_3218 { 2 };
                                                                                bool id_3219 { bool(dsum1_fst_595 == id_3218) };
                                                                                Void id_3220 { ((void)(assert(id_3219)), VOID) };
                                                                                (void)id_3220;
                                                                                (void)VOID;
                                                                                te10a95f610a64bfb7ccea542c54f0a25 id_3221 { std::in_place_index<2>, VOID };
                                                                                tf0d49dee148c406cd202993cce2a4a2d id_3222 { id_3221, dsum1_snd_596 };
                                                                                choose_res_3169 = id_3222;
                                                                              }
                                                                              choose_res_3164 = choose_res_3169;
                                                                            }
                                                                            letpair_res_3161 = choose_res_3164;
                                                                          }
                                                                          let_res_3160 = letpair_res_3161;
                                                                        }
                                                                        t2a2e361c672135221e41ae1e54a712a2 let_res_3223;
                                                                        {
                                                                          tf0d49dee148c406cd202993cce2a4a2d dtup_618 { let_res_3160 };
                                                                          t2a2e361c672135221e41ae1e54a712a2 letpair_res_3224;
                                                                          {
                                                                            auto dtup_fst_619 { std::get<0>(dtup_618) };
                                                                            auto dtup_snd_620 { std::get<1>(dtup_618) };
                                                                            Size id_3225 { 0UL };
                                                                            uint8_t id_3226 { dtup_snd_620.peekU8(id_3225) };
                                                                            uint8_t id_3227 { 1 };
                                                                            bool id_3228 { bool(id_3226 == id_3227) };
                                                                            t3fbff88eef4e4c8bc42b06e5ad07ea51 choose_res_3229;
                                                                            if (id_3228) {
                                                                              std::optional<std::string> id_3230 { std::nullopt };
                                                                              Size id_3231 { 1UL };
                                                                              Pointer id_3232 { dtup_snd_620.skip(id_3231) };
                                                                              t3fbff88eef4e4c8bc42b06e5ad07ea51 id_3233 { id_3230, id_3232 };
                                                                              choose_res_3229 = id_3233;
                                                                            } else {
                                                                              uint32_t id_3234 { 0U };
                                                                              Vec<1, uint32_t> id_3235 {  id_3234  };
                                                                              t8beb80162423aee37bd383e9b6834c9c let_res_3236;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_621 { id_3235 };
                                                                                uint8_t id_3237 { 0 };
                                                                                Vec<1, uint8_t> id_3238 {  id_3237  };
                                                                                t8beb80162423aee37bd383e9b6834c9c let_res_3239;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_622 { id_3238 };
                                                                                  Size id_3240 { 1UL };
                                                                                  Pointer id_3241 { dtup_snd_620.skip(id_3240) };
                                                                                  Vec<1, Pointer> id_3242 {  id_3241  };
                                                                                  t8beb80162423aee37bd383e9b6834c9c let_res_3243;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_623 { id_3242 };
                                                                                    bool while_flag_3244 { true };
                                                                                    do {
                                                                                      uint8_t id_3245 { 0 };
                                                                                      Pointer id_3246 { p_ref_623[id_3245] };
                                                                                      tb3f98ea670610d40658a618de3ec7b90 id_3247 { id_3246.readU8() };
                                                                                      bool let_res_3248;
                                                                                      {
                                                                                        tb3f98ea670610d40658a618de3ec7b90 leb128_624 { id_3247 };
                                                                                        bool letpair_res_3249;
                                                                                        {
                                                                                          auto leb128_fst_625 { std::get<0>(leb128_624) };
                                                                                          auto leb128_snd_626 { std::get<1>(leb128_624) };
                                                                                          uint8_t id_3250 { 0 };
                                                                                          Void id_3251 { ((void)(p_ref_623[id_3250] = leb128_snd_626), VOID) };
                                                                                          (void)id_3251;
                                                                                          uint8_t id_3252 { 0 };
                                                                                          uint8_t id_3253 { 127 };
                                                                                          uint8_t id_3254 { uint8_t(leb128_fst_625 & id_3253) };
                                                                                          uint32_t id_3255 { uint32_t(id_3254) };
                                                                                          uint8_t id_3256 { 0 };
                                                                                          uint8_t id_3257 { shft_ref_622[id_3256] };
                                                                                          uint32_t id_3258 { uint32_t(id_3255 << id_3257) };
                                                                                          uint8_t id_3259 { 0 };
                                                                                          uint32_t id_3260 { leb_ref_621[id_3259] };
                                                                                          uint32_t id_3261 { uint32_t(id_3258 | id_3260) };
                                                                                          Void id_3262 { ((void)(leb_ref_621[id_3252] = id_3261), VOID) };
                                                                                          (void)id_3262;
                                                                                          uint8_t id_3263 { 0 };
                                                                                          uint8_t id_3264 { 0 };
                                                                                          uint8_t id_3265 { shft_ref_622[id_3264] };
                                                                                          uint8_t id_3266 { 7 };
                                                                                          uint8_t id_3267 { uint8_t(id_3265 + id_3266) };
                                                                                          Void id_3268 { ((void)(shft_ref_622[id_3263] = id_3267), VOID) };
                                                                                          (void)id_3268;
                                                                                          uint8_t id_3269 { 128 };
                                                                                          bool id_3270 { bool(leb128_fst_625 >= id_3269) };
                                                                                          letpair_res_3249 = id_3270;
                                                                                        }
                                                                                        let_res_3248 = letpair_res_3249;
                                                                                      }
                                                                                      while_flag_3244 = let_res_3248;
                                                                                      if (while_flag_3244) {
                                                                                        (void)VOID;
                                                                                      }
                                                                                    } while (while_flag_3244);
                                                                                    (void)VOID;
                                                                                    uint8_t id_3271 { 0 };
                                                                                    uint32_t id_3272 { leb_ref_621[id_3271] };
                                                                                    Size id_3273 { Size(id_3272) };
                                                                                    uint8_t id_3274 { 0 };
                                                                                    Pointer id_3275 { p_ref_623[id_3274] };
                                                                                    t8beb80162423aee37bd383e9b6834c9c id_3276 { id_3273, id_3275 };
                                                                                    let_res_3243 = id_3276;
                                                                                  }
                                                                                  let_res_3239 = let_res_3243;
                                                                                }
                                                                                let_res_3236 = let_res_3239;
                                                                              }
                                                                              t3fbff88eef4e4c8bc42b06e5ad07ea51 let_res_3277;
                                                                              {
                                                                                t8beb80162423aee37bd383e9b6834c9c dstring1_627 { let_res_3236 };
                                                                                t3fbff88eef4e4c8bc42b06e5ad07ea51 letpair_res_3278;
                                                                                {
                                                                                  auto dstring1_fst_628 { std::get<0>(dstring1_627) };
                                                                                  auto dstring1_snd_629 { std::get<1>(dstring1_627) };
                                                                                  t188345aa49abd0cb47ff73fedc219f08 id_3279 { dstring1_snd_629.readBytes(dstring1_fst_628) };
                                                                                  t3fbff88eef4e4c8bc42b06e5ad07ea51 letpair_res_3280;
                                                                                  {
                                                                                    auto dstring2_fst_631 { std::get<0>(id_3279) };
                                                                                    auto dstring2_snd_632 { std::get<1>(id_3279) };
                                                                                    std::string id_3281 { dstring2_fst_631.toString() };
                                                                                    std::optional<std::string> id_3282 { id_3281 };
                                                                                    t3fbff88eef4e4c8bc42b06e5ad07ea51 id_3283 { id_3282, dstring2_snd_632 };
                                                                                    letpair_res_3280 = id_3283;
                                                                                  }
                                                                                  letpair_res_3278 = letpair_res_3280;
                                                                                }
                                                                                let_res_3277 = letpair_res_3278;
                                                                              }
                                                                              choose_res_3229 = let_res_3277;
                                                                            }
                                                                            t2a2e361c672135221e41ae1e54a712a2 let_res_3284;
                                                                            {
                                                                              t3fbff88eef4e4c8bc42b06e5ad07ea51 dtup_636 { choose_res_3229 };
                                                                              t2a2e361c672135221e41ae1e54a712a2 letpair_res_3285;
                                                                              {
                                                                                auto dtup_fst_637 { std::get<0>(dtup_636) };
                                                                                auto dtup_snd_638 { std::get<1>(dtup_636) };
                                                                                auto fun3286 { dessser::gen::function_name::of_row_binary };
                                                                                tc7d3fcfd06c0f02b3732e1754a18402b id_3287 { fun3286(dtup_snd_638) };
                                                                                t2a2e361c672135221e41ae1e54a712a2 letpair_res_3288;
                                                                                {
                                                                                  auto dtup_fst_640 { std::get<0>(id_3287) };
                                                                                  auto dtup_snd_641 { std::get<1>(id_3287) };
                                                                                  t9b471a57e45588f3795bf9ca91c31ff6 id_3289 { dtup_fst_619, dtup_fst_637, dtup_fst_640 };
                                                                                  t7c6bbe37b66fb3a66c00c4bd1bfc4369 id_3290 { std::in_place_index<0>, id_3289 };
                                                                                  t2a2e361c672135221e41ae1e54a712a2 id_3291 { id_3290, dtup_snd_641 };
                                                                                  letpair_res_3288 = id_3291;
                                                                                }
                                                                                letpair_res_3285 = letpair_res_3288;
                                                                              }
                                                                              let_res_3284 = letpair_res_3285;
                                                                            }
                                                                            letpair_res_3224 = let_res_3284;
                                                                          }
                                                                          let_res_3223 = letpair_res_3224;
                                                                        }
                                                                        choose_res_3156 = let_res_3223;
                                                                      } else {
                                                                        uint16_t id_3292 { 1 };
                                                                        bool id_3293 { bool(dsum1_fst_583 == id_3292) };
                                                                        Void id_3294 { ((void)(assert(id_3293)), VOID) };
                                                                        (void)id_3294;
                                                                        t45217dce3db5a9a49037839afd0048e8 id_3295 { fun2628(dsum1_snd_584) };
                                                                        t2a2e361c672135221e41ae1e54a712a2 letpair_res_3296;
                                                                        {
                                                                          auto dsum2_fst_586 { std::get<0>(id_3295) };
                                                                          auto dsum2_snd_587 { std::get<1>(id_3295) };
                                                                          t7c6bbe37b66fb3a66c00c4bd1bfc4369 id_3297 { std::in_place_index<1>, dsum2_fst_586 };
                                                                          t2a2e361c672135221e41ae1e54a712a2 id_3298 { id_3297, dsum2_snd_587 };
                                                                          letpair_res_3296 = id_3298;
                                                                        }
                                                                        choose_res_3156 = letpair_res_3296;
                                                                      }
                                                                      letpair_res_3153 = choose_res_3156;
                                                                    }
                                                                    let_res_3152 = letpair_res_3153;
                                                                  }
                                                                  t5c362d56d9dbfb12c2e68c4ed4a25c50 letpair_res_3299;
                                                                  {
                                                                    auto dlist3_fst_646 { std::get<0>(let_res_3152) };
                                                                    auto dlist3_snd_647 { std::get<1>(let_res_3152) };
                                                                    Lst<t7c6bbe37b66fb3a66c00c4bd1bfc4369> id_3300 { dlist3_fst_646, dlist2_fst_574 };
                                                                    t5c362d56d9dbfb12c2e68c4ed4a25c50 id_3301 { id_3300, dlist3_snd_647 };
                                                                    letpair_res_3299 = id_3301;
                                                                  }
                                                                  Void id_3302 { ((void)(inits_src_ref_571[id_3148] = letpair_res_3299), VOID) };
                                                                  (void)id_3302;
                                                                }
                                                                (void)VOID;
                                                              }
                                                              (void)VOID;
                                                              uint8_t id_3303 { 0 };
                                                              uint8_t id_3304 { 0 };
                                                              int32_t id_3305 { repeat_n_572[id_3304] };
                                                              int32_t id_3306 { 1L };
                                                              int32_t id_3307 { int32_t(id_3305 + id_3306) };
                                                              Void id_3308 { ((void)(repeat_n_572[id_3303] = id_3307), VOID) };
                                                              (void)id_3308;
                                                              (void)id_3308;
                                                            }
                                                          } while (while_flag_3141);
                                                          (void)VOID;
                                                        }
                                                        (void)VOID;
                                                        uint8_t id_3309 { 0 };
                                                        t5c362d56d9dbfb12c2e68c4ed4a25c50 id_3310 { inits_src_ref_571[id_3309] };
                                                        let_res_3138 = id_3310;
                                                      }
                                                      letpair_res_3134 = let_res_3138;
                                                    }
                                                    let_res_3133 = letpair_res_3134;
                                                  }
                                                  t5c362d56d9dbfb12c2e68c4ed4a25c50 letpair_res_3311;
                                                  {
                                                    auto dlist4_fst_649 { std::get<0>(let_res_3133) };
                                                    auto dlist4_snd_650 { std::get<1>(let_res_3133) };
                                                    t5c362d56d9dbfb12c2e68c4ed4a25c50 id_3312 { dlist4_fst_649, dlist4_snd_650 };
                                                    letpair_res_3311 = id_3312;
                                                  }
                                                  t45217dce3db5a9a49037839afd0048e8 let_res_3313;
                                                  {
                                                    t5c362d56d9dbfb12c2e68c4ed4a25c50 drec_651 { letpair_res_3311 };
                                                    t45217dce3db5a9a49037839afd0048e8 letpair_res_3314;
                                                    {
                                                      auto drec_fst_652 { std::get<0>(drec_651) };
                                                      auto drec_snd_653 { std::get<1>(drec_651) };
                                                      Size id_3315 { 0UL };
                                                      uint8_t id_3316 { drec_snd_653.peekU8(id_3315) };
                                                      uint8_t id_3317 { 1 };
                                                      bool id_3318 { bool(id_3316 == id_3317) };
                                                      tf1063a6af8c1fb72f0e0ee089d43d040 choose_res_3319;
                                                      if (id_3318) {
                                                        std::optional<dessser::gen::raql_expr::t_ext> id_3320 { std::nullopt };
                                                        Size id_3321 { 1UL };
                                                        Pointer id_3322 { drec_snd_653.skip(id_3321) };
                                                        tf1063a6af8c1fb72f0e0ee089d43d040 id_3323 { id_3320, id_3322 };
                                                        choose_res_3319 = id_3323;
                                                      } else {
                                                        auto fun3324 { dessser::gen::raql_expr::of_row_binary };
                                                        Size id_3325 { 1UL };
                                                        Pointer id_3326 { drec_snd_653.skip(id_3325) };
                                                        t1113e6691818baaf60a775527f6cc1ac id_3327 { fun3324(id_3326) };
                                                        tf1063a6af8c1fb72f0e0ee089d43d040 letpair_res_3328;
                                                        {
                                                          auto make1_1_fst_655 { std::get<0>(id_3327) };
                                                          auto make1_1_snd_656 { std::get<1>(id_3327) };
                                                          std::optional<dessser::gen::raql_expr::t_ext> id_3329 { make1_1_fst_655 };
                                                          tf1063a6af8c1fb72f0e0ee089d43d040 id_3330 { id_3329, make1_1_snd_656 };
                                                          letpair_res_3328 = id_3330;
                                                        }
                                                        choose_res_3319 = letpair_res_3328;
                                                      }
                                                      t45217dce3db5a9a49037839afd0048e8 let_res_3331;
                                                      {
                                                        tf1063a6af8c1fb72f0e0ee089d43d040 drec_657 { choose_res_3319 };
                                                        t45217dce3db5a9a49037839afd0048e8 letpair_res_3332;
                                                        {
                                                          auto drec_fst_658 { std::get<0>(drec_657) };
                                                          auto drec_snd_659 { std::get<1>(drec_657) };
                                                          uint32_t id_3333 { 0U };
                                                          Vec<1, uint32_t> id_3334 {  id_3333  };
                                                          t405eb186408556fed8f2c41523c07d13 let_res_3335;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_660 { id_3334 };
                                                            uint8_t id_3336 { 0 };
                                                            Vec<1, uint8_t> id_3337 {  id_3336  };
                                                            t405eb186408556fed8f2c41523c07d13 let_res_3338;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_661 { id_3337 };
                                                              Vec<1, Pointer> id_3339 {  drec_snd_659  };
                                                              t405eb186408556fed8f2c41523c07d13 let_res_3340;
                                                              {
                                                                Vec<1, Pointer> p_ref_662 { id_3339 };
                                                                bool while_flag_3341 { true };
                                                                do {
                                                                  uint8_t id_3342 { 0 };
                                                                  Pointer id_3343 { p_ref_662[id_3342] };
                                                                  tb3f98ea670610d40658a618de3ec7b90 id_3344 { id_3343.readU8() };
                                                                  bool let_res_3345;
                                                                  {
                                                                    tb3f98ea670610d40658a618de3ec7b90 leb128_663 { id_3344 };
                                                                    bool letpair_res_3346;
                                                                    {
                                                                      auto leb128_fst_664 { std::get<0>(leb128_663) };
                                                                      auto leb128_snd_665 { std::get<1>(leb128_663) };
                                                                      uint8_t id_3347 { 0 };
                                                                      Void id_3348 { ((void)(p_ref_662[id_3347] = leb128_snd_665), VOID) };
                                                                      (void)id_3348;
                                                                      uint8_t id_3349 { 0 };
                                                                      uint8_t id_3350 { 127 };
                                                                      uint8_t id_3351 { uint8_t(leb128_fst_664 & id_3350) };
                                                                      uint32_t id_3352 { uint32_t(id_3351) };
                                                                      uint8_t id_3353 { 0 };
                                                                      uint8_t id_3354 { shft_ref_661[id_3353] };
                                                                      uint32_t id_3355 { uint32_t(id_3352 << id_3354) };
                                                                      uint8_t id_3356 { 0 };
                                                                      uint32_t id_3357 { leb_ref_660[id_3356] };
                                                                      uint32_t id_3358 { uint32_t(id_3355 | id_3357) };
                                                                      Void id_3359 { ((void)(leb_ref_660[id_3349] = id_3358), VOID) };
                                                                      (void)id_3359;
                                                                      uint8_t id_3360 { 0 };
                                                                      uint8_t id_3361 { 0 };
                                                                      uint8_t id_3362 { shft_ref_661[id_3361] };
                                                                      uint8_t id_3363 { 7 };
                                                                      uint8_t id_3364 { uint8_t(id_3362 + id_3363) };
                                                                      Void id_3365 { ((void)(shft_ref_661[id_3360] = id_3364), VOID) };
                                                                      (void)id_3365;
                                                                      uint8_t id_3366 { 128 };
                                                                      bool id_3367 { bool(leb128_fst_664 >= id_3366) };
                                                                      letpair_res_3346 = id_3367;
                                                                    }
                                                                    let_res_3345 = letpair_res_3346;
                                                                  }
                                                                  while_flag_3341 = let_res_3345;
                                                                  if (while_flag_3341) {
                                                                    (void)VOID;
                                                                  }
                                                                } while (while_flag_3341);
                                                                (void)VOID;
                                                                uint8_t id_3368 { 0 };
                                                                uint32_t id_3369 { leb_ref_660[id_3368] };
                                                                uint8_t id_3370 { 0 };
                                                                Pointer id_3371 { p_ref_662[id_3370] };
                                                                t405eb186408556fed8f2c41523c07d13 id_3372 { id_3369, id_3371 };
                                                                let_res_3340 = id_3372;
                                                              }
                                                              let_res_3338 = let_res_3340;
                                                            }
                                                            let_res_3335 = let_res_3338;
                                                          }
                                                          t0dfa866705b76efff53e4aa97228a967 let_res_3373;
                                                          {
                                                            t405eb186408556fed8f2c41523c07d13 dlist1_669 { let_res_3335 };
                                                            t0dfa866705b76efff53e4aa97228a967 letpair_res_3374;
                                                            {
                                                              auto dlist1_fst_670 { std::get<0>(dlist1_669) };
                                                              auto dlist1_snd_671 { std::get<1>(dlist1_669) };
                                                              Lst<dessser::gen::field_name::t_ext> endoflist_3375;
                                                              t0dfa866705b76efff53e4aa97228a967 id_3376 { endoflist_3375, dlist1_snd_671 };
                                                              Vec<1, t0dfa866705b76efff53e4aa97228a967> id_3377 {  id_3376  };
                                                              t0dfa866705b76efff53e4aa97228a967 let_res_3378;
                                                              {
                                                                Vec<1, t0dfa866705b76efff53e4aa97228a967> inits_src_ref_672 { id_3377 };
                                                                int32_t id_3379 { 0L };
                                                                Vec<1, int32_t> id_3380 {  id_3379  };
                                                                {
                                                                  Vec<1, int32_t> repeat_n_673 { id_3380 };
                                                                  bool while_flag_3381 { true };
                                                                  do {
                                                                    int32_t id_3382 { int32_t(dlist1_fst_670) };
                                                                    uint8_t id_3383 { 0 };
                                                                    int32_t id_3384 { repeat_n_673[id_3383] };
                                                                    bool id_3385 { bool(id_3382 > id_3384) };
                                                                    while_flag_3381 = id_3385;
                                                                    if (while_flag_3381) {
                                                                      uint8_t id_3386 { 0 };
                                                                      t0dfa866705b76efff53e4aa97228a967 id_3387 { inits_src_ref_672[id_3386] };
                                                                      {
                                                                        t0dfa866705b76efff53e4aa97228a967 dlist2_674 { id_3387 };
                                                                        {
                                                                          auto dlist2_fst_675 { std::get<0>(dlist2_674) };
                                                                          auto dlist2_snd_676 { std::get<1>(dlist2_674) };
                                                                          uint8_t id_3388 { 0 };
                                                                          auto fun3389 { dessser::gen::field_name::of_row_binary };
                                                                          t273a2b7978f5b466a128a51c1cc4a27b id_3390 { fun3389(dlist2_snd_676) };
                                                                          t0dfa866705b76efff53e4aa97228a967 letpair_res_3391;
                                                                          {
                                                                            auto dlist3_fst_678 { std::get<0>(id_3390) };
                                                                            auto dlist3_snd_679 { std::get<1>(id_3390) };
                                                                            Lst<dessser::gen::field_name::t_ext> id_3392 { dlist3_fst_678, dlist2_fst_675 };
                                                                            t0dfa866705b76efff53e4aa97228a967 id_3393 { id_3392, dlist3_snd_679 };
                                                                            letpair_res_3391 = id_3393;
                                                                          }
                                                                          Void id_3394 { ((void)(inits_src_ref_672[id_3388] = letpair_res_3391), VOID) };
                                                                          (void)id_3394;
                                                                        }
                                                                        (void)VOID;
                                                                      }
                                                                      (void)VOID;
                                                                      uint8_t id_3395 { 0 };
                                                                      uint8_t id_3396 { 0 };
                                                                      int32_t id_3397 { repeat_n_673[id_3396] };
                                                                      int32_t id_3398 { 1L };
                                                                      int32_t id_3399 { int32_t(id_3397 + id_3398) };
                                                                      Void id_3400 { ((void)(repeat_n_673[id_3395] = id_3399), VOID) };
                                                                      (void)id_3400;
                                                                      (void)id_3400;
                                                                    }
                                                                  } while (while_flag_3381);
                                                                  (void)VOID;
                                                                }
                                                                (void)VOID;
                                                                uint8_t id_3401 { 0 };
                                                                t0dfa866705b76efff53e4aa97228a967 id_3402 { inits_src_ref_672[id_3401] };
                                                                let_res_3378 = id_3402;
                                                              }
                                                              letpair_res_3374 = let_res_3378;
                                                            }
                                                            let_res_3373 = letpair_res_3374;
                                                          }
                                                          t45217dce3db5a9a49037839afd0048e8 letpair_res_3403;
                                                          {
                                                            auto dlist4_fst_681 { std::get<0>(let_res_3373) };
                                                            auto dlist4_snd_682 { std::get<1>(let_res_3373) };
                                                            ta2fe18cae70948742cabb6081fd22a0c id_3404 { .fields = drec_fst_411, .and_all_others = drec_fst_440, .sort = drec_fst_484, .where = drec_fst_487, .event_time = drec_fst_493, .notifications = drec_fst_519, .key = drec_fst_545, .commit_cond = drec_fst_548, .commit_before = drec_fst_554, .flush_how = drec_fst_557, .from = drec_fst_652, .every = drec_fst_658, .factors = dlist4_fst_681 };
                                                            t* id_3405 { new t(std::in_place_index<0>, id_3404) };
                                                            t45217dce3db5a9a49037839afd0048e8 id_3406 { id_3405, dlist4_snd_682 };
                                                            letpair_res_3403 = id_3406;
                                                          }
                                                          letpair_res_3332 = letpair_res_3403;
                                                        }
                                                        let_res_3331 = letpair_res_3332;
                                                      }
                                                      letpair_res_3314 = let_res_3331;
                                                    }
                                                    let_res_3313 = letpair_res_3314;
                                                  }
                                                  letpair_res_3092 = let_res_3313;
                                                }
                                                let_res_3091 = letpair_res_3092;
                                              }
                                              letpair_res_3088 = let_res_3091;
                                            }
                                            let_res_3087 = letpair_res_3088;
                                          }
                                          letpair_res_3080 = let_res_3087;
                                        }
                                        let_res_3079 = letpair_res_3080;
                                      }
                                      letpair_res_3076 = let_res_3079;
                                    }
                                    let_res_3075 = letpair_res_3076;
                                  }
                                  letpair_res_3002 = let_res_3075;
                                }
                                let_res_3001 = letpair_res_3002;
                              }
                              letpair_res_2928 = let_res_3001;
                            }
                            let_res_2927 = letpair_res_2928;
                          }
                          letpair_res_2910 = let_res_2927;
                        }
                        let_res_2909 = letpair_res_2910;
                      }
                      letpair_res_2906 = let_res_2909;
                    }
                    let_res_2905 = letpair_res_2906;
                  }
                  letpair_res_2796 = let_res_2905;
                }
                let_res_2795 = letpair_res_2796;
              }
              letpair_res_2710 = let_res_2795;
            }
            let_res_2709 = letpair_res_2710;
          }
          choose_res_2636 = let_res_2709;
        } else {
          uint16_t id_3407 { 1 };
          bool id_3408 { bool(id_3407 == dsum1_fst_63) };
          t45217dce3db5a9a49037839afd0048e8 choose_res_3409;
          if (id_3408) {
            t22a32080ad88ab548b80077a17b7dd46 id_3410 { dsum1_snd_64.readU16Le() };
            t22a32080ad88ab548b80077a17b7dd46 letpair_res_3411;
            {
              auto du16_fst_119 { std::get<0>(id_3410) };
              auto du16_snd_120 { std::get<1>(id_3410) };
              t22a32080ad88ab548b80077a17b7dd46 id_3412 { du16_fst_119, du16_snd_120 };
              letpair_res_3411 = id_3412;
            }
            t1313b4ee18248dd765ed6ae8b0058504 let_res_3413;
            {
              t22a32080ad88ab548b80077a17b7dd46 dsum1_124 { letpair_res_3411 };
              t1313b4ee18248dd765ed6ae8b0058504 letpair_res_3414;
              {
                auto dsum1_fst_125 { std::get<0>(dsum1_124) };
                auto dsum1_snd_126 { std::get<1>(dsum1_124) };
                uint16_t id_3415 { 0 };
                bool id_3416 { bool(id_3415 == dsum1_fst_125) };
                t1313b4ee18248dd765ed6ae8b0058504 choose_res_3417;
                if (id_3416) {
                  auto fun3418 { dessser::gen::raql_expr::of_row_binary };
                  t1113e6691818baaf60a775527f6cc1ac id_3419 { fun3418(dsum1_snd_126) };
                  t1313b4ee18248dd765ed6ae8b0058504 let_res_3420;
                  {
                    t1113e6691818baaf60a775527f6cc1ac drec_213 { id_3419 };
                    t1313b4ee18248dd765ed6ae8b0058504 letpair_res_3421;
                    {
                      auto drec_fst_214 { std::get<0>(drec_213) };
                      auto drec_snd_215 { std::get<1>(drec_213) };
                      Size id_3422 { 0UL };
                      uint8_t id_3423 { drec_snd_215.peekU8(id_3422) };
                      uint8_t id_3424 { 1 };
                      bool id_3425 { bool(id_3423 == id_3424) };
                      tf1063a6af8c1fb72f0e0ee089d43d040 choose_res_3426;
                      if (id_3425) {
                        std::optional<dessser::gen::raql_expr::t_ext> id_3427 { std::nullopt };
                        Size id_3428 { 1UL };
                        Pointer id_3429 { drec_snd_215.skip(id_3428) };
                        tf1063a6af8c1fb72f0e0ee089d43d040 id_3430 { id_3427, id_3429 };
                        choose_res_3426 = id_3430;
                      } else {
                        auto fun3431 { dessser::gen::raql_expr::of_row_binary };
                        Size id_3432 { 1UL };
                        Pointer id_3433 { drec_snd_215.skip(id_3432) };
                        t1113e6691818baaf60a775527f6cc1ac id_3434 { fun3431(id_3433) };
                        tf1063a6af8c1fb72f0e0ee089d43d040 letpair_res_3435;
                        {
                          auto make1_1_fst_217 { std::get<0>(id_3434) };
                          auto make1_1_snd_218 { std::get<1>(id_3434) };
                          std::optional<dessser::gen::raql_expr::t_ext> id_3436 { make1_1_fst_217 };
                          tf1063a6af8c1fb72f0e0ee089d43d040 id_3437 { id_3436, make1_1_snd_218 };
                          letpair_res_3435 = id_3437;
                        }
                        choose_res_3426 = letpair_res_3435;
                      }
                      t1313b4ee18248dd765ed6ae8b0058504 let_res_3438;
                      {
                        tf1063a6af8c1fb72f0e0ee089d43d040 drec_219 { choose_res_3426 };
                        t1313b4ee18248dd765ed6ae8b0058504 letpair_res_3439;
                        {
                          auto drec_fst_220 { std::get<0>(drec_219) };
                          auto drec_snd_221 { std::get<1>(drec_219) };
                          auto fun3440 { dessser::gen::raql_expr::of_row_binary };
                          t1113e6691818baaf60a775527f6cc1ac id_3441 { fun3440(drec_snd_221) };
                          t1313b4ee18248dd765ed6ae8b0058504 letpair_res_3442;
                          {
                            auto drec_fst_223 { std::get<0>(id_3441) };
                            auto drec_snd_224 { std::get<1>(id_3441) };
                            ta828a76692b94aa6a15973ace224bedc id_3443 { .fname = drec_fst_214, .preprocessor = drec_fst_220, .unlink = drec_fst_223 };
                            tf708b6568b9bac184e3f5da3a64f4419 id_3444 { std::in_place_index<0>, id_3443 };
                            t1313b4ee18248dd765ed6ae8b0058504 id_3445 { id_3444, drec_snd_224 };
                            letpair_res_3442 = id_3445;
                          }
                          letpair_res_3439 = letpair_res_3442;
                        }
                        let_res_3438 = letpair_res_3439;
                      }
                      letpair_res_3421 = let_res_3438;
                    }
                    let_res_3420 = letpair_res_3421;
                  }
                  choose_res_3417 = let_res_3420;
                } else {
                  uint16_t id_3446 { 1 };
                  bool id_3447 { bool(dsum1_fst_125 == id_3446) };
                  Void id_3448 { ((void)(assert(id_3447)), VOID) };
                  (void)id_3448;
                  uint32_t id_3449 { 0U };
                  Vec<1, uint32_t> id_3450 {  id_3449  };
                  t405eb186408556fed8f2c41523c07d13 let_res_3451;
                  {
                    Vec<1, uint32_t> leb_ref_127 { id_3450 };
                    uint8_t id_3452 { 0 };
                    Vec<1, uint8_t> id_3453 {  id_3452  };
                    t405eb186408556fed8f2c41523c07d13 let_res_3454;
                    {
                      Vec<1, uint8_t> shft_ref_128 { id_3453 };
                      Vec<1, Pointer> id_3455 {  dsum1_snd_126  };
                      t405eb186408556fed8f2c41523c07d13 let_res_3456;
                      {
                        Vec<1, Pointer> p_ref_129 { id_3455 };
                        bool while_flag_3457 { true };
                        do {
                          uint8_t id_3458 { 0 };
                          Pointer id_3459 { p_ref_129[id_3458] };
                          tb3f98ea670610d40658a618de3ec7b90 id_3460 { id_3459.readU8() };
                          bool let_res_3461;
                          {
                            tb3f98ea670610d40658a618de3ec7b90 leb128_130 { id_3460 };
                            bool letpair_res_3462;
                            {
                              auto leb128_fst_131 { std::get<0>(leb128_130) };
                              auto leb128_snd_132 { std::get<1>(leb128_130) };
                              uint8_t id_3463 { 0 };
                              Void id_3464 { ((void)(p_ref_129[id_3463] = leb128_snd_132), VOID) };
                              (void)id_3464;
                              uint8_t id_3465 { 0 };
                              uint8_t id_3466 { 127 };
                              uint8_t id_3467 { uint8_t(leb128_fst_131 & id_3466) };
                              uint32_t id_3468 { uint32_t(id_3467) };
                              uint8_t id_3469 { 0 };
                              uint8_t id_3470 { shft_ref_128[id_3469] };
                              uint32_t id_3471 { uint32_t(id_3468 << id_3470) };
                              uint8_t id_3472 { 0 };
                              uint32_t id_3473 { leb_ref_127[id_3472] };
                              uint32_t id_3474 { uint32_t(id_3471 | id_3473) };
                              Void id_3475 { ((void)(leb_ref_127[id_3465] = id_3474), VOID) };
                              (void)id_3475;
                              uint8_t id_3476 { 0 };
                              uint8_t id_3477 { 0 };
                              uint8_t id_3478 { shft_ref_128[id_3477] };
                              uint8_t id_3479 { 7 };
                              uint8_t id_3480 { uint8_t(id_3478 + id_3479) };
                              Void id_3481 { ((void)(shft_ref_128[id_3476] = id_3480), VOID) };
                              (void)id_3481;
                              uint8_t id_3482 { 128 };
                              bool id_3483 { bool(leb128_fst_131 >= id_3482) };
                              letpair_res_3462 = id_3483;
                            }
                            let_res_3461 = letpair_res_3462;
                          }
                          while_flag_3457 = let_res_3461;
                          if (while_flag_3457) {
                            (void)VOID;
                          }
                        } while (while_flag_3457);
                        (void)VOID;
                        uint8_t id_3484 { 0 };
                        uint32_t id_3485 { leb_ref_127[id_3484] };
                        uint8_t id_3486 { 0 };
                        Pointer id_3487 { p_ref_129[id_3486] };
                        t405eb186408556fed8f2c41523c07d13 id_3488 { id_3485, id_3487 };
                        let_res_3456 = id_3488;
                      }
                      let_res_3454 = let_res_3456;
                    }
                    let_res_3451 = let_res_3454;
                  }
                  t20007ff08d465535358862e7faf3b556 let_res_3489;
                  {
                    t405eb186408556fed8f2c41523c07d13 dlist1_136 { let_res_3451 };
                    t20007ff08d465535358862e7faf3b556 letpair_res_3490;
                    {
                      auto dlist1_fst_137 { std::get<0>(dlist1_136) };
                      auto dlist1_snd_138 { std::get<1>(dlist1_136) };
                      Lst<tcd17c85cefeae7a860c0732c05eaeaed> endoflist_3491;
                      t20007ff08d465535358862e7faf3b556 id_3492 { endoflist_3491, dlist1_snd_138 };
                      Vec<1, t20007ff08d465535358862e7faf3b556> id_3493 {  id_3492  };
                      t20007ff08d465535358862e7faf3b556 let_res_3494;
                      {
                        Vec<1, t20007ff08d465535358862e7faf3b556> inits_src_ref_139 { id_3493 };
                        int32_t id_3495 { 0L };
                        Vec<1, int32_t> id_3496 {  id_3495  };
                        {
                          Vec<1, int32_t> repeat_n_140 { id_3496 };
                          bool while_flag_3497 { true };
                          do {
                            int32_t id_3498 { int32_t(dlist1_fst_137) };
                            uint8_t id_3499 { 0 };
                            int32_t id_3500 { repeat_n_140[id_3499] };
                            bool id_3501 { bool(id_3498 > id_3500) };
                            while_flag_3497 = id_3501;
                            if (while_flag_3497) {
                              uint8_t id_3502 { 0 };
                              t20007ff08d465535358862e7faf3b556 id_3503 { inits_src_ref_139[id_3502] };
                              {
                                t20007ff08d465535358862e7faf3b556 dlist2_141 { id_3503 };
                                {
                                  auto dlist2_fst_142 { std::get<0>(dlist2_141) };
                                  auto dlist2_snd_143 { std::get<1>(dlist2_141) };
                                  uint8_t id_3504 { 0 };
                                  uint32_t id_3505 { 0U };
                                  Vec<1, uint32_t> id_3506 {  id_3505  };
                                  t8beb80162423aee37bd383e9b6834c9c let_res_3507;
                                  {
                                    Vec<1, uint32_t> leb_ref_144 { id_3506 };
                                    uint8_t id_3508 { 0 };
                                    Vec<1, uint8_t> id_3509 {  id_3508  };
                                    t8beb80162423aee37bd383e9b6834c9c let_res_3510;
                                    {
                                      Vec<1, uint8_t> shft_ref_145 { id_3509 };
                                      Vec<1, Pointer> id_3511 {  dlist2_snd_143  };
                                      t8beb80162423aee37bd383e9b6834c9c let_res_3512;
                                      {
                                        Vec<1, Pointer> p_ref_146 { id_3511 };
                                        bool while_flag_3513 { true };
                                        do {
                                          uint8_t id_3514 { 0 };
                                          Pointer id_3515 { p_ref_146[id_3514] };
                                          tb3f98ea670610d40658a618de3ec7b90 id_3516 { id_3515.readU8() };
                                          bool let_res_3517;
                                          {
                                            tb3f98ea670610d40658a618de3ec7b90 leb128_147 { id_3516 };
                                            bool letpair_res_3518;
                                            {
                                              auto leb128_fst_148 { std::get<0>(leb128_147) };
                                              auto leb128_snd_149 { std::get<1>(leb128_147) };
                                              uint8_t id_3519 { 0 };
                                              Void id_3520 { ((void)(p_ref_146[id_3519] = leb128_snd_149), VOID) };
                                              (void)id_3520;
                                              uint8_t id_3521 { 0 };
                                              uint8_t id_3522 { 127 };
                                              uint8_t id_3523 { uint8_t(leb128_fst_148 & id_3522) };
                                              uint32_t id_3524 { uint32_t(id_3523) };
                                              uint8_t id_3525 { 0 };
                                              uint8_t id_3526 { shft_ref_145[id_3525] };
                                              uint32_t id_3527 { uint32_t(id_3524 << id_3526) };
                                              uint8_t id_3528 { 0 };
                                              uint32_t id_3529 { leb_ref_144[id_3528] };
                                              uint32_t id_3530 { uint32_t(id_3527 | id_3529) };
                                              Void id_3531 { ((void)(leb_ref_144[id_3521] = id_3530), VOID) };
                                              (void)id_3531;
                                              uint8_t id_3532 { 0 };
                                              uint8_t id_3533 { 0 };
                                              uint8_t id_3534 { shft_ref_145[id_3533] };
                                              uint8_t id_3535 { 7 };
                                              uint8_t id_3536 { uint8_t(id_3534 + id_3535) };
                                              Void id_3537 { ((void)(shft_ref_145[id_3532] = id_3536), VOID) };
                                              (void)id_3537;
                                              uint8_t id_3538 { 128 };
                                              bool id_3539 { bool(leb128_fst_148 >= id_3538) };
                                              letpair_res_3518 = id_3539;
                                            }
                                            let_res_3517 = letpair_res_3518;
                                          }
                                          while_flag_3513 = let_res_3517;
                                          if (while_flag_3513) {
                                            (void)VOID;
                                          }
                                        } while (while_flag_3513);
                                        (void)VOID;
                                        uint8_t id_3540 { 0 };
                                        uint32_t id_3541 { leb_ref_144[id_3540] };
                                        Size id_3542 { Size(id_3541) };
                                        uint8_t id_3543 { 0 };
                                        Pointer id_3544 { p_ref_146[id_3543] };
                                        t8beb80162423aee37bd383e9b6834c9c id_3545 { id_3542, id_3544 };
                                        let_res_3512 = id_3545;
                                      }
                                      let_res_3510 = let_res_3512;
                                    }
                                    let_res_3507 = let_res_3510;
                                  }
                                  tef94b55d8809251f13165d9a05bd9d0e let_res_3546;
                                  {
                                    t8beb80162423aee37bd383e9b6834c9c dstring1_150 { let_res_3507 };
                                    tef94b55d8809251f13165d9a05bd9d0e letpair_res_3547;
                                    {
                                      auto dstring1_fst_151 { std::get<0>(dstring1_150) };
                                      auto dstring1_snd_152 { std::get<1>(dstring1_150) };
                                      t188345aa49abd0cb47ff73fedc219f08 id_3548 { dstring1_snd_152.readBytes(dstring1_fst_151) };
                                      tef94b55d8809251f13165d9a05bd9d0e letpair_res_3549;
                                      {
                                        auto dstring2_fst_154 { std::get<0>(id_3548) };
                                        auto dstring2_snd_155 { std::get<1>(id_3548) };
                                        std::string id_3550 { dstring2_fst_154.toString() };
                                        tef94b55d8809251f13165d9a05bd9d0e id_3551 { id_3550, dstring2_snd_155 };
                                        letpair_res_3549 = id_3551;
                                      }
                                      letpair_res_3547 = letpair_res_3549;
                                    }
                                    let_res_3546 = letpair_res_3547;
                                  }
                                  t20007ff08d465535358862e7faf3b556 let_res_3552;
                                  {
                                    tef94b55d8809251f13165d9a05bd9d0e dtup_156 { let_res_3546 };
                                    t20007ff08d465535358862e7faf3b556 letpair_res_3553;
                                    {
                                      auto dtup_fst_157 { std::get<0>(dtup_156) };
                                      auto dtup_snd_158 { std::get<1>(dtup_156) };
                                      auto fun3554 { dessser::gen::raql_expr::of_row_binary };
                                      t1113e6691818baaf60a775527f6cc1ac id_3555 { fun3554(dtup_snd_158) };
                                      t20007ff08d465535358862e7faf3b556 letpair_res_3556;
                                      {
                                        auto dtup_fst_160 { std::get<0>(id_3555) };
                                        auto dtup_snd_161 { std::get<1>(id_3555) };
                                        tcd17c85cefeae7a860c0732c05eaeaed id_3557 { dtup_fst_157, dtup_fst_160 };
                                        Lst<tcd17c85cefeae7a860c0732c05eaeaed> id_3558 { id_3557, dlist2_fst_142 };
                                        t20007ff08d465535358862e7faf3b556 id_3559 { id_3558, dtup_snd_161 };
                                        letpair_res_3556 = id_3559;
                                      }
                                      letpair_res_3553 = letpair_res_3556;
                                    }
                                    let_res_3552 = letpair_res_3553;
                                  }
                                  Void id_3560 { ((void)(inits_src_ref_139[id_3504] = let_res_3552), VOID) };
                                  (void)id_3560;
                                }
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_3561 { 0 };
                              uint8_t id_3562 { 0 };
                              int32_t id_3563 { repeat_n_140[id_3562] };
                              int32_t id_3564 { 1L };
                              int32_t id_3565 { int32_t(id_3563 + id_3564) };
                              Void id_3566 { ((void)(repeat_n_140[id_3561] = id_3565), VOID) };
                              (void)id_3566;
                              (void)id_3566;
                            }
                          } while (while_flag_3497);
                          (void)VOID;
                        }
                        (void)VOID;
                        uint8_t id_3567 { 0 };
                        t20007ff08d465535358862e7faf3b556 id_3568 { inits_src_ref_139[id_3567] };
                        let_res_3494 = id_3568;
                      }
                      letpair_res_3490 = let_res_3494;
                    }
                    let_res_3489 = letpair_res_3490;
                  }
                  t20007ff08d465535358862e7faf3b556 letpair_res_3569;
                  {
                    auto dlist4_fst_166 { std::get<0>(let_res_3489) };
                    auto dlist4_snd_167 { std::get<1>(let_res_3489) };
                    t20007ff08d465535358862e7faf3b556 id_3570 { dlist4_fst_166, dlist4_snd_167 };
                    letpair_res_3569 = id_3570;
                  }
                  t1313b4ee18248dd765ed6ae8b0058504 let_res_3571;
                  {
                    t20007ff08d465535358862e7faf3b556 drec_168 { letpair_res_3569 };
                    t1313b4ee18248dd765ed6ae8b0058504 letpair_res_3572;
                    {
                      auto drec_fst_169 { std::get<0>(drec_168) };
                      auto drec_snd_170 { std::get<1>(drec_168) };
                      auto fun3573 { dessser::gen::raql_expr::of_row_binary };
                      t1113e6691818baaf60a775527f6cc1ac id_3574 { fun3573(drec_snd_170) };
                      t1313b4ee18248dd765ed6ae8b0058504 let_res_3575;
                      {
                        t1113e6691818baaf60a775527f6cc1ac drec_171 { id_3574 };
                        t1313b4ee18248dd765ed6ae8b0058504 letpair_res_3576;
                        {
                          auto drec_fst_172 { std::get<0>(drec_171) };
                          auto drec_snd_173 { std::get<1>(drec_171) };
                          Size id_3577 { 0UL };
                          uint8_t id_3578 { drec_snd_173.peekU8(id_3577) };
                          uint8_t id_3579 { 1 };
                          bool id_3580 { bool(id_3578 == id_3579) };
                          tf1063a6af8c1fb72f0e0ee089d43d040 choose_res_3581;
                          if (id_3580) {
                            std::optional<dessser::gen::raql_expr::t_ext> id_3582 { std::nullopt };
                            Size id_3583 { 1UL };
                            Pointer id_3584 { drec_snd_173.skip(id_3583) };
                            tf1063a6af8c1fb72f0e0ee089d43d040 id_3585 { id_3582, id_3584 };
                            choose_res_3581 = id_3585;
                          } else {
                            auto fun3586 { dessser::gen::raql_expr::of_row_binary };
                            Size id_3587 { 1UL };
                            Pointer id_3588 { drec_snd_173.skip(id_3587) };
                            t1113e6691818baaf60a775527f6cc1ac id_3589 { fun3586(id_3588) };
                            tf1063a6af8c1fb72f0e0ee089d43d040 letpair_res_3590;
                            {
                              auto make1_1_fst_175 { std::get<0>(id_3589) };
                              auto make1_1_snd_176 { std::get<1>(id_3589) };
                              std::optional<dessser::gen::raql_expr::t_ext> id_3591 { make1_1_fst_175 };
                              tf1063a6af8c1fb72f0e0ee089d43d040 id_3592 { id_3591, make1_1_snd_176 };
                              letpair_res_3590 = id_3592;
                            }
                            choose_res_3581 = letpair_res_3590;
                          }
                          t1313b4ee18248dd765ed6ae8b0058504 let_res_3593;
                          {
                            tf1063a6af8c1fb72f0e0ee089d43d040 drec_177 { choose_res_3581 };
                            t1313b4ee18248dd765ed6ae8b0058504 letpair_res_3594;
                            {
                              auto drec_fst_178 { std::get<0>(drec_177) };
                              auto drec_snd_179 { std::get<1>(drec_177) };
                              t22a32080ad88ab548b80077a17b7dd46 id_3595 { drec_snd_179.readU16Le() };
                              t22a32080ad88ab548b80077a17b7dd46 letpair_res_3596;
                              {
                                auto du16_fst_181 { std::get<0>(id_3595) };
                                auto du16_snd_182 { std::get<1>(id_3595) };
                                t22a32080ad88ab548b80077a17b7dd46 id_3597 { du16_fst_181, du16_snd_182 };
                                letpair_res_3596 = id_3597;
                              }
                              tae0102a98baabe959d4e6cb1e047e44b let_res_3598;
                              {
                                t22a32080ad88ab548b80077a17b7dd46 dsum1_186 { letpair_res_3596 };
                                tae0102a98baabe959d4e6cb1e047e44b letpair_res_3599;
                                {
                                  auto dsum1_fst_187 { std::get<0>(dsum1_186) };
                                  auto dsum1_snd_188 { std::get<1>(dsum1_186) };
                                  uint16_t id_3600 { 0 };
                                  bool id_3601 { bool(id_3600 == dsum1_fst_187) };
                                  tae0102a98baabe959d4e6cb1e047e44b choose_res_3602;
                                  if (id_3601) {
                                    (void)VOID;
                                    t6f8c1c936ce8cf2fe9dc881177aa3e62 id_3603 { std::in_place_index<0>, VOID };
                                    tae0102a98baabe959d4e6cb1e047e44b id_3604 { id_3603, dsum1_snd_188 };
                                    choose_res_3602 = id_3604;
                                  } else {
                                    uint16_t id_3605 { 1 };
                                    bool id_3606 { bool(id_3605 == dsum1_fst_187) };
                                    tae0102a98baabe959d4e6cb1e047e44b choose_res_3607;
                                    if (id_3606) {
                                      auto fun3608 { dessser::gen::raql_expr::of_row_binary };
                                      t1113e6691818baaf60a775527f6cc1ac id_3609 { fun3608(dsum1_snd_188) };
                                      tae0102a98baabe959d4e6cb1e047e44b letpair_res_3610;
                                      {
                                        auto dsum2_fst_202 { std::get<0>(id_3609) };
                                        auto dsum2_snd_203 { std::get<1>(id_3609) };
                                        t6f8c1c936ce8cf2fe9dc881177aa3e62 id_3611 { std::in_place_index<1>, dsum2_fst_202 };
                                        tae0102a98baabe959d4e6cb1e047e44b id_3612 { id_3611, dsum2_snd_203 };
                                        letpair_res_3610 = id_3612;
                                      }
                                      choose_res_3607 = letpair_res_3610;
                                    } else {
                                      uint16_t id_3613 { 2 };
                                      bool id_3614 { bool(id_3613 == dsum1_fst_187) };
                                      tae0102a98baabe959d4e6cb1e047e44b choose_res_3615;
                                      if (id_3614) {
                                        (void)VOID;
                                        t6f8c1c936ce8cf2fe9dc881177aa3e62 id_3616 { std::in_place_index<2>, VOID };
                                        tae0102a98baabe959d4e6cb1e047e44b id_3617 { id_3616, dsum1_snd_188 };
                                        choose_res_3615 = id_3617;
                                      } else {
                                        uint16_t id_3618 { 3 };
                                        bool id_3619 { bool(dsum1_fst_187 == id_3618) };
                                        Void id_3620 { ((void)(assert(id_3619)), VOID) };
                                        (void)id_3620;
                                        auto fun3621 { dessser::gen::raql_expr::of_row_binary };
                                        t1113e6691818baaf60a775527f6cc1ac id_3622 { fun3621(dsum1_snd_188) };
                                        tae0102a98baabe959d4e6cb1e047e44b let_res_3623;
                                        {
                                          t1113e6691818baaf60a775527f6cc1ac drec_189 { id_3622 };
                                          tae0102a98baabe959d4e6cb1e047e44b letpair_res_3624;
                                          {
                                            auto drec_fst_190 { std::get<0>(drec_189) };
                                            auto drec_snd_191 { std::get<1>(drec_189) };
                                            auto fun3625 { dessser::gen::raql_expr::of_row_binary };
                                            t1113e6691818baaf60a775527f6cc1ac id_3626 { fun3625(drec_snd_191) };
                                            tae0102a98baabe959d4e6cb1e047e44b letpair_res_3627;
                                            {
                                              auto drec_fst_193 { std::get<0>(id_3626) };
                                              auto drec_snd_194 { std::get<1>(id_3626) };
                                              tee7dccc2726e2723462077a878a69c99 id_3628 { .after_max_secs = drec_fst_190, .after_max_events = drec_fst_193 };
                                              t6f8c1c936ce8cf2fe9dc881177aa3e62 id_3629 { std::in_place_index<3>, id_3628 };
                                              tae0102a98baabe959d4e6cb1e047e44b id_3630 { id_3629, drec_snd_194 };
                                              letpair_res_3627 = id_3630;
                                            }
                                            letpair_res_3624 = letpair_res_3627;
                                          }
                                          let_res_3623 = letpair_res_3624;
                                        }
                                        choose_res_3615 = let_res_3623;
                                      }
                                      choose_res_3607 = choose_res_3615;
                                    }
                                    choose_res_3602 = choose_res_3607;
                                  }
                                  letpair_res_3599 = choose_res_3602;
                                }
                                let_res_3598 = letpair_res_3599;
                              }
                              t1313b4ee18248dd765ed6ae8b0058504 letpair_res_3631;
                              {
                                auto drec_fst_208 { std::get<0>(let_res_3598) };
                                auto drec_snd_209 { std::get<1>(let_res_3598) };
                                te6ac276a1b6044b9474a56a7da93a611 id_3632 { .options = drec_fst_169, .topic = drec_fst_172, .partitions = drec_fst_178, .restart_from = drec_fst_208 };
                                tf708b6568b9bac184e3f5da3a64f4419 id_3633 { std::in_place_index<1>, id_3632 };
                                t1313b4ee18248dd765ed6ae8b0058504 id_3634 { id_3633, drec_snd_209 };
                                letpair_res_3631 = id_3634;
                              }
                              letpair_res_3594 = letpair_res_3631;
                            }
                            let_res_3593 = letpair_res_3594;
                          }
                          letpair_res_3576 = let_res_3593;
                        }
                        let_res_3575 = letpair_res_3576;
                      }
                      letpair_res_3572 = let_res_3575;
                    }
                    let_res_3571 = letpair_res_3572;
                  }
                  choose_res_3417 = let_res_3571;
                }
                letpair_res_3414 = choose_res_3417;
              }
              let_res_3413 = letpair_res_3414;
            }
            t45217dce3db5a9a49037839afd0048e8 let_res_3635;
            {
              t1313b4ee18248dd765ed6ae8b0058504 drec_228 { let_res_3413 };
              t45217dce3db5a9a49037839afd0048e8 letpair_res_3636;
              {
                auto drec_fst_229 { std::get<0>(drec_228) };
                auto drec_snd_230 { std::get<1>(drec_228) };
                t22a32080ad88ab548b80077a17b7dd46 id_3637 { drec_snd_230.readU16Le() };
                t22a32080ad88ab548b80077a17b7dd46 letpair_res_3638;
                {
                  auto du16_fst_232 { std::get<0>(id_3637) };
                  auto du16_snd_233 { std::get<1>(id_3637) };
                  t22a32080ad88ab548b80077a17b7dd46 id_3639 { du16_fst_232, du16_snd_233 };
                  letpair_res_3638 = id_3639;
                }
                t61bdb3f643c3108bb612fc36951fce20 let_res_3640;
                {
                  t22a32080ad88ab548b80077a17b7dd46 dsum1_237 { letpair_res_3638 };
                  t61bdb3f643c3108bb612fc36951fce20 letpair_res_3641;
                  {
                    auto dsum1_fst_238 { std::get<0>(dsum1_237) };
                    auto dsum1_snd_239 { std::get<1>(dsum1_237) };
                    uint16_t id_3642 { 0 };
                    bool id_3643 { bool(id_3642 == dsum1_fst_238) };
                    t61bdb3f643c3108bb612fc36951fce20 choose_res_3644;
                    if (id_3643) {
                      tb3f98ea670610d40658a618de3ec7b90 id_3645 { dsum1_snd_239.readU8() };
                      t9c427530664aa522ce95ad420b884056 letpair_res_3646;
                      {
                        auto dchar_fst_267 { std::get<0>(id_3645) };
                        auto dchar_snd_268 { std::get<1>(id_3645) };
                        char id_3647 { char(dchar_fst_267) };
                        t9c427530664aa522ce95ad420b884056 id_3648 { id_3647, dchar_snd_268 };
                        letpair_res_3646 = id_3648;
                      }
                      t61bdb3f643c3108bb612fc36951fce20 let_res_3649;
                      {
                        t9c427530664aa522ce95ad420b884056 drec_269 { letpair_res_3646 };
                        t61bdb3f643c3108bb612fc36951fce20 letpair_res_3650;
                        {
                          auto drec_fst_270 { std::get<0>(drec_269) };
                          auto drec_snd_271 { std::get<1>(drec_269) };
                          uint32_t id_3651 { 0U };
                          Vec<1, uint32_t> id_3652 {  id_3651  };
                          t8beb80162423aee37bd383e9b6834c9c let_res_3653;
                          {
                            Vec<1, uint32_t> leb_ref_272 { id_3652 };
                            uint8_t id_3654 { 0 };
                            Vec<1, uint8_t> id_3655 {  id_3654  };
                            t8beb80162423aee37bd383e9b6834c9c let_res_3656;
                            {
                              Vec<1, uint8_t> shft_ref_273 { id_3655 };
                              Vec<1, Pointer> id_3657 {  drec_snd_271  };
                              t8beb80162423aee37bd383e9b6834c9c let_res_3658;
                              {
                                Vec<1, Pointer> p_ref_274 { id_3657 };
                                bool while_flag_3659 { true };
                                do {
                                  uint8_t id_3660 { 0 };
                                  Pointer id_3661 { p_ref_274[id_3660] };
                                  tb3f98ea670610d40658a618de3ec7b90 id_3662 { id_3661.readU8() };
                                  bool let_res_3663;
                                  {
                                    tb3f98ea670610d40658a618de3ec7b90 leb128_275 { id_3662 };
                                    bool letpair_res_3664;
                                    {
                                      auto leb128_fst_276 { std::get<0>(leb128_275) };
                                      auto leb128_snd_277 { std::get<1>(leb128_275) };
                                      uint8_t id_3665 { 0 };
                                      Void id_3666 { ((void)(p_ref_274[id_3665] = leb128_snd_277), VOID) };
                                      (void)id_3666;
                                      uint8_t id_3667 { 0 };
                                      uint8_t id_3668 { 127 };
                                      uint8_t id_3669 { uint8_t(leb128_fst_276 & id_3668) };
                                      uint32_t id_3670 { uint32_t(id_3669) };
                                      uint8_t id_3671 { 0 };
                                      uint8_t id_3672 { shft_ref_273[id_3671] };
                                      uint32_t id_3673 { uint32_t(id_3670 << id_3672) };
                                      uint8_t id_3674 { 0 };
                                      uint32_t id_3675 { leb_ref_272[id_3674] };
                                      uint32_t id_3676 { uint32_t(id_3673 | id_3675) };
                                      Void id_3677 { ((void)(leb_ref_272[id_3667] = id_3676), VOID) };
                                      (void)id_3677;
                                      uint8_t id_3678 { 0 };
                                      uint8_t id_3679 { 0 };
                                      uint8_t id_3680 { shft_ref_273[id_3679] };
                                      uint8_t id_3681 { 7 };
                                      uint8_t id_3682 { uint8_t(id_3680 + id_3681) };
                                      Void id_3683 { ((void)(shft_ref_273[id_3678] = id_3682), VOID) };
                                      (void)id_3683;
                                      uint8_t id_3684 { 128 };
                                      bool id_3685 { bool(leb128_fst_276 >= id_3684) };
                                      letpair_res_3664 = id_3685;
                                    }
                                    let_res_3663 = letpair_res_3664;
                                  }
                                  while_flag_3659 = let_res_3663;
                                  if (while_flag_3659) {
                                    (void)VOID;
                                  }
                                } while (while_flag_3659);
                                (void)VOID;
                                uint8_t id_3686 { 0 };
                                uint32_t id_3687 { leb_ref_272[id_3686] };
                                Size id_3688 { Size(id_3687) };
                                uint8_t id_3689 { 0 };
                                Pointer id_3690 { p_ref_274[id_3689] };
                                t8beb80162423aee37bd383e9b6834c9c id_3691 { id_3688, id_3690 };
                                let_res_3658 = id_3691;
                              }
                              let_res_3656 = let_res_3658;
                            }
                            let_res_3653 = let_res_3656;
                          }
                          tef94b55d8809251f13165d9a05bd9d0e let_res_3692;
                          {
                            t8beb80162423aee37bd383e9b6834c9c dstring1_278 { let_res_3653 };
                            tef94b55d8809251f13165d9a05bd9d0e letpair_res_3693;
                            {
                              auto dstring1_fst_279 { std::get<0>(dstring1_278) };
                              auto dstring1_snd_280 { std::get<1>(dstring1_278) };
                              t188345aa49abd0cb47ff73fedc219f08 id_3694 { dstring1_snd_280.readBytes(dstring1_fst_279) };
                              tef94b55d8809251f13165d9a05bd9d0e letpair_res_3695;
                              {
                                auto dstring2_fst_282 { std::get<0>(id_3694) };
                                auto dstring2_snd_283 { std::get<1>(id_3694) };
                                std::string id_3696 { dstring2_fst_282.toString() };
                                tef94b55d8809251f13165d9a05bd9d0e id_3697 { id_3696, dstring2_snd_283 };
                                letpair_res_3695 = id_3697;
                              }
                              letpair_res_3693 = letpair_res_3695;
                            }
                            let_res_3692 = letpair_res_3693;
                          }
                          t61bdb3f643c3108bb612fc36951fce20 let_res_3698;
                          {
                            tef94b55d8809251f13165d9a05bd9d0e drec_284 { let_res_3692 };
                            t61bdb3f643c3108bb612fc36951fce20 letpair_res_3699;
                            {
                              auto drec_fst_285 { std::get<0>(drec_284) };
                              auto drec_snd_286 { std::get<1>(drec_284) };
                              tb3f98ea670610d40658a618de3ec7b90 id_3700 { drec_snd_286.readU8() };
                              t4138de986e20d18b01e4c493dc9d5451 letpair_res_3701;
                              {
                                auto dbool_fst_288 { std::get<0>(id_3700) };
                                auto dbool_snd_289 { std::get<1>(id_3700) };
                                uint8_t id_3702 { 0 };
                                bool id_3703 { bool(dbool_fst_288 == id_3702) };
                                bool id_3704 { ! id_3703 };
                                t4138de986e20d18b01e4c493dc9d5451 id_3705 { id_3704, dbool_snd_289 };
                                letpair_res_3701 = id_3705;
                              }
                              t61bdb3f643c3108bb612fc36951fce20 let_res_3706;
                              {
                                t4138de986e20d18b01e4c493dc9d5451 drec_290 { letpair_res_3701 };
                                t61bdb3f643c3108bb612fc36951fce20 letpair_res_3707;
                                {
                                  auto drec_fst_291 { std::get<0>(drec_290) };
                                  auto drec_snd_292 { std::get<1>(drec_290) };
                                  uint32_t id_3708 { 0U };
                                  Vec<1, uint32_t> id_3709 {  id_3708  };
                                  t8beb80162423aee37bd383e9b6834c9c let_res_3710;
                                  {
                                    Vec<1, uint32_t> leb_ref_293 { id_3709 };
                                    uint8_t id_3711 { 0 };
                                    Vec<1, uint8_t> id_3712 {  id_3711  };
                                    t8beb80162423aee37bd383e9b6834c9c let_res_3713;
                                    {
                                      Vec<1, uint8_t> shft_ref_294 { id_3712 };
                                      Vec<1, Pointer> id_3714 {  drec_snd_292  };
                                      t8beb80162423aee37bd383e9b6834c9c let_res_3715;
                                      {
                                        Vec<1, Pointer> p_ref_295 { id_3714 };
                                        bool while_flag_3716 { true };
                                        do {
                                          uint8_t id_3717 { 0 };
                                          Pointer id_3718 { p_ref_295[id_3717] };
                                          tb3f98ea670610d40658a618de3ec7b90 id_3719 { id_3718.readU8() };
                                          bool let_res_3720;
                                          {
                                            tb3f98ea670610d40658a618de3ec7b90 leb128_296 { id_3719 };
                                            bool letpair_res_3721;
                                            {
                                              auto leb128_fst_297 { std::get<0>(leb128_296) };
                                              auto leb128_snd_298 { std::get<1>(leb128_296) };
                                              uint8_t id_3722 { 0 };
                                              Void id_3723 { ((void)(p_ref_295[id_3722] = leb128_snd_298), VOID) };
                                              (void)id_3723;
                                              uint8_t id_3724 { 0 };
                                              uint8_t id_3725 { 127 };
                                              uint8_t id_3726 { uint8_t(leb128_fst_297 & id_3725) };
                                              uint32_t id_3727 { uint32_t(id_3726) };
                                              uint8_t id_3728 { 0 };
                                              uint8_t id_3729 { shft_ref_294[id_3728] };
                                              uint32_t id_3730 { uint32_t(id_3727 << id_3729) };
                                              uint8_t id_3731 { 0 };
                                              uint32_t id_3732 { leb_ref_293[id_3731] };
                                              uint32_t id_3733 { uint32_t(id_3730 | id_3732) };
                                              Void id_3734 { ((void)(leb_ref_293[id_3724] = id_3733), VOID) };
                                              (void)id_3734;
                                              uint8_t id_3735 { 0 };
                                              uint8_t id_3736 { 0 };
                                              uint8_t id_3737 { shft_ref_294[id_3736] };
                                              uint8_t id_3738 { 7 };
                                              uint8_t id_3739 { uint8_t(id_3737 + id_3738) };
                                              Void id_3740 { ((void)(shft_ref_294[id_3735] = id_3739), VOID) };
                                              (void)id_3740;
                                              uint8_t id_3741 { 128 };
                                              bool id_3742 { bool(leb128_fst_297 >= id_3741) };
                                              letpair_res_3721 = id_3742;
                                            }
                                            let_res_3720 = letpair_res_3721;
                                          }
                                          while_flag_3716 = let_res_3720;
                                          if (while_flag_3716) {
                                            (void)VOID;
                                          }
                                        } while (while_flag_3716);
                                        (void)VOID;
                                        uint8_t id_3743 { 0 };
                                        uint32_t id_3744 { leb_ref_293[id_3743] };
                                        Size id_3745 { Size(id_3744) };
                                        uint8_t id_3746 { 0 };
                                        Pointer id_3747 { p_ref_295[id_3746] };
                                        t8beb80162423aee37bd383e9b6834c9c id_3748 { id_3745, id_3747 };
                                        let_res_3715 = id_3748;
                                      }
                                      let_res_3713 = let_res_3715;
                                    }
                                    let_res_3710 = let_res_3713;
                                  }
                                  tef94b55d8809251f13165d9a05bd9d0e let_res_3749;
                                  {
                                    t8beb80162423aee37bd383e9b6834c9c dstring1_299 { let_res_3710 };
                                    tef94b55d8809251f13165d9a05bd9d0e letpair_res_3750;
                                    {
                                      auto dstring1_fst_300 { std::get<0>(dstring1_299) };
                                      auto dstring1_snd_301 { std::get<1>(dstring1_299) };
                                      t188345aa49abd0cb47ff73fedc219f08 id_3751 { dstring1_snd_301.readBytes(dstring1_fst_300) };
                                      tef94b55d8809251f13165d9a05bd9d0e letpair_res_3752;
                                      {
                                        auto dstring2_fst_303 { std::get<0>(id_3751) };
                                        auto dstring2_snd_304 { std::get<1>(id_3751) };
                                        std::string id_3753 { dstring2_fst_303.toString() };
                                        tef94b55d8809251f13165d9a05bd9d0e id_3754 { id_3753, dstring2_snd_304 };
                                        letpair_res_3752 = id_3754;
                                      }
                                      letpair_res_3750 = letpair_res_3752;
                                    }
                                    let_res_3749 = letpair_res_3750;
                                  }
                                  t61bdb3f643c3108bb612fc36951fce20 let_res_3755;
                                  {
                                    tef94b55d8809251f13165d9a05bd9d0e drec_305 { let_res_3749 };
                                    t61bdb3f643c3108bb612fc36951fce20 letpair_res_3756;
                                    {
                                      auto drec_fst_306 { std::get<0>(drec_305) };
                                      auto drec_snd_307 { std::get<1>(drec_305) };
                                      uint32_t id_3757 { 0U };
                                      Vec<1, uint32_t> id_3758 {  id_3757  };
                                      t405eb186408556fed8f2c41523c07d13 let_res_3759;
                                      {
                                        Vec<1, uint32_t> leb_ref_308 { id_3758 };
                                        uint8_t id_3760 { 0 };
                                        Vec<1, uint8_t> id_3761 {  id_3760  };
                                        t405eb186408556fed8f2c41523c07d13 let_res_3762;
                                        {
                                          Vec<1, uint8_t> shft_ref_309 { id_3761 };
                                          Vec<1, Pointer> id_3763 {  drec_snd_307  };
                                          t405eb186408556fed8f2c41523c07d13 let_res_3764;
                                          {
                                            Vec<1, Pointer> p_ref_310 { id_3763 };
                                            bool while_flag_3765 { true };
                                            do {
                                              uint8_t id_3766 { 0 };
                                              Pointer id_3767 { p_ref_310[id_3766] };
                                              tb3f98ea670610d40658a618de3ec7b90 id_3768 { id_3767.readU8() };
                                              bool let_res_3769;
                                              {
                                                tb3f98ea670610d40658a618de3ec7b90 leb128_311 { id_3768 };
                                                bool letpair_res_3770;
                                                {
                                                  auto leb128_fst_312 { std::get<0>(leb128_311) };
                                                  auto leb128_snd_313 { std::get<1>(leb128_311) };
                                                  uint8_t id_3771 { 0 };
                                                  Void id_3772 { ((void)(p_ref_310[id_3771] = leb128_snd_313), VOID) };
                                                  (void)id_3772;
                                                  uint8_t id_3773 { 0 };
                                                  uint8_t id_3774 { 127 };
                                                  uint8_t id_3775 { uint8_t(leb128_fst_312 & id_3774) };
                                                  uint32_t id_3776 { uint32_t(id_3775) };
                                                  uint8_t id_3777 { 0 };
                                                  uint8_t id_3778 { shft_ref_309[id_3777] };
                                                  uint32_t id_3779 { uint32_t(id_3776 << id_3778) };
                                                  uint8_t id_3780 { 0 };
                                                  uint32_t id_3781 { leb_ref_308[id_3780] };
                                                  uint32_t id_3782 { uint32_t(id_3779 | id_3781) };
                                                  Void id_3783 { ((void)(leb_ref_308[id_3773] = id_3782), VOID) };
                                                  (void)id_3783;
                                                  uint8_t id_3784 { 0 };
                                                  uint8_t id_3785 { 0 };
                                                  uint8_t id_3786 { shft_ref_309[id_3785] };
                                                  uint8_t id_3787 { 7 };
                                                  uint8_t id_3788 { uint8_t(id_3786 + id_3787) };
                                                  Void id_3789 { ((void)(shft_ref_309[id_3784] = id_3788), VOID) };
                                                  (void)id_3789;
                                                  uint8_t id_3790 { 128 };
                                                  bool id_3791 { bool(leb128_fst_312 >= id_3790) };
                                                  letpair_res_3770 = id_3791;
                                                }
                                                let_res_3769 = letpair_res_3770;
                                              }
                                              while_flag_3765 = let_res_3769;
                                              if (while_flag_3765) {
                                                (void)VOID;
                                              }
                                            } while (while_flag_3765);
                                            (void)VOID;
                                            uint8_t id_3792 { 0 };
                                            uint32_t id_3793 { leb_ref_308[id_3792] };
                                            uint8_t id_3794 { 0 };
                                            Pointer id_3795 { p_ref_310[id_3794] };
                                            t405eb186408556fed8f2c41523c07d13 id_3796 { id_3793, id_3795 };
                                            let_res_3764 = id_3796;
                                          }
                                          let_res_3762 = let_res_3764;
                                        }
                                        let_res_3759 = let_res_3762;
                                      }
                                      tfba505af7788ece275315330d94bba2e let_res_3797;
                                      {
                                        t405eb186408556fed8f2c41523c07d13 dlist1_317 { let_res_3759 };
                                        tfba505af7788ece275315330d94bba2e letpair_res_3798;
                                        {
                                          auto dlist1_fst_318 { std::get<0>(dlist1_317) };
                                          auto dlist1_snd_319 { std::get<1>(dlist1_317) };
                                          Lst<dessser::gen::field_type::t_ext> endoflist_3799;
                                          tfba505af7788ece275315330d94bba2e id_3800 { endoflist_3799, dlist1_snd_319 };
                                          Vec<1, tfba505af7788ece275315330d94bba2e> id_3801 {  id_3800  };
                                          tfba505af7788ece275315330d94bba2e let_res_3802;
                                          {
                                            Vec<1, tfba505af7788ece275315330d94bba2e> inits_src_ref_320 { id_3801 };
                                            int32_t id_3803 { 0L };
                                            Vec<1, int32_t> id_3804 {  id_3803  };
                                            {
                                              Vec<1, int32_t> repeat_n_321 { id_3804 };
                                              bool while_flag_3805 { true };
                                              do {
                                                int32_t id_3806 { int32_t(dlist1_fst_318) };
                                                uint8_t id_3807 { 0 };
                                                int32_t id_3808 { repeat_n_321[id_3807] };
                                                bool id_3809 { bool(id_3806 > id_3808) };
                                                while_flag_3805 = id_3809;
                                                if (while_flag_3805) {
                                                  uint8_t id_3810 { 0 };
                                                  tfba505af7788ece275315330d94bba2e id_3811 { inits_src_ref_320[id_3810] };
                                                  {
                                                    tfba505af7788ece275315330d94bba2e dlist2_322 { id_3811 };
                                                    {
                                                      auto dlist2_fst_323 { std::get<0>(dlist2_322) };
                                                      auto dlist2_snd_324 { std::get<1>(dlist2_322) };
                                                      uint8_t id_3812 { 0 };
                                                      auto fun3813 { dessser::gen::field_type::of_row_binary };
                                                      t2f09fa79b0bdf1902e3b53bc7e485604 id_3814 { fun3813(dlist2_snd_324) };
                                                      tfba505af7788ece275315330d94bba2e letpair_res_3815;
                                                      {
                                                        auto dlist3_fst_326 { std::get<0>(id_3814) };
                                                        auto dlist3_snd_327 { std::get<1>(id_3814) };
                                                        Lst<dessser::gen::field_type::t_ext> id_3816 { dlist3_fst_326, dlist2_fst_323 };
                                                        tfba505af7788ece275315330d94bba2e id_3817 { id_3816, dlist3_snd_327 };
                                                        letpair_res_3815 = id_3817;
                                                      }
                                                      Void id_3818 { ((void)(inits_src_ref_320[id_3812] = letpair_res_3815), VOID) };
                                                      (void)id_3818;
                                                    }
                                                    (void)VOID;
                                                  }
                                                  (void)VOID;
                                                  uint8_t id_3819 { 0 };
                                                  uint8_t id_3820 { 0 };
                                                  int32_t id_3821 { repeat_n_321[id_3820] };
                                                  int32_t id_3822 { 1L };
                                                  int32_t id_3823 { int32_t(id_3821 + id_3822) };
                                                  Void id_3824 { ((void)(repeat_n_321[id_3819] = id_3823), VOID) };
                                                  (void)id_3824;
                                                  (void)id_3824;
                                                }
                                              } while (while_flag_3805);
                                              (void)VOID;
                                            }
                                            (void)VOID;
                                            uint8_t id_3825 { 0 };
                                            tfba505af7788ece275315330d94bba2e id_3826 { inits_src_ref_320[id_3825] };
                                            let_res_3802 = id_3826;
                                          }
                                          letpair_res_3798 = let_res_3802;
                                        }
                                        let_res_3797 = letpair_res_3798;
                                      }
                                      tfba505af7788ece275315330d94bba2e letpair_res_3827;
                                      {
                                        auto dlist4_fst_329 { std::get<0>(let_res_3797) };
                                        auto dlist4_snd_330 { std::get<1>(let_res_3797) };
                                        tfba505af7788ece275315330d94bba2e id_3828 { dlist4_fst_329, dlist4_snd_330 };
                                        letpair_res_3827 = id_3828;
                                      }
                                      t61bdb3f643c3108bb612fc36951fce20 let_res_3829;
                                      {
                                        tfba505af7788ece275315330d94bba2e drec_331 { letpair_res_3827 };
                                        t61bdb3f643c3108bb612fc36951fce20 letpair_res_3830;
                                        {
                                          auto drec_fst_332 { std::get<0>(drec_331) };
                                          auto drec_snd_333 { std::get<1>(drec_331) };
                                          tb3f98ea670610d40658a618de3ec7b90 id_3831 { drec_snd_333.readU8() };
                                          t4138de986e20d18b01e4c493dc9d5451 letpair_res_3832;
                                          {
                                            auto dbool_fst_335 { std::get<0>(id_3831) };
                                            auto dbool_snd_336 { std::get<1>(id_3831) };
                                            uint8_t id_3833 { 0 };
                                            bool id_3834 { bool(dbool_fst_335 == id_3833) };
                                            bool id_3835 { ! id_3834 };
                                            t4138de986e20d18b01e4c493dc9d5451 id_3836 { id_3835, dbool_snd_336 };
                                            letpair_res_3832 = id_3836;
                                          }
                                          t61bdb3f643c3108bb612fc36951fce20 let_res_3837;
                                          {
                                            t4138de986e20d18b01e4c493dc9d5451 drec_337 { letpair_res_3832 };
                                            t61bdb3f643c3108bb612fc36951fce20 letpair_res_3838;
                                            {
                                              auto drec_fst_338 { std::get<0>(drec_337) };
                                              auto drec_snd_339 { std::get<1>(drec_337) };
                                              tb3f98ea670610d40658a618de3ec7b90 id_3839 { drec_snd_339.readU8() };
                                              t61bdb3f643c3108bb612fc36951fce20 letpair_res_3840;
                                              {
                                                auto dbool_fst_341 { std::get<0>(id_3839) };
                                                auto dbool_snd_342 { std::get<1>(id_3839) };
                                                uint8_t id_3841 { 0 };
                                                bool id_3842 { bool(dbool_fst_341 == id_3841) };
                                                bool id_3843 { ! id_3842 };
                                                tc1ee34cdd9bdb8371d318bb284a788a8 id_3844 { .separator = drec_fst_270, .null = drec_fst_285, .may_quote = drec_fst_291, .escape_seq = drec_fst_306, .fields = drec_fst_332, .vectors_of_chars_as_string = drec_fst_338, .clickhouse_syntax = id_3843 };
                                                t570dd118e4f520aece0574b2f62e7634 id_3845 { std::in_place_index<0>, id_3844 };
                                                t61bdb3f643c3108bb612fc36951fce20 id_3846 { id_3845, dbool_snd_342 };
                                                letpair_res_3840 = id_3846;
                                              }
                                              letpair_res_3838 = letpair_res_3840;
                                            }
                                            let_res_3837 = letpair_res_3838;
                                          }
                                          letpair_res_3830 = let_res_3837;
                                        }
                                        let_res_3829 = letpair_res_3830;
                                      }
                                      letpair_res_3756 = let_res_3829;
                                    }
                                    let_res_3755 = letpair_res_3756;
                                  }
                                  letpair_res_3707 = let_res_3755;
                                }
                                let_res_3706 = letpair_res_3707;
                              }
                              letpair_res_3699 = let_res_3706;
                            }
                            let_res_3698 = letpair_res_3699;
                          }
                          letpair_res_3650 = let_res_3698;
                        }
                        let_res_3649 = letpair_res_3650;
                      }
                      choose_res_3644 = let_res_3649;
                    } else {
                      uint16_t id_3847 { 1 };
                      bool id_3848 { bool(dsum1_fst_238 == id_3847) };
                      Void id_3849 { ((void)(assert(id_3848)), VOID) };
                      (void)id_3849;
                      uint32_t id_3850 { 0U };
                      Vec<1, uint32_t> id_3851 {  id_3850  };
                      t405eb186408556fed8f2c41523c07d13 let_res_3852;
                      {
                        Vec<1, uint32_t> leb_ref_240 { id_3851 };
                        uint8_t id_3853 { 0 };
                        Vec<1, uint8_t> id_3854 {  id_3853  };
                        t405eb186408556fed8f2c41523c07d13 let_res_3855;
                        {
                          Vec<1, uint8_t> shft_ref_241 { id_3854 };
                          Vec<1, Pointer> id_3856 {  dsum1_snd_239  };
                          t405eb186408556fed8f2c41523c07d13 let_res_3857;
                          {
                            Vec<1, Pointer> p_ref_242 { id_3856 };
                            bool while_flag_3858 { true };
                            do {
                              uint8_t id_3859 { 0 };
                              Pointer id_3860 { p_ref_242[id_3859] };
                              tb3f98ea670610d40658a618de3ec7b90 id_3861 { id_3860.readU8() };
                              bool let_res_3862;
                              {
                                tb3f98ea670610d40658a618de3ec7b90 leb128_243 { id_3861 };
                                bool letpair_res_3863;
                                {
                                  auto leb128_fst_244 { std::get<0>(leb128_243) };
                                  auto leb128_snd_245 { std::get<1>(leb128_243) };
                                  uint8_t id_3864 { 0 };
                                  Void id_3865 { ((void)(p_ref_242[id_3864] = leb128_snd_245), VOID) };
                                  (void)id_3865;
                                  uint8_t id_3866 { 0 };
                                  uint8_t id_3867 { 127 };
                                  uint8_t id_3868 { uint8_t(leb128_fst_244 & id_3867) };
                                  uint32_t id_3869 { uint32_t(id_3868) };
                                  uint8_t id_3870 { 0 };
                                  uint8_t id_3871 { shft_ref_241[id_3870] };
                                  uint32_t id_3872 { uint32_t(id_3869 << id_3871) };
                                  uint8_t id_3873 { 0 };
                                  uint32_t id_3874 { leb_ref_240[id_3873] };
                                  uint32_t id_3875 { uint32_t(id_3872 | id_3874) };
                                  Void id_3876 { ((void)(leb_ref_240[id_3866] = id_3875), VOID) };
                                  (void)id_3876;
                                  uint8_t id_3877 { 0 };
                                  uint8_t id_3878 { 0 };
                                  uint8_t id_3879 { shft_ref_241[id_3878] };
                                  uint8_t id_3880 { 7 };
                                  uint8_t id_3881 { uint8_t(id_3879 + id_3880) };
                                  Void id_3882 { ((void)(shft_ref_241[id_3877] = id_3881), VOID) };
                                  (void)id_3882;
                                  uint8_t id_3883 { 128 };
                                  bool id_3884 { bool(leb128_fst_244 >= id_3883) };
                                  letpair_res_3863 = id_3884;
                                }
                                let_res_3862 = letpair_res_3863;
                              }
                              while_flag_3858 = let_res_3862;
                              if (while_flag_3858) {
                                (void)VOID;
                              }
                            } while (while_flag_3858);
                            (void)VOID;
                            uint8_t id_3885 { 0 };
                            uint32_t id_3886 { leb_ref_240[id_3885] };
                            uint8_t id_3887 { 0 };
                            Pointer id_3888 { p_ref_242[id_3887] };
                            t405eb186408556fed8f2c41523c07d13 id_3889 { id_3886, id_3888 };
                            let_res_3857 = id_3889;
                          }
                          let_res_3855 = let_res_3857;
                        }
                        let_res_3852 = let_res_3855;
                      }
                      tfba505af7788ece275315330d94bba2e let_res_3890;
                      {
                        t405eb186408556fed8f2c41523c07d13 dlist1_249 { let_res_3852 };
                        tfba505af7788ece275315330d94bba2e letpair_res_3891;
                        {
                          auto dlist1_fst_250 { std::get<0>(dlist1_249) };
                          auto dlist1_snd_251 { std::get<1>(dlist1_249) };
                          Lst<dessser::gen::field_type::t_ext> endoflist_3892;
                          tfba505af7788ece275315330d94bba2e id_3893 { endoflist_3892, dlist1_snd_251 };
                          Vec<1, tfba505af7788ece275315330d94bba2e> id_3894 {  id_3893  };
                          tfba505af7788ece275315330d94bba2e let_res_3895;
                          {
                            Vec<1, tfba505af7788ece275315330d94bba2e> inits_src_ref_252 { id_3894 };
                            int32_t id_3896 { 0L };
                            Vec<1, int32_t> id_3897 {  id_3896  };
                            {
                              Vec<1, int32_t> repeat_n_253 { id_3897 };
                              bool while_flag_3898 { true };
                              do {
                                int32_t id_3899 { int32_t(dlist1_fst_250) };
                                uint8_t id_3900 { 0 };
                                int32_t id_3901 { repeat_n_253[id_3900] };
                                bool id_3902 { bool(id_3899 > id_3901) };
                                while_flag_3898 = id_3902;
                                if (while_flag_3898) {
                                  uint8_t id_3903 { 0 };
                                  tfba505af7788ece275315330d94bba2e id_3904 { inits_src_ref_252[id_3903] };
                                  {
                                    tfba505af7788ece275315330d94bba2e dlist2_254 { id_3904 };
                                    {
                                      auto dlist2_fst_255 { std::get<0>(dlist2_254) };
                                      auto dlist2_snd_256 { std::get<1>(dlist2_254) };
                                      uint8_t id_3905 { 0 };
                                      auto fun3906 { dessser::gen::field_type::of_row_binary };
                                      t2f09fa79b0bdf1902e3b53bc7e485604 id_3907 { fun3906(dlist2_snd_256) };
                                      tfba505af7788ece275315330d94bba2e letpair_res_3908;
                                      {
                                        auto dlist3_fst_258 { std::get<0>(id_3907) };
                                        auto dlist3_snd_259 { std::get<1>(id_3907) };
                                        Lst<dessser::gen::field_type::t_ext> id_3909 { dlist3_fst_258, dlist2_fst_255 };
                                        tfba505af7788ece275315330d94bba2e id_3910 { id_3909, dlist3_snd_259 };
                                        letpair_res_3908 = id_3910;
                                      }
                                      Void id_3911 { ((void)(inits_src_ref_252[id_3905] = letpair_res_3908), VOID) };
                                      (void)id_3911;
                                    }
                                    (void)VOID;
                                  }
                                  (void)VOID;
                                  uint8_t id_3912 { 0 };
                                  uint8_t id_3913 { 0 };
                                  int32_t id_3914 { repeat_n_253[id_3913] };
                                  int32_t id_3915 { 1L };
                                  int32_t id_3916 { int32_t(id_3914 + id_3915) };
                                  Void id_3917 { ((void)(repeat_n_253[id_3912] = id_3916), VOID) };
                                  (void)id_3917;
                                  (void)id_3917;
                                }
                              } while (while_flag_3898);
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_3918 { 0 };
                            tfba505af7788ece275315330d94bba2e id_3919 { inits_src_ref_252[id_3918] };
                            let_res_3895 = id_3919;
                          }
                          letpair_res_3891 = let_res_3895;
                        }
                        let_res_3890 = letpair_res_3891;
                      }
                      t61bdb3f643c3108bb612fc36951fce20 letpair_res_3920;
                      {
                        auto dlist4_fst_261 { std::get<0>(let_res_3890) };
                        auto dlist4_snd_262 { std::get<1>(let_res_3890) };
                        t570dd118e4f520aece0574b2f62e7634 id_3921 { std::in_place_index<1>, dlist4_fst_261 };
                        t61bdb3f643c3108bb612fc36951fce20 id_3922 { id_3921, dlist4_snd_262 };
                        letpair_res_3920 = id_3922;
                      }
                      choose_res_3644 = letpair_res_3920;
                    }
                    letpair_res_3641 = choose_res_3644;
                  }
                  let_res_3640 = letpair_res_3641;
                }
                t45217dce3db5a9a49037839afd0048e8 let_res_3923;
                {
                  t61bdb3f643c3108bb612fc36951fce20 drec_349 { let_res_3640 };
                  t45217dce3db5a9a49037839afd0048e8 letpair_res_3924;
                  {
                    auto drec_fst_350 { std::get<0>(drec_349) };
                    auto drec_snd_351 { std::get<1>(drec_349) };
                    Size id_3925 { 0UL };
                    uint8_t id_3926 { drec_snd_351.peekU8(id_3925) };
                    uint8_t id_3927 { 1 };
                    bool id_3928 { bool(id_3926 == id_3927) };
                    te3858ac581a2bb69ede2f45fc6f9aff4 choose_res_3929;
                    if (id_3928) {
                      std::optional<dessser::gen::event_time::t_ext> id_3930 { std::nullopt };
                      Size id_3931 { 1UL };
                      Pointer id_3932 { drec_snd_351.skip(id_3931) };
                      te3858ac581a2bb69ede2f45fc6f9aff4 id_3933 { id_3930, id_3932 };
                      choose_res_3929 = id_3933;
                    } else {
                      auto fun3934 { dessser::gen::event_time::of_row_binary };
                      Size id_3935 { 1UL };
                      Pointer id_3936 { drec_snd_351.skip(id_3935) };
                      te8ff255b34432f8503a86cf675cbafe6 id_3937 { fun3934(id_3936) };
                      te3858ac581a2bb69ede2f45fc6f9aff4 letpair_res_3938;
                      {
                        auto make1_1_fst_353 { std::get<0>(id_3937) };
                        auto make1_1_snd_354 { std::get<1>(id_3937) };
                        std::optional<dessser::gen::event_time::t_ext> id_3939 { make1_1_fst_353 };
                        te3858ac581a2bb69ede2f45fc6f9aff4 id_3940 { id_3939, make1_1_snd_354 };
                        letpair_res_3938 = id_3940;
                      }
                      choose_res_3929 = letpair_res_3938;
                    }
                    t45217dce3db5a9a49037839afd0048e8 let_res_3941;
                    {
                      te3858ac581a2bb69ede2f45fc6f9aff4 drec_355 { choose_res_3929 };
                      t45217dce3db5a9a49037839afd0048e8 letpair_res_3942;
                      {
                        auto drec_fst_356 { std::get<0>(drec_355) };
                        auto drec_snd_357 { std::get<1>(drec_355) };
                        uint32_t id_3943 { 0U };
                        Vec<1, uint32_t> id_3944 {  id_3943  };
                        t405eb186408556fed8f2c41523c07d13 let_res_3945;
                        {
                          Vec<1, uint32_t> leb_ref_358 { id_3944 };
                          uint8_t id_3946 { 0 };
                          Vec<1, uint8_t> id_3947 {  id_3946  };
                          t405eb186408556fed8f2c41523c07d13 let_res_3948;
                          {
                            Vec<1, uint8_t> shft_ref_359 { id_3947 };
                            Vec<1, Pointer> id_3949 {  drec_snd_357  };
                            t405eb186408556fed8f2c41523c07d13 let_res_3950;
                            {
                              Vec<1, Pointer> p_ref_360 { id_3949 };
                              bool while_flag_3951 { true };
                              do {
                                uint8_t id_3952 { 0 };
                                Pointer id_3953 { p_ref_360[id_3952] };
                                tb3f98ea670610d40658a618de3ec7b90 id_3954 { id_3953.readU8() };
                                bool let_res_3955;
                                {
                                  tb3f98ea670610d40658a618de3ec7b90 leb128_361 { id_3954 };
                                  bool letpair_res_3956;
                                  {
                                    auto leb128_fst_362 { std::get<0>(leb128_361) };
                                    auto leb128_snd_363 { std::get<1>(leb128_361) };
                                    uint8_t id_3957 { 0 };
                                    Void id_3958 { ((void)(p_ref_360[id_3957] = leb128_snd_363), VOID) };
                                    (void)id_3958;
                                    uint8_t id_3959 { 0 };
                                    uint8_t id_3960 { 127 };
                                    uint8_t id_3961 { uint8_t(leb128_fst_362 & id_3960) };
                                    uint32_t id_3962 { uint32_t(id_3961) };
                                    uint8_t id_3963 { 0 };
                                    uint8_t id_3964 { shft_ref_359[id_3963] };
                                    uint32_t id_3965 { uint32_t(id_3962 << id_3964) };
                                    uint8_t id_3966 { 0 };
                                    uint32_t id_3967 { leb_ref_358[id_3966] };
                                    uint32_t id_3968 { uint32_t(id_3965 | id_3967) };
                                    Void id_3969 { ((void)(leb_ref_358[id_3959] = id_3968), VOID) };
                                    (void)id_3969;
                                    uint8_t id_3970 { 0 };
                                    uint8_t id_3971 { 0 };
                                    uint8_t id_3972 { shft_ref_359[id_3971] };
                                    uint8_t id_3973 { 7 };
                                    uint8_t id_3974 { uint8_t(id_3972 + id_3973) };
                                    Void id_3975 { ((void)(shft_ref_359[id_3970] = id_3974), VOID) };
                                    (void)id_3975;
                                    uint8_t id_3976 { 128 };
                                    bool id_3977 { bool(leb128_fst_362 >= id_3976) };
                                    letpair_res_3956 = id_3977;
                                  }
                                  let_res_3955 = letpair_res_3956;
                                }
                                while_flag_3951 = let_res_3955;
                                if (while_flag_3951) {
                                  (void)VOID;
                                }
                              } while (while_flag_3951);
                              (void)VOID;
                              uint8_t id_3978 { 0 };
                              uint32_t id_3979 { leb_ref_358[id_3978] };
                              uint8_t id_3980 { 0 };
                              Pointer id_3981 { p_ref_360[id_3980] };
                              t405eb186408556fed8f2c41523c07d13 id_3982 { id_3979, id_3981 };
                              let_res_3950 = id_3982;
                            }
                            let_res_3948 = let_res_3950;
                          }
                          let_res_3945 = let_res_3948;
                        }
                        t0dfa866705b76efff53e4aa97228a967 let_res_3983;
                        {
                          t405eb186408556fed8f2c41523c07d13 dlist1_367 { let_res_3945 };
                          t0dfa866705b76efff53e4aa97228a967 letpair_res_3984;
                          {
                            auto dlist1_fst_368 { std::get<0>(dlist1_367) };
                            auto dlist1_snd_369 { std::get<1>(dlist1_367) };
                            Lst<dessser::gen::field_name::t_ext> endoflist_3985;
                            t0dfa866705b76efff53e4aa97228a967 id_3986 { endoflist_3985, dlist1_snd_369 };
                            Vec<1, t0dfa866705b76efff53e4aa97228a967> id_3987 {  id_3986  };
                            t0dfa866705b76efff53e4aa97228a967 let_res_3988;
                            {
                              Vec<1, t0dfa866705b76efff53e4aa97228a967> inits_src_ref_370 { id_3987 };
                              int32_t id_3989 { 0L };
                              Vec<1, int32_t> id_3990 {  id_3989  };
                              {
                                Vec<1, int32_t> repeat_n_371 { id_3990 };
                                bool while_flag_3991 { true };
                                do {
                                  int32_t id_3992 { int32_t(dlist1_fst_368) };
                                  uint8_t id_3993 { 0 };
                                  int32_t id_3994 { repeat_n_371[id_3993] };
                                  bool id_3995 { bool(id_3992 > id_3994) };
                                  while_flag_3991 = id_3995;
                                  if (while_flag_3991) {
                                    uint8_t id_3996 { 0 };
                                    t0dfa866705b76efff53e4aa97228a967 id_3997 { inits_src_ref_370[id_3996] };
                                    {
                                      t0dfa866705b76efff53e4aa97228a967 dlist2_372 { id_3997 };
                                      {
                                        auto dlist2_fst_373 { std::get<0>(dlist2_372) };
                                        auto dlist2_snd_374 { std::get<1>(dlist2_372) };
                                        uint8_t id_3998 { 0 };
                                        auto fun3999 { dessser::gen::field_name::of_row_binary };
                                        t273a2b7978f5b466a128a51c1cc4a27b id_4000 { fun3999(dlist2_snd_374) };
                                        t0dfa866705b76efff53e4aa97228a967 letpair_res_4001;
                                        {
                                          auto dlist3_fst_376 { std::get<0>(id_4000) };
                                          auto dlist3_snd_377 { std::get<1>(id_4000) };
                                          Lst<dessser::gen::field_name::t_ext> id_4002 { dlist3_fst_376, dlist2_fst_373 };
                                          t0dfa866705b76efff53e4aa97228a967 id_4003 { id_4002, dlist3_snd_377 };
                                          letpair_res_4001 = id_4003;
                                        }
                                        Void id_4004 { ((void)(inits_src_ref_370[id_3998] = letpair_res_4001), VOID) };
                                        (void)id_4004;
                                      }
                                      (void)VOID;
                                    }
                                    (void)VOID;
                                    uint8_t id_4005 { 0 };
                                    uint8_t id_4006 { 0 };
                                    int32_t id_4007 { repeat_n_371[id_4006] };
                                    int32_t id_4008 { 1L };
                                    int32_t id_4009 { int32_t(id_4007 + id_4008) };
                                    Void id_4010 { ((void)(repeat_n_371[id_4005] = id_4009), VOID) };
                                    (void)id_4010;
                                    (void)id_4010;
                                  }
                                } while (while_flag_3991);
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_4011 { 0 };
                              t0dfa866705b76efff53e4aa97228a967 id_4012 { inits_src_ref_370[id_4011] };
                              let_res_3988 = id_4012;
                            }
                            letpair_res_3984 = let_res_3988;
                          }
                          let_res_3983 = letpair_res_3984;
                        }
                        t45217dce3db5a9a49037839afd0048e8 letpair_res_4013;
                        {
                          auto dlist4_fst_379 { std::get<0>(let_res_3983) };
                          auto dlist4_snd_380 { std::get<1>(let_res_3983) };
                          t1d5c57287ee550c3ccac78b88bba5862 id_4014 { .source = drec_fst_229, .format = drec_fst_350, .event_time = drec_fst_356, .factors = dlist4_fst_379 };
                          t* id_4015 { new t(std::in_place_index<1>, id_4014) };
                          t45217dce3db5a9a49037839afd0048e8 id_4016 { id_4015, dlist4_snd_380 };
                          letpair_res_4013 = id_4016;
                        }
                        letpair_res_3942 = letpair_res_4013;
                      }
                      let_res_3941 = letpair_res_3942;
                    }
                    letpair_res_3924 = let_res_3941;
                  }
                  let_res_3923 = letpair_res_3924;
                }
                letpair_res_3636 = let_res_3923;
              }
              let_res_3635 = letpair_res_3636;
            }
            choose_res_3409 = let_res_3635;
          } else {
            uint16_t id_4017 { 2 };
            bool id_4018 { bool(dsum1_fst_63 == id_4017) };
            Void id_4019 { ((void)(assert(id_4018)), VOID) };
            (void)id_4019;
            uint32_t id_4020 { 0U };
            Vec<1, uint32_t> id_4021 {  id_4020  };
            t8beb80162423aee37bd383e9b6834c9c let_res_4022;
            {
              Vec<1, uint32_t> leb_ref_65 { id_4021 };
              uint8_t id_4023 { 0 };
              Vec<1, uint8_t> id_4024 {  id_4023  };
              t8beb80162423aee37bd383e9b6834c9c let_res_4025;
              {
                Vec<1, uint8_t> shft_ref_66 { id_4024 };
                Vec<1, Pointer> id_4026 {  dsum1_snd_64  };
                t8beb80162423aee37bd383e9b6834c9c let_res_4027;
                {
                  Vec<1, Pointer> p_ref_67 { id_4026 };
                  bool while_flag_4028 { true };
                  do {
                    uint8_t id_4029 { 0 };
                    Pointer id_4030 { p_ref_67[id_4029] };
                    tb3f98ea670610d40658a618de3ec7b90 id_4031 { id_4030.readU8() };
                    bool let_res_4032;
                    {
                      tb3f98ea670610d40658a618de3ec7b90 leb128_68 { id_4031 };
                      bool letpair_res_4033;
                      {
                        auto leb128_fst_69 { std::get<0>(leb128_68) };
                        auto leb128_snd_70 { std::get<1>(leb128_68) };
                        uint8_t id_4034 { 0 };
                        Void id_4035 { ((void)(p_ref_67[id_4034] = leb128_snd_70), VOID) };
                        (void)id_4035;
                        uint8_t id_4036 { 0 };
                        uint8_t id_4037 { 127 };
                        uint8_t id_4038 { uint8_t(leb128_fst_69 & id_4037) };
                        uint32_t id_4039 { uint32_t(id_4038) };
                        uint8_t id_4040 { 0 };
                        uint8_t id_4041 { shft_ref_66[id_4040] };
                        uint32_t id_4042 { uint32_t(id_4039 << id_4041) };
                        uint8_t id_4043 { 0 };
                        uint32_t id_4044 { leb_ref_65[id_4043] };
                        uint32_t id_4045 { uint32_t(id_4042 | id_4044) };
                        Void id_4046 { ((void)(leb_ref_65[id_4036] = id_4045), VOID) };
                        (void)id_4046;
                        uint8_t id_4047 { 0 };
                        uint8_t id_4048 { 0 };
                        uint8_t id_4049 { shft_ref_66[id_4048] };
                        uint8_t id_4050 { 7 };
                        uint8_t id_4051 { uint8_t(id_4049 + id_4050) };
                        Void id_4052 { ((void)(shft_ref_66[id_4047] = id_4051), VOID) };
                        (void)id_4052;
                        uint8_t id_4053 { 128 };
                        bool id_4054 { bool(leb128_fst_69 >= id_4053) };
                        letpair_res_4033 = id_4054;
                      }
                      let_res_4032 = letpair_res_4033;
                    }
                    while_flag_4028 = let_res_4032;
                    if (while_flag_4028) {
                      (void)VOID;
                    }
                  } while (while_flag_4028);
                  (void)VOID;
                  uint8_t id_4055 { 0 };
                  uint32_t id_4056 { leb_ref_65[id_4055] };
                  Size id_4057 { Size(id_4056) };
                  uint8_t id_4058 { 0 };
                  Pointer id_4059 { p_ref_67[id_4058] };
                  t8beb80162423aee37bd383e9b6834c9c id_4060 { id_4057, id_4059 };
                  let_res_4027 = id_4060;
                }
                let_res_4025 = let_res_4027;
              }
              let_res_4022 = let_res_4025;
            }
            tef94b55d8809251f13165d9a05bd9d0e let_res_4061;
            {
              t8beb80162423aee37bd383e9b6834c9c dstring1_71 { let_res_4022 };
              tef94b55d8809251f13165d9a05bd9d0e letpair_res_4062;
              {
                auto dstring1_fst_72 { std::get<0>(dstring1_71) };
                auto dstring1_snd_73 { std::get<1>(dstring1_71) };
                t188345aa49abd0cb47ff73fedc219f08 id_4063 { dstring1_snd_73.readBytes(dstring1_fst_72) };
                tef94b55d8809251f13165d9a05bd9d0e letpair_res_4064;
                {
                  auto dstring2_fst_75 { std::get<0>(id_4063) };
                  auto dstring2_snd_76 { std::get<1>(id_4063) };
                  std::string id_4065 { dstring2_fst_75.toString() };
                  tef94b55d8809251f13165d9a05bd9d0e id_4066 { id_4065, dstring2_snd_76 };
                  letpair_res_4064 = id_4066;
                }
                letpair_res_4062 = letpair_res_4064;
              }
              let_res_4061 = letpair_res_4062;
            }
            t45217dce3db5a9a49037839afd0048e8 let_res_4067;
            {
              tef94b55d8809251f13165d9a05bd9d0e drec_77 { let_res_4061 };
              t45217dce3db5a9a49037839afd0048e8 letpair_res_4068;
              {
                auto drec_fst_78 { std::get<0>(drec_77) };
                auto drec_snd_79 { std::get<1>(drec_77) };
                t22a32080ad88ab548b80077a17b7dd46 id_4069 { drec_snd_79.readU16Le() };
                t22a32080ad88ab548b80077a17b7dd46 letpair_res_4070;
                {
                  auto du16_fst_81 { std::get<0>(id_4069) };
                  auto du16_snd_82 { std::get<1>(id_4069) };
                  t22a32080ad88ab548b80077a17b7dd46 id_4071 { du16_fst_81, du16_snd_82 };
                  letpair_res_4070 = id_4071;
                }
                t45217dce3db5a9a49037839afd0048e8 let_res_4072;
                {
                  t22a32080ad88ab548b80077a17b7dd46 drec_83 { letpair_res_4070 };
                  t45217dce3db5a9a49037839afd0048e8 letpair_res_4073;
                  {
                    auto drec_fst_84 { std::get<0>(drec_83) };
                    auto drec_snd_85 { std::get<1>(drec_83) };
                    auto fun4074 { dessser::gen::raql_net_protocol::of_row_binary };
                    t09401f6cfd6a52d2f08b29ed5a55a113 id_4075 { fun4074(drec_snd_85) };
                    t45217dce3db5a9a49037839afd0048e8 let_res_4076;
                    {
                      t09401f6cfd6a52d2f08b29ed5a55a113 drec_86 { id_4075 };
                      t45217dce3db5a9a49037839afd0048e8 letpair_res_4077;
                      {
                        auto drec_fst_87 { std::get<0>(drec_86) };
                        auto drec_snd_88 { std::get<1>(drec_86) };
                        uint32_t id_4078 { 0U };
                        Vec<1, uint32_t> id_4079 {  id_4078  };
                        t405eb186408556fed8f2c41523c07d13 let_res_4080;
                        {
                          Vec<1, uint32_t> leb_ref_89 { id_4079 };
                          uint8_t id_4081 { 0 };
                          Vec<1, uint8_t> id_4082 {  id_4081  };
                          t405eb186408556fed8f2c41523c07d13 let_res_4083;
                          {
                            Vec<1, uint8_t> shft_ref_90 { id_4082 };
                            Vec<1, Pointer> id_4084 {  drec_snd_88  };
                            t405eb186408556fed8f2c41523c07d13 let_res_4085;
                            {
                              Vec<1, Pointer> p_ref_91 { id_4084 };
                              bool while_flag_4086 { true };
                              do {
                                uint8_t id_4087 { 0 };
                                Pointer id_4088 { p_ref_91[id_4087] };
                                tb3f98ea670610d40658a618de3ec7b90 id_4089 { id_4088.readU8() };
                                bool let_res_4090;
                                {
                                  tb3f98ea670610d40658a618de3ec7b90 leb128_92 { id_4089 };
                                  bool letpair_res_4091;
                                  {
                                    auto leb128_fst_93 { std::get<0>(leb128_92) };
                                    auto leb128_snd_94 { std::get<1>(leb128_92) };
                                    uint8_t id_4092 { 0 };
                                    Void id_4093 { ((void)(p_ref_91[id_4092] = leb128_snd_94), VOID) };
                                    (void)id_4093;
                                    uint8_t id_4094 { 0 };
                                    uint8_t id_4095 { 127 };
                                    uint8_t id_4096 { uint8_t(leb128_fst_93 & id_4095) };
                                    uint32_t id_4097 { uint32_t(id_4096) };
                                    uint8_t id_4098 { 0 };
                                    uint8_t id_4099 { shft_ref_90[id_4098] };
                                    uint32_t id_4100 { uint32_t(id_4097 << id_4099) };
                                    uint8_t id_4101 { 0 };
                                    uint32_t id_4102 { leb_ref_89[id_4101] };
                                    uint32_t id_4103 { uint32_t(id_4100 | id_4102) };
                                    Void id_4104 { ((void)(leb_ref_89[id_4094] = id_4103), VOID) };
                                    (void)id_4104;
                                    uint8_t id_4105 { 0 };
                                    uint8_t id_4106 { 0 };
                                    uint8_t id_4107 { shft_ref_90[id_4106] };
                                    uint8_t id_4108 { 7 };
                                    uint8_t id_4109 { uint8_t(id_4107 + id_4108) };
                                    Void id_4110 { ((void)(shft_ref_90[id_4105] = id_4109), VOID) };
                                    (void)id_4110;
                                    uint8_t id_4111 { 128 };
                                    bool id_4112 { bool(leb128_fst_93 >= id_4111) };
                                    letpair_res_4091 = id_4112;
                                  }
                                  let_res_4090 = letpair_res_4091;
                                }
                                while_flag_4086 = let_res_4090;
                                if (while_flag_4086) {
                                  (void)VOID;
                                }
                              } while (while_flag_4086);
                              (void)VOID;
                              uint8_t id_4113 { 0 };
                              uint32_t id_4114 { leb_ref_89[id_4113] };
                              uint8_t id_4115 { 0 };
                              Pointer id_4116 { p_ref_91[id_4115] };
                              t405eb186408556fed8f2c41523c07d13 id_4117 { id_4114, id_4116 };
                              let_res_4085 = id_4117;
                            }
                            let_res_4083 = let_res_4085;
                          }
                          let_res_4080 = let_res_4083;
                        }
                        t0dfa866705b76efff53e4aa97228a967 let_res_4118;
                        {
                          t405eb186408556fed8f2c41523c07d13 dlist1_98 { let_res_4080 };
                          t0dfa866705b76efff53e4aa97228a967 letpair_res_4119;
                          {
                            auto dlist1_fst_99 { std::get<0>(dlist1_98) };
                            auto dlist1_snd_100 { std::get<1>(dlist1_98) };
                            Lst<dessser::gen::field_name::t_ext> endoflist_4120;
                            t0dfa866705b76efff53e4aa97228a967 id_4121 { endoflist_4120, dlist1_snd_100 };
                            Vec<1, t0dfa866705b76efff53e4aa97228a967> id_4122 {  id_4121  };
                            t0dfa866705b76efff53e4aa97228a967 let_res_4123;
                            {
                              Vec<1, t0dfa866705b76efff53e4aa97228a967> inits_src_ref_101 { id_4122 };
                              int32_t id_4124 { 0L };
                              Vec<1, int32_t> id_4125 {  id_4124  };
                              {
                                Vec<1, int32_t> repeat_n_102 { id_4125 };
                                bool while_flag_4126 { true };
                                do {
                                  int32_t id_4127 { int32_t(dlist1_fst_99) };
                                  uint8_t id_4128 { 0 };
                                  int32_t id_4129 { repeat_n_102[id_4128] };
                                  bool id_4130 { bool(id_4127 > id_4129) };
                                  while_flag_4126 = id_4130;
                                  if (while_flag_4126) {
                                    uint8_t id_4131 { 0 };
                                    t0dfa866705b76efff53e4aa97228a967 id_4132 { inits_src_ref_101[id_4131] };
                                    {
                                      t0dfa866705b76efff53e4aa97228a967 dlist2_103 { id_4132 };
                                      {
                                        auto dlist2_fst_104 { std::get<0>(dlist2_103) };
                                        auto dlist2_snd_105 { std::get<1>(dlist2_103) };
                                        uint8_t id_4133 { 0 };
                                        auto fun4134 { dessser::gen::field_name::of_row_binary };
                                        t273a2b7978f5b466a128a51c1cc4a27b id_4135 { fun4134(dlist2_snd_105) };
                                        t0dfa866705b76efff53e4aa97228a967 letpair_res_4136;
                                        {
                                          auto dlist3_fst_107 { std::get<0>(id_4135) };
                                          auto dlist3_snd_108 { std::get<1>(id_4135) };
                                          Lst<dessser::gen::field_name::t_ext> id_4137 { dlist3_fst_107, dlist2_fst_104 };
                                          t0dfa866705b76efff53e4aa97228a967 id_4138 { id_4137, dlist3_snd_108 };
                                          letpair_res_4136 = id_4138;
                                        }
                                        Void id_4139 { ((void)(inits_src_ref_101[id_4133] = letpair_res_4136), VOID) };
                                        (void)id_4139;
                                      }
                                      (void)VOID;
                                    }
                                    (void)VOID;
                                    uint8_t id_4140 { 0 };
                                    uint8_t id_4141 { 0 };
                                    int32_t id_4142 { repeat_n_102[id_4141] };
                                    int32_t id_4143 { 1L };
                                    int32_t id_4144 { int32_t(id_4142 + id_4143) };
                                    Void id_4145 { ((void)(repeat_n_102[id_4140] = id_4144), VOID) };
                                    (void)id_4145;
                                    (void)id_4145;
                                  }
                                } while (while_flag_4126);
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_4146 { 0 };
                              t0dfa866705b76efff53e4aa97228a967 id_4147 { inits_src_ref_101[id_4146] };
                              let_res_4123 = id_4147;
                            }
                            letpair_res_4119 = let_res_4123;
                          }
                          let_res_4118 = letpair_res_4119;
                        }
                        t45217dce3db5a9a49037839afd0048e8 letpair_res_4148;
                        {
                          auto dlist4_fst_110 { std::get<0>(let_res_4118) };
                          auto dlist4_snd_111 { std::get<1>(let_res_4118) };
                          t9ddff9e1963b15ba493db1f8dadd34fb id_4149 { .net_addr = drec_fst_78, .port = drec_fst_84, .proto = drec_fst_87, .factors = dlist4_fst_110 };
                          t* id_4150 { new t(std::in_place_index<2>, id_4149) };
                          t45217dce3db5a9a49037839afd0048e8 id_4151 { id_4150, dlist4_snd_111 };
                          letpair_res_4148 = id_4151;
                        }
                        letpair_res_4077 = letpair_res_4148;
                      }
                      let_res_4076 = letpair_res_4077;
                    }
                    letpair_res_4073 = let_res_4076;
                  }
                  let_res_4072 = letpair_res_4073;
                }
                letpair_res_4068 = let_res_4072;
              }
              let_res_4067 = letpair_res_4068;
            }
            choose_res_3409 = let_res_4067;
          }
          choose_res_2636 = choose_res_3409;
        }
        letpair_res_2633 = choose_res_2636;
      }
      let_res_2632 = letpair_res_2633;
    }
    t45217dce3db5a9a49037839afd0048e8 letpair_res_4152;
    {
      auto make_fst_690 { std::get<0>(let_res_2632) };
      auto make_snd_691 { std::get<1>(let_res_2632) };
      t45217dce3db5a9a49037839afd0048e8 id_4153 { make_fst_690, make_snd_691 };
      letpair_res_4152 = id_4153;
    }
    return letpair_res_4152;
  }
   };
  return fun2628;
}
std::function<t45217dce3db5a9a49037839afd0048e8(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;

}
