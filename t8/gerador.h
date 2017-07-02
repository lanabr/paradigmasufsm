#ifndef gerador_h
#define gerador_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Browser.H>

class UserInterface {
public:
    UserInterface();
protected:
    Fl_Double_Window *w; //janela
    Fl_Input *inputArq; //nome do arquivo a ser lido/salvo
    Fl_Button *btnSave; //salvar projeto
    Fl_Button *btnRead; //le projeto
    Fl_Input *inputId; //le id pro html
    Fl_Input *inputLabel; //le label pro html
    Fl_Button *btnClear; //limpa tudo
    Fl_Button *btnUpdate; //altera o selecionado
    Fl_Button *btnDelete; //deleta o selecionado
    Fl_Button *btnInsert; //insere o pedido
    Fl_Button *btnCreate; //gera o html
    Fl_Browser *browser; //tela branca
};
#endif
