open Batteries
open RamenLog
open RamenHelpers
module C = RamenConf
module F = C.Func

let propose (l, h) =
  String.print stdout l ;
  if h <> "" then (
    Char.print stdout '\t' ;
    String.print stdout h) ;
  print_endline ""

let complete lst s =
  List.filter (fun (l, _) -> String.starts_with l s) lst |>
  List.iter propose

let complete_commands s =
  let commands =
    [ "start", RamenConsts.CliInfo.start ;
      "compile", RamenConsts.CliInfo.compile ;
      "run", RamenConsts.CliInfo.run ;
      "kill", RamenConsts.CliInfo.kill ;
      "tail", RamenConsts.CliInfo.tail ;
      "timeseries", RamenConsts.CliInfo.timeseries ;
      "timerange", RamenConsts.CliInfo.timerange ;
      "ps", RamenConsts.CliInfo.ps ;
      "test", RamenConsts.CliInfo.test ;
      "graphite", RamenConsts.CliInfo.graphite] in
  complete commands s

let complete_global_options s =
  let options =
    [ "--help", RamenConsts.CliInfo.help ;
      "--version", RamenConsts.CliInfo.version ] in
  complete options s

let find_opt o =
  let opt_value s =
    String.split s ~by:"=" |> snd in
  let o_eq = o ^ "=" in
  let find_opt_1 s =
    if String.starts_with s o_eq then opt_value s else
    raise Not_found in
  let rec loop = function
  | [] -> raise Not_found
  | [s] -> find_opt_1 s
  | s::(n::_ as rest) ->
      if s = o then n else
      try find_opt_1 s
      with Not_found -> loop rest in
  fun lst -> loop lst

let persist_dir toks =
  try find_opt "--persist-dir" toks
  with Not_found ->
    try Sys.getenv "RAMEN_PERSIST_DIR"
    with Not_found -> RamenConsts.default_persist_dir

let complete_file select str =
  let count = ref 0 in
  let res = ref [] in
  let root, pref =
    if str = "" then ".", ""
    else if str.[String.length str - 1] = '/' then str, str
    else let d = Filename.dirname str in d, if d = "." && str.[0] <> '.' then "" else d^"/" in
  let start =
    (* [basename ""] would be ".", and [basename "toto/"] would be toto ?! *)
    if str = "" || str.[String.length str - 1] = '/' then ""
    else Filename.basename str in
  let on_file fname rel_fname =
    if select fname && String.starts_with rel_fname start then (
      incr count ;
      if !count > 500 then raise Exit ;
      res := (pref ^ rel_fname, "") :: !res) in
  if str <> "" && str.[0] = '-' then [] else (
    (try dir_subtree_iter ~on_file root
    with Exit -> ()) ;
    !res)

let extension_is ext fname =
  String.ends_with fname ext

let complete_program_files str =
  complete_file (extension_is ".ramen") str

let complete_binary_files str =
  complete_file (extension_is ".x") str

let complete_test_files str =
  complete_file (extension_is ".test") str

let empty_help s = s, ""

let complete_running_function persist_dir str =
  let conf = C.make_conf persist_dir in
  (
    (Lwt_main.run (C.with_rlock conf Lwt.return) |> Hashtbl.values) /@
    (fun get_rc -> snd (get_rc ())) /@
    (fun rc -> Enum.map (fun func -> func.F.program_name ^"/"^ func.F.name) (List.enum rc)) |>
    Enum.flatten
  ) /@
  empty_help |> List.of_enum

let complete_running_program persist_dir str =
  let conf = C.make_conf persist_dir in
  (Lwt_main.run (C.with_rlock conf Lwt.return) |> Hashtbl.keys) /@
  empty_help |> List.of_enum

