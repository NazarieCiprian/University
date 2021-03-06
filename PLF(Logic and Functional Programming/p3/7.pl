minsert1([],E,[E]).
minsert1([H|T],E,[H,E|T]).
minsert1([H|T],E,[H|TR]):-
    minsert1(T,E,TR).

perm1([],[]).
perm1([H|T],R):-
    perm1(T,R1),
    minsert1(R1,H,R).

comb1(_,0,[]).
comb1([H|T],K,[H|TR]):-
    K>0,
    K1 is K-1,
    comb1(T,K1,TR).
comb1([_|T],K,R):-
    K>0,
    comb1(T,K,R).

arr1(L,K,R):-
    comb1(L,K,R1),
    perm1(R1,R).

oneSol5(L,K,R):-
    arr1(L,K,R).

allSol5(L,K,R):-
    findall(Ri,oneSol5(L,K,Ri),R).


