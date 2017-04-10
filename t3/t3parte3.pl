%Questões 2 e 3 da prova da OBI de 2014. Modalidade iniciação, Nível 1, Fase 2.

%Torneio de tênis:

%Está acontecendo nesta semana o Torneio Aberto de Tênis dos EUA, um dos mais prestigiosos torneios de
%tênis do mundo, no qual participam 128 tenistas. Em cada partida, participam dois jogadores, sendo que o
%vencedor passa para a próxima fase, e o perdedor é eliminado do torneio. A cada rodada, os tenistas que ainda
%continuam no torneio participam de exatamente uma partida.

%Código:

torneio(1, 0, 0).
torneio(J, P, R) :- J > 0,
                    Js is J / 2,
                    torneio(Js, Po, Ro),
                    R is Ro + 1,
                    P is Po + Js.

%Questões:

%Questão 2. Qual o número total da partidas do torneio?
(A) 63
(B) 64
(C) 65
(D) 127
(E) 128

%Questão 3. Quantas rodadas existem, no total, durante
o torneio?
(A) 6
(B) 7
(C) 8
(D) 12
(E) 16

%As respostas para as consultas correspondentes as questão de acordo com o código são:
%?- torneio(128, P, R).
%P = 127,
%R = 7 .
