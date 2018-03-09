member([H|_],H).
member([_|T],E):-
  member(T,E).

append1([],E,[E]).
append1([H|T],E,[H|TR]):-
    append1(T,E,TR).
toSet([],C,C).
toSet([H|T],C,R):-
    not(member(C,H)),
    append1(C,H,C1),
    toSet(T,C1,R).
toSet([H|T],C,R):-
    member(C,H),
    toSet(T,C,R).

merge([],[],[]).
merge(L,[],L).
merge([],L,L).
merge([H1|T1],[H2|T2],[H2|TR]):-
    H1>H2,
    merge([H1|T1],T2,TR).
merge([H1|T1],[H2|T2],[H1|TR]):-
    H1<H2,
    merge(T1,[H2|T2],TR).
merge([H1|T1],[H2|T2],[H2|TR]):-
    H1=:=H2,
    merge(T1,T2,TR).

mergea(L1,L2,R):-
    toSet(L1,[],L11),
    toSet(L2,[],L22),
    merge(L11,L22,R).

merges([],[]).
merges([H|T],[H|TR]):-
    number(H),
    merges(T,TR).
merges([H|T],R):-
    is_list(H),
    mergea(R,H,R1),
    merges(T,R1).


