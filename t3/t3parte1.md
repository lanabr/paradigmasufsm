Exercício 1. Considere a seguinte base de fatos e regras:
```prolog
pai(roberto,joao).
pai(joao, jose).
pai(roberto,julio).
pai(julio,marcos).
pai(julio,mario).
avo(X,Z) :- pai(X,Y), pai(Y,Z).
```
Mostre o trace comentado das consultas:
```
?- avo(joao,Y).
false.
?- avo(roberto,Y).
Y = jose ;
Y = marcos ;
Y = mario.
```
Trace comentado:
```
?- trace.                                      %Ativando o trace  
true.                                          %Certo!  

[trace]  ?- avo(joao, Y).                      %Chama o predicado avo
   Call: (8) avo(joao, _980) ? creep           %Atribui Y a uma variável única (joao tem avô?)
   Call: (9) pai(joao, _1198) ? creep          %Primeira regra (joao tem pai?)  
   Exit: (9) pai(joao, jose) ? creep           %Retorna com sucesso (o pai de joao é jose)  
   Call: (9) pai(jose, _980) ? creep           %Segunda regra (jose tem pai?)  
   Fail: (9) pai(jose, _980) ? creep           %Falha ao tentar encontrar e retorna (jose não tem pai)  
   Fail: (8) avo(joao, _980) ? creep           %Retorna o fail (como jose não tem pai, joao não tem avo)  
false.                                         %Retorno falso  
  
[trace]  ?- avo(roberto, Y).                   %Chama o predicado avo  
   Call: (8) avo(roberto, _980) ? creep        %Atribui Y a uma variável única (roberto tem avô?)  
   Call: (9) pai(roberto, _1198) ? creep       %Preira regra (roberto tem pai?)  
   Exit: (9) pai(roberto, joao) ? creep        %Retorna com sucesso (o pai de roberto é joao)  
   Call: (9) pai(joao, _980) ? creep           %Segunda regra (joao tem pai?)  
   Exit: (9) pai(joao, jose) ? creep           %Retorna com sucesso (o pai de joao é jose)  
   Exit: (8) avo(roberto, jose) ? creep        %Retorna com sucesso (o avo de roberto é jose)  
Y = jose ;                                     %Retorno verdadeiro do valor Y pedido e o sinal ; pede outra resposta  
   Redo: (9) pai(roberto, _1198) ? creep       %Procura nova resposta para a primeira regra (roberto tem outro pai?)  
   Exit: (9) pai(roberto, julio) ? creep       %Retorna com sucesso (o pai de roberto é julio)  
   Call: (9) pai(julio, _980) ? creep          %Segunda regra (julio tem pai?)  
   Exit: (9) pai(julio, marcos) ? creep        %Retorna com sucesso (o pai de julio é marcos)  
   Exit: (8) avo(roberto, marcos) ? creep      %Retorna com sucesso (o avo de roberto é marcos)  
Y = marcos ;                                   %Retorno verdadeiro do valor Y pedido e o sinal ; pede outra resposta     
   Redo: (9) pai(julio, _980) ? creep          %Procura nova resposta para a segunda regra (julio tem outro pai?)  
   Exit: (9) pai(julio, mario) ? creep         %Retorna com sucesso (o pai de julio é mario)  
   Exit: (8) avo(roberto, mario) ? creep       %Retorna com sucesso (o avo de roberto é mario)  
Y = mario.                                     %Retorno verdadeiro do valor Y pedido  
```
Exercício 2. Considere o predicado definido abaixo, que resolve um problema de uma [prova da Olimpíada Brasileira de Informática](http://olimpiada.ic.unicamp.br/passadas/pdf/provas/ProvaOBI2006_inic_f1n1.pdf).
```prolog
azulejos(0,0).
azulejos(Na,Nq) :-
   Na > 0,
   Q is floor(sqrt(Na)),
   R is Na - Q*Q,
   azulejos(R,C),
   Nq is 1 + C.
```
Mostre o trace comentado desta consulta:
```
?- azulejos(120,A).
```
Trace comentado:
```
?- trace.                                          %Chama o trace
true.                                              %Certo!

[trace]  ?- azulejos(120,A).                       %Chama o predicado azulejos
   Call: (8) azulejos(120, _980) ? creep           %Aplica A a uma variável unica
   Call: (9) 120>0 ? creep                         %Primeira regra (120 é maior do que 0?)
   Exit: (9) 120>0 ? creep                         %Retorna com sucesso (120 é maior do que 0)
   Call: (9) _1206 is floor(sqrt(120)) ? creep     %Uma nova variável é igual ao maior inteiro não maior que a raíz de 120 (raíz de 120 é igual a 10.95)
   Exit: (9) 10 is floor(sqrt(120)) ? creep        %Retorna com sucesso o valor da operação (maior número inteiro menor ou igual do que 10.95)
   Call: (9) _1218 is 120-10*10 ? creep            %Uma nova variável é igual a operação (o quadrado do resultado do predicado floor menos 120 (azulejos iniciais)) 
   Exit: (9) 20 is 120-10*10 ? creep               %Retorna com sucesso o resultado da operação anterior (o total de azulejos restantes é 20)
   Call: (9) azulejos(20, _1220) ? creep           %Chama novamente o predicado azulejos (recursividade)
   Call: (10) 20>0 ? creep                         %Primeira regra (20 é maior do que 0?)
   Exit: (10) 20>0 ? creep                         %Retorna com sucesso (20 é maior do que 0)
   Call: (10) _1226 is floor(sqrt(20)) ? creep     %Uma nova variável é igual ao maior inteiro não maior que a raíz de 20 (raíz de 20 é igual a 4.47)
   Exit: (10) 4 is floor(sqrt(20)) ? creep         %Retorna com sucesso o valor da operação (maior número inteiro menor ou igual do que 4.47)
   Call: (10) _1238 is 20-4*4 ? creep              %Uma nova variável é igual a operação (o quadrado do resultado do predicado floor menos 20 (azulejos depois da 1ª recursão))
   Exit: (10) 4 is 20-4*4 ? creep                  %Retorna com sucesso o resultado da operação anterior (o total de azulejos restantes é 4)
   Call: (10) azulejos(4, _1240) ? creep           %Chama novamente o predicado azulejos (recursividade)
   Call: (11) 4>0 ? creep                          %Primeira regra (4 é maior do que 0?)
   Exit: (11) 4>0 ? creep                          %Retorna com sucesso (4 é maior do que 0)
   Call: (11) _1246 is floor(sqrt(4)) ? creep      %Uma nova variável é igual ao maior inteiro não maior que a raíz de 4 (raíz de 4 é igual a 2)
   Exit: (11) 2 is floor(sqrt(4)) ? creep          %Retorna com sucesso o valor da operação (maior número inteiro menor ou igual do que 2)
   Call: (11) _1258 is 4-2*2 ? creep               %Uma nova variável é igual a operação (o quadrado do resultado do predicado floor menos 4 (azulejos depois da 2ª recursão))
   Exit: (11) 0 is 4-2*2 ? creep                   %Retorna com sucesso o resultado da operação anterior (o total de azulejos restantes é 0)
   Call: (11) azulejos(0, _1260) ? creep           %Chama novamente o predicado azulejos (recursividade)
   Exit: (11) azulejos(0, 0) ? creep               %Retorna que 0 é igual a 0 (condição de parada)
   Call: (11) _1264 is 1+0 ? creep                 %Começa a segunda parte do predicado, calculando o número de quadrados (atribui a uma variável o valor retornado mais um)
   Exit: (11) 1 is 1+0 ? creep                     %Retorna com sucesso o valor da soma (número total de quadrados é igual a 1)
   Exit: (10) azulejos(4, 1) ? creep               %Retorno da 2ª recursão com o número de quadrados 
   Call: (10) _1270 is 1+1 ? creep                 %Calcula o número de quadrados (atribui a uma variável o valor retornado mais um)
   Exit: (10) 2 is 1+1 ? creep                     %Retorna com sucesso o valor da soma (número total de quadrados é igual a 2)
   Exit: (9) azulejos(20, 2) ? creep               %Retorno da 1ª recursão com o número de quadrados 
   Call: (9) _980 is 1+2 ? creep                   %Calcula o número de quadrados (atribui a uma variável o valor retornado mais um)
   Exit: (9) 3 is 1+2 ? creep                      %Retorna com sucesso o valor da soma (número total de quadrados é igual a 3)
   Exit: (8) azulejos(120, 3) ? creep              %Retorno da chamada inicial com o número de quadrados
A = 3 .                                            %Retorno com sucesso do valor Nq pedido
```

Exercício 3. Escolha algum predicado recursivo que esteja nos slides ou em qualquer outra fonte. Faça a execução passo-a-passo de uma consulta com o predicado escolhido. Lembre-se de mostrar o código do predicado no seu arquivo t3parte1.md.

Função recursiva escolhida faz a soma dos termos da lista:
```prolog
sum([],0). 
sum([H|T], S) :- sum(T, S1),   
                 S is H + S1.
```
Trace comentado:
```
?- trace.                                               %Chama o trace
true.                                                   %Certo!

[trace]  ?- sum([3, 5, 6, 2, 9, 4], S).                 %Chama o predicado sum
   Call: (8) sum([3, 5, 6, 2, 9, 4], _2318) ? creep     %Atribui S a uma variável única 
   Call: (9) sum([5, 6, 2, 9, 4], _2578) ? creep        %Primeira recursão separando [H|T] e atribui outra variável 
   Call: (10) sum([6, 2, 9, 4], _2578) ? creep          %Segunda recursão separando [H|T]
   Call: (11) sum([2, 9, 4], _2578) ? creep             %Terceira recursão separando [H|T]
   Call: (12) sum([9, 4], _2578) ? creep                %Quarta recursão separando [H|T]
   Call: (13) sum([4], _2578) ? creep                   %Quinta recursão separando [H|T]
   Call: (14) sum([], _2578) ? creep                    %Sexta recursão separando [H|T]
   Exit: (14) sum([], 0) ? creep                        %Retorna pela condição de parada com soma igual a 0
   Call: (14) _2582 is 4+0 ? creep                      %Faz a soma (4 (valor de H) + 0 (valor retornado da sexta recursão))
   Exit: (14) 4 is 4+0 ? creep                          %Retorna a soma na variável 
   Exit: (13) sum([4], 4) ? creep                       %Retorno da função com a soma
   Call: (13) _2588 is 9+4 ? creep                      %Faz a soma (9 (valor de H) + 4 (valor retornado da quinta recursão))
   Exit: (13) 13 is 9+4 ? creep                         %Retorna a soma na variável 
   Exit: (12) sum([9, 4], 13) ? creep                   %Retorno da função com a soma
   Call: (12) _2594 is 2+13 ? creep                     %Faz a soma (2 (valor de H) + 13 (valor retornado da quarta recursão))
   Exit: (12) 15 is 2+13 ? creep                        %Retorna a soma na variável 
   Exit: (11) sum([2, 9, 4], 15) ? creep                %Retorno da função com a soma
   Call: (11) _2600 is 6+15 ? creep                     %Faz a soma (6 (valor de H) + 15 (valor retornado da terceira recursão))
   Exit: (11) 21 is 6+15 ? creep                        %Retorna a soma na variável 
   Exit: (10) sum([6, 2, 9, 4], 21) ? creep             %Retorno da função com a soma
   Call: (10) _2606 is 5+21 ? creep                     %Faz a soma (5 (valor de H) + 21 (valor retornado da segunda recursão))
   Exit: (10) 26 is 5+21 ? creep                        %Retorna a soma na variável 
   Exit: (9) sum([5, 6, 2, 9, 4], 26) ? creep           %Retorno da função com a soma
   Call: (9) _2318 is 3+26 ? creep                      %Faz a soma (3 (valor de H) + 26 (valor retornado da primeira recursão))
   Exit: (9) 29 is 3+26 ? creep                         %Retorna a soma na variável 
   Exit: (8) sum([3, 5, 6, 2, 9, 4], 29) ? creep        %Retorno da função com a soma
S = 29                                                  %Retorno com sucesso do valor S pedido na chamada
