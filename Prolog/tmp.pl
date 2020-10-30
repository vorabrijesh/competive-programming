f(1,one).
f(s(1),two).
f(s(s(1)),three).
f(s(s(s(X))),N) :-
    f(X,N).



L = [a,b,c].

member1(X,[X|Tail]).
member1(X,[Head|Tail]) :-
    member1(X,Tail).

conc1([],L,L).

conc1([X|L1],L2,[X|L3]) :-
    conc1(L1,L2,L3).

member2(X,L) :-
    conc1(_,[X|L2],L).

add1(X,L,[X|L]).

del1(X,[X|Tail],Tail).
del1(X,[Y|Tail],[Y|Tail1]) :-
    del1(X,Tail,Tail1).

len1([],0).
len1([_|Tail],N) :-
    len1(Tail,N1),
    N is N1 + 1.






