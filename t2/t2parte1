#1.Defina uma função addSuffix(suf,nomes)
#que retorne a lista de nomes com o sufixo suf adicionado.

def addSuffix(suf,nomes):
    return [x + suf for x in nomes] 

#2.Escreva uma função countShorts(words), que receba uma
#lista de palavras e retorne a quantidade de palavras dessa
#lista que possuem menos de 5 caracteres.

def countShorts(words):
    return len([x for x in words if len(x) < 5])

#3.Defina uma função stripVowels(s) que receba uma string e retire suas vogais.

def stripVowels(s):
    return ''.join([x for x in s if x not in "aeiouAEIOU"])

#4.Defina uma função hideChars(s) que receba uma string,
#possivelmente contendo espaços, e que retorne outra string
#substituindo os demais caracteres por '-', mas mantendo os espaços. 

def hideChars(s):
    return ''.join(['-' if x not in ' ' else ' ' for x in s])

#5.Defina uma função que receba um número n e retorne uma tabela
#de números de 1 a n e seus quadrados

def genTable(n):
    return [(x,x**2) for x in range(1, n + 1)]

#6.Defina uma função que receba uma lista de palavras e retorne uma
#string contendo o primeiro e o último caracter de cada palavra da lista. 

def genCode(s):
    return ''.join([x[0] + x[-1] for x in s])

#7.Defina uma função myZip(l1,l2) que reproduza o
#comportamento da função zip do Python.

def myZip(l1,l2):
    return [(l1[i], l2[i]) for i in list(range(min([len(l1), len(l2)])))]

#8.Escreva uma função enumerate(words) que numere cada palavra da lista recebida.

def enumerate(words):
    return [(x + 1, words[x]) for x in range(len(words))]

#9.Escreva uma função isBin(s) que verifique se a
#string recebida representa um número binário.

def isBin(s):
    return [True if x in '01' else False for x in s] == [True] * len(s)

#10.Escreva uma função bin2dec(digits), que receba uma lista de dígitos
#representando um número binário e retorne seu equivalente em decimal.

def bin2dec(digits):
    lis = list(range(len(digits) - 1, -1, -1))
    return sum([digits[i] * (2**lis[i]) for i in range(len(digits))])
