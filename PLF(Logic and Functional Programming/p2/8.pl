append6([],E,[E]).
append6([H|T],E,[H|TR]):-
    append6(T,E,TR).

reverse4([],[]).
reverse4([H|T],R):-
    reverse4(T,R1),
    append6(R1,H,R).

increment([],1,[1]).
increment([],0,[]).
increment([H|T],C,[HR|TR]):-
    HR is (H+C) mod 10,
    C1 is (H+C) div 10,
    increment(T,C1,TR).

doinc(L,R):-
   increment(L,1,R).

subst2([],[]).
subst2([H|T],[H|TR]):-
    number(H),
    subst2(T,TR).

subst2([H|T],[R2|TR]):-
    is_list(H),
    reverse4(H,R),
    doinc(R,R1),
    reverse4(R1,R2),
    subst2(T,TR).
