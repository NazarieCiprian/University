evenOdd([],1).
evenOdd([_|T],C):-
    evenOdd(T,C1),
    C is C1*(-1).
nrEl(L):-
    evenOdd(L,1),
    write('Even').
nrEl(L):-
    evenOdd(L,-1),
    write('Odd').

mini(A,B,A):-A<B.
mini(A,B,B):-A>=B.
minimList([E],E).
minimList([H|T],M):-
    minimList(T,M1),
    mini(H,M1,M).

removeFirst([],_,_,[]).
removeFirst([H|T],E,P,R):-
    H=:=E,
    P=:=1,
    P1 is P-1,
    removeFirst(T,E,P1,R).
removeFirst([H|T],E,P,[H|TR]):-
    H=:=E,
    P=\=1,
    removeFirst(T,E,P,TR).
removeFirst([H|T],E,P,[H|TR]):-
    H=\=E,
    removeFirst(T,E,P,TR).
