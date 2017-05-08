#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <functional>

using namespace std;

class Pessoa{
    string nome;
    string atividade;
    int pontos;
public:
    Pessoa(string nome, string atividade, int ponto){
        this->nome = nome;
        this->atividade = atividade;
        this->pontos = ponto;
    }
    string getNome(){
        return nome;
    }
    int getPontos(){
        return pontos;
    }
    void imprime(){
        cout << this->nome << ", " << atividade << ", " << pontos << endl;
    }
};

class Pontuacao{
    string nome;
    vector<int> pontos;
    int soma;
public:
    Pontuacao(string nome, int pontos){
        this->nome = nome;
        this->pontos.push_back(pontos);
        soma = 0;
    }
    void insere(int pontos){
        this->pontos.push_back(pontos);
    }
    string getNome(){
        return nome;
    }
    int getSoma(){
        return soma;
    }
    void somatorio(){
        vector<int>::iterator it;
        for(it = pontos.begin(); it != pontos.end(); it++){
            soma = soma + *it;
        }
    }
    void imprime(){
        cout << nome << ", " << soma << endl;
    }
};

bool cmpSoma(Pontuacao &p1, Pontuacao &p2)
{
    return p1.getSoma() < p2.getSoma();
}

bool cmpNome(Pontuacao &p1, Pontuacao &p2)
{
    return p1.getNome() < p2.getNome();
}

bool cmpPontos(Pessoa &p1, Pessoa &p2)
{
    return p1.getPontos() > p2.getPontos();
}

int main()
{
    ifstream entrada("pontos.csv");

    string line;
    string cell[3];
    vector<Pessoa> v;
    char flag;

    while (getline(entrada, line)) {
        stringstream linestream(line);
        getline(linestream, cell[0], ',');
        getline(linestream, cell[1], ',');
        getline(linestream, cell[2], ',');
        v.push_back(Pessoa(cell[0], cell[1], strtol(cell[2].c_str(), 0, 10)));
    }

    vector<Pessoa>::iterator it;
    vector<Pontuacao> pontPessoas;
    vector<Pontuacao>::iterator pp;

    for(it = v.begin(); it != v.end(); it++){
        flag = 0;
        for(pp = pontPessoas.begin(); pp != pontPessoas.end(); pp++)
            if(it->getNome() == pp->getNome()){
                pp->insere(it->getPontos());
                flag = 1;
                continue;
            }
        if(flag == 0) pontPessoas.push_back(Pontuacao{it->getNome(), it->getPontos()});
    }

    for(pp = pontPessoas.begin(); pp != pontPessoas.end(); pp++)
        pp->somatorio();

    sort(v.begin(), v.end(), cmpPontos);
    cout << "\nOrdenacao por pontos em atividade: " << endl;
    for (it = v.begin(); it != v.end(); it++)
        it->imprime();

    sort(pontPessoas.begin(), pontPessoas.end(), cmpNome);
    cout << "\nOrdenacao por nome: " << endl;
    for(pp = pontPessoas.begin(); pp != pontPessoas.end(); pp++)
        pp->imprime();

    sort(pontPessoas.begin(), pontPessoas.end(), cmpSoma);
    cout << "\nOrdenacao por somatorio: " << endl;
    for(pp = pontPessoas.begin(); pp != pontPessoas.end(); pp++)
        pp->imprime();

    return 0;
}
