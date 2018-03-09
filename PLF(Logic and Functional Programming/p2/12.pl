divs(E,E,[]).
divs(E,D,[D|T]):-
    A is E mod D,
    A=:=0,
    D1 is D +1,
    divs(E,D1,T).
divs(E,D,R):-
    A is E mod D,
    A=\=0,
    D1 is D + 1,
    divs(E,D1,R).

append5([],L,L).
append5([H|T],L,[H|TR]):-
    append5(T,L,TR).


addDivs([],[]).
addDivs([H|T],R):-
    divs(H,2,R1),
    addDivs(T,R2),
    append5(R1,R2,R3),
    R=[H|R3].

subst7([],[]).
subst7([H|T],[H|TR]):-
    number(H),
    subst7(T,TR).

subst7([H|T],[R|TR]):-
    is_list(H),
    addDivs(H,R),
    subst7(T,TR).
