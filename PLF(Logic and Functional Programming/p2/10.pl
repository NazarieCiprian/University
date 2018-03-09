prime(1,_):-fail.
prime(E,D):-
    D > E div 2.
prime(E,D):-
    A is E mod D,
    A =\=0,
    D1 is D+1,
    prime(E,D1).


twice([],[]).
twice([H|T],[H,H|TR]):-
    prime(H,2),
    twice(T,TR).
twice([H|T],[H|TR]):-
    not(prime(H,2)),
    twice(T,TR).

subst5([],[]).
subst5([H|T],[H|TR]):-
    number(H),
    subst5(T,TR).
subst5([H|T],[R|TR]):-
    is_list(H),
    twice(H,R),
    subst5(T,TR).
