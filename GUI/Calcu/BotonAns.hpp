#ifndef WIN32_BOTTONANS_H
#define WIN32_BOTTONANS_H

#include "AmbitoBoton.hpp"

namespace WIN32API{
  class BotonAns:public AmbitoBoton,public Boton{
    public:
      BotonAns(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){
        //printf("Mi id es: %d\n",get_id_btn());
      }
    void pushAction(){
      char ansb[10];
      Button_GetText(get_hwndButton_resu(),get_pantalla(),50);
      sprintf(ansb,"%d",(int)get_ans());//funciona como printf, pero imprime en la cadenas
      strcat(get_pantalla(),ansb);//es para concatenar
      Button_SetText(get_hwndButton_resu(),get_pantalla());
    }
  };
};
#endif
