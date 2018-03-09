counte([],_,0).
counte([H|T],E,C):-
   H=:=E,
   counte(T,H,C1),
   C is C1 +1.
counte([H|T],E,C):-
    H=\=E,
    counte(T,E,C).

isSet([],_).
isSet([H|T],CL):-
    counte(CL,H,N),
    N=:=1,
    isSet(T,CL).
isSet([H|_],CL):-
    not(counte(CL,H,1)).

removeThree([],_,_,[]).
removeThree([H|T],E,N,[H|TR]):-
    H=\=E,
    removeThree(T,E,N,TR).
removeThree([H|T],E,N,[H|TR]):-
    H=:=E,
    N=:=0,
    removeThree(T,E,N,TR).
removeThree([H|T],E,N,R):-
    H=:=E,
    N=\=0,
    N1 is N-1,
    removeThree(T,E,N1,R).


