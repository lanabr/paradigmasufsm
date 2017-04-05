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
