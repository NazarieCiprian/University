removeSeq([],_,[]).

removeSeq([_],1,[]).
removeSeq([E],0,[E]).
removeSeq([H1,H2|T],_,R):-
    H1=:=H2-1,
    F1 is 1,
    removeSeq([H2|T],F1,R).
removeSeq([H1,H2|T],F,R):-
    H1=\=H2-1,
    F =:= 1,
    F1 is 0,
    removeSeq([H2|T],F1,R).
removeSeq([H1,H2|T],F,[H1|TR]):-
    H1=\=H2-1,
    F =:=0,
    removeSeq([H2|T],F,TR).
