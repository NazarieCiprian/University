member2([H|_],H).
member2([_|T],E):-
    member2(T,E).
intersect([],_,[]).
intersect([H1|T1],L2,[H1|TR]):-
    member2(L2,H1),
    intersect(T1,L2,TR).
intersect([H1|T1],L2,R):-
    not(member2(L2,H1)),
    intersect(T1,L2,R).

append3([],E,[E]).
append3([H|T],E,[H|TR]):-
    append3(T,E,TR).
createList(_,N,P,C,C):-
    P>N.
createList(M,N,P,C,R):-
    P1 is P +1,
    append3(C,P,C1),
    createList(M,N,P1,C1,R).


