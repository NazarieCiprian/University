minsert([],E,[E]).
minsert([H|T],E,[E,H|T]).
minsert([H|T],E,[H|TR]):-
    minsert(T,E,TR).

perm([],[]).
perm([H|T],R):-
    perm(T,RT),
    minsert(RT,H,R).

comb(_,0,[]).
comb([H|T],K,[H|TR]):-
    K>0,
    K1 is K-1,
    comb(T,K1,TR).

comb([_|T],K,R):-
    K>0,
    comb(T,K,R).

arr(L,K,R):-
    comb(L,K,R1),
    perm(R1,R).

oneSol4(L,K,R):-
    arr(L,K,R).

allSol4(L,K,R):-
    findall(Ri,oneSol4(L,K,Ri),R).
