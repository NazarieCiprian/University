len([],0).
len([_|T],R):-
    len(T,R1),
    R is R1+1.

largest(L1,L2,L1):-
    len(L1,R1),
    len(L2,R2),
    R1>=R2.
largest(L1,L2,L2):-
    len(L1,R1),
    len(L2,R2),
    R1<R2.

append([],E,[E]).
append([H|T],E,[H|TR]):-
    append(T,E,TR).

maxSeq([],[],[]).
maxSeq([H|T],C,R):-
    A is H mod 2,
    A=:=0,
    maxSeq(T,C1,R1),
    append(C1,H,C),
    largest(C,R1,R).

maxSeq([H|T],C,R):-
    A is H mod 2,
    A=\=0,
    maxSeq(T,_,R1),
    C=[],
    largest(R1,C,R).


