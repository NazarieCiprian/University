append3([],L,L).
append3([H|T],L,[H|TR]):-
    append3(T,L,TR).


substl([],_,_,[]).
substl([H|T],E,L,[H|TR]):-
    H=\=E,
    substl(T,E,L,TR).
substl([H|T],E,L,R):-
    H=:=E,
    substl(T,E,L,R1),
    append3(L,R1,R).
