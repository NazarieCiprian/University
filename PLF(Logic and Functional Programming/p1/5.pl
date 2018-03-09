member1([H|_],H).
member1([_|T],E):-
    member1(T,E).

append1([],E,[E]).
append1([H|T],E,[H|TR]):-
    append1(T,E,TR).

union([],L2,L2).
union([H1|T1],L2,[H1|TR]):-
    not(member1(L2,H1)),
    union(T1,L2,TR).
union([H1|T1],L2,R):-
    member1(L2,H1),
    union(T1,L2,R).

nrEls([],0).
nrEls([_|T],R):-
    nrEls(T,R1),
    R is R1 +1.

subset([],[]).
subset([H|T],[H|TR]):-
    subset(T,TR).
subset([_|T],R):-
    subset(T,R).

oneSol(L,R):-
    subset(L,R),
    nrEls(R,2).
allSol(L,R):-
    findall(Ri,oneSol(L,Ri),R).

