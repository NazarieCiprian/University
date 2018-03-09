append5([],E,[E]).
append5([H|T],E,[H|TR]):-
    append5(T,E,TR).
reverse2([],[]).
reverse2([H|T],R):-
    reverse2(T,R1),
    append5(R1,H,R).

product(_,0,0,[]).
product([],_,0,[]).
product([],_,1,[]).
product(_,0,1,[1]).
product([H|T],E,C,[HR|TR]):-
    HR is (H*E+C) mod 10,
    C1 is (H*E+C) div 10,
    product(T,E,C1,TR).

doproduct(L,E,R):-
    reverse2(L,L1),
    product(L1,E,0,R1),
    reverse2(R1,R).

maxi(A,B,A):-A>=B.
maxi(A,B,B):-A<B.
maximList([E],E).
maximList([H|T],M):-
    maximList(T,M1),
    maxi(M1,H,M).

maxl([],_,_,[]).
maxl([H|T],E,P,[P|TR]):-
    H=:=E,
    P1 is P+1,
    maxl(T,E,P1,TR).
maxl([H|T],E,P,R):-
    H=\=E,
    P1 is P +1,
    maxl(T,E,P1,R).

getl([],[]).
getl(L,R):-
   maximList(L,M),
   maxl(L,M,1,R).
subst([],[]).
subst([H|T],[H|TR]):-
    number(H),
    subst(T,TR).
subst([H|T],[R1|TR]):-
    is_list(H),
    getl(H,R1),
    subst(T,TR).
