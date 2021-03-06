
invalid(state(M,L,G,C)) :- L==G,M=:=(1-L);G==C,M=:=(1-G).
move(state(M,L,G,C),
     shiftL,
     state(1-M,1-L,G,C)).
move(state(M,L,G,C),
     shiftG,
     state(1-M,L,1-G,C)).
move(state(M,L,G,C),
     shiftC,
     state(1-M,L,G,1-C)).
move(state(M,L,G,C),
     shiftNone,
     state(1-M,L,G,C)).

sum(X,Y) :-
       S is X+Y,
       write(S).

flip(X) :- S is 1-X, write(S).

sL(state(M,L,G,C)) :- state(flip(M),flip(L),G,C).

sL2(state(M,L,G,C),state(M2,L2,G2,C2)) :- M2 is 1-M, L2 is 1-L, G2 is G, C2 is C.

same2( state(M,L,G,C), state(M2,L2,G2,C2) ) :- M=:=M2, L=:=L2,G=:=G2,C=:=C2.
same3(state(M,L,G,C),state(M,L,G,C)).
same4(A,A).
canget(state(1,1,1,1)).
canget(State1) :-
       move(State1,Move,State2),not(invalid(State2)),
       canget(State2).





