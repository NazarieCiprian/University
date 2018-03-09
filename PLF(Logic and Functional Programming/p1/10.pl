valley_inc([_]).
valley_inc([H1,H2|T]):-
    H1<H2,
    valley_inc([H2|T]).
valley_dec([H1,H2|T]):-
    H1<H2,
    valley_inc([H2|T]).
valley_dec([H1,H2|T]):-
    H1>H2,
    valley_dec([H2|T]).

valley([H1,H2|T]):-
    H1>H2,
    valley_dec([H2|T]).

alternateSum([],_,0).
alternateSum([H|T],P,S):-
    P mod 2 =:= 0,
    P1 is P+1,
    alternateSum(T,P1,S1),
    S is S1+H.
alternateSum([H|T],P,S):-
    P mod 2 =\=0,
    P1 is P+1,
    alternateSum(T,P1,S1),
    S is S1-H.
