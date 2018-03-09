consecutive([]).
consecutive([_]).
consecutive([H1,H2|T]):-
    H2 =:= H1 +1,
    consecutive([H2|T]).

suma([],0).
suma([H|T],S):-
    suma(T,S1),
    S is S1+H.
subset2([],[]).
subset2([_|T],R):-
    subset2(T,R).

subset2([H|T],[H|TR]):-
    subset2(T,TR).

oneSol(L,N,R):-
    subset2(L,R1),
    consecutive(R1),
    suma(R1,N),
    R = R1.

append([],E,[E]).
append([H|T],E,[H|TR]):-
    append(T,E,TR).
allSol(L,N,R):-
    findall(Ri,oneSol(L,N,Ri),R).

generateList(0,[]).
generateList(N,R):-
    N1 is N-1,
    generateList(N1,R1),
    append(R1,N1,R).

apel(N,R):-
    generateList(N,L),
    allSol(L,N,R).


