fib(1,0,1).

fib(D,M,N):-
	D > 0,
	D1 is D-1,
	fib(D1,M1,N1),
	N is M1,
	M is M1 + N1.


recurs(L,R):-
    L =< R,
    L mod 2 =\= 0 -> format("~a ", L),
    L1 is L + 1,
    recurs(L1 ,R);
    L =<R ,
    L1 is L + 1,
	recurs(L1 ,R).
    

input:-
	write("left border"),
    read(L),
    write("right border"),
    read(R),
	format("[ ~a:~a ]~n",[L, R]),
    recurs(L,R).

split(M,[H1|T1],[H1|T],L2):-
	H1@<M,!,split(M,T1,T,L2).
split(M,[H1|T1],L1,[H1|T2]):-
    split(M,T1,L1,T2).
split(_,[],[],[]).

third(List, X, Y):-
    X =< Y,
    split(X, List, L1, L2),
	write(L1),
    split(Y, L2, L3, L4),
    write(L3),
    write(L4);
    X > Y,
    split(X, List, L1, L2),
    write(L1),
    split(Y, L2, L3, L4),
    write(L3),
    write(L4).


memeber(List2, [X|T], Max):-
   	count(List2, X),
    Max < X, Max is X,
    memeber(List2, T, Max);
    memeber(List2, T, Max).
    
echo:-
    read(List),
    memeber(List, List, 0).
    
    
count([],0).
count([_|T],N):-count(T,N1),N is N1+1.
