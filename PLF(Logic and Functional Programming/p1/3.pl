mycount([],_,0):-!.
mycount([H|T],E,R):-
    H=:=E,!,
    mycount(T,E,R1),
    R is R1 +1.
mycount([_|T],E,R):-
    mycount(T,E,R).

removeRep([],_,[]).
removeRep([H|T],CL,[H|TR]):-
    mycount(CL,H,1),
    removeRep(T,CL,TR).

removeRep([H|T],CL,R):-
    not(mycount(CL,H,1)),
    removeRep(T,CL,R).

maxi(A,B,A):-A>B,!.
maxi(_,B,B).

maxList([E],E).
maxList([H|T],M):-
    maxList(T,M1),
    maxi(H,M1,M).

removeMax([],_,[]).
removeMax([H|T],E,[H|TR]):-
    H=\=E,
    removeMax(T,E,TR).
removeMax([H|T],E,R):-
    H=:=E,
    removeMax(T,E,R).

maxrem(L,R):-
    maxList(L,M),
    removeMax(L,M,R).

