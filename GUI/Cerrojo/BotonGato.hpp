#ifndef WIN32_BOTTONGATO_H
#define WIN32_BOTTONGATO_H
#include "AmbitoBoton.hpp"

namespace WIN32API{
  class BotonGato:public AmbitoBoton,public Boton{
  public:
    BotonGato(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){
      //printf("Mi id es: %d\n",get_id_btn());
    }
    void pushAction(){
      Button_GetText(get_hwndButton_panel(),get_pantalla(),50);
      Button_GetText(get_hwndButton(),get_boton(),6);//se lee el manejador
      strcat(get_pantalla(),"*");//es para concatenar
      Button_SetText(get_hwndButton_panel(),get_pantalla());
    }
  };
};
#endif
