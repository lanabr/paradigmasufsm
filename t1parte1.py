#1.Defina uma função somaQuad(x,y) que calcule a soma dos quadrados de
#dois números x e y.

def somaQuad(x, y):
    return x**2 + y**2

#2.Crie uma função hasEqHeads(l1,l2) que verifique se as listas l1 e l2
#possuem o mesmo primeiro elemento.

def hasEqHeads(l1, l2):
    return l1[0] == l2[0]

#3.Escreva uma função que receba uma lista de nomes e retorne uma lista
#com a string "Sr. " adicionada ao início de cada nome.
#Defina uma função auxiliar para ajudar neste exercício.
    
def nomesSr(lnomes):
    return list(map(auxNomeSr, lnomes))

def auxNomeSr(x):
    return 'Sr. ' + x

#4.Crie uma função que receba uma string e retorne o número de espaços
#nela contidos. Defina uma função auxiliar para ajudar neste exercício.

def espacos(s):
    return len(list(filter(auxEspacos, s)))

def auxEspacos(s):
    return s == ' '

#5.Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1
#para cada número n da lista. Defina uma função auxiliar para
#ajudar neste exercício.

def calc(num):
    return list(map(auxCalc, num))

def auxCalc(n):
    return ((3 * n * 2) + 2)/(n + 1)

#6.Escreva uma função que, dada uma lista de números, retorne uma lista com
#apenas os que forem negativos. Defina uma função auxiliar para ajudar
#neste exercício.

def cont(n):
    return list(filter(auxCont, n))

def auxCont(num):
    return num < 0

#7.Escreva uma função que receba uma lista de números e retorne somente
#os que estiverem entre 1 e 100, inclusive. Defina uma função auxiliar
#para ajudar neste exercício.

def separa(num):
    return list(filter(auxSepara, num))

def auxSepara(n):
    return (n >= 1) & (n <= 100)

#8.Escreva uma função que receba uma lista de números e retorne somente
#aqueles que forem pares. Defina uma função auxiliar para
#ajudar neste exercício.

def par(num):
    return list(filter(auxPar, num))

def auxPar(n):
    return n%2 == 0
    

#10.Escreva uma função que receba uma lista de strings e retorne uma
#nova lista com adição de marcações HTML (p.ex.: <B> e </B>) antes e
#depois de cada string.

def HTML(s):
    return list(map(auxHTML, s))

def auxHTML(x):
    return '<B> ' + x + '</B>'
