append([],E,[E]).
append([H|T],E,[H|TR]):-
    append(T,E,TR).

reverse([],[]).
reverse([H|T],R):-
    reverse(T,R1),
    append(R1,H,R).

decrement([],0,[]).
decrement([H|T],C,[HR|TR]):-
    H<C,
    HR is (H+10-C) mod 10,
    C1 is 1,
    decrement(T,C1,TR).
decrement([H|T],C,[HR|TR]):-
    H>=C,
    HR is H-C,
    C1 is 0,
    decrement(T,C1,TR).

dodec(L,R):-
    reverse(L,L1),
    decrement(L1,1,R1),
    reverse(R1,R).

subst([],[]).
subst([H|T],[H|TR]):-
    number(H),
    subst(T,TR).

subst([H|T],[R|TR]):-
    is_list(H),
    dodec(H,R),
    subst(T,TR).
