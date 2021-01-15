(* Helpers for code generated by the Dessser OCaml backend *)

let pointer_of_tx tx =
  let b = RingBuf.read_raw_tx tx in
  DessserOCamlBackendHelpers.Pointer.of_bytes b 0 (Bytes.length b)

(* Dessser has no type variables and cannot build pairs (or tuples) so we need
 * those very explicit helpers: *)

let make_float_pair (v1 : float) (v2 : float) =
  v1, v2

let make_string_pair (v1 : string) (v2 : string) =
  v1, v2

let make_factor_value (v1 : string) (v2 : RamenTypes.value) =
  v1, v2
