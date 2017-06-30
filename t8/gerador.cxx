#include "gerador.h"

UserInterface::UserInterface() {
  { w = new Fl_Double_Window(520, 490, "Gerador HTML");
    w->user_data((void*)(this));
    { inputArq = new Fl_Input(80, 48, 195, 25, "Arquivo"); }
    { inputId = new Fl_Input(80, 85, 150, 25, "ID"); }
    { inputLabel = new Fl_Input(285, 85, 150, 25, "Label"); }
    { btnSave = new Fl_Button(285, 48, 100, 25, "Save"); }
    { btnRead = new Fl_Button(395, 48, 100, 25, "Read"); }
    { btnClear = new Fl_Button(24, 122, 100, 25, "Clear"); }
    { btnUpdate = new Fl_Button(147, 122, 100, 25, "Update"); }
    { btnDelete = new Fl_Button(270, 122, 100, 25, "Delete"); }
    { btnInsert = new Fl_Button(394, 122, 100, 25, "Insert"); }
    { btnCreate = new Fl_Button(210, 450, 100, 25, "Create!"); }
    { Fl_Box* o = new Fl_Box(132, 16, 255, 16, "Gerador HTML");
      o->labelfont(1);
      o->labelsize(22);
    }
    { browser = new Fl_Browser(24, 159, 470, 277);
      browser->type(2);
    }
    w->end();
  }
}

