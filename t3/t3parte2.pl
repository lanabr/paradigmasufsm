%1. Defina um predicado somaQuad(X,Y,Q) que seja verdadeiro se Q for a soma dos quadrados de X e Y.

somaQuad(X,Y,Q) :- Q is X*X + Y*Y.

%2. Defina um predicado zeroInit(L) que é verdadeiro se L for uma lista que inicia com o número 0 (zero).

zeroInit(L) :- L = [H|_],
               H = 0.

%3. Defina um predicado hasEqHeads(L1,L2) que seja verdadeiro se as listas L1 e L2 possuírem o mesmo primeiro elemento.

hasEqHeads(L1,L2) :- L1 = [H|_],
                     L2 = [C|_],
                     C = H.
                     
%4. Defina um predicado has5(L) que seja verdadeiro se L for uma lista de 5 elementos. Lembre de como funciona a unificação em Prolog e resolva este exercício sem usar o predicado pré-definido length.

has5(L) :- L = [_, _, _, _, _].

%5. Defina um predicado hasN(L,N) que seja verdadeiro se L for uma lista de N elementos. Agora você pode usar um predicado pré-definido.

hasN(L,N) :- length(L, M),
             M = N.

%6. Defina um predicado isBin(L) que seja verdadeiro se L for uma lista contendo somente elementos 0 e 1. Use recursão.

isBin([]).
isBin(L) :- L = [H|T],
            isBin(T),
            member(H, [0, 1]).

%7. Defina um predicado mesmaPosicao(A,L1,L2) para verificar se umelemento A está na mesma posição nas listas L1 e L2. Assuma que L1 e L2 sejam permutações de uma lista de elementos distintos, sem repetições. Dica: procure auxílio em predicados pré-definidos.

mesmaPosicao(X, [X|_], [X|_]).
mesmaPosicao(X, [_|U], [_|V]) :- mesmaPosicao(X, U, V).

%8. Defina um predicado repete5(E,L) que seja verdadeiro se a lista L for composta por exatamente 5 repetições do elemento E. Não use recursão.

repete5(E, L) :- L = [E, E, E, E, E].

%9. Defina um predicado recursivo sumQuads(L,S) que seja verdadeiro se S for o somatório dos quadrados dos elementos da lista L.

sumQuads([], 0).
sumQuads(L, S) :- L = [H|T],
                 sumQuads(T, S1),
                 S is H**2 + S1.

%10. Defina um predicado recursivo repete(N,E,L) que seja verdadeiro se a lista L for composta por exatamente N repetições do elemento E.

repete(0, _, []).
repete(N, E, L) :- L = [H|T],
                   length(L, X),
                   N = X,
                   M is N - 1,
                   repete(M, E, T),
                   E = H.

%11. Defina um predicado recursivo mapop(L1,L2) que seja verdadeiro se a lista L2 for formada aplicando-se a operação 2*x+1 a cada elemento x da lista L1.

mapop([], []).
mapop(L1, L2) :- L1 = [H1|T1],
                 L2 = [H2|T2],
                 mapop(T1, T2),
                 H2 is H1 * 2 + 1.

%12. Defina um predicado positivos(L1,L2), de forma que L2 seja uma lista só com os elementos positivos de L1.

positivos([ ], [ ]).
positivos([X|Y], [X|Z]) :- X > 0,
                           positivos(Y,Z).
positivos([X|Y], Z) :- X < 0,
                       positivos(Y,Z).
positivos([X|Y], Z) :- X = 0, 
                       positivos(Y,Z).
