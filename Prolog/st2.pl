day(6).
day(7). %and so on...
day(18).

night(20).
night(21). %and so on...
night(18).

sun(H) :- day(H).
moon(H) :- night(H).
twilight(H) :- sun(H), moon(H).

not(P) :-
    P,!,fail
    ;
    true.

source(X,H) :- X = sun, sun(H),not(moon(H));X = moon, moon(H),not(sun(H)); X = both, twilight(H).

source2(X,H) :- X = sun, sun(H);X = moon, moon(H), not(sun(H)); X = both, twilight(H).

ontable(a).
green(a).

tab(X) :-
    X = a, ontable(a)
    ;
    X = b, ontable(b).

color(X) :-
    X = a, green(a)
    ;
    X = b, green(b).

other(X) :-
    X = a, ontable(a), green(a)
    ;
    X = b, ontable(b), green(b).


gcd(0, X, X):- X > 0, !.
gcd(X, Y, Z):- X >= Y, X1 is X-Y, gcd(X1,Y,Z).
gcd(X, Y, Z):- X < Y, X1 is Y-X, gcd(X1,X,Z).

coprime(X,Y) :- gcd(X,Y,Z), Z is 1.

factor(N,X) :- gcd(N,X,Z), Z = X.

mammals(cat).
mammals(dog).

spider(blackwidow).

myrule(X) :-
    mammals(X) -> not(spider(X)).

myrule2(X) :-
    \+((mammals(X),spider(X))).

p1(a).
p1(b).
q1(a).
q1(b).

fun(X,Y) :- p1(X),q1(X),Y=X,!,fail.

fun2(X) :- p1(X),q1(X).












