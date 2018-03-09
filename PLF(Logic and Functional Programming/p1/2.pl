removeOc([],_,[]):-!.
removeOc([H|T],E,R):-
    H=:=E,!,
    removeOc(T,E,R).
removeOc([H|T],E,[H|TR]):-
    removeOc(T,E,TR).

nrOc([],_,C,C).
nrOc([H|T],E,C,R):-
    H=:=E,
    C1 is C+1,
    nrOc(T,E,C1,R).
nrOc([H|T],E,C,R):-
    H=\=E,
    nrOc(T,E,C,R).

createSub([],[]).
createSub([H|T],[[H,R]|TR]):-
    nrOc([H|T],H,0,R),
    removeOc([H|T],H,L1),
    createSub(L1,TR).

