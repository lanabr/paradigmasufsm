#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

/*faixas de biscoitos e preços
    pequenos: 3 a 5 cm² - 50 centavos
    médios: 6 a 8 cm² - 1 real
    grandes: 9 a 11 cm² - 1,5 real
*/
class ContaCookie{
    string tipo;
    string tamanho;
    float area;
public:
    ContaCookie(string tip, int tam, float a){
        tipo = tip;
        area = a;
        if(tam == 1) tamanho = "pequeno";
        else if(tam == 2) tamanho = "medio";
        else if(tam == 3) tamanho = "grande";
    }
    void imprime(){
        cout.precision(3);
        cout << "  " << tamanho << ", na forma de um " << tipo << " de area " << area << endl;
    }
    string getTamanho(){
        return tamanho;
    }
    bool operator<(ContaCookie& k){
        return area > k.area;
    }
};

class Cookie{
    int tamanho; //1, 2 ou 3
    float preco;
public:
    Cookie(){
        tamanho = preco = 0;
    }
    setPreco(int tam){
        tamanho = tam;

        if(tamanho == 1) preco = 0.5;
        else if(tamanho == 2) preco = 1;
        else if(tamanho == 3) preco = 1.5;
    }
    float getPreco(){
        return preco;
    }
};

class Circulo : public Cookie{
    float raio;
    float a;
public:
    Circulo(float r){
        raio = r;
        a = 0.0;
    }
    int area(){
        a = (raio * raio) * 3.14;

        if(a >= 3.0 && a < 6.0){
            setPreco(1);
            return 1;
        }else if(a >= 6.0 && a < 9.0){
            setPreco(2);
            return 2;
        }else if(a >= 9.0 && a <= 11.0){
            setPreco(3);
            return 3;
        }
    }
    float getArea(){
        return a;
    }
};

class Triangulo : public Cookie{
    float base;
    float altura;
    float a;
public:
    Triangulo(float b, float h){
        base = b;
        altura = h;
    }
    int area(){
        a = (base * altura) / 2;

        if(a >= 3.0 && a < 6.0){
            setPreco(1);
            return 1;
        }else if(a >= 6.0 && a < 9.0){
            setPreco(2);
            return 2;
        }else if(a >= 9.0 && a <= 11.0){
            setPreco(3);
            return 3;
        }
    }
    float getArea(){
        return a;
    }
};

class Retangulo : public Cookie{
    float ladoA;
    float ladoB;
    float a;
public:
    Retangulo(float a, float b){
        ladoA = a;
        ladoB = b;
    }
    int area(){
        a = ladoA * ladoB;

        if(a >= 3.0 && a < 6.0){
            setPreco(1);
            return 1;
        }else if(a >= 6.0 && a < 9.0){
            setPreco(2);
            return 2;
        }else if(a >= 9.0 && a <= 11.0){
            setPreco(3);
            return 3;
        }
    }
    float getArea(){
        return a;
    }
};

main()
{
    int n, auxT = 0, contP = 0, contM = 0, contG = 0;
    int tipo; //1, 2, 3
    float auxR = 0, auxB = 0, auxH = 0;
    vector<ContaCookie> cont;
    vector<Circulo> cir;
    vector<Triangulo> tri;
    vector<Retangulo> ret;
    vector<ContaCookie>::iterator k;
    vector<Circulo>::iterator c;
    vector<Triangulo>::iterator t;
    vector<Retangulo>::iterator r;

    srand((unsigned)time(0));

    cout << "Quantos biscoitos sao?  ";
    cin >> n;

    for(int i = 0; i < n; i++){
        tipo = rand()%3 + 1;
        if(tipo == 1){
            auxR = rand()%9 + 10;
            cir.push_back(Circulo(auxR / 10));
        }else if(tipo == 2){
            auxB = rand()%21 + 26;
            auxH = rand()%21 + 26;
            tri.push_back(Triangulo(auxB / 10, auxH / 10));
        }else if(tipo == 3){
            auxB = rand()%15 + 18;
            auxH = rand()%15 + 18;
            ret.push_back(Retangulo(auxB / 10, auxH / 10));
        }
    }

    for(c = cir.begin(); c != cir.end(); c++){
        auxT = c->area();
        cont.push_back(ContaCookie("circulo", auxT, c->getArea()));
    }
    for(t = tri.begin(); t != tri.end(); t++){
        auxT = t->area();
        cont.push_back(ContaCookie("triangulo", auxT, t->getArea()));
    }
    for(r = ret.begin(); r != ret.end(); r++){
        auxT = r->area();
        cont.push_back(ContaCookie("retangulo", auxT, r->getArea()));
    }

    sort(cont.begin(), cont.end());
    cout << "\nOs biscoitos ordenados por tamanho: " << endl;
    for(k = cont.begin(); k != cont.end(); k++){
        k->imprime();
        if(k->getTamanho() == "pequeno") contP++;
        else if(k->getTamanho() == "medio") contM++;
        else if(k->getTamanho() == "grande") contG++;
    }

    cout << "\nCom " << contP << " biscoitos pequenos, o total arrecadado sera de " << (contP * 0.5) << " reais" << endl;
    cout << "Com " << contM << " biscoitos medios, o total arrecadado sera de " << contM << " reais" << endl;
    cout << "Com " << contG << " biscoitos grandes, o total arrecadado sera de " << (contG * 1.5) << " reais" << endl;
}
