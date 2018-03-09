createList(N,R):-
    findall(Ri,between(1,N,Ri),R).


suma([],0).
suma([H|T],S):-
    suma(T,S1),
    S is S1+H.
subset6([],[]).
subset6([_|T],R):-
    subset6(T,R).

subset6([H|T],[H|TR]):-
    subset6(T,TR).
consecutive([_]).
consecutive([H1,H2|T]):-
    H1<H2,
    consecutive([H2|T]).

oneSol8(L,N,R):-
    subset6(L,R1),
    suma(R1,N),
    consecutive(R1),
    R =R1.

allSol8(L,N,R):-
    findall(Ri,oneSol8(L,N,Ri),R).

apel(N,R):-
    createList(N,L),
    allSol8(L,N,R).
