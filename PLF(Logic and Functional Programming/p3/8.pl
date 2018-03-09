createList(N,R):-
    findall(Nr,between(1,N,Nr),R).

minsert3([],E,[E]).
minsert3([H|T],E,[H,E|T]).
minsert3([H|T],E,[H|TR]):-
    minsert3(T,E,TR).

perm([],[]).
perm([H|T],R):-
    perm(T,R1),
    minsert3(R1,H,R).

consecutive(
