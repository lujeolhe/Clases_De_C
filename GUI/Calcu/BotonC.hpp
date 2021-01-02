#ifndef WIN32_BOTTONC_H
#define WIN32_BOTTONC_H

#include "AmbitoBoton.hpp"

namespace WIN32API{
  class BotonC:public AmbitoBoton,public Boton{
    public:
      BotonC(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){}
    void pushAction(){
      sprintf(get_pantalla(),"");
      Button_SetText(get_hwndButton_resu(),get_pantalla());
    }
  };
};
#endif
