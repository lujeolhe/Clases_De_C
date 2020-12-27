#ifndef WIN32_BOTTONANS_H
#define WIN32_BOTTONANS_H

#include "AmbitoBoton.hpp"

namespace WIN32{
  class BotonAns:public AmbitoBoton,public Boton{
    public:
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
