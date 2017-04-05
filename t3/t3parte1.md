1. Considere a seguinte base de fatos e regras:
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
