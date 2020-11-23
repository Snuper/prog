parent('John', 'Bob').
parent('Marry', 'Bob').
parent('Marry', 'Ann').
parent('Bob', 'Lisa').
parent('Bob', 'Sam').
parent('Bob', 'Paul').
parent('Paul', 'Pat').

man('John').
man('Bob').
man('Paul').
man('Sam').
man('Pat').

woman('Marry').
woman('Ann').
woman('Lisa').

father(X, Y):-
    parent(X, Y),
    man(X).


parent('John', 'Bob').
parent('Marry', 'Bob').
parent('Marry', 'Ann').
parent('Bob', 'Lisa').
parent('Bob', 'Sam').
parent('Bob', 'Paul').
parent('Paul', 'Pat').

man('John').
man('Bob').
man('Paul').
man('Sam').
man('Pat').

woman('Marry').
woman('Ann').
woman('Lisa').

father(X, Y):- % ( Parent , Child )
    parent(X, Y),
    man(X).

mother(X, Y):- % ( Parent , Child )
    parent(X, Y),
    woman(X).

sister(X, Y):- % (   Sister , Who) 
    parent(Z,X),
    parent(Z, Y),
    woman(Y),
    X \= Y.

brother(X, Y):- % (   Sister , Who) 
    parent(Z, X),
    parent(Z, Y),
    man(X), X \= Y.

grandson(X, Y):- % (  child, grand) 
    parent(Y, Z),
    parent(Z, X),
    man(X).

aunt(X, Y):- % (   aunt , child)
    parent(Z, Y),
    sister(X, Z).

newphews(X,Y):- % (   aunt , child)
    parent(Z,X),
    parent(Z,W),
    parent(W,Y).
    
potg(X):-
    man(X),
    parent(X, Y),
    man(Y).

twoChild(X):-
parent(X,Y),
parent(X,Z),
Y \= Z.

childs(X):-
limit(1, (twoChild(X))).