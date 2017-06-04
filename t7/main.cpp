#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#include <FL/fl_ask.H>
#include "window.h"

class RandomView : public UserInterface {
    std::vector<int> rand;
    int cont;
public:

    RandomView() {
        btnReset->callback((Fl_Callback*) cbBtnReset, (void*)(this));
        btnSort->callback((Fl_Callback*) cbBtnRandom, (void*)(this));
    }

    static void cbBtnRandom(Fl_Widget* btn, void* userdata){
        RandomView* gui = static_cast<RandomView*>(userdata);
        try {
            int x = std::stoi(gui->inputValue->value());
            if(gui->rand.empty()){
                for(int i = 1; i <= x; i++)
                    gui->rand.push_back(i);

                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                shuffle(gui->rand.begin(), gui->rand.end(), std::default_random_engine(seed));
            }

            int e = gui->rand.back();
            gui->rand.pop_back();

            gui->boxResult->copy_label(std::to_string(e).c_str());

            gui->tbuff->text(std::to_string(gui->cont).c_str());
            gui->tbuff->insert(gui->tbuff->length(), "º Ganhador");

            gui->cont++;

        }catch (std::invalid_argument&) {
            fl_alert("O numero de participantes deve ser inteiro");
        }catch (std::out_of_range&) {
            fl_alert("Argumentos fora de faixa");
        }

        if(gui->rand.empty())
            fl_alert("Nao ha numeros para sortear");
    }

    static void cbBtnReset(Fl_Widget* btn, void* userdata){
        RandomView* gui = static_cast<RandomView*>(userdata);

        gui->inputValue->value("");
        gui->boxResult->label("");
        gui->tbuff->text("");
        gui->rand.clear();
    }

    void inicializa(){
        cont = 1;
    }

    void show() {
        w->show();
    }
};

int main() {
    RandomView gui;
    gui.inicializa();
    gui.show();
    return Fl::run();
}
