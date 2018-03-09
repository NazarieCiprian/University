insertnth([],_,_,_,[]).
insertnth([H|T],E,N,P,[E,H|TR]):-
    P=:=N,
    P1 is P+1,
    insertnth(T,E,N,P1,TR).
insertnth([H|T],E,N,P,[H|TR]):-
    P=\=N,
    P1 is P+1,
    insertnth(T,E,N,P1,TR).
