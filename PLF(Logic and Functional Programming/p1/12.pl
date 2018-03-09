append([],L,L).
append([H|T],L,[H|TR]):-
    append(T,L,TR).

substl([],_,_,[]):-!.
substl([H|T],E,L,R):-
    H=:=E,!,
    substl(T,E,L,R1),
    append(L,R1,R).
substl([H|T],E,L,[H|TR]):-
    substl(T,E,L,TR).


removeN([],_,_,[]).
removeN([_|T],N,P,R):-
    P=:=N,
    P1 is P+1,
    removeN(T,N,P1,R).
removeN([H|T],N,P,[H|TR]):-
    P=\=N,
    P1 is P+1,
    removeN(T,N,P1,TR).
