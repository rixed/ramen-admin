(* Version Numbers used to identify anything that's saved on disc or
 * transferred via network. *)

(* Release tag just for information purpose but not actually used to version
 * anything. *)
let release_tag = "v2.0.0"

(* Ramen graph configuration *)
let graph_config = "v8" (* last: additions to Program.t and Func.t *)

(* Code generation: sources, binaries... *)
let codegen = "v6" (* last: single binary per program *)

(* Alerting state *)
let alerting_state = "v1"

(* Instrumentation data sent from workers to Ramen *)
let instrumentation_tuple = "v1"

(* Notifications sent from workers to Ramen *)
let notify_tuple = "v1"

(* Ringbuf formats *)
let ringbuf = "v2" (* last: non-wrapping ringbufs *)

(* Ref-ringbuf format *)
let out_ref = "v2" (* last: added timeout *)

(* Workers state format *)
let worker_state = "v2"
