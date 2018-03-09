member5([H|_],H).
member5([_|T],E):-
    member5(T,E).
append5([],E,[E]).
append5([H|T],E,[H|TR]):-
    append5(T,E,TR).

toSet1([],C,C).
toSet1([H|T],C,R):-
    member5(C,H),
    toSet1(T,C,R).
toSet1([H|T],C,R):-
    not(member5(C,H)),
    append5(C,H,C1),
    toSet1(T,C1,R).

append6([],L,L).
append6([H|T],L,[H|TR]):-
    append6(T,L,TR).

listOddEven([],[],[],0,0).
listOddEven([H|T],[H|TR],O,NE,NO):-
    A is H mod 2,
    A=:=0,
    listOddEven(T,TR,O,NE1,NO),
    NE is NE1+1.
listOddEven([H|T],E,[H|TR],NE,NO):-
    A is H mod 2,
    A=\=0,
    listOddEven(T,E,TR,NE,NO1),
    NO is NO1 +1.

createList([],[]).
createList(L,R):-
    listOddEven(L,E,O,NE,NO),
    append6(E,O,R1),
    append5(R1,NE,R2),
    append5(R2,NO,R).


