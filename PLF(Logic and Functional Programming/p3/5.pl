diff([_],_).
diff([H1,H2|T],M):-
    abs(H1-H2)>=M,
    diff([H2|T],M).

subset4([],[]).
subset4([_|T],R):-
    subset4(T,R).
subset4([H|T],[H|TR]):-
    subset4(T,TR).

oneSol2(L,M,R):-
    subset4(L,R1),
    diff(R1,M),
    R = R1.
allSol2(L,M,R):-
    findall(Ri,oneSol2(L,M,Ri),R).
