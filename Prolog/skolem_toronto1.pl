person(X) :- man(X).

mother(X,m(X)) :- person(X).

loves(X,Y) :- mother(Y,X).

man(plato).

momname(X,Y) :-
    X = m(plato), Y = tulsi
    ;
    false.
