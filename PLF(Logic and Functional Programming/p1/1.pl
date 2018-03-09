cmmdc(A,0,A).
cmmdc(A,B,R):-
    B1 is A mod B,
    cmmdc(B,B1,R).

cmmdcList([E],E).
cmmdcList([H|T],R):-
    cmmdcList(T,R1),
    cmmdc(H,R1,R).

cmmcList([E],E).
cmmcList([H|T],R):-
    cmmcList(T,R1),
    cmmdc(H,R1,D),
    R is H*R1 div D.

isPower(1,_).
isPower(E,D):-
    E1 is E div D,
    A is E mod D,
    A=:=0,
    isPower(E1,D).

insertPos([],_,_,[]).
insertPos([H|T],E,P,[H,E|TR]):-
    isPower(P,2),
    P1 is P +1,
    insertPos(T,E,P1,TR).
insertPos([H|T],E,P,[H|TR]):-
    not(isPower(P,2)),
    P1 is P+1,
    insertPos(T,E,P1,TR).
