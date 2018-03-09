suma1([],0).
suma1([H|T],S):-
    suma1(T,S1),
    S is S1 +H.

subset9([],[]).
subset9([_|T],R):-
    subset9(T,R).
subset9([H|T],[H|TR]):-
    subset9(T,TR).

oneSol9(L,S,R):-
    subset9(L,R1),
    suma1(R1,S),
    R = R1.

allSol9(L,S,R):-
    findall(Ri,oneSol9(L,S,Ri),R).


