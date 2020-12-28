working([H|T], List, [HEX|TEX], Nlist, NlistEX, NlistExConst, NewList, ListExCount):-
    Nex is NlistEX - 1,
    Nex > 0, H =\= HEX, !,
   		append([H], T, HLIST),	
    	working(HLIST, List, TEX, Nlist, Nex, NlistExConst, NewList, ListExCount)    		
    ;
    New is Nlist - 1,
    H == HEX ,!,
    working(T, T, ListExCount, New, NlistExConst, NlistExConst, NewList, ListExCount);    
    append([H], NewList, NewListNext),
    New is Nlist - 1,
    New > 0 ,!, 
    working(T, T, ListExCount, New, NlistExConst, NlistExConst, NewListNext, ListExCount);
    append([H], NewList, NewListNext),
    write(NewListNext).

mainKostya(List, ListEX, NewList):-
    length(ListEX, NlistEX),
    length(List, Nlist),
    working(List, List, ListEX, Nlist, NlistEX, NlistEX, NewList, ListEX).
    