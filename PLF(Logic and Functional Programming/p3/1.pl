len([],0).
len([_|T],R):-
    len(T,R1),
    R is R1 +1.

subset([],[]).
subset([_|T],R):-
    subset(T,R).
subset([H|T],[H|TR]):-
    subset(T,TR).

oneSolution(L,N,R):-
    subset(L,R1),
    len(R1,N),
    R = R1.
allSolutions(L,N,Rall):-
    findall(Ri,oneSolution(L,N,Ri),Rall).




