isPos(P):-P=:=1.
isPos(P):-P=:=3.
isPos(P):-P=:=7.
isPos(P):-P=:=15.

insertPos([],_,_,[]).
insertPos([H|T],E,P,[H,E|TR]):-
    isPos(P),
    P1 is P+1,
    insertPos(T,E,P1,TR).

insertPos([H|T],E,P,[H|TR]):-
    not(isPos(P)),
    P1 is P+1,
    insertPos(T,E,P1,TR).

subst4([],_,[]).
subst4([H|T],E,[H|TR]):-
    number(H),
    subst4(T,E,TR).

subst4([H|T],E,[R|TR]):-
    is_list(H),
    insertPos(H,E,1,R),
    subst4(T,E,TR).
