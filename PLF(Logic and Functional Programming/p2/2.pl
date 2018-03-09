mini1(A,B,A):-A<B.
mini1(A,B,B):-A>=B.
minList1([E],E).
minList1([H|T],R):-
    minList1(T,R1),
    mini1(H,R1,R).

removeOne([],_,_,[]).
removeOne([H|T],E,P,R):-
    H=:=E,
    P=:=1,
    P1 is P-1,
    removeOne(T,E,P1,R).
removeOne([H|T],E,P,[H|TR]):-
    H=:=E,
    P=\=1,
    removeOne(T,E,P,TR).

removeOne([H|T],E,P,[H|TR]):-
    H=\=E,
    removeOne(T,E,P,TR).


sortare1([],[]).
sortare1(L,[M|T]):-
    minList1(L,M),
    removeOne(L,M,1,L1),
    sortare1(L1,T).

substi1([],[]).
substi1([H|T],[H|TR]):-
    number(H),
    substi1(T,TR).
substi1([H|T],[H1|TR]):-
    is_list(H),
    sortare1(H,H1),
    substi1(T,TR).