let complete str () =
  (* Tokenize str, find where we are: *)
  let last_tok_is_complete =
    let len = String.length str in
    len > 0 && Char.is_whitespace str.[len - 1] in
  let toks =
    String.split_on_char ' ' str |>
    List.filter (fun s -> String.length s > 0) in
  let toks =
    match toks with
    | s :: rest when String.ends_with s "ramen" -> rest
    | r -> r (* ?? *) in
  let nb_toks = List.length toks in
  let command_idx, command =
    try List.findi (fun i s -> s.[0] <> '-') toks
    with Not_found -> -1, "" in
  let last_tok =
    if nb_toks > 0 then List.nth toks (nb_toks-1)
    else "" in
  (*!logger.info "nb_toks=%d, command_idx=%d, command=%s, last_tok_complete=%b"
    nb_toks command_idx command last_tok_is_complete ;*)

  (match nb_toks, command_idx, last_tok_is_complete with
  | 0, _, true -> (* "ramen<TAB>" *)
    complete_commands ""
  | 0, _, false -> (* "ramen <TAB>" *)
    complete_commands ""
  | _, -1, false -> (* "ramen [[other options]] --...<TAB>" *)
    complete_global_options last_tok
  | _, c_idx, false when c_idx = nb_toks-1 -> (* "ramen ... comm<TAB>" *)
    complete_commands last_tok
  | _ -> (* "ramen ... command ...? <TAB>" *)
    let toks = List.drop (command_idx+1) toks in
    let completions =
      (match command with
      | "start" ->
          [ "--daemonize", RamenConsts.CliInfo.daemonize ;
            "--help", RamenConsts.CliInfo.help ;
            "--persist-dir=", RamenConsts.CliInfo.persist_dir ;
            "--rand-seed=", RamenConsts.CliInfo.rand_seed ;
            "--to-stdout", RamenConsts.CliInfo.to_stdout ;
            "--autoreload=", RamenConsts.CliInfo.autoreload ]
      | "compile" ->
          ("--bundle-dir=", RamenConsts.CliInfo.bundle_dir) ::
          ("--keep-temp-files", RamenConsts.CliInfo.keep_temp_files) ::
          ("--help", RamenConsts.CliInfo.help) ::
          ("--persist-dir=", RamenConsts.CliInfo.persist_dir) ::
          ("--root-path=", RamenConsts.CliInfo.root_path) ::
          ("--external-compiler", RamenConsts.CliInfo.external_compiler) ::
          (complete_program_files last_tok)
      | "run" ->
          ("--help", RamenConsts.CliInfo.help) ::
          ("--persist-dir=", RamenConsts.CliInfo.persist_dir) ::
          ("--parameter=", RamenConsts.CliInfo.param) ::
          (complete_binary_files last_tok)
      | "kill" ->
          let persist_dir = persist_dir toks in
          ("--help", RamenConsts.CliInfo.help) ::
          (complete_running_program persist_dir last_tok)
      | "tail" ->
          let persist_dir = persist_dir toks in
          ("--help", RamenConsts.CliInfo.help) ::
          ("--last=", RamenConsts.CliInfo.last) ::
          ("--max-seqnum=", RamenConsts.CliInfo.max_seq) ::
          ("--min-seqnum=", RamenConsts.CliInfo.min_seq) ::
          ("--null=", RamenConsts.CliInfo.csv_null) ::
          ("--separator=", RamenConsts.CliInfo.csv_separator) ::
          ("--persist-dir", RamenConsts.CliInfo.persist_dir) ::
          ("--with-header", RamenConsts.CliInfo.with_header) ::
          ("--with-seqnums", RamenConsts.CliInfo.with_seqnums) ::
          ("stats", "") ::
          (complete_running_function persist_dir last_tok)
      | "timeseries" ->
          let persist_dir = persist_dir toks in
          (* TODO: get the function name from toks and autocomplete
           * field names! *)
          ("--help", RamenConsts.CliInfo.help) ::
          ("--since=", RamenConsts.CliInfo.since) ::
          ("--until=", RamenConsts.CliInfo.until) ::
          ("--max-nb-points=", RamenConsts.CliInfo.max_nb_points) ::
          ("--data-field=", RamenConsts.CliInfo.data_field) ::
          ("--consolidation=", RamenConsts.CliInfo.consolidation) ::
          ("--separator=", RamenConsts.CliInfo.csv_separator) ::
          ("--null=", RamenConsts.CliInfo.csv_null) ::
          ("stats", "") ::
          (complete_running_function persist_dir last_tok)
      | "timerange" ->
          let persist_dir = persist_dir toks in
          ("--help", RamenConsts.CliInfo.help) ::
          (complete_running_function persist_dir last_tok)
      | "ps" ->
          [ "--help", RamenConsts.CliInfo.help ;
            "--short", RamenConsts.CliInfo.short ;
            "--sort", RamenConsts.CliInfo.sort_col ;
            "--top", RamenConsts.CliInfo.top ]
      | "test" ->
          ("--help", RamenConsts.CliInfo.help) ::
          ("--root-path=", RamenConsts.CliInfo.root_path) ::
          (complete_test_files last_tok)
      | "graphite" ->
          [ "--help", RamenConsts.CliInfo.help ;
            "--daemonize", RamenConsts.CliInfo.daemonize ;
            "--to-stdout", RamenConsts.CliInfo.to_stdout ;
            "--port=", RamenConsts.CliInfo.port ]
      | _ -> []) in
    complete completions (if last_tok_is_complete then "" else last_tok))
