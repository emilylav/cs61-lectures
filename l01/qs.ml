let rec qs = function
     | []    -> []
     | pivot::xs ->
           let left  = List.filter (fun y -> y < pivot)  xs
           and right = List.filter (fun y -> y >= pivot) xs
           in  (qs left) @ [pivot] @ (qs right);;
