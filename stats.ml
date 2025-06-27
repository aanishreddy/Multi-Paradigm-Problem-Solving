let mean lst =
  let sum = List.fold_left ( +. ) 0.0 (List.map float_of_int lst) in
  sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 0 then
    let mid1 = List.nth sorted (n/2 - 1) in
    let mid2 = List.nth sorted (n/2) in
    float_of_int (mid1 + mid2) /. 2.0
  else
    float_of_int (List.nth sorted (n/2))

let mode lst =
  let counts =
    List.fold_left
      (fun acc x ->
         if List.mem_assoc x acc then
           (x, List.assoc x acc + 1) :: List.remove_assoc x acc
         else
           (x, 1) :: acc)
      [] lst
  in
  let max_count = List.fold_left (fun acc (_, count) -> max acc count) 0 counts in
  List.filter (fun (_, count) -> count = max_count) counts
  |> List.map fst

let () =
  let data = [1; 3; 3; 6; 7; 8; 9] in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  Printf.printf "Mode(s): ";
  mode data |> List.iter (Printf.printf "%d ");
  print_newline ()
