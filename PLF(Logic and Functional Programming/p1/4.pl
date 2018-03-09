member([H|_],H).
member([_|T],E):-
    member(T,E).
difference([],_,[]).
difference([H1|T1],L2,[H1|TR]):-
    not(member(L2,H1)),
    difference(T1,L2,TR).
difference([H1|T1],L2,R):-
    member(L2,H1),
    difference(T1,L2,R).

addOne([],[]).
addOne([H|T],[H,1|TR]):-
    addOne(T,TR).
