#define __USE_MINGW_ANSI_STDIO 0
#include <string>
#include <cstring>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <FL/fl_ask.H>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "gerador.h"

class Data {
private:
    std::string id;
    std::string label;
public:
  Data(std::string id, std::string label) {
    this->id = id;
    this->label = label;
  }
  std::string getId() const {
    return id;
  }
  std::string getLabel() const {
    return label;
  }
  void setId(std::string id) {
    this->id = id;
  }
  void setLabel(std::string label) {
    this->label = label;
  }
};

class View : public UserInterface {

private:
  std::vector<Data> data;

public:

  View() {
    btnSave->callback((Fl_Callback*) cbBtnSave, (void*)(this));
    btnRead->callback((Fl_Callback*) cbBtnRead, (void*)(this));
    btnClear->callback((Fl_Callback*) cbBtnClear, (void*)(this));
    btnUpdate->callback((Fl_Callback*) cbBtnUpdate, (void*)(this));
    btnDelete->callback((Fl_Callback*) cbBtnDelete, (void*)(this));
    btnInsert->callback((Fl_Callback*) cbBtnInsert, (void*)(this));
    btnCreate->callback((Fl_Callback*) cbBtnCreate, (void*)(this));
    browser->callback((Fl_Callback*) cbBrowser, (void*)(this));
  }

  void show() {
    // Mostra janela
    w->show();
  }

  // Funcao callback chamada quando pressionado botao 'Save'
  static void cbBtnSave(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::string inputArq(gui->inputArq->value());

    std::ofstream in(inputArq);

    std::vector<Data>::const_iterator it;

    for(it = gui->data.begin(); it != gui->data.end(); it++){
        in << it->getId() << "," << it->getLabel() << std::endl;
    }

    in.close();
  }

  // Funcao callback chamada quando pressionado botao 'Read'
  static void cbBtnRead(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::string inputArq(gui->inputArq->value());

    std::ifstream in(inputArq);

    if(!in.is_open()) fl_alert("Nao ha nenhum arquivo com esse nome!");
    std::string line;
    std::string cell[2];

    while(getline(in, line)){
        std::stringstream linestream(line);
        getline(linestream, cell[0], ',');
        getline(linestream, cell[1], ',');
        gui->data.push_back(Data(cell[0], cell[1]));
        gui->browser->add((cell[0]+" : "+cell[1]).c_str());
    }

    in.close();
  }

  // Funcao callback chamada quando pressionado botao 'Clear'
  static void cbBtnClear(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    gui->inputId->value("");
    gui->inputLabel->value("");
  }

  // Funcao callback chamada quando pressionado botao 'Insert'
  static void cbBtnInsert(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    std::string inputId(gui->inputId->value());
    std::string inputLabel(gui->inputLabel->value());
    gui->data.push_back(Data(inputId, inputLabel));
    gui->browser->add((inputId+" : "+inputLabel).c_str());
  }

  // Funcao callback chamada quando selecionada uma linha no Fl_Browser
  static void cbBrowser(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    gui->inputId->value(gui->data[index-1].getId().c_str());
    gui->inputLabel->value(gui->data[index-1].getLabel().c_str());
  }

  // Funcao callback chamada quando pressionado botao 'Update'
  static void cbBtnUpdate(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    if (index > 0) {
      std::string inputId(gui->inputId->value());
      std::string inputLabel(gui->inputLabel->value());
      gui->data[index-1].setId(inputId);
      gui->data[index-1].setLabel(inputLabel);
      gui->browser->text(index,(inputId+" : "+inputLabel).c_str());
    }
  }

  // Funcao callback chamada quando pressionado botao 'Delete'
  static void cbBtnDelete(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    if (index > 0) {
      std::string inputNome(gui->inputId->value());
      std::string inputTipo(gui->inputLabel->value());
      gui->data.erase(gui->data.begin() + index-1);
      gui->browser->remove(index);
    }
  }

  // Funcao callback chamada quando pressionado botao 'Create!'
  static void cbBtnCreate(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);

    if(gui->browser->size() == 0) fl_alert("Nao ha nenhuma informacao!");

    std::ifstream in("template.html");
    std::ofstream out("index.html");

    std::vector<Data>::const_iterator it;

    std::string line;
    int cont = 0;

    while(getline(in, line)){

        if(cont == 6) {
            for(it = gui->data.begin(); it != gui->data.end(); it++)
                if(it->getId() == "title") break;
            //if(it->getId() != "title") fl_alert("Esta faltando alguma informacao!");

            out << "<title>" << it->getLabel() << "</title>" << std::endl;
        }else if(cont == 18){
            for(it = gui->data.begin(); it != gui->data.end(); it++)
                if(it->getId() == "h1") break;
            //if(it->getId() == "") fl_alert("Esta faltando alguma informacao!");

            out << "<h1>" << it->getLabel() << "</h1>" << std::endl;
        }else
            out << line << std::endl;;

        cont++;
    }
  }
};

int main() {
  View gui;
  gui.show();
  return Fl::run();
}
