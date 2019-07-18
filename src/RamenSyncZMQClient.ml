(* A specific Client using ZMQ, for the values/keys defined in RamenSync. *)
open Batteries
open RamenConsts
open RamenLog
open RamenHelpers
open RamenSync
module Files = RamenFiles

module CltMsg = Client.CltMsg
module SrvMsg = Client.SrvMsg

(* FIXME: We want to make all extra parameters (clt and zock) disappear in order
 * to simplify passing them to httpd router functions. But we also need clt
 * for inspecting the hash. Both zock and clt should go into the conf parameter
 * which role it is! So we need to reorder the conf type so that it can
 * have a SyncClient and a Zocket, or move Sync modules much higher up the
 * list of modules. This requires to rethink module dependencies though. *)

(* Set once synchronized *)
let zock_clt : ([`Dealer] Zmq.Socket.t * Client.t) option ref = ref None

let get_connection () =
  option_get "zock_clt" !zock_clt

let retry_zmq ?while_ f =
  let on = function
    (* EWOULDBLOCK: According to 0mq documentation blocking is supposed
     * to be signaled with EAGAIN but... *)
    | Unix.(Unix_error ((EAGAIN|EWOULDBLOCK), _, _)) -> true
    | _ -> false in
  retry ~on ~first_delay:0.3 ?while_ f

(* To help with RPC like interaction, we have two callbacks here that can be
 * set when calling send_cmd, and that are automatically called when the Error
 * message (that is automatically subscribed by the server) is updated. This is
 * a hash from command id to continuation.
 * FIXME: timeout after a while and replace the continuation with
 * `raise Timeout` in that case. *)
let on_oks : (int, unit -> unit) Hashtbl.t = Hashtbl.create 5
let on_kos : (int, unit -> unit) Hashtbl.t = Hashtbl.create 5
(* When we exec a command we might also want to have a callback when it's
 * actually effective (which is not the same as the command being accepted).
 * So here we register call backs that will be triggered automatically when a
 * given server command is received (regardless of mtime etc). *)
let on_dones : (Key.t, int * (SrvMsg.t -> bool) * (unit -> unit)) Hashtbl.t =
  Hashtbl.create 5

(* Return the number of pending callbacks.
 * Also a good place to time them out. *)
let pending_callbacks () =
  Hashtbl.length on_oks + Hashtbl.length on_kos + Hashtbl.length on_dones

let log_done cmd_id =
  !logger.debug "Cmd %d: done!" cmd_id

(* Given a callback, return another one that intercept error messages and call
 * RPC continuations first: *)
let check_ok clt k v =
  let maybe_cb ~do_ ~dont cmd_id =
    (match Hashtbl.find do_ cmd_id with
    | exception Not_found ->
        !logger.debug "No callback pending for cmd #%d, only for %a"
          cmd_id
          (Enum.print Int.print) (Hashtbl.keys do_)
    | k ->
        !logger.debug "Calling back pending function for cmd #%d" cmd_id ;
        k () ;
        (* TODO: Hashtbl.take *)
        Hashtbl.remove do_ cmd_id) ;
    Hashtbl.remove dont cmd_id in
  if clt.Client.my_errors = Some k then (
    match v with
    | Value.(Error (_ts, cmd_id, err_msg)) ->
        if err_msg = "" then (
          !logger.debug "Cmd %d: OK" cmd_id ;
          maybe_cb ~do_:on_oks ~dont:on_kos cmd_id
        ) else (
          !logger.error "Cmd %d: %s" cmd_id err_msg ;
          maybe_cb ~do_:on_kos ~dont:on_oks cmd_id
        )
    | v ->
        !logger.error "Error value is not an error: %a" Value.print v
  )

let check_new_cbs on_msg =
  fun clt k v uid mtime owner expiry ->
    check_ok clt k v ;
    (match Hashtbl.find on_dones k with
    | exception Not_found ->
        !logger.debug "no on_dones cb for %a" Key.print k
    | cmd_id, filter, cb ->
        let srv_cmd = SrvMsg.NewKey { k ; v ; uid ; mtime ; owner ; expiry } in
        if filter srv_cmd then (
          Hashtbl.remove on_dones k ;
          !logger.debug "on_dones cb filter pass, calling back." ;
          log_done cmd_id ;
          cb ()
        ) else (
          !logger.debug "on_dones cb filter does not pass."
        )) ;
    on_msg clt k v uid mtime owner expiry

let check_set_cbs on_msg =
  fun clt k v uid mtime ->
    check_ok clt k v ;
    (match Hashtbl.find on_dones k with
    | exception Not_found ->
        !logger.debug "no on_dones cb for %a" Key.print k
    | cmd_id, filter, cb ->
        let srv_cmd = SrvMsg.SetKey { k ; v ; uid ; mtime } in
        if filter srv_cmd then (
          Hashtbl.remove on_dones k ;
          !logger.debug "on_dones cb filter pass, calling back." ;
          log_done cmd_id ;
          cb ()
        ) else (
          !logger.debug "on_dones cb filter does not pass."
        )) ;
    on_msg clt k v uid mtime

let check_del_cbs on_msg =
  fun clt k prev_v ->
    (match Hashtbl.find on_dones k with
    | exception Not_found -> ()
    | cmd_id, filter, cb ->
        let srv_cmd = SrvMsg.DelKey k in
        if filter srv_cmd then (
          Hashtbl.remove on_dones k ;
          log_done cmd_id ;
          cb ())) ;
    on_msg clt k prev_v

let check_lock_cbs on_msg =
  fun clt k owner expiry ->
    (* owner check is part of the filter *)
    (match Hashtbl.find on_dones k with
    | exception Not_found ->
        !logger.debug "No done cb for key %a" Key.print k
    | cmd_id, filter, cb ->
        !logger.debug "Found a done filter for lock of %a"
          Key.print k ;
        let srv_cmd = SrvMsg.LockKey { k ; owner ; expiry } in
        if filter srv_cmd then (
          Hashtbl.remove on_dones k ;
          log_done cmd_id ;
          cb ())) ;
    on_msg clt k owner expiry

let check_unlock_cbs on_msg =
  fun clt k ->
    (match Hashtbl.find on_dones k with
    | exception Not_found -> ()
    | cmd_id, filter, cb ->
        let srv_cmd = SrvMsg.UnlockKey k in
        if filter srv_cmd then (
          Hashtbl.remove on_dones k ;
          log_done cmd_id ;
          cb ())) ;
    on_msg clt k

(* As the same user might be sending commands at the same time, rather use
 * start from a random cmd_id so different client programs can tell their
 * errors apart; but wait for the random seed to have been set: *)
let next_id = ref None
let init_next_id () =
  next_id := Some (Random.int max_int_for_random)

let send_cmd ?(eager=false) ?while_ ?on_ok ?on_ko ?on_done clt cmd =
  let zock, _clt = get_connection () in
  let my_uid =
    IO.to_string User.print_id clt.Client.my_uid in
  let cmd_id =
    match !next_id with
    | None ->
        init_next_id () ;
        Option.get !next_id
    | Some i -> i in
  next_id := Some (cmd_id + 1) ;
  let msg = cmd_id, cmd in
  !logger.debug "> Clt msg: %a" CltMsg.print msg ;
  let save_cb h h_name cb =
    Option.may (fun cb ->
      assert (clt.Client.my_errors <> None) ;
      Hashtbl.add h cmd_id cb ;
      let h_len = Hashtbl.length h in
      (if h_len > 10 then !logger.warning else !logger.debug)
        "%s size is now %d (%a)"
        h_name h_len
        (Enum.print Int.print) (Hashtbl.keys h)
    ) cb in
  save_cb on_oks "SyncZMQClient.on_oks" on_ok ;
  save_cb on_kos "SyncZMQClient.on_kos" on_ko ;
  Option.may (fun cb ->
    let add_done_cb cb k filter =
      Hashtbl.add on_dones k (cmd_id, filter, cb) ;
      !logger.debug "on_dones size is now %d (%a)"
        (Hashtbl.length on_dones)
        (Enum.print Key.print) (Hashtbl.keys on_dones) in
    match cmd with
    | CltMsg.Auth _
    | CltMsg.StartSync _ ->
        ()
    | CltMsg.SetKey (k, v)
    | CltMsg.NewKey (k, v, _)
    | CltMsg.UpdKey (k, v) ->
        add_done_cb cb k
          (function
          | SrvMsg.SetKey { v = v' ; _ }
          | SrvMsg.NewKey { v = v' ; _ } when Value.equal v v' -> true
          | _ -> false)
    | CltMsg.DelKey k ->
        add_done_cb cb k
          (function
          | SrvMsg.DelKey _ -> true
          | _ -> false)
    | CltMsg.LockKey (k, _)
    | CltMsg.LockOrCreateKey (k, _) ->
        add_done_cb cb k
          (function
          | SrvMsg.LockKey { owner ; _ } when owner = my_uid -> true
          | SrvMsg.LockKey { owner ; _ } ->
              !logger.debug
                "Received a lock for key %a but for user %S instead of %S"
                Key.print k
                owner my_uid ;
              false
          | _ -> false)
    | CltMsg.UnlockKey k ->
        add_done_cb cb k
          (function
          | SrvMsg.UnlockKey _ -> true
          | _ -> false)
  ) on_done ;
  let s = CltMsg.to_string msg in
  (match while_ with
  | None ->
      Zmq.Socket.send_all zock [ "" ; s ]
  | Some while_ ->
      retry_zmq ~while_
        (Zmq.Socket.send_all ~block:false zock) [ "" ; s ]) ;
  let set_eagerly k v lock_timeo =
    let new_hv () =
      Client.{ value = v ;
               uid = clt.Client.my_uid ;
               mtime = Unix.gettimeofday () ;
               owner = if lock_timeo > 0. then clt.Client.my_uid else "" ;
               expiry = 0. ; (* whatever *)
               eagerly = Created } in
    match Client.H.find clt.Client.h k with
    | exception Not_found ->
        let hv = new_hv () in
        Client.H.add clt.Client.h k (Value hv)
    | Waiters conts ->
        let hv = new_hv () in
        Client.H.replace clt.Client.h k (Value hv) ;
        List.iter (fun cont -> cont hv) conts
    | Value hv ->
        hv.value <- v ;
        hv.eagerly <- Overwritten in
  if eager then (
    match cmd with
    | SetKey (k, v) | UpdKey (k, v) ->
        set_eagerly k v 0.
    | NewKey (k, v, lock_timeo) ->
        set_eagerly k v lock_timeo
    | DelKey k ->
        (match Client.find clt k with
        | exception Not_found -> ()
        | hv ->
            hv.eagerly <- Deleted)
    | _ ->
        !logger.debug "Cannot do %a eagerly"
          CltMsg.print_cmd cmd
  )

let recv_cmd _clt =
  let zock, _clt = get_connection () in
  match Zmq.Socket.recv_all zock with
  | [ "" ; s ] ->
      (* !logger.debug "srv message (raw): %S" s ; *)
      let msg = SrvMsg.of_string s in
      !logger.debug "< Srv msg: %a" SrvMsg.print msg ;
      msg
  | m ->
      Printf.sprintf2 "Received unexpected message %a"
        (List.print String.print) m |>
      failwith

let unexpected_reply cmd =
  Printf.sprintf "Unexpected reply %s"
    (SrvMsg.to_string cmd) |>
  failwith

(* This locks keys one by one (waiting for the answer at every step.
 * FIXME: lock all then wait for all answers *)
let matching_keys clt f =
  Client.H.enum clt.Client.h //@
  (fun (k, _) -> if f k then Some k else None) |>
  List.of_enum

let with_locked_matching
      ?while_ ?(lock_timeo=Default.sync_lock_timeout) clt f cb =
  let keys = matching_keys clt f in
  let rec loop unlock_all = function
    | [] ->
        !logger.debug "All keys locked, calling back user" ;
        cb () ;
        !logger.debug "...Back from user, unlocking everything" ;
        unlock_all ()
    | key :: rest ->
        let unlock_all' () =
          send_cmd ?while_ ~on_ok:unlock_all ~on_ko:unlock_all clt
            (CltMsg.UnlockKey key) in
        let on_ok () =
          loop unlock_all' rest in
        send_cmd ?while_ ~on_ok ~on_ko:unlock_all clt
          (CltMsg.LockKey (key, lock_timeo)) in
  loop ignore keys

module Stage =
struct
  type t = | Conn | Auth | Sync
  let to_string = function
    | Conn -> "Connection"
    | Auth -> "Authentication"
    | Sync -> "Synchronization"
  let print oc s =
    String.print oc (to_string s)
end

module Status =
struct
  type t =
    | InitStart | InitOk | InitFail of string (* For the init stage *)
    | Ok of string | Fail of string
  let to_string = function
    | InitStart -> "Starting"
    | InitOk -> "Established"
    | InitFail s -> "Not established: "^ s
    | Ok s -> "Ok: "^ s
    | Fail s -> "Failed: "^ s
  let print oc s =
    String.print oc (to_string s)
end

let default_on_progress _clt stage status =
  (match status with
  | Status.InitStart | InitOk -> !logger.info
  | InitFail _ | Fail _ -> !logger.error
  | _ -> !logger.debug)
    "%a: %a" Stage.print stage Status.print status

let init_connect clt ?while_ url on_progress =
  let zock, _clt = get_connection () in
  let connect_to = "tcp://"^ url in
  on_progress clt Stage.Conn Status.InitStart ;
  try
    !logger.info "Connecting to %s..." connect_to ;
    retry_zmq ?while_
      (Zmq.Socket.connect zock) connect_to ;
    on_progress clt Stage.Conn Status.InitOk
  with e ->
    on_progress clt Stage.Conn Status.(InitFail (Printexc.to_string e))

let init_auth ?while_ clt login on_progress =
  on_progress clt Stage.Auth Status.InitStart ;
  try
    send_cmd ?while_ clt (CltMsg.Auth login) ;
    match retry_zmq ?while_ recv_cmd clt with
    | SrvMsg.AuthOk _ as msg ->
        Client.process_msg clt msg ;
        on_progress clt Stage.Auth Status.InitOk
    | SrvMsg.AuthErr s as msg ->
        Client.process_msg clt msg ;
        on_progress clt Stage.Auth (Status.InitFail s)
    | rep ->
        unexpected_reply rep
  with e ->
    on_progress clt Stage.Auth Status.(InitFail (Printexc.to_string e))

(* Receive and process incoming commands until timeout.
 * Returns the number of messages that have been read. *)
let process_in ?(while_=always) ?(single=false) clt =
  let rec loop msg_count =
    if while_ () then
      match recv_cmd clt with
      | exception Unix.(Unix_error (EAGAIN, _, _)) ->
          msg_count
      | msg ->
          Client.process_msg clt msg ;
          let msg_count = msg_count + 1 in
          if single then msg_count else loop msg_count
    else
      msg_count in
  loop 0

let init_sync ?while_ clt topics on_progress =
  on_progress clt Stage.Sync Status.InitStart ;
  let globs = List.map Globs.compile topics in
  (* Also subscribe to the error messages, unless it's covered already: *)
  assert (clt.Client.my_errors <> None) ;
  let my_errors = Option.get clt.Client.my_errors |> Key.to_string in
  let globs =
    if List.exists (fun glob -> Globs.matches glob my_errors) globs then (
      !logger.debug "subscribed topics already cover error stream %S, \
                     not subscribing separately" my_errors ;
      globs
    ) else
      Globs.escape my_errors :: globs
  in
  let synced = ref false in
  let rec loop = function
    | [] ->
        () (* Nothing to sync to -> nothing to wait for *)
    | [glob] ->
        (* Last command: wait until it's acked *)
        let on_ok () = synced := true in
        send_cmd ?while_ ~on_ok clt (CltMsg.StartSync glob)
    | glob :: rest ->
        send_cmd ?while_ clt (CltMsg.StartSync glob) ;
        loop rest in
  match loop globs with
  | exception e ->
      on_progress clt Stage.Sync Status.(InitFail (Printexc.to_string e))
  | () ->
      on_progress clt Stage.Sync Status.InitOk ;
      (* Wait until it's acked *)
      let while_ () =
        not !synced &&
        (match while_ with Some f -> f () | None -> true) in
      while while_ () do
        !logger.debug "Wait for end of sync..." ;
        let msg_count = process_in ~while_ clt in
        !logger.debug "Received %d messages" msg_count
      done

(* Will be called by the C++ on a dedicated thread, never returns: *)
let start ?while_ srv_pub_key url creds ?(topics=[])
          ?(on_progress=default_on_progress)
          ?(on_sock=ignore1) ?(on_synced=ignore1)
          ?(on_new=ignore7) ?(on_set=ignore5) ?(on_del=ignore3)
          ?(on_lock=ignore4) ?(on_unlock=ignore2)
          ?(conntimeo=0.) ?(recvtimeo= ~-.1.) ?(sndtimeo= ~-.1.) sync_loop =
  let to_ms f =
    if f < 0. then -1 else int_of_float (f *. 1000.) in
  let ctx = Zmq.Context.create () in
  finally
    (fun () -> Zmq.Context.terminate ctx)
    (fun () ->
      let on_new = check_new_cbs on_new
      and on_set = check_set_cbs on_set
      and on_del = check_del_cbs on_del
      and on_lock = check_lock_cbs on_lock
      and on_unlock = check_unlock_cbs on_unlock in
      let clt =
        Client.make ~my_uid:creds ~on_new ~on_set ~on_del ~on_lock ~on_unlock in
      let zock = Zmq.Socket.(create ctx dealer) in
      zock_clt := Some (zock, clt) ;
      finally
        (fun () -> Zmq.Socket.close zock)
        (fun () ->
          if srv_pub_key <> "" then (
            Zmq.Socket.set_curve_serverkey zock srv_pub_key ;
            (* TODO: got those from somewhere: *)
            let secret_key_test =
              "D:)Q[IlAW!ahhC2ac:9*A}h:p?([4%wOTJ%JR%cs"
            and public_key_test =
              "Yne@$w-vo<fVvi]a<NY6T1ed:M$fCG*[IaLV{hID" in
            Zmq.Socket.set_curve_secretkey zock secret_key_test ;
            Zmq.Socket.set_curve_publickey zock public_key_test) ;
          (* Timeouts must be in place before connect: *)
          (* Not implemented for some reasons, although there is a
           * ZMQ_CONNECT_TIMEOUT:
           * Zmq.Socket.set_connect_timeout zock conntimeo ; *)
          ignore conntimeo ;
          Zmq.Socket.set_receive_timeout zock (to_ms recvtimeo) ;
          Zmq.Socket.set_send_timeout zock (to_ms sndtimeo) ;
          Zmq.Socket.set_send_high_water_mark zock 0 ;
          on_sock clt ;
          let url =
            if String.contains url ':' then url
            else url ^":"^ string_of_int (
              if srv_pub_key = "" then Default.confserver_port
              else Default.confserver_port_sec) in
          log_exceptions ~what:"init_connect"
            (fun () -> init_connect clt ?while_ url on_progress) ;
          log_exceptions ~what:"init_auth"
            (fun () -> init_auth ?while_ clt creds on_progress) ;
          log_exceptions ~what:"init_sync"
            (fun () -> init_sync ?while_ clt topics on_progress) ;
          on_synced () ;
          log_exceptions ~what:"sync_loop" (fun () -> sync_loop clt)
        ) ()
    ) ()
