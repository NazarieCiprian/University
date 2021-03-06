ascend([_(]).
ascend([H1,H2|T]):-
    H1<H2,
    ascend([H2|T]).

subset3([],[]).
subset3([_|T],R):-
    subset3(T,R).
subset3([H|T],[H|TR]):-
    subset3(T,TR).


oneSol1(L,R):-
    subset3(L,R1),
    ascend(R1),
    R = R1.
allSol1(L,R):-
    findall(Ri,oneSol1(L,Ri),R).
