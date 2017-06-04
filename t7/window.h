#ifndef window_h
#define window_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Image.H>

class UserInterface {
public:
  UserInterface();
protected:
  Fl_Double_Window *w;
  Fl_Int_Input *inputValue;
  Fl_Button *btnReset;
  Fl_Button *btnSort;
  Fl_Box *boxResult;

  Fl_Text_Buffer *tbuff;
  Fl_Text_Display *disp;

  Fl_Box *boxImage;
  Fl_PNG_Image *imagePNG;
};

#endif
