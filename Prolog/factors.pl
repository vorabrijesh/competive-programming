factors(1,[1]) :- true, !.
factors(X,[Factor1|Tail]) :- X > 0, 1 < X, X < Factor1, NewX is X, factors(NewX, Tail), !.
