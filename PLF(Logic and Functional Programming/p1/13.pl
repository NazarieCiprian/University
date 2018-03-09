member4([E|_],E).
member4([_|T],E):-
    member4(T,E).

append4([],E,[E]).
append4([H|T],E,[H|TR]):-
    append4(T,E,TR).

toSet([],[]).
toSet([H|T],R):-
    member4(T,H),
    toSet(T,R).
toSet([H|T],[H|TR]):-
    not(member4(T,H)),
    toSet(T,TR).
