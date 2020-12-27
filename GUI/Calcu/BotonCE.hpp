#ifndef WIN32_BOTTONCE_H
#define WIN32_BOTTONCE_H

#include "AmbitoBoton.hpp"

namespace WIN32{
  class BotonCE:public AmbitoBoton,public Boton{
    public:
    void pushAction(){
      char operacion;
      char *p;
        Button_GetText(get_hwndButton_resu(),get_pantalla(),50);
        p=get_pantalla();
        operacion=*(p+strlen(get_pantalla())-1);
        if(operacion=='/'||operacion=='+'||operacion=='-'||operacion=='*'){
          *(p+strlen(get_pantalla())-2)='\0';
          Button_SetText(get_hwndButton_resu(),get_pantalla());
      }
      else{
        *(p+strlen(get_pantalla())-1)='\0';
        Button_SetText(get_hwndButton_resu(),get_pantalla());
      }
    }
  };
};
#endif
