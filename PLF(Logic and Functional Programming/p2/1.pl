mini(A,B,A):-A<B.
mini(A,B,B):-A>=B.
minList([E],E).
minList([H|T],R):-
    minList(T,R1),
    mini(R1,H,R).

removeOne([],_,[]).
removeOne([H|T],E,[H|TR]):-
    H=\=E,
    removeOne(T,E,TR).
removeOne([H|T],E,R):-
    H=:=E,
    %P=\=1,
    removeOne(T,E,R).

sortare([],[]).
sortare(L,[M|TR]):-
    minList(L,M),
    removeOne(L,M,L1),
    sortare(L1,TR).

substi([],[]).
substi([H|T],[H|TR]):-
    number(H),
    substi(T,TR).
substi([H|T],[L1|TR]):-
    is_list(H),
    sortare(H,L1),
    substi(T,TR).
