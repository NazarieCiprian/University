replaceE([],_,_,[]).
replaceE([H|T],E,O,[H|TR]):-
    H=\=E,
    replaceE(T,E,O,TR).
replaceE([H|T],E,O,[O|TR]):-
    H=:=E,
    replaceE(T,E,O,TR).

createSubList([],_,_,_,[]).
createSubList([H|T],E,O,P,[H|TR]):-
    P>=E,
    P=<O,
    P1 is P+1,
    createSubList(T,E,O,P1,TR).
createSubList([_|T],E,O,P,R):-
    P<E,
    P1 is P+1,
    createSubList(T,E,O,P1,R).

createSubList([_|T],E,O,P,R):-
    P>O,
    P1 is P+1,
    createSubList(T,E,O,P1,R).
