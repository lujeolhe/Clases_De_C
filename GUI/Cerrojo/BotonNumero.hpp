#ifndef WIN32_BOTTONNUMERO_H
#define WIN32_BOTTONNUMERO_H
#include "AmbitoBoton.hpp"

namespace WIN32API{
  class BotonNumeros:public AmbitoBoton,public Boton{
  public:
    BotonNumeros(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){
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
