#include "window.h"

UserInterface::UserInterface() {
    {   w = new Fl_Double_Window(370, 447, "Random!");
        w->box(FL_FLAT_BOX);
        w->user_data((void*)(this));
        w->color(0x171C3000);
        {   inputValue = new Fl_Int_Input(155, 210, 60, 26, "Participantes");
            inputValue->type(2);
            inputValue->labelcolor(0x74888900);
            inputValue->align(Fl_Align(FL_ALIGN_TOP));
        }
        {   boxResult = new Fl_Box(50, 270, 270, 70);
            boxResult->box(FL_DOWN_BOX);
            boxResult->labelsize(30);
        }
        {   btnSort = new Fl_Button(50, 345, 270, 37, "Sortear!");
        }
        {   btnReset = new Fl_Button(110, 387, 150, 30, "Reset");
        }
        {   tbuff = new Fl_Text_Buffer();
        }
        {   disp = new Fl_Text_Display(138, 245, 150, 25);
            disp->buffer(tbuff);
            disp->box(FL_NO_BOX);
            disp->color(0x171C3000);
            disp->textcolor(0x74888900);
        }
        {   imagePNG = new Fl_PNG_Image("image.png");
        }
        {   boxImage = new Fl_Box(40, 30, 290, 150);
            boxImage->image(imagePNG);
            boxImage->redraw();
        }

        w->end();
    }

}
