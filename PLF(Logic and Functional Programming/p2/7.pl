maxi1(A,B,A):-A>=B.
maxi1(A,B,B):-A<B.
maxList1([E],E).
maxList1([H|T],M):-
    maxList1(T,M1),
    maxi1(M1,H,M).

getPos([],_,_,[]).
getPos([H|T],E,P,[P|TR]):-
    H=:=E,
    P1 is P + 1,
    getPos(T,E,P1,TR).

getPos([H|T],E,P,R):-
    H=\=E,
    P1 is P+1,
    getPos(T,E,P1,R).

maxPos1([],[]).
maxPos1(L,R):-
    maxList1(L,M),
    getPos(L,M,1,R).


subst1([],[]).
subst1([H|T],[H|TR]):-
    number(H),
    subst1(T,TR).

subst1([H|T],[R1|TR]):-
    is_list(H),
    maxPos1(H,R1),
    subst1(T,TR).

