(* See RamenNames.mli *)
open Batteries
open RamenHelpers
module T = RamenTypes

type 'a t = string [@@ppp PPP_OCaml] [@@ppp PPP_JSON]

(* Field names *)

type field = [`Fiield] t

let field_ppp_ocaml = t_ppp_ocaml
let field_ppp_json = t_ppp_json

let field s =
  (* New lines have to be forbidden because of the out_ref ringbuf files.
   * Slashes have to be forbidden because we rsplit to get program names. *)
  if s = "" ||
     String.fold_left (fun bad c ->
       bad || c = '\n' || c = '\r' || c = '/') false s then
    invalid_arg "operation name" ;
  s

let field_print = String.print
let field_print_quoted = String.print_quoted (* TODO: or just use color *)

let starts_with c f =
  String.length f > 0 && f.[0] = c

let is_virtual = starts_with '#'
let is_private = starts_with '_'


(* Function names *)

type func = [`Function] t

let func_ppp_ocaml = t_ppp_ocaml

let func s =
  (* New lines have to be forbidden because of the out_ref ringbuf files.
   * Slashes have to be forbidden because we rsplit to get program names. *)
  if s = "" ||
     String.fold_left (fun bad c ->
       bad || c = '\n' || c = '\r' || c = '/') false s then
    invalid_arg "operation name" ;
  s

let func_print = String.print
let func_print_quoted = String.print_quoted

(* Program names *)

type program = [`Program] t

let program_ppp_ocaml = t_ppp_ocaml

let program s =
  let rec remove_heading_slashes s =
    if String.length s > 0 && s.[0] = '/' then
      remove_heading_slashes (String.lchop s)
    else s in
  let s = remove_heading_slashes s in
  if s = "" then
    failwith "Program names must not be empty" else
  if has_dotnames s then
    failwith "Program names cannot include directory dotnames" else
  simplified_path s

(* Make sure a path component is shorter that max_dir_len: *)
let max_dir_len = 255
let abbrev s =
  if String.length s <= max_dir_len then s else md5 s

let path_of_program prog =
  String.split_on_char '/' prog |>
  List.map abbrev |>
  String.join "/"

let program_print = String.print
let program_print_quoted = String.print_quoted

(* Relative Program Names: "../" are allowed, and conversion to a normal
 * program name requires the location from which the program is relative: *)

type rel_program = [`RelProgram] t

let rel_program_ppp_ocaml = t_ppp_ocaml

let rel_program s =
  if s = "" then invalid_arg "relative program name"
  else s

let program_of_rel_program start rel_program =
  (* TODO: for now we just support "../" prefix: *)
  if rel_program = ".." || String.starts_with rel_program "../" then
    simplified_path (start ^"/"^ rel_program)
  else rel_program

let rel_program_print = String.print
let rel_program_print_quoted = String.print_quoted

(* Program parameters
 *
 * String representation is the printed out values of all parameters
 * ("{p1=n1;p2=v2;...}"), if short enough;
 * - The MD5 hash of the above, otherwise.  *)

type param = string * T.value [@@ppp PPP_OCaml]
type params = (field, T.value) Hashtbl.t [@@ppp PPP_OCaml]

let params_sort =
  let param_compare (a, _) (b, _) = String.compare a b in
  List.fast_sort param_compare

let string_of_params params =
  let print_param oc (n, v) =
    Printf.fprintf oc "%s=%a" n T.print v in
  Hashtbl.enum params |>
  List.of_enum |>
  params_sort |>
  IO.to_string (List.print ~first:"" ~last:"" ~sep:";" print_param) |>
  abbrev

let signature_of_params = md5 % string_of_params

(* Fully Qualified function names *)

type fq = [`FQ] t

let fq_ppp_ocaml = t_ppp_ocaml

external fq : string -> fq = "%identity"

let fq_of_program prog func = prog ^"/"^ func

let fq_print = String.print
let fq_print_quoted = String.print_quoted

let fq_parse ?default_program s =
  let s = String.trim s in
  (* rsplit because we might have '/'s in the program name. *)
  match String.rsplit ~by:"/" s with
  | exception Not_found ->
      (match default_program with
      | Some l -> l, func s
      | None ->
          Printf.sprintf "Cannot find function %S" s |>
          failwith)
  | p, f -> (program p, func f)

(* Base units *)

type base_unit = [`BaseUnit] t

let base_unit_ppp_ocaml = t_ppp_ocaml

external base_unit : string -> base_unit = "%identity"
let base_unit_print = String.print
let base_unit_print_quoted = String.print_quoted

(* File paths *)

type path = [`Path] t

let path_ppp_ocaml = t_ppp_ocaml
external path : string -> path = "%identity"
let path_print = String.print
let path_print_quoted = String.print_quoted
let path_cat = String.concat "/"

(* Some dedicated colors for those strings: *)

let field_color = RamenLog.blue
let func_color = RamenLog.green
let program_color = RamenLog.green
let rel_program_color = program_color
let expr_color = RamenLog.yellow
let fq_color = func_color

type 'a any =
  [< `Field|`Function|`Program|`RelProgram|`FQ|`BaseUnit|`Url|`Path] as 'a

let compare = String.compare
let cat = (^)
let length = String.length
let is_empty s = String.length s = 0
let lchop = String.lchop
let starts_with = String.starts_with
let sub = String.sub
