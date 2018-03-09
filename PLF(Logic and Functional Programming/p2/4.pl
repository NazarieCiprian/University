
append2([],E,[E]).
append2([H|T],E,[H|TR]):-
    append2(T,E,TR).

reverse1([],[]).
reverse1([H|T],R):-
  reverse1(T,R1),
  append2(R1,H,R).
suma([],[],0,[]).
suma([],[],1,[1]).
suma(L1,[],0,L1).
suma([],L2,0,L2).
suma([H1|T1],[H2|T2],C,[HR|TR]):-
    HR is (H1+H2+C) mod 10,
    C1 is (H1+H2+C) div 10,
    suma(T1,T2,C1,TR).
suma([H1|T1],[],C,[HR|TR]):-
    HR is (H1+C) mod 10,
    C1 is (H1+C) div 10,
    suma(T1,[],C1,TR).
suma([],[H2|T2],C,[HR|TR]):-
    HR is (H2+C) mod 10,
    C1 is (H2+C) div 10,
    suma([],T2,C1,TR).


dosuma(L1,L2,R):-
    reverse1(L1,R1),
    reverse1(L2,R2),
    suma(R1,R2,0,R3),
    reverse1(R3,R).

addList([],C,C).
addList([H|T],C,R):-
    number(H),
    addList(T,C,R).
addList([H|T],C,R):-
    is_list(H),
    dosuma(H,C,C1),
    addList(T,C1,R).


