doubleList([H|T], List, N):-
    New is N - 1,
    New > 0, !,
    	append([H], [H], NewList),
   		append(List, NewList, ListX2),
    	doubleList(T, ListX2, New);
    append([H], [H], NewList),
   	append(List, NewList, ListX2),
    write(ListX2).

resultWrite(ListX2):-
    write(ListX2).

main1(List, ListX2):-
    length(List, N),
    doubleList(List, ListX2, N).
	
	
	
goal:-
	writeln("File"),
	read(Filename),
	check_exist(Filename),
	open(Filename,read,F), set_input(F),
	read_file(F,1),
	write_screen(F), close(F).

check_exist(Filename):-
	exists_file(Filename),!.

check_exist(_):-
	writeln("error"),fail.

read_file(_,_):-
	at_end_of_stream,!,  fail.

read_file(_,1):- !.

read_file(F,N):-
	read_line_to_codes(F,_),
	N1 is N-1, 
	read_file(F,N1).
	
write_screen(_):-
	at_end_of_stream,!.
	
write_screen(F):-
	read_line_to_string(F,L), 
	string_to_list(S,L),
	writeln(S),
	writekek(L),
	write_screen(F).

check([H|T], L, Add, Spaces):-
	string_length(H,H1),
	Al is (H1 + Add + 1 + Spaces),
	length(L,N),
	N > 1, !,
		check(T, T, Al, Spaces);
	string_length(H,H1),
	Al is (H1 + Add),
	checkSpace(Al, Spaces).
	
checkSpace(All, Spaces):-
	All > 40, !,
	Need is All - 40,
	write(Need),
	write(" "),
	write(Spaces),
	write(" "),
	write(All),
	write_in_file(Spaces - Need);
	All == 40,!,
	write_in_file(Spaces);
	Need is 41 - All,
	write(Need),
	write_in_file(Spaces + Need).
	
kek([H|T],L, Spaces, LL):-
	open("write1.txt", append, Out),
	write(Out, H),
	close(Out),
	length(L,N),
	N > 2,!,
		write_in_file(Spaces),
		kek(T,T, Spaces, LL);
	length(L,N),
	N == 2,
		check(LL, LL, 0, Spaces),
		kek(T,T, Spaces, LL);
	writeln("").

write_in_file(Spaces):-
	Spaces > 0,!,
	open("write1.txt", append, Out),
	write(Out, " "),
	close(Out),
	write_in_file(Spaces - 1);
	writeln("").
	
writekek(S):-
	string_length(S,N),
	N < 40,!,
	split_string(S, " ", " ", L),
	length(L, Space),
	NeedSpace is (40 - N) / (Space-1),
	kek(L, L, floor(NeedSpace), L),
	open("write1.txt", append, Out),
	write(Out, "\n"),
	close(Out);
	open("write1.txt", append, Out),
	write(Out,S),
	write(Out, "\n"),
	close(Out).
	
	
	
	
	

:-dynamic maxPrice/1.

domains:-
	s = string,
	i = integer.

database:-
	toys(s,i).

menu:-
	consult("toys.ddb"),
	repeat,
	nl,
	writeln("---------------------------------------"),
	writeln("1 - Display information about all toys"),
	writeln("2 - Input"),
    writeln("3 - Delete"),
    writeln("4 - The most expensive toys"),
	writeln("5 - Exit"),nl,
	write("Input: (1-5) "),
	read(X), nl, X<6, X > 0,
	writeln("---------------------------------------"), nl, process(X), nl, X = 5,!.
	
	process(5).
	
	process(1):- 
		toys(E,R),
		format("[~a ~a]~n",[E, R]),fail.
	
	process(2):-
		repeat,
		write("Input name toy: "),nl,read(Name),
		write("Input price: "),nl,read(Price),
		asserta(toys(Name, Price)),
		write("Input next? 1/0"),nl,read(Answer),
		answerInput(Answer),!,
		fail.
		
	process(3):-
		write("Input name toy: "),nl,read(Name),
		retractall(toys(Name, _)),
		write("Input next? 1/0"),nl,read(Answer),
		answerOutput(Answer),!,
		fail.
		
	process(4):-
		findall(X, toys(_, X), PriceList),
		max_list(PriceList, MaxList),
		retractall(maxPrice(_)),
		asserta(maxPrice(MaxList)),
		toys(E,R),
		maxPrice(N),
		R > N -100,
		format("[~a ~a]~n",[E, R]),fail.
	
	answerInput(0).
	answerInput(1):- process(2), fail.
	
	answerOutput(0).
	answerOutput(1):- process(3), fail.
