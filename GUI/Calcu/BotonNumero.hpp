#ifndef WIN32_BOTTONNUMERO_H
#define WIN32_BOTTONNUMERO_H
#include "AmbitoBoton.hpp"

namespace WIN32{
  class BotonNumeros:public AmbitoBoton,public Boton{
  public:
    BotonNumeros(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){}
    void pushAction(){
      if(get_bandera()){
        set_bandera(0);
        set_pantalla("");
        Button_SetText(get_hwndButton_resu(),get_pantalla());
      }
      Button_GetText(get_hwndButton_resu(),get_pantalla(),50);
      Button_GetText(get_hwndButton_resu(),get_boton(),6);//se lee el manejador
      strcat(get_pantalla(),get_boton());//es para concatenar
      Button_SetText(get_hwndButton_resu(),get_pantalla());
    }
  };
};
#endif
