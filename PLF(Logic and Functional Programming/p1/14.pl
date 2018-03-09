removel([],_,[]).
removel([H|T],E,[H|TR]):-
    H=\=E,
    removel(T,E,TR).
removel([H|T],E,R):-
    H=:=E,
    removel(T,E,R).

equal([],[]).
equal([H|T],R):-
    removel(R,H,R1),
    equal(T,R1).

selectn([],N,_):-N>0,fail.
selectn([_|T],N,R):-
    N=\=0,
    N1 is N-1,
    selectn
